#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_b1_clicked();
  void on_b2_clicked();
  void on_b3_clicked();
  void on_b4_clicked();
  void on_b5_clicked();
  void on_b6_clicked();
  void on_b7_clicked();
  void on_b8_clicked();
  void on_b9_clicked();
  void on_b0_clicked();

  void on_b_plus_clicked();
  void on_b_minus_clicked();
  void on_b_mult_clicked();
  void on_b_divide_clicked();

  void on_b_pow_clicked();
  void on_b_tilde_clicked();

  void on_b_sqrt_clicked();
  void on_b_log_clicked();
  void on_b_ln_clicked();

  void on_b_sin_clicked();
  void on_b_cos_clicked();
  void on_b_tan_clicked();
  void on_b_asin_clicked();
  void on_b_acos_clicked();
  void on_b_atan_clicked();

  void on_b_skobk_l_clicked();
  void on_b_skobk_r_clicked();

  void on_b_x_clicked();

  void on_b_enter_clicked();

  void on_toolBox_currentChanged(int index);

  void on_b_create_graph_clicked();

  void on_b_credit_calculate_clicked();

 private:
  Ui::MainWindow *ui;
  double x_begin, x_end, step, X;
  int N;

  QVector<double> x, y;
};
#endif  // MAINWINDOW_H
