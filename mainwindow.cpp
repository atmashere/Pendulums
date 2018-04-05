#include "mainwindow.h"
//#include "mainwindow.ui"

#include "ui_mainwindow.h"

#include <tchar.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "array.h"

#define max(a, b) ( ( (a) > (b) ) ? (a) : (b) )
#define min(a, b) ( ( (a) < (b) ) ? (a) : (b) )


#include "integrator.h"
#include "custom.h"

void showResult(TModel* model);


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//---------------------------------------------------------------------------

void MainWindow::on_pushButton_clicked()
{
        TModel* Model = new TIdealMathPendulum();
        MainWindow::showResult(Model);
        delete Model;
}

//---------------------------------------------------------------------------
void MainWindow::on_pushButton_2_clicked()
{
    TModel* Model = new TRealMathPendulum();
    MainWindow::showResult(Model);
    delete Model;
}
//---------------------------------------------------------------------------

void MainWindow::on_pushButton_3_clicked()
{
    TModel* Model = new TIdealPhysicPendulum();
    MainWindow::showResult(Model);
    delete Model;
}

//---------------------------------------------------------------------------

void MainWindow::on_pushButton_4_clicked()
{
    TModel* Model = new TViscousPhysicPendulum();
    MainWindow::showResult(Model);
    delete Model;
}

//---------------------------------------------------------------------------

void MainWindow::on_pushButton_5_clicked()
{
    TModel* Model = new TSlydingPhysicPendulum();
    MainWindow::showResult(Model);
    delete Model;
}

//---------------------------------------------------------------------------

void MainWindow::showResult(TModel* model){

    TIntegrator* Integrator = new TDormandPrinceIntegrator();
        Integrator->setPrecision(1e-8);
        Integrator->Run( model );

    TMatrix Result = model->getResult();

    QVector<double> t(Result.rowCount()), x(Result.rowCount());//, v(Result.rowCount());

    for (int i=0; i<Result.rowCount(); i++)
    {
        for (int j=0; j<Result.colCount(); j++)
        {
            if (j == 0) { t[i] = Result(i,j);   }
            if (j == 1) { x[i] = Result(i,j); }
            //if ((j == 2) and (i != 0)) { v[i] = Result(i,j); }
        }
    }

    ui->widget->clearGraphs();//Если нужно, но очищаем все графики
    //Добавляем один график в widget
    ui->widget->addGraph();
    //Говорим, что отрисовать нужно график по нашим двум массивам t и phi
    ui->widget->graph(0)->setData(t, x);
    ui->widget->graph(0)->setPen(QColor(50, 50, 50, 255));//задаем цвет точки
    ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);//убираем линии
    //формируем вид точек
    ui->widget->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));

    ui->widget->xAxis->setLabel("t");
    ui->widget->yAxis->setLabel("val");

    ui->widget->xAxis->setRange(0, 40);
    ui->widget->yAxis->setRange(-100, 100);

    ui->widget->replot();

        delete Integrator;
}
