import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: window
    visible: true
    width: 480
    height: 640
    title: qsTr("Hello World")

    Text {
        text: qsTr("Splash Screen")
        anchors.centerIn: parent
    }
}
