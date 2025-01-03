#ifndef BINARY_VISUALIZATION_H
#define BINARY_VISUALIZATION_H

#include "visualization.h"
#include <bits/stdc++.h>
#include <QWidget>
class Binary_Visualization: public Visualization
{
    Q_OBJECT
protected:
    int leftIndex;
    int rightIndex;
    int midIndex;
    void setIndex(int leftIndex, int rightIndex, int midIndex);
    void paintEvent(QPaintEvent *event) override;
public:
    explicit Binary_Visualization(QWidget *parent = nullptr);
    void startVisualization() override;
    void visualize(int target) override;
};

#endif // BINARY_VISUALIZATION_H
