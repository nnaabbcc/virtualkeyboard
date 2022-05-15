import QtQuick 2.15
import QtQuick.Controls 2.15
import com.nnaabbcc.virtualkeyboard 1.0

Item {
    width: 1280
    height: 800

    Rectangle {
        id: rect
        anchors.top: parent.top
        anchors.topMargin: 100
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width * 0.8
        height: 300
        color: '#222822'
        border.color: '#cccccc'
        border.width: 2
        radius: 10

        TextArea {
            anchors.fill: parent
            anchors.margins: 10
            font.pixelSize: 25
            color: 'white'
        }
    }

    Row {
        anchors.top: rect.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.topMargin: 10
        spacing: 10

        Button {
            text: 'Click'
        }

        CheckBox {
            text: 'Check'
        }

    }

    InputPanel {
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        visible: Qt.inputMethod.visible
        height: 300
    }

}
