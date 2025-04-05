#include "editor.h"
#include <QFile>
#include <QTextStream>

TextEditor::TextEditor(QWidget *parent)
    : QWidget(parent),
      textEdit(new QTextEdit(this)),
      openButton(new QPushButton("Open", this)),
      saveButton(new QPushButton("Save", this)),
      closeButton(new QPushButton("Close", this)),
      undoButton(new QPushButton("Undo", this)),
      redoButton(new QPushButton("Redo", this))
{
    // Set up layout
    QGridLayout *layout = new QGridLayout;

    // Add QTextEdit (span full width, more rows)
    layout->addWidget(textEdit, 0, 0, 1, 3);  // row 0, column 0, span 1 row and 3 columns

    // Add buttons in a row
    layout->addWidget(openButton, 1, 0);
    layout->addWidget(saveButton, 1, 1);
    layout->addWidget(closeButton, 1, 2);

    layout->addWidget(undoButton, 2, 0);
    layout->addWidget(redoButton, 2, 1);

    setLayout(layout);

    // Connect buttons to their respective slots
    connect(openButton, &QPushButton::clicked, this, &TextEditor::openFile);
    connect(saveButton, &QPushButton::clicked, this, &TextEditor::saveFile);
    connect(closeButton, &QPushButton::clicked, this, &TextEditor::closeEditor);
    connect(undoButton, &QPushButton::clicked, textEdit, &QTextEdit::undo);
    connect(redoButton, &QPushButton::clicked, textEdit, &QTextEdit::redo);
}


// TextEditor::TextEditor(QWidget *parent)
//     : QWidget(parent),
//       textEdit(new QTextEdit(this)),
//       openButton(new QPushButton("Open", this)),
//       saveButton(new QPushButton("Save", this)),
//       closeButton(new QPushButton("Close", this)),
//       undoButton(new QPushButton("Undo", this)),
//       redoButton(new QPushButton("Redo", this))
// {
//     // Set up layout
//     QVBoxLayout *layout = new QVBoxLayout;
//     layout->addWidget(textEdit);
//     layout->addWidget(openButton);
//     layout->addWidget(saveButton);
//     layout->addWidget(closeButton);
//     layout->addWidget(undoButton);
//     layout->addWidget(redoButton);
//     setLayout(layout);

//     // Connect buttons to their respective slots
//     connect(openButton, &QPushButton::clicked, this, &TextEditor::openFile);
//     connect(saveButton, &QPushButton::clicked, this, &TextEditor::saveFile);
//     connect(closeButton, &QPushButton::clicked, this, &TextEditor::closeEditor);
//     connect(undoButton, &QPushButton::clicked, textEdit, &QTextEdit::undo);
//     connect(redoButton, &QPushButton::clicked, textEdit, &QTextEdit::redo);

// }

TextEditor::~TextEditor()
{
}

void TextEditor::openFile()
{
    // Open file dialog to select a file
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", "", "Text Files (*.txt);;All Files (*)");

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QMessageBox::warning(this, "Error", "Could not open the file.");
            return;
        }

        QTextStream in(&file);
        textEdit->setText(in.readAll());
        file.close();
    }
}

void TextEditor::saveFile()
{
    // Open file dialog to choose save location
    QString fileName = QFileDialog::getSaveFileName(this, "Save File", "", "Text Files (*.txt);;All Files (*)");

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::warning(this, "Error", "Could not save the file.");
            return;
        }

        QTextStream out(&file);
        out << textEdit->toPlainText();
        file.close();
    }
}

void TextEditor::closeEditor()
{
    close();
}
