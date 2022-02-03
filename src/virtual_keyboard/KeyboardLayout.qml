import QtQuick 2.15
import QtQuick.Controls 2.15
import com.nnaabbcc.virtualkeyboard 1.0

Item {
    id: control
    height: childrenRect.height

    Column {
        id: col

        width: parent.width
        anchors.margins: 10

        spacing: 10

        Row {
            spacing: 10

            Key {
                text: '1'
                key: Qt.Key_1
            }

            Key {
                text: '2'
                key: Qt.Key_2
            }

            Key {
                text: '3'
                key: Qt.Key_3
            }

            Key {
                text: '4'
                key: Qt.Key_4
            }

            Key {
                text: '5'
                key: Qt.Key_5
            }

            Key {
                text: '6'
                key: Qt.Key_6
            }

            Key {
                text: '7'
                key: Qt.Key_7
            }

            Key {
                text: '8'
                key: Qt.Key_8
            }

            Key {
                text: '9'
                key: Qt.Key_9
            }

            Key {
                text: '0'
                key: Qt.Key_0
            }

            Key {
                text: 'Backspace'
                eventText: ''
                key: Qt.Key_Backspace
            }
        }

        Row {
            spacing: 10

            Key {
                text: 'Tab'
                eventText: ''
                key: Qt.Key_Tab
            }

            Key {
                text: 'Q'
                key: Qt.Key_Q
            }

            Key {
                text: 'W'
                key: Qt.Key_W
            }

            Key {
                text: 'E'
                key: Qt.Key_E
            }

            Key {
                text: 'R'
                key: Qt.Key_R
            }

            Key {
                text: 'T'
                key: Qt.Key_T
            }

            Key {
                text: 'Y'
                key: Qt.Key_Y
            }

            Key {
                text: 'U'
                key: Qt.Key_U
            }

            Key {
                text: 'I'
                key: Qt.Key_I
            }

            Key {
                text: 'O'
                key: Qt.Key_O
            }

            Key {
                text: 'P'
                key: Qt.Key_P
            }

        }

        Row {
            spacing: 10

            Key {
                text: 'Caps'
                eventText: ''
                key: Qt.Key_CapsLock
            }

            Key {
                text: 'A'
                key: Qt.Key_A
            }

            Key {
                text: 'S'
                key: Qt.Key_S
            }

            Key {
                text: 'D'
                key: Qt.Key_D
            }

            Key {
                text: 'F'
                key: Qt.Key_F
            }

            Key {
                text: 'G'
                key: Qt.Key_G
            }

            Key {
                text: 'H'
                key: Qt.Key_H
            }

            Key {
                text: 'J'
                key: Qt.Key_J
            }

            Key {
                text: 'K'
                key: Qt.Key_K
            }

            Key {
                text: 'L'
                key: Qt.Key_L
            }

            Key {
                text: 'Enter'
                eventText: ''
                key: Qt.Key_Enter
            }
        }

        Row {
            spacing: 10

            Key {
                text: 'Shift'
                eventText: ''
                key: Qt.Key_Shift
            }

            Key {
                text: 'Z'
                key: Qt.Key_Z
            }

            Key {
                text: 'X'
                key: Qt.Key_X
            }

            Key {
                text: 'C'
                key: Qt.Key_C
            }

            Key {
                text: 'V'
                key: Qt.Key_V
            }

            Key {
                text: 'B'
                key: Qt.Key_B
            }

            Key {
                text: 'N'
                key: Qt.Key_N
            }

            Key {
                text: 'M'
                key: Qt.Key_M
            }

            Key {
                text: 'Shift'
                eventText: ''
                key: Qt.Key_Shift
            }
        }

        Row {
            spacing: 10

            Key {
                text: 'Ctrl'
                eventText: ''
                key: Qt.Key_Control
            }

            Key {
                text: 'Alt'
                eventText: ''
                key: Qt.Key_Alt
            }

            Key {
                text: 'SPACE'
                eventText: ' '
                key: Qt.Key_Space
            }

            Key {
                text: 'Alt'
                eventText: ''
                key: Qt.Key_Alt
            }

            Key {
                text: 'Ctrl'
                eventText: ''
                key: Qt.Key_Control
            }

            KeyboardKey{}
        }
    }
}