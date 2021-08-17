#include <QtWidgets>
#include "./golfield.h"
#include "./golmain.h"


GolMain::GolMain(QWidget* parent){
    field = new GolField;
    startButton = new QPushButton("&Start");
    pauseButton = new QPushButton("&Pause");
    resetButton = new QPushButton("&Reset");

    connect(startButton, &QPushButton::clicked, field, &GolField::start);
    connect(pauseButton, &QPushButton::clicked, field, &GolField::pause);
    connect(resetButton, &QPushButton::clicked, field, &GolField::reset);

    QHBoxLayout* controlLayout = new QHBoxLayout;
    QHBoxLayout* topLayout = new QHBoxLayout;
    QVBoxLayout* mainLayout = new QVBoxLayout;

    controlLayout->addWidget(startButton);
    controlLayout->addWidget(pauseButton);
    controlLayout->addWidget(resetButton);

    QGroupBox* controlBox = new QGroupBox("Control");
    controlBox->setLayout(controlLayout);

    topLayout->addWidget(controlBox);
    topLayout->addStretch();

    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(field);

    setWindowTitle(tr("Conway\'s Game of Life"));
    setLayout(mainLayout);
}