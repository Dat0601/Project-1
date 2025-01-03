#ifndef JUMP_VISUALIZATION_H
#define JUMP_VISUALIZATION_H

#include "visualization.h"
#include <QWidget>
class Jump_Visualization: public Visualization
{
    Q_OBJECT
protected:
    int previousIndex;
    int lowerIndex;
    int upperIndex;
    void setIndex(int previousIndex, int lowerIndex, int upperIndex);
    void paintEvent(QPaintEvent *event) override;
public:
    explicit Jump_Visualization(QWidget *parent = nullptr);
    void startVisualization() override;
    void visualize(int target) override;
};

#endif // JUMP_VISUALIZATION_H
