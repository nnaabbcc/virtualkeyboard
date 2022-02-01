import QtQuick 2.15
import QtQuick.Controls 2.15
import com.nnaabbcc.virtualkeyboard 1.0

Item {
    id: control
    visible : InputContext.visible

    Rectangle {
        id: background
        anchors.fill: parent
        color: '#222332'
    }

    Column {
        anchors.fill: parent
        anchors.margins: 10

        spacing: 10

        Row {
            spacing: 10

            Button {
                text: '1'
                focusPolicy: Qt.NoFocus
                onClicked: {
                    InputContext.triggerKey(Qt.Key_1, '1');
                }
            }
            Button {
                text: '2'
                focusPolicy: Qt.NoFocus
                onClicked: {
                    InputContext.triggerKey(Qt.Key_2, '2');
                }
            }
            Button {
                text: '3'
                focusPolicy: Qt.NoFocus
                onClicked: {
                    InputContext.triggerKey(Qt.Key_3, '3');
                }
            }
            Button {
                text: '4'
                focusPolicy: Qt.NoFocus
                onClicked: {
                    InputContext.triggerKey(Qt.Key_4, '4');
                }
            }
        }

        Row {
            spacing: 10

            Button {
                text: 'Tab'
                focusPolicy: Qt.NoFocus
                onClicked: {
                    InputContext.triggerKey(Qt.Key_Tab, '');
                }
            }

            Button {
                text: 'Q'
                focusPolicy: Qt.NoFocus
                onClicked: {
                    InputContext.triggerKey(Qt.Key_Q, 'Q');
                }
            }
            Button {
                text: 'W'
                focusPolicy: Qt.NoFocus
                onClicked: {
                    InputContext.triggerKey(Qt.Key_W, 'W');
                }
            }
            Button {
                text: 'E'
                focusPolicy: Qt.NoFocus
                onClicked: {
                    InputContext.triggerKey(Qt.Key_E, 'E');
                }
            }
            Button {
                text: 'R'
                focusPolicy: Qt.NoFocus
                onClicked: {
                    InputContext.triggerKey(Qt.Key_R, 'R');
                }
            }
            Button {
                text: 'T'
                focusPolicy: Qt.NoFocus
                onClicked: {
                    InputContext.triggerKey(Qt.Key_T, 'T');
                }
            }

            Button {
                text: '<-'
                focusPolicy: Qt.NoFocus
                onClicked: {
                    InputContext.triggerKey(Qt.Key_Backspace, '');
                }
            }
        }

        Row {
            spacing: 10

            Button {
                text: 'Enter'
                focusPolicy: Qt.NoFocus
                onClicked: {
                    InputContext.triggerKey(Qt.Key_Enter, '');
                }
            }
        }

    }
}
