#pragma once

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QPixmap>
#include <QFontDatabase>

class PixelButton : public QWidget
{
	Q_OBJECT

public:
	explicit PixelButton(const QString& text, int m_scaleFactor = 1, QWidget* parent = nullptr);

signals:
	void clicked();

protected:
	void paintEvent(QPaintEvent* event) override;
	void mousePressEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;

private:
	QString m_text;
	QPixmap m_normalPixmap;
	QPixmap m_pressedPixmap;
	bool m_isPressed;
	int m_scaleFactor;
	QFont m_pixelFont;
};