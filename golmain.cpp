#include <QtWidgets>
#include "./golfield.h"
#include "./golmain.h"

GolMain::GolMain(QWidget* parent){
    field = new GolField;
    startButton = new QPushButton(tr("&Start"));
    pauseButton = new QPushButton(tr("&Pause"));
    resetButton = new QPushButton(tr("&Reset"));

    iterationLabel = new QLabel(tr("Iteration: 0"));
    liveCellsLabel = new QLabel(tr("Ratio of Alive Cells: %1 %").arg(field->ratioLiveCells(), 4, 'f', 1));

    connect(startButton, &QPushButton::clicked, field, &GolField::start);
    connect(pauseButton, &QPushButton::clicked, field, &GolField::pause);
    connect(resetButton, &QPushButton::clicked, field, &GolField::reset);

    connect(field, &GolField::changeIterationsLabel, iterationLabel, &QLabel::setText);
    connect(field, &GolField::changeLiveCellsLabel, liveCellsLabel, &QLabel::setText);


    QHBoxLayout* controlLayout = new QHBoxLayout;
    QVBoxLayout* infoLayout = new QVBoxLayout;
    QHBoxLayout* topLayout = new QHBoxLayout;
    QVBoxLayout* mainLayout = new QVBoxLayout;

    controlLayout->addWidget(startButton);
    controlLayout->addWidget(pauseButton);
    controlLayout->addWidget(resetButton);

    infoLayout->addWidget(iterationLabel);
    infoLayout->addWidget(liveCellsLabel);

    QGroupBox* controlBox = new QGroupBox("Control");
    controlBox->setLayout(controlLayout);

    QGroupBox* infoBox = new QGroupBox("Information");
    infoBox->setLayout(infoLayout);

    topLayout->addWidget(controlBox);
    topLayout->addWidget(infoBox);
    topLayout->addStretch();

    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(field);

    setWindowTitle(tr("Conway\'s Game of Life"));
    setLayout(mainLayout);
}

