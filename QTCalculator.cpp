#include "QTCalculator.h"

QTCalculator::QTCalculator(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
	display();
}
void QTCalculator::addition() {
    number1 = ui.num1->text().toDouble();
    number2 = ui.num2->text().toDouble();
	number1 = number1 * flag + ui.num1->text().toDouble();
	number2 = number2 * flag + ui.num2->text().toDouble();
    result = number1 + number2;
 }

void QTCalculator::subtraction() {
	number1 = ui.num1->text().toDouble();
	number2 = ui.num2->text().toDouble();
	result = number1 - number2;
}

void QTCalculator::multiplication() {
	number1 = ui.num1->text().toDouble();
	number2 = ui.num2->text().toDouble();
	result = number1 * number2;
}

void QTCalculator::division() {
	number1 = ui.num1->text().toDouble();
	number2 = ui.num2->text().toDouble();
	if (number2==0)
	{
		QMessageBox::information(this, "错误", "除数不能为0","确认");
		return;
	}
	result = number1 / number2;
}

void QTCalculator::Sin() {
	number1 = ui.num1->text().toDouble();
	result = sin(number1);
}

void QTCalculator::Cos() {
	number1 = ui.num1->text().toDouble();
	result = cos(number1);
}

void QTCalculator::Tan() {
	number1 = ui.num1->text().toDouble();
	result = tan(number1);
}

void QTCalculator::equal() {
	ui.result->setText(QString::fromStdString(to_string(result)));
}

void QTCalculator::power() {
	number1 = ui.num1->text().toDouble();
	number2 = ui.num2->text().toDouble();
	result = pow(number1,number2);
}

void QTCalculator::celsius() {
	number1 = ui.num1->text().toDouble();
	result = number1 * 1.8 + 32;
}

void QTCalculator::fahrenheit() {
	number1 = ui.num1->text().toDouble();
	result = (number1 - 32) / 1.8;
}

void QTCalculator::accumulate() {
	number1 = ui.num1->text().toInt();
	number2 = ui.num2->text().toInt();
	result = 0;
	if (number1 > number2) swap(number1, number2);
	for (int i = number1 ; i <= number2;i++){
		result += i;
	}
}

void QTCalculator::multiply() {
	number1 = ui.num1->text().toInt();
	number2 = ui.num2->text().toInt();
	result = 1;
	if (number1 > number2) swap(number1, number2);
	for (int i = number1; i <= number2; i++) {
		result *= i;
	}
}

void QTCalculator::Log(){
	number1 = ui.num1->text().toDouble();
	number2 = ui.num2->text().toDouble();
	result = log(number1)/log(number2);
}

void QTCalculator::Ln() {
	number1 = ui.num1->text().toDouble();
	result = log(number1)/log(exp(1));
}

void QTCalculator::Mod() {
	number1 = ui.num1->text().toInt();
	number2 = ui.num2->text().toInt();
	result =(int)number1%(int)number2;
}

void QTCalculator::display() {
	connect(ui.add, SIGNAL(clicked(bool)), this, SLOT(addition()));
	connect(ui.div, SIGNAL(clicked(bool)), this, SLOT(division()));
	connect(ui.sub, SIGNAL(clicked(bool)), this, SLOT(subtraction()));
	connect(ui.mul, SIGNAL(clicked(bool)), this, SLOT(multiplication()));
	connect(ui.equal, SIGNAL(clicked(bool)), this, SLOT(equal()));
	connect(ui.log, SIGNAL(clicked(bool)), this, SLOT(Log()));
	connect(ui.ln, SIGNAL(clicked(bool)), this, SLOT(Ln()));
	connect(ui.sin, SIGNAL(clicked(bool)), this, SLOT(Sin()));
	connect(ui.tan, SIGNAL(clicked(bool)), this, SLOT(Tan()));
	connect(ui.cos, SIGNAL(clicked(bool)), this, SLOT(Cos()));
	connect(ui.power, SIGNAL(clicked(bool)), this, SLOT(power()));
	connect(ui.celsius, SIGNAL(clicked(bool)), this, SLOT(celsius()));
	connect(ui.fahrenheit, SIGNAL(clicked()), this, SLOT(fahrenheit()));
	connect(ui.accumulate, SIGNAL(clicked()), this, SLOT(accumulate()));
	connect(ui.multiply, SIGNAL(clicked()), this, SLOT(multiply()));
	connect(ui.mod, SIGNAL(clicked(bool)), this, SLOT(Mod()));
	//QTCalculatorClass
}