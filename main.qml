import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    ComboBox {
        id:cbDevName
        width: 150
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.leftMargin: 0
        anchors.topMargin: 0
        model: gui.devName
    }

    Button {
        text: "Open"
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.leftMargin: 155
        anchors.topMargin: 0
        onClicked: gui.open(cbDevName.currentValue)
    }

    TextField {
        id: macSrc
        x: 270
        width: 120
        height: 40
        text: gui.macSrc
        anchors.left: parent.left
        anchors.top: parent.top
        font.pixelSize: 12
        verticalAlignment: Text.AlignVCenter
        anchors.topMargin: 0
        anchors.leftMargin: 260
        inputMask: "HH:HH:HH:HH:HH:HH"
    }

    ListView {
        id: listView
        anchors.fill: parent
        anchors.rightMargin: 10
        anchors.leftMargin: 10
        anchors.bottomMargin: 100
        anchors.topMargin: 50
        delegate: Item {
            x: 5
            width: 80
            height: 40
            Row {
                id: row1
                Rectangle {
                    width: 25
                    height: 25
                    color: colorCode
                    radius: 20
                }

                Text {
                    text: name
                    anchors.verticalCenter: parent.verticalCenter
                    font.bold: true
                }
                spacing: 10
            }
        }
        model: ListModel {
            ListElement {
                name: "Grey"
                colorCode: "grey"
            }

            ListElement {
                name: "Red"
                colorCode: "red"
            }

            ListElement {
                name: "Blue"
                colorCode: "blue"
            }

            ListElement {
                name: "Green"
                colorCode: "green"
            }
        }
    }

    TextField {
        id: msg
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.rightMargin: 210
        anchors.leftMargin: 10
        anchors.bottomMargin: 10
        anchors.right: parent.right
        validator: RegExpValidator {
            regExp: /[0-9A-Fa-f]+/
        }
    }

    TextField {
        id: macDst
        width: 120
        height: 40
        text: gui.macDst
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        font.pixelSize: 12
        verticalAlignment: Text.AlignVCenter
        anchors.rightMargin: 85
        anchors.bottomMargin: 10
        inputMask: "HH:HH:HH:HH:HH:HH"
    }


    Button {
        text: "Send"
        width: 70
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.rightMargin: 10
        anchors.bottomMargin: 10
        onClicked: gui.sendData(macSrc.text, macDst.text, msg.text)
    }

}
