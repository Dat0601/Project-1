#ifndef INTERPOLATION_VISUALIZATION_H
#define INTERPOLATION_VISUALIZATION_H

#include "visualization.h"
#include <QWidget>
class Interpolation_Visualization: public Visualization
{
    Q_OBJECT
protected:
    int leftIndex;
    int rightIndex;
    int posIndex;
    void setIndex(int leftIndex, int rightIndex, int posIndex);
    void paintEvent(QPaintEvent *event) override;
public:
    explicit Interpolation_Visualization(QWidget *parent = nullptr);
    void startVisualization() override;
    void visualize(int target) override;
};

#endif // INTERPOLATION_VISUALIZATION_H
