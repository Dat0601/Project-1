#include "linear_visualization.h"
#include "visualization.h"
#include <bits/stdc++.h>
#include <QWidget>
Linear_Visualization::Linear_Visualization(QWidget *parent): Visualization(parent) {}
void Linear_Visualization::startVisualization() {
    qTimer->stop();
    int dataSize = (int) data.size();
    for (int i = 0; i < dataSize; i++) {
        highlightElement(i);
        if (data[i] == this->target) {
            highlightFoundElement(i);
            return;
        }
    }
}
