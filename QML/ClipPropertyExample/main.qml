import QtQuick 2.12
import QtQuick.Window 2.12
import QtGraphicalEffects 1.13

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Clip Property Example")

    Rectangle {
        id: rect
        x: 27
        y: 31
        width: 100
        height: 100
        color: "blue"
        radius: 30
        clip: true

        layer.enabled: true
        layer.effect: OpacityMask {
            maskSource: Item {
                width: rect.width
                height: rect.height
                Rectangle {
                    anchors.centerIn: parent
                    width: rect.adapt ? rect.width : Math.min(rect.width, rect.height)
                    height: rect.adapt ? rect.height : width
                    radius: 30
                }
            }
        }

        Rectangle {
            x: -20
            y: -20
            width: 100
            height: 100

            color: "green"
        }
    }
}
