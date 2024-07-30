#include "TextEditor.h"

TextEditor::TextEditor(QWidget* parent) : QPlainTextEdit(parent)
{
	applyCustomStyle();
}

TextEditor::~TextEditor()
{
    //Not necessary at all.
}

void TextEditor::newFile()
{
	this->clear();
}

void TextEditor::openFile()
{
	QString content;
	if (m_fileManager.openFile(content))
	{
		this->setPlainText(content);
	}
}

void TextEditor::saveFile()
{
	m_fileManager.saveFile(this->toPlainText());
}

void TextEditor::exitFile()
{
    QMessageBox messageBox(this);
    messageBox.setText("Are you sure you want to exit?");
    messageBox.setWindowTitle("Exit");
    messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    messageBox.setDefaultButton(QMessageBox::No);

    messageBox.setStyleSheet(R"(
        QMessageBox {
            background-color: #FADDE1;
        }
        QPushButton {
            background-color: white;
            border: 2px solid white;
            padding: 5px;
            min-width: 60px;
        }
        QPushButton:hover {
            background-color: #FFB6C1;
        }
    )");

    QFont pixelFont = this->font();
    messageBox.setFont(pixelFont);

    int reply = messageBox.exec();

    if (reply == QMessageBox::Yes)
    {
        QApplication::quit();
    }
}


void TextEditor::applyCustomStyle()
{
	QString textEditStyle = R"(
		QPlainTextEdit{
			background-color: #FADDE1;
			border: 2px solid black;
			border-radius: 4px;
			padding: 0px;
			selection-background-color: #FFB6C1;
			selection-color: #000000; 
		}
	)";
	setStyleSheet(textEditStyle);
    this->setCursorWidth(3);
}

void TextEditor::contextMenuEvent(QContextMenuEvent* event)
{
    QMenu* contextMenu = createStandardContextMenu();

    QFont pixelFont = this->font();
    contextMenu->setFont(pixelFont);

    for (QAction* action : contextMenu->actions())
    {
        action->setFont(pixelFont);
    }

    contextMenu->setStyleSheet(R"(
        QMenuBar{
            padding: 0;
            margin: 0;
            background-color: transparent;
        }
        QMenuBar::item:selected{
            background-color: white;
        }
        QMenu{
            border: 2px solid black;
            padding: 2px;
            background-color: #fbf1d0;
        }
        QMenu::item:selected{
            background: transparent;
            background-color: #fbe6ac;
            background-image: url(:/resources/assets/heart.png);
            background-repeat: no-repeat;
            background-position: center;
        }
        QMenu::separator{
            height: 2px;
            background: none;
            margin: 4px 0;
            border-top: 2px dashed gray
        }
    )");

    contextMenu->exec(event->globalPos());
}