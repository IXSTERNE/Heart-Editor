#pragma once

#include <QMainWindow.h>
#include "FileManager.h"
#include "CustomTextEdit.h"
#include <QTextEdit>


class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget* parent = nullptr);

private slots:
	void newFile();
	void openFile();
	void saveFile();
	void exit();
private:
	void createMenus();
	void createActions();
	void setupUi();
	void applyPixelFont();
	void applyCustomStyle();

	CustomTextEdit* m_textEdit;
	QMenu* m_fileMenu;
	QMenu* m_editMenu;
	QAction* m_newAction;
	QAction* m_openAction;
	QAction* m_saveAction;
	QAction* m_exitAction;
	QAction* m_cutAction;
	QAction* m_copyAction;
	QAction* m_pasteAction;

	FileManager m_fileManager;
};



