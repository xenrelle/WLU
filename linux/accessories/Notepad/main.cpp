#include <QMessageBox>
#include <QApplication>
#include <QMainWindow>
#include <QString>
#include <string>
#include <QTextDocument>
#include <QTextFrame>
#include <QTextFrameFormat>
#include <QSizeGrip>
#include <QStyle>
#include <QStyleFactory>
#include "ui_MainWindow.h"
#include "WindowHelper.h"

Ui::MainWindow ui;

bool IsTextUTF8(int64_t a1, int a2) {
	int v3 = 1;
	int v4 = 0;
	int64_t v5 = 0;
	uint8_t v6;
	if (a2 <= 0) return false;
	do {
		v6 = *(uint8_t*)(v5 + a1);
		if ((v6 & 0xC0) != 0) v3 = 0;
		if (v4) {
			if ((v6 & 0xC0) != 0x80) return false;
			--v4;
		} else if (v6 >= 0x80) {
			do {
				v6 *= 2;
				++v4;
			} while ((v6 & 0x80) != 0);
			if (!--v4) {
				return false;
			}
		}
		++v5;
	} while (v5 < a2);
	return !v4 && !v3;
}

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	QMainWindow mainWindow;

	WindowHelper::launch(&mainWindow, [&](QMainWindow* w) {
		ui.setupUi(w);

		// accuracy :3
		QTextDocument* doc = ui.plainTextEdit->document();
		doc->setDocumentMargin(2); doc->setIndentWidth(4);

		ui.plainTextEdit->setPlainText("Current style:" + QApplication::style()->objectName());

		QSizeGrip* grip = new QSizeGrip(ui.plainTextEdit);
		ui.plainTextEdit->setCornerWidget(grip);
	});

	return app.exec();
}
