#include "PixelButton.h"

PixelButton::PixelButton(const QString &text, int scaleFactor , QWidget* parent)
    : QWidget(parent), m_text(text), m_isPressed(false), m_scaleFactor(scaleFactor)
{
    int fontId = QFontDatabase::addApplicationFont(":/resources/fonts/minecraft.ttf");
    if (fontId != -1)
    {
        QString family = QFontDatabase::applicationFontFamilies(fontId).at(0);
        m_pixelFont = QFont(family);
    }
    else
    {
        m_pixelFont = QFont("Courier");
    }


    m_normalPixmap.load("assets/button_pret.png");
    m_pressedPixmap.load("assets/button_red_pret.png");

    m_pixelFont.setPixelSize(8 * m_scaleFactor);

    setFixedSize(m_normalPixmap.size() * m_scaleFactor);
    setMouseTracking(true);
}

void PixelButton::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, false);

    QPixmap scaledPixmap = m_isPressed ? m_pressedPixmap : m_normalPixmap;
    scaledPixmap = scaledPixmap.scaled(size(), Qt::KeepAspectRatio, Qt::FastTransformation);

    painter.drawPixmap(rect(), scaledPixmap);

    painter.setFont(m_pixelFont);
    painter.setPen(Qt::white);
    painter.drawText(rect(), Qt::AlignCenter, m_text);
}

void PixelButton::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        m_isPressed = true;
        update();
    }
}

void PixelButton::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        m_isPressed = false;
        update();
        emit clicked();
    }
}