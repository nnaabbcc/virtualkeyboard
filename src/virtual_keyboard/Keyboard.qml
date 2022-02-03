import QtQuick 2.15
import QtQuick.Controls 2.15
import com.nnaabbcc.virtualkeyboard 1.0

Item {
    id: control

    WordCandidates {
        id: wordCandidates
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: keyboardLayout.top
        anchors.leftMargin: 10
        anchors.rightMargin: 10
        anchors.bottomMargin: 10
    }

    KeyboardLayout {
        id: keyboardLayout
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottomMargin: 10
        anchors.leftMargin: 10
        anchors.rightMargin: 10
    }

}
