#pragma once

#include <QtWidgets/QWidget>
#include <QMessageBox>
#include <QDebug>
#include <cmath>
#include <iostream>
#include "ui_QTCalculator.h"
using namespace std;
#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif // 

class QTCalculator : public QWidget
{
    Q_OBJECT

public:
    QTCalculator(QWidget *parent = Q_NULLPTR);
    void display();
private slots:
    void addition();//加法
    void subtraction();//减法
    void multiplication();//乘法
    void division();//除法
    void equal();//等于
    void Log();
    void Ln();
    void Sin();
    void Cos();
    void Tan();
    void power();
    void celsius();
    void fahrenheit();
    void Mod();
    void multiply();
    void accumulate();
private:
    Ui::QTCalculatorClass ui;
    double number1,number2,result = 0 , flag = 0;
};
