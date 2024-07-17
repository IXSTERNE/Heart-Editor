#pragma once

#include <QString>

class FileManager
{
public:
	bool openFile(QString& content);
	bool saveFile(const QString& content);
};