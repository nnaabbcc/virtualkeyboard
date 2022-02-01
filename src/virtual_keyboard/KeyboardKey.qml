import QtQuick 2.15
import QtQuick.Controls 2.15
import com.nnaabbcc.virtualkeyboard 1.0

Button {
    text: 'Hide'
    focusPolicy: Qt.NoFocus

    onClicked: {
        InputContext.visible = false;
    }
}