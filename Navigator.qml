import QtQuick

Item {
    id: navPanelId

    Image {
        id: navCarUnionId
        anchors.horizontalCenter:  parent.horizontalCenter
        anchors.bottom: parent.bottom
        source: "qrc:/images/navigation/Union.svg"
    }

    Image {
        id: navCarUnionRedId
        anchors.horizontalCenter:  parent.horizontalCenter
        anchors.bottom: parent.bottom
        source: "qrc:/images/navigation/UnionRed.svg"
    }

    Image {
        id: navCarUnionCenterId
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        source: "qrc:/images/navigation/UnionCenter.svg"
    }


    Image {
        id: navCarPathId
        anchors.horizontalCenter:  navCarUnionId.horizontalCenter
        anchors.verticalCenter: navCarUnionId.verticalCenter
        source: "qrc:/images/navigation/car.png"
    }

}
