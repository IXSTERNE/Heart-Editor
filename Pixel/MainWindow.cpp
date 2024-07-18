#include "MainWindow.h"
#include <QVBoxLayout>
#include <QMenuBar>
#include <QMessageBox>
#include <QFontDatabase>
#include <QApplication>
#include <QLabel>


MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
    setupUi();
    createActions();
    createMenus();
    applyPixelFont();
    applyCustomStyle();
}

void MainWindow::setupUi()
{
    QWidget* centralWidget = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(centralWidget);
    layout->setSpacing(0);
    layout->setContentsMargins(8, 0, 8, 8);

    //m_saveButton = new PixelButton("Click me", 8);
    //layout->addWidget(m_saveButton);

    m_textEdit = new CustomTextEdit(this);

    layout->addWidget(m_textEdit);
    //setCentralWidget(m_textEdit);
    setCentralWidget(centralWidget);

    // Setting custom cursor
    //QPixmap cursorPixmap(":/resources/assets/custom_cursor.png");
    //QCursor customCursor(cursorPixmap);
    //m_textEdit->setCursor(customCursor);
}

void MainWindow::createActions()
{
    m_newAction = new QAction(tr("&New"), this);
    m_newAction->setShortcuts(QKeySequence::New);
    connect(m_newAction, &QAction::triggered, this, &MainWindow::newFile);

    m_openAction = new QAction(tr("&Open..."), this);
    m_openAction->setShortcuts(QKeySequence::Open);
    connect(m_openAction, &QAction::triggered, this, &MainWindow::openFile);

    m_saveAction = new QAction(tr("&Save"), this);
    m_saveAction->setShortcuts(QKeySequence::Save);
    connect(m_saveAction, &QAction::triggered, this, &MainWindow::saveFile);

    m_exitAction = new QAction(tr("E&xit"), this);
    m_exitAction->setShortcuts(QKeySequence::Quit);
    connect(m_exitAction, &QAction::triggered, this, &MainWindow::exit);

    m_cutAction = new QAction(tr("Cu&t"), this);
    m_cutAction->setShortcuts(QKeySequence::Cut);
    connect(m_cutAction, &QAction::triggered, m_textEdit, &QTextEdit::cut);

    m_copyAction = new QAction(tr("&Copy"), this);
    m_copyAction->setShortcuts(QKeySequence::Copy);
    connect(m_copyAction, &QAction::triggered, m_textEdit, &QTextEdit::copy);

    m_pasteAction = new QAction(tr("&Paste"), this);
    m_pasteAction->setShortcuts(QKeySequence::Paste);
    connect(m_pasteAction, &QAction::triggered, m_textEdit, &QTextEdit::paste);
}

void MainWindow::createMenus()
{
    m_fileMenu = menuBar()->addMenu(tr("&File"));
    m_fileMenu->addAction(m_newAction);
    m_fileMenu->addAction(m_openAction);
    m_fileMenu->addAction(m_saveAction);
    m_fileMenu->addSeparator();
    m_fileMenu->addAction(m_exitAction);

    m_editMenu = menuBar()->addMenu(tr("&Edit"));
    m_editMenu->addAction(m_cutAction);
    m_editMenu->addAction(m_copyAction);
    m_editMenu->addAction(m_pasteAction);
}

void MainWindow::applyPixelFont()
{
    int fontId = QFontDatabase::addApplicationFont(":/resources/fonts/minecraft.ttf");
    if (fontId != -1) 
    {
        QString family = QFontDatabase::applicationFontFamilies(fontId).at(0);
        QFont pixelFont(family, 12);
        pixelFont.setStyleStrategy(QFont::NoAntialias);

        QApplication::setFont(pixelFont);
        menuBar()->setFont(pixelFont);
        m_fileMenu->setFont(pixelFont);
        m_editMenu->setFont(pixelFont);
        m_textEdit->setFont(pixelFont);
    }
}

void MainWindow::applyCustomStyle()
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
            background-color: white;
        }
        QMenu::item:selected{
            background: transparent;
            background-color: #FADDE1;
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

    QString textEditStyle = R"(
        QTextEdit{
            background-color: #FADDE1;
            border: 2px solid black;
            border-radius: 4px;
            padding: 0px;
            selection-background-color: #FFB6C1; 
            selection-color: #000000;
        }
    )";

    setStyleSheet(styleSheet);
    m_textEdit->setCursorWidth(3);
    m_textEdit->setStyleSheet(textEditStyle);
}

void MainWindow::newFile()
{
    m_textEdit->clear();
}

void MainWindow::openFile()
{
    QString content;
    if (m_fileManager.openFile(content)) {
        m_textEdit->setText(content);
    }
}

void MainWindow::saveFile()
{
    m_fileManager.saveFile(m_textEdit->toPlainText());
}

void MainWindow::exit()
{
    QMessageBox messageBox(this);
    messageBox.setText("Are you sure you want to exit?");
    messageBox.setWindowTitle("Exit");
    messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    messageBox.setDefaultButton(QMessageBox::No);

    messageBox.setStyleSheet(R"(
        QMessageBox {
            background-color: #FADDE1;
            border: 2px solid black;
        }
        QPushButton {
            background-color: white;
            border: 2px solid black;
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