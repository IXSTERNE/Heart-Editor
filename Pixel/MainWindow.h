#pragma once

#include "MenuBar.h"
#include "FileManager.h"
#include "TextEditor.h"
#include "StatusBar.h"
#include <QMainWindow>
#include <QPlainTextEdit>



class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget* parent = nullptr);

private:
	void setupUi();
	void createTriggers();
	void clearTextFile();
	void openTextFile();
	void saveTextFile();
	void exit();

	FileManager m_fileManager;
	MenuBar* menuBar;
	TextEditor* editor;
	StatusBar* status;
};



