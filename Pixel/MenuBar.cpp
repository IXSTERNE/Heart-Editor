#include "MenuBar.h"
#include "MainWindow.h"
#include "TextEditor.h"
#include <QMenuBar>
#include <QMessageBox>
#include <QFontDatabase>
#include <QApplication>



MenuBar::MenuBar(QWidget* parent) : QMenuBar(parent)
{    
    createActions();
    createMenu();
    applyPixelFont();
    applyCustomStyle();
}

MenuBar::~MenuBar()
{
    //Destructor is not really needed here.
}


void MenuBar::createActions()
{
	m_newAction = new QAction(tr("&New"), this);
    m_newAction->setShortcuts(QKeySequence::New);
    
    m_openAction = new QAction(tr("&Open"), this);
    m_openAction->setShortcuts(QKeySequence::Open);

    m_saveAction = new QAction(tr("&Save"), this);
    m_saveAction->setShortcuts(QKeySequence::Save);

    m_exitAction = new QAction(tr("E&xit"), this);
    m_exitAction->setShortcuts(QKeySequence::Quit);

    m_cutAction = new QAction(tr("Cu&t"), this);
    m_cutAction->setShortcuts(QKeySequence::Cut);

	m_copyAction = new QAction(tr("&Copy"), this);
    m_copyAction->setShortcuts(QKeySequence::Copy);

    m_pasteAction = new QAction(tr("&Paste"), this);
    m_pasteAction->setShortcuts(QKeySequence::Paste);
}

void MenuBar::createMenu()
{
	m_fileMenu = addMenu(tr("&File"));
	m_fileMenu->addAction(m_newAction);
    m_fileMenu->addAction(m_openAction);
    m_fileMenu->addAction(m_saveAction);
    m_fileMenu->addSeparator();
    m_fileMenu->addAction(m_exitAction);

	m_editMenu = addMenu(tr("&Edit"));
    m_editMenu->addAction(m_cutAction);
	m_editMenu->addAction(m_copyAction);
    m_editMenu->addAction(m_pasteAction);
}

void MenuBar::applyPixelFont()
{
    int fontId = QFontDatabase::addApplicationFont(":/resources/fonts/minecraft.ttf");
    if (fontId != -1)
    {
        QString family = QFontDatabase::applicationFontFamilies(fontId).at(0);
        QFont pixelFont(family, 12);
        pixelFont.setStyleStrategy(QFont::NoAntialias);

        QApplication::setFont(pixelFont);
        MenuBar::setFont(pixelFont);
        m_fileMenu->setFont(pixelFont);
        m_editMenu->setFont(pixelFont);
    }
}

void MenuBar::applyCustomStyle()
{
    QString styleSheet = R"(
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
    )";
    setStyleSheet(styleSheet);
}


