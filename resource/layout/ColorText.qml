import QtQuick 2.15

Item {
    id: root
    
    signal clicked(string buttonColor)
    
    Text {
        id: text1
        text: qsTr('Hello QML')
        
        anchors.centerIn: parent
        
        font.bold: true
        font { pointSize: 14; capitalization: Font.AllUppercase }
        Behavior on rotation {
            NumberAnimation { duration: 50}
        }
    }

    
    Rectangle {
        id: colorRect
        width: 20 * 2
        height: width
        radius: 20
        color: "green"

        anchors.left: text1.right
        anchors.leftMargin: 10
        
        anchors.verticalCenter: text1.verticalCenter

        MouseArea {
            
            anchors.fill: parent
            onClicked: {
                
                console.log("colorRect: ", parent.color)
                text1.rotation += 360
                text1.color = parent.border.color
                root.clicked(parent.border.color)
            }
            hoverEnabled: true
            onEntered: {
                parent.width = 32
                parent.color = "black"
            }
            onExited: {
                parent.width = 40
                parent.color = "white"
            }
        }
        Rectangle {
            width: 12 * 2
            height: width
            radius: 12
            color: parent.border.color
            
            anchors.centerIn: parent
            
        }
    }
}
