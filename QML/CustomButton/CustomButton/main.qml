import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Custom Button")

    // Create the first button
    Button {
        id: button_1
        // Customize layout using anchors
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.horizontalCenter
        anchors.rightMargin: 15
        text: qsTr("Press me 1")

        // To customize the text, you need to set the Text object to contentItem
        contentItem: Text {
            text: button_1.text
            color: button_1.pressed ? "black" : "red"
        }

        // To customize the background, you must override the background property
        // namely, install some object that inherits from Item
        // For example Rectangle
        background: Rectangle {
            // The important point for dynamically setting the color is
            // that we control the pressed property of the button we are interested in
            // and depending on its state, set the color
            color: button_1.pressed ? "red" : "black"           // as background color
            border.color: button_1.pressed ? "black" : "red"    // so the borders
            border.width: 2
            radius: 5
        }
    }

    // Similarly, we customize the second button
    Button {
        id: button_2
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.horizontalCenter
        anchors.leftMargin: 15
        text: qsTr("Press me 2")

        contentItem: Text {
            text: button_2.text
            color: button_2.pressed ? "red" : "black"
        }

        background: Rectangle {
            color: button_2.pressed ? "black" : "red"
            border.color: button_2.pressed ? "red" : "black"
            border.width: 2
            radius: 5
        }
    }
}
