#include "editor.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    TextEditor editor;
    editor.setWindowTitle("Simple Text Editor");
    editor.resize(600, 400);
    editor.show();

    return app.exec();
}
