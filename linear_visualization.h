#ifndef LINEAR_VISUALIZATION_H
#define LINEAR_VISUALIZATION_H

#include "visualization.h"
#include <QWidget>
class Linear_Visualization:public Visualization
{
    Q_OBJECT;
public:
    explicit Linear_Visualization(QWidget *parent = nullptr);
    void startVisualization() override;
};

#endif // LINEAR_VISUALIZATION_H
