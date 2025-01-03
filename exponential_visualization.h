#ifndef EXPONENTIAL_VISUALIZATION_H
#define EXPONENTIAL_VISUALIZATION_H

#include "visualization.h"
#include <QWidget>

class Exponential_Visualization : public Visualization
{
    Q_OBJECT
protected:
    int leftIndex;
    int rightIndex;
    int midIndex;
    int posIndex;
    void setIndex(int leftIndex, int rightIndex, int midIndex, int posIndex);
    void paintEvent(QPaintEvent *event) override;
public:
    explicit Exponential_Visualization(QWidget *parent = nullptr);
    void startVisualization() override;
    void visualize(int target) override;
};

#endif // EXPONENTIAL_VISUALIZATION_H
