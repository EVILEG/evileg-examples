from PyQt5.QtCore import QSize, Qt
from PyQt5.QtWidgets import QApplication, QMainWindow, QGridLayout, QWidget, QTableWidgetItem

from widgets import CustomTableWidget


# Inheriting from QMainWindow
class MainWindow(QMainWindow):
    # Overriding the class constructor
    def __init__(self):
        # Be sure to call the super class method
        QMainWindow.__init__(self)

        self.setMinimumSize(QSize(480, 80))  # Set sizes
        self.setWindowTitle("Работа с QTableWidget")  # Set the window title
        central_widget = QWidget(self)  # Create a central widget
        self.setCentralWidget(central_widget)  # Install the central widget

        grid_layout = QGridLayout()  # Create a QGridLayout
        central_widget.setLayout(grid_layout)  # Install this placement in the central widget

        table = CustomTableWidget(self)  # Create a table
        table.setColumnCount(3)  # We install three columns
        table.setRowCount(1)  # and one row in the table

        # Set table headers
        table.setHorizontalHeaderLabels(["Header 1", "Header 2", "Header 3"])

        # Set tooltips for headers
        table.horizontalHeaderItem(0).setToolTip("Column 1 ")
        table.horizontalHeaderItem(1).setToolTip("Column 2 ")
        table.horizontalHeaderItem(2).setToolTip("Column 3 ")

        # Set the alignment to the headers
        table.horizontalHeaderItem(0).setTextAlignment(Qt.AlignLeft)
        table.horizontalHeaderItem(1).setTextAlignment(Qt.AlignHCenter)
        table.horizontalHeaderItem(2).setTextAlignment(Qt.AlignRight)

        # fill the first line
        table.setItem(0, 0, self.createItem("Text in column 1", Qt.ItemIsSelectable | Qt.ItemIsEnabled))
        table.setItem(0, 1, self.createItem("Text in column 2", Qt.ItemIsSelectable | Qt.ItemIsEnabled | Qt.ItemIsEditable))
        table.setItem(0, 2, self.createItem("Text in column 3", Qt.ItemIsSelectable | Qt.ItemIsEnabled | Qt.ItemIsEditable))

        # do column resizing by content
        table.resizeColumnsToContents()

        grid_layout.addWidget(table, 0, 0)  # Add a table to the grid

    def createItem(self, text, flags):
        tableWidgetItem = QTableWidgetItem(text)
        tableWidgetItem.setFlags(flags)
        return tableWidgetItem


if __name__ == "__main__":
    import sys

    app = QApplication(sys.argv)
    mw = MainWindow()
    mw.show()
    sys.exit(app.exec())
