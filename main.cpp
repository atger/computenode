#include <QApplication>
#include <QWidget>
#include "cursors.hpp"

int main(int argc, char** argv) {
	QApplication app(argc, argv);
	Cursors window;
	window.resize(600,400);
	window.setWindowTitle("First App");
	window.setToolTip("First App Of Milenial");
	window.show();
	return app.exec();
}
