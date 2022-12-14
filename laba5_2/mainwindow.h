#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPoint>
#include <QVBoxLayout>
#include <QLabel>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    double one = 20.0;
    QVector < std::pair<QPoint, QPoint>> lines;
    QVector<std::pair<std::pair<double, double>, std::pair<double, double>>> lines4;
    QVector < std::pair<QPoint, QPoint>> added;
    QVector <QPoint> poly;
    QVector <QPoint> otsecPoly;
    QVector <QPoint> cuttedPoly;
    double xmin = 0, ymin = 0, xmax = 15, ymax = 15;
    int Xmax, Xmin, Ymax, Ymin;
    double cx, cy;
    QPoint pmin;
    QPoint pmax;
    bool haveRect = false;
    QVBoxLayout layout;
    QLabel lbl;
    QWidget* wdg;
private slots:
    void on_actionadd_triggered();
    void cutPolygon();
    int getCode(QPoint point);
    void on_actionadd_Rectangle_triggered();
    QPoint intersectionPoint(QPoint P1, QPoint P2, int border);
    void on_actioncut_off_triggered();
    void suthHodgClip(QVector < QPoint >& poly_points, QVector < QPoint >& clipper_points);
    void clip(QVector < QPoint >& poly_points, int x1, int y1, int x2, int y2);
    int y_intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
    int x_intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);

    void on_actionadd_polygon_triggered();

    void on_actionpolygon_cut_off_triggered();

    void on_actionadd_cutting_polynom_triggered();

private:
    Ui::MainWindow *ui;
    void paintEvent(QPaintEvent*);

    void otsech(double x1, double y1, double x2, double y2);

};
#endif // MAINWINDOW_H
