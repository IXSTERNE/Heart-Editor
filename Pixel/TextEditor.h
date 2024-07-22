#pragma once

#include <QPlainTextEdit>
#include "FileManager.h"
#include <QMessageBox>
#include <QApplication>
#include <QMenu>
#include <QContextMenuEvent>

class TextEditor : public QPlainTextEdit
{
	Q_OBJECT

public:
	explicit TextEditor(QWidget* parent = nullptr);
	~TextEditor();
	
public slots:
	
	void newFile();
	void openFile();
	void saveFile();
	void exitFile();

private:
	FileManager m_fileManager;
	void applyCustomStyle();

protected:
	void contextMenuEvent(QContextMenuEvent* even) override;
};