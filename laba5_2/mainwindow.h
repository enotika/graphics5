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
    QVector <QPointF> poly;
    QVector <QPointF> otsecPoly;
    QVector <QPointF> cuttedPoly;
    double xmin = 0, ymin = 0, xmax = 15, ymax = 15;
    int Xmax, Xmin, Ymax, Ymin;
    double cx, cy;
    QPoint pmin;
    QPoint pmax;
    bool haveRect = false;
private slots:
    void on_actionadd_triggered();
    void on_actionadd_Rectangle_triggered();
    void on_actioncut_off_triggered();
    void suthHodgClip(QVector < QPointF >& poly_points, QVector < QPointF >& clipper_points);
    void clip(QVector < QPointF >& poly_points, double x1, double y1, double x2, double y2);
    double y_intersect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
    double x_intersect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);

    void on_actionadd_polygon_triggered();

    void on_actionpolygon_cut_off_triggered();

    void on_actionadd_cutting_polynom_triggered();

    void on_actionclear_polygons_triggered();

private:
    Ui::MainWindow *ui;
    void paintEvent(QPaintEvent*);

    void otsech(double x1, double y1, double x2, double y2);

};
#endif // MAINWINDOW_H
