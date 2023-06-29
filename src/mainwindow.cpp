#include "mainwindow.h"

#include "ui_mainwindow.h"

extern "C" {
#include "s21_calc.h"
}

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_b1_clicked() { ui->edit_expression->insert("1"); }

void MainWindow::on_b2_clicked() { ui->edit_expression->insert("2"); }

void MainWindow::on_b3_clicked() { ui->edit_expression->insert("3"); }

void MainWindow::on_b4_clicked() { ui->edit_expression->insert("4"); }

void MainWindow::on_b5_clicked() { ui->edit_expression->insert("5"); }

void MainWindow::on_b6_clicked() { ui->edit_expression->insert("6"); }

void MainWindow::on_b7_clicked() { ui->edit_expression->insert("7"); }

void MainWindow::on_b8_clicked() { ui->edit_expression->insert("8"); }

void MainWindow::on_b9_clicked() { ui->edit_expression->insert("9"); }

void MainWindow::on_b0_clicked() { ui->edit_expression->insert("0"); }

void MainWindow::on_b_plus_clicked() { ui->edit_expression->insert("+"); }

void MainWindow::on_b_minus_clicked() { ui->edit_expression->insert("-"); }

void MainWindow::on_b_mult_clicked() { ui->edit_expression->insert("*"); }

void MainWindow::on_b_divide_clicked() { ui->edit_expression->insert("/"); }

void MainWindow::on_b_pow_clicked() { ui->edit_expression->insert("^"); }

void MainWindow::on_b_tilde_clicked() { ui->edit_expression->insert("~"); }

void MainWindow::on_b_sin_clicked() { ui->edit_expression->insert("sin("); }

void MainWindow::on_b_asin_clicked() { ui->edit_expression->insert("asin("); }

void MainWindow::on_b_cos_clicked() { ui->edit_expression->insert("cos("); }

void MainWindow::on_b_acos_clicked() { ui->edit_expression->insert("acos("); }

void MainWindow::on_b_tan_clicked() { ui->edit_expression->insert("tan("); }

void MainWindow::on_b_atan_clicked() { ui->edit_expression->insert("atan("); }

void MainWindow::on_b_log_clicked() { ui->edit_expression->insert("log("); }

void MainWindow::on_b_ln_clicked() { ui->edit_expression->insert("ln("); }

void MainWindow::on_b_sqrt_clicked() { ui->edit_expression->insert("sqrt("); }

void MainWindow::on_b_skobk_l_clicked() { ui->edit_expression->insert("("); }

void MainWindow::on_b_skobk_r_clicked() { ui->edit_expression->insert(")"); }

void MainWindow::on_b_x_clicked() { ui->edit_expression->insert("x"); }

void MainWindow::on_b_enter_clicked() {
  double output = 0.0;
  char* string = (char*)ui->edit_expression->text().toUtf8().constData();
  double x = ui->x_value->value();
  int error = main_function(string, &output, x);
  ui->edit_expression->clear();
  if (error == 1)
    ui->edit_expression->setText("Invalid bracket number");
  else if (error == 2)
    ui->edit_expression->setText("Mismatched brackets");
  else if (error == 3)
    ui->edit_expression->setText("Too many dots in number");
  else if (error == 4)
    ui->edit_expression->setText("Stack error");
  else
    ui->edit_expression->setText(QString::number(output));
}

void MainWindow::on_toolBox_currentChanged(int index) {
  on_b_create_graph_clicked();
}

void MainWindow::on_b_create_graph_clicked() {
  x.clear();
  y.clear();

  double output = 0.0;
  char* string = (char*)ui->edit_expression->text().toUtf8().constData();
  double x_begin = ui->x_start_value->value();
  double x_end = ui->x_end_value->value();
  if (x_begin < 0 && x_end == 0) x_end = -x_begin;
  //  if (x_end > 10000 && x_begin < -10000) ui->step_value->setValue(10);

  step = ui->step_value->value();

  ui->graph->xAxis->setRange(ui->x_range_start->value(),
                             ui->x_range_end->value());
  ui->graph->yAxis->setRange(ui->y_range_start->value(),
                             ui->y_range_end->value());

  X = x_begin;

  for (X = x_begin; X < x_end; X += step) {
    x.push_back(X);
    main_function(string, &output, X);
    y.push_back(output);
  }

  ui->graph->addGraph();
  ui->graph->graph(0)->setData(x, y);
  ui->graph->replot();
  ui->graph->setInteraction(QCP::iRangeDrag, true);
  ui->graph->setInteraction(QCP::iRangeZoom, true);
}

void MainWindow::on_b_credit_calculate_clicked() {
  ui->hidden_1->setEnabled(1);
  ui->hidden_2->setEnabled(1);
  if (ui->cb_is_differentiated->isChecked())
    ui->hidden_2->setText("Monthly payment (average)");
  else
    ui->hidden_2->setText("Monthly payment");
  ui->hidden_3->setDisabled(0);
  ui->monthly_payment->setEnabled(1);
  ui->overpayment->setEnabled(1);
  ui->total_payment->setDisabled(0);

  double total = get_total(
      ui->credit_amount->value(), ui->months_to_pay->value(),
      ui->interest_rate->value(), ui->cb_is_differentiated->isChecked());
  ui->total_payment->setValue(total);
  ui->overpayment->setValue(total - ui->credit_amount->value());
  ui->monthly_payment->setValue(total / ui->months_to_pay->value());
}
