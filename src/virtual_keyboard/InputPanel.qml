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

    Keyboard {
        id: keyboard
        anchors.fill: parent
    }

}
