from PyQt5.QtGui import QGuiApplication
from PyQt5.QtQml import QQmlApplicationEngine

if __name__ == "__main__":
    import sys

    app = QGuiApplication(sys.argv)
    engine = QQmlApplicationEngine()
    engine.load("main.qml")

    engine.quit.connect(app.quit)
    sys.exit(app.exec_())
