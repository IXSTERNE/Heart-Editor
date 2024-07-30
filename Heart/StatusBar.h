#pragma once

#include "TextEditor.h"
#include <QStatusBar>
#include <QRegularExpression>
#include <QLabel>


class StatusBar : public QStatusBar
{
	Q_OBJECT

public:
	StatusBar(QWidget* parent = nullptr);
	~StatusBar();
	void connectEditor(TextEditor* editor);

private slots:
	void updateStatusBar();

private:
	QLabel* statusLabel;
	TextEditor* editor;
};