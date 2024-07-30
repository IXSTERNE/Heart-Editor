#include "MainWindow.h"
#include <QVBoxLayout>
#include <QMenuBar>
#include <QMessageBox>
#include <QFontDatabase>
#include <QApplication>

#include <QDebug>


MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
    menuBar = new MenuBar();
    editor = new TextEditor();
    status = new StatusBar();
    setupUi();
    createTriggers();
    resize(600, 600);

    status->connectEditor(editor);
}

void MainWindow::setupUi()
{
    QWidget* centralWidget = new QWidget(this);
    QVBoxLayout* editorLayout = new QVBoxLayout(centralWidget);    

    editorLayout->addWidget(editor);
    editorLayout->setContentsMargins(8, 0, 8, 8);

    setMenuBar(menuBar);
    setCentralWidget(centralWidget);
    setStatusBar(status);
}

void MainWindow::createTriggers()
{
    QObject::connect(menuBar->m_newAction, &QAction::triggered, this, &MainWindow::clearTextFile);
    QObject::connect(menuBar->m_openAction, &QAction::triggered, this, &MainWindow::openTextFile);
    QObject::connect(menuBar->m_saveAction, &QAction::triggered, this, &MainWindow::saveTextFile);
    QObject::connect(menuBar->m_exitAction, &QAction::triggered, this, &MainWindow::exit);
    QObject::connect(menuBar->m_cutAction, &QAction::triggered, editor, &TextEditor::cut);
    QObject::connect(menuBar->m_copyAction, &QAction::triggered, editor, &TextEditor::copy);
    QObject::connect(menuBar->m_pasteAction, &QAction::triggered, editor, &TextEditor::paste);
}

void MainWindow::clearTextFile()
{
    editor->newFile();
}

void MainWindow::openTextFile()
{
    editor->openFile();
}

void MainWindow::saveTextFile()
{
    editor->saveFile();
}

void MainWindow::exit()
{
    editor->exitFile();
}




