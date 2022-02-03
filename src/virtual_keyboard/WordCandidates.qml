import QtQuick 2.15
import QtQuick.Controls 2.15
import com.nnaabbcc.virtualkeyboard 1.0

Item {
    id: control
    height: 40

    ListView {
        anchors.fill: parent
        model: InputContext.candidatesModel
        orientation: ListView.Horizontal

        delegate: Label {
            anchors.verticalCenter: parent.verticalCenter
            text: model.display
            font.pixelSize: 20
            color: 'white'
            leftPadding: 10
            rightPadding: 10

            MouseArea {
                anchors.fill: parent
                onClicked: InputContext.selectCandidate(model.index)
            }
        }
    }

}
