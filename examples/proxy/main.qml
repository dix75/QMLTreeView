import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15

import QMLTreeView 1.0

Window {
  width: 800
  height: 600
  visible: true
  title: qsTr("Styled TreeView")

  ColumnLayout {
    anchors.fill: parent

    TextField {
      focus: true
      implicitWidth: 300
      placeholderText: qsTr("Enter filter text")
      Keys.onReleased: {
        treeProxyModel.filter = text
        treeProxyModel.reload()
      }
    }

    TreeView {
        id: proxyTreeView

      model: treeProxyModel
      selectionEnabled: true
      hoverEnabled: true

      color: "steelblue"
      handleColor: "steelblue"
      hoverColor: "skyblue"
      selectedColor: "cornflowerblue"
      selectedItemColor: "white"
      handleStyle: TreeView.Handle.Chevron
      rowHeight: 40
      rowPadding: 30
      rowSpacing: 12
      font.pixelSize: 20

      onCurrentIndexChanged: console.log("current index is (row=" + currentIndex.row + ", depth=" + model.depth(currentIndex) + ")")
      onCurrentDataChanged: console.log("current data is " + currentData)
      onCurrentItemChanged: console.log("current item is " + currentItem)
    }
  }
}

