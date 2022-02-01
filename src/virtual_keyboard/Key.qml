import QtQuick 2.15
import QtQuick.Controls 2.15
import com.nnaabbcc.virtualkeyboard 1.0

Button {
    property int key: 0
    property string eventText: text
    focusPolicy: Qt.NoFocus

    onPressed: {
        InputContext.triggerKeyPressed(key, eventText);
    }

    onReleased: {
        InputContext.triggerKeyReleased(key, eventText);
    }
}