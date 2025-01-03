#ifndef TERNARY_VISUALIZATION_H
#define TERNARY_VISUALIZATION_H

#include "visualization.h"
#include <QWidget>
class Ternary_Visualization: public Visualization
{
    Q_OBJECT
protected:
    int leftIndex;
    int rightIndex;
    int mid1Index;
    int mid2Index;
    void setIndex(int leftIndex, int rightIndex, int mid1Index, int mid2Index);
    void paintEvent(QPaintEvent *event) override;
public:
    explicit Ternary_Visualization(QWidget *parent = nullptr);
    void startVisualization() override;
    void visualize(int target) override;
};

#endif // TERNARY_VISUALIZATION_H
