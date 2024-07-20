#include <QTextEdit>
#include <QMenu>
#include <QContextMenuEvent>

class CustomTextEdit : public QTextEdit
{
    Q_OBJECT

public:
    explicit CustomTextEdit(QWidget* parent = nullptr);

protected:
    void contextMenuEvent(QContextMenuEvent* event) override;
};