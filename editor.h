#ifndef EDITOR_H
#define EDITOR_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QMessageBox>

class TextEditor : public QWidget
{
    Q_OBJECT

public:
    TextEditor(QWidget *parent = nullptr);
    ~TextEditor();

private slots:
    void openFile();
    void saveFile();
    void closeEditor();

private:
    QTextEdit *textEdit;
    QPushButton *openButton;
    QPushButton *saveButton;
    QPushButton *closeButton;
    QPushButton *undoButton;
    QPushButton *redoButton;
};

#endif // EDITOR_H
