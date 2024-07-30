#include "StatusBar.h"

StatusBar::StatusBar(QWidget* parent) : QStatusBar(parent)
{
    editor = new TextEditor();
    statusLabel = new QLabel(this);
    addPermanentWidget(statusLabel);
}

StatusBar::~StatusBar()
{

}

void StatusBar::connectEditor(TextEditor* editor)
{
    this->editor = editor;
    connect(editor, &TextEditor::textChanged, this, &StatusBar::updateStatusBar);
    connect(editor, &TextEditor::cursorPositionChanged, this, &StatusBar::updateStatusBar);
    updateStatusBar();
}

void StatusBar::updateStatusBar()
{
    int wordCount = editor->toPlainText().split(QRegularExpression("(\\s|\\n|\\r)+"), Qt::SkipEmptyParts).count();
    QTextCursor cursor = editor->textCursor();
    int lineNumber = cursor.blockNumber() + 1;
    int columnNumber = cursor.columnNumber() + 1;

    statusLabel->setText(QString("Words: %1  Line: %2  Column: %3").arg(wordCount).arg(lineNumber).arg(columnNumber));
}
