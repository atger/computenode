#include <QApplication>
#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include "cursors.hpp"

Cursors::Cursors(QWidget * parent) : QWidget(parent) {
	
	auto *frame1 = new QFrame(this);
	frame1->setFrameStyle(QFrame::Box);
	frame1->setCursor(Qt::SizeAllCursor);

	auto *frame2 = new QFrame(this);
	frame2->setFrameStyle(QFrame::Box);
	frame2->setCursor(Qt::WaitCursor);

	auto *frame3 = new QFrame(this);
	frame3->setFrameStyle(QFrame::Box);
	frame3->setCursor(Qt::PointingHandCursor);

	auto *frame4 = new QFrame(this);
	frame4->setFrameStyle(QFrame::Box);

	auto *quitBtn = new QPushButton("Quit", frame4);

	auto *grid = new QGridLayout(this);
	grid->addWidget(frame1, 0, 0);
	grid->addWidget(frame2, 0, 1);
	grid->addWidget(frame3, 1, 0);
	grid->addWidget(frame4, 1, 1);

	auto *plusBtn = new QPushButton("+", frame4);
	auto *minusBtn = new QPushButton("-", frame4);
	label = new QLabel("0", frame4);

	auto *grid2 = new QGridLayout(frame4);
	grid2->addWidget(plusBtn, 0, 0);
	grid2->addWidget(minusBtn, 0, 1);
	grid2->addWidget(label, 1, 0);
	grid2->addWidget(quitBtn, 2,3);
	
	setLayout(grid);
	connect(quitBtn, &QPushButton::clicked, qApp, &QApplication::quit);
	connect(plusBtn, &QPushButton::clicked, this, &Cursors::onPlus);
	connect(minusBtn, &QPushButton::clicked, this, &Cursors::onMinus);
}

void Cursors::onPlus() {
	int val = label->text().toInt();
	val++;
	label->setText(QString::number(val));
}

void Cursors::onMinus() {
	int val = label->text().toInt();
	val--;
	label->setText(QString::number(val));
}
