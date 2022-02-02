
#include "pinyinime.h"
#include <filesystem>
#include <iostream>
#include <QString>
#include <QDebug>

namespace fs = std::filesystem;

void print_candidates(size_t number_of_candidates)
{
    const size_t bufsize = 1024;
    ime_pinyin::char16 buffer[bufsize];
    for (decltype(number_of_candidates) i = 0;
        i < number_of_candidates;
        i++)
    {
        memset(buffer, 0, bufsize * sizeof(ime_pinyin::char16));
        auto candidate = ime_pinyin::im_get_candidate(
            i,
            buffer,
            bufsize);
        if (candidate != nullptr)
        {
            auto ss = QString::fromUtf16(candidate);
            qDebug() << i << ss;
        }
    }
}

void test(std::string s)
{
    auto candidate_number = ime_pinyin::im_search(s.c_str(), s.size());
    std::cout << "Input "
        << s
        << ", Found "
        << candidate_number
        << " candidates"
        << std::endl;
    print_candidates(candidate_number);
}

int main(int, char**)
{

    auto cwd = fs::current_path();
    std::cout << cwd << std::endl;

    auto sys_dict = "res/raw/dict_pinyin.dat";
    auto user_dict = "user_dict.dat";
    auto ok = ime_pinyin::im_open_decoder(
        sys_dict,
        user_dict
    );
    if (ok)
    {
        ime_pinyin::im_set_max_lens(50, 50);
        test("yangcongtou");
        ime_pinyin::im_reset_search();
        test("yangcong");
        ime_pinyin::im_reset_search();
        test("zhong");
        ime_pinyin::im_reset_search();
        test("jian");
        ime_pinyin::im_reset_search();
        test("zhongjian");
    }
    else
    {
        std::cout << "Failed to open decoder" << std::endl;
    }
    ime_pinyin::im_close_decoder();
    return 0;
}
