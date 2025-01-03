#include "visualization.h"
#include "jump_visualization.h"
#include <bits/stdc++.h>
#include <QWidget>
#include <QPainter>
using namespace std;

Jump_Visualization::Jump_Visualization(QWidget *parent): Visualization(parent) {
    previousIndex = -1;
    lowerIndex = -1;
    upperIndex = -1;
}

void Jump_Visualization::setIndex(int previousIndex, int lowerIndex, int upperIndex) {
    this->previousIndex = previousIndex;
    this->lowerIndex = lowerIndex;
    this->upperIndex = upperIndex;
}

void Jump_Visualization::visualize(int target) {
    setIndex(-1, -1, -1);
    Visualization::visualize(target);
}

void Jump_Visualization::startVisualization() {
    qTimer->stop();
    int step = max(1, (int) floor(sqrt((int) data.size())));
    int previous = 0, dataSize = (int) data.size();
    while (data[previous] < target) {
        setIndex(previous, -1, -1);
        highlightElement(previous);
        previous += step;
        if (previous >= dataSize) {
            break;
        }
    }
    previous -= step;

    int lower = max(0, previous), upper = min(dataSize, previous + step);
    setIndex(-1, lower, upper);
    for (int i = lower; i <= upper; i++) {
        highlightElement(i);
        if (data[i] == target) {
            highlightFoundElement(i);
            return;
        }
    }
    setIndex(-1, -1, -1);
}

void Jump_Visualization::paintEvent(QPaintEvent *event) {
    Visualization::paintEvent(event);

    QPainter painter(this);
    Visualization::prepareSize();
    int yOffsetForText = 20;
    if (previousIndex != -1) {
        int previousX = xOffset + previousIndex * rectSize;
        int step = max(1, (int) floor(sqrt((int) data.size())));
        painter.drawText(QRect(previousX, yOffset - yOffsetForText, rectSize, 20), Qt::AlignCenter, "previous");
        QString labelText = QString("step = %1, previous = %2 + %1 = %3")
                                .arg(QString::number(step),
                                     QString::number(max(0, previousIndex - step)),
                                     QString::number(previousIndex));

        if (previousIndex != 0) painter.drawText(QRect(xOffset + 100, yOffset - 75, 500, 20), Qt::AlignCenter, labelText);
    }
    if (lowerIndex != -1) {
        int lowerX = xOffset + lowerIndex * rectSize;
        painter.drawText(QRect(lowerX, yOffset - yOffsetForText, rectSize, 20), Qt::AlignCenter, "lower");
    }
    if (upperIndex != -1) {
        int upperX = xOffset + upperIndex * rectSize;
        painter.drawText(QRect(upperX, yOffset - yOffsetForText, rectSize, 20), Qt::AlignCenter, "upper");
    }
}
