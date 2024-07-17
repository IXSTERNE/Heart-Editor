#include "CustomTextEdit.h"

CustomTextEdit::CustomTextEdit(QWidget* parent) : QTextEdit(parent)
{
}

void CustomTextEdit::contextMenuEvent(QContextMenuEvent* event)
{
    QMenu* menu = createStandardContextMenu();

    QFont pixelFont = this->font();
    menu->setFont(pixelFont);

    for (QAction* action : menu->actions()) {
        action->setFont(pixelFont);
    }

    menu->exec(event->globalPos());
    delete menu;
}