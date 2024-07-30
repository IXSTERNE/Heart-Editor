#pragma once

#include <QMenuBar>
#include <QMainWindow>
#include <QAction>
#include "TextEditor.h"


class MenuBar : public QMenuBar
{
	Q_OBJECT

public:
	explicit MenuBar(QWidget* parent = nullptr);
	~MenuBar();

	QAction* m_newAction;
	QAction* m_openAction;
	QAction* m_saveAction;
	QAction* m_exitAction;
	QAction* m_copyAction;
	QAction* m_cutAction;
	QAction* m_pasteAction;

private:
	void createActions();
	void createMenu();
	void applyPixelFont();
	void applyCustomStyle();

	QMenu* m_fileMenu;
	QMenu* m_editMenu;

	TextEditor* textEdit;
};
