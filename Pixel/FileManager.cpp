#include "FileManager.h"
#include <QFileDialog>
#include <QTextStream>

bool FileManager::openFile(QString& content)
{
    QString fileName = QFileDialog::getOpenFileName(nullptr);
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            content = in.readAll();
            return true;
        }
    }
    return false;
}

bool FileManager::saveFile(const QString& content)
{
    QString fileName = QFileDialog::getSaveFileName(nullptr);
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << content;
            return true;
        }
    }
    return false;
}