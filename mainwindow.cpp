#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "functions.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
 QString infixExpression;
    infixExpression = ui->string1->text();
 QString result;
 if (balancedParentheses(infixExpression.toStdString())) {
     string postfixExpression = infixToPostfix(infixExpression.toStdString());
     result= "Yes";
     ui->result->setText(result);
     QString post = QString::fromStdString(postfixExpression);
     ui->postfix->setText(post);
 } else {
     result="No";
     ui->result->setText(result);
     ui->postfix->setText("unbalanced");
}
}


void MainWindow::on_checkbutton2_clicked()
{
    QString stringy;
    stringy= ui->input2->text();
    string count = countCharacters(stringy.toStdString());
    QString countfinal = QString::fromStdString(count);
    ui->answer2->setText(countfinal);


    string tobereversed = reverseString(stringy.toStdString());
    ui->reversebox->setText(QString::fromStdString(tobereversed));

}

