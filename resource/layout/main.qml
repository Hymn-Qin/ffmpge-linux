import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    ColorText {
        anchors.centerIn: parent
        onClicked: {
            console.log("colorButton: ", buttonColor)
            var value = buttonColor
            switch(value) {
                case "#ff0000": backImg.source = ":/image/resource/Player.png"; break;
                case "#0000ff": backImg.source = ":/image/resource/Player.png"; break;
                default: backImg.source = ":/image/resource/Player.png";
            }
        }
    }

    Image {
        id: backImg
        source: ":/image/resource/Player.png"
        width: parent.width
        anchors.bottom: parent.bottom
        fillMode: Image.PreserveAspectFit
    }
    
}
