#ifndef FIBONACCI_VISUALIZATION_H
#define FIBONACCI_VISUALIZATION_H

#include "visualization.h"
#include <QWidget>
class Fibonacci_Visualization: public Visualization
{
    Q_OBJECT
protected:
    int nowIndex;
    int fib0;
    int fib1;
    int fib2;
    void setIndex(int nowIndex);
    void paintEvent(QPaintEvent *event) override;
public:
    explicit Fibonacci_Visualization(QWidget *parent = nullptr);
    void startVisualization() override;
    void visualize(int target) override;
};

#endif // FIBONACCI_VISUALIZATION_H
