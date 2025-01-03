#include "binary_visualization.h"
#include "visualization.h"
#include <bits/stdc++.h>
#include <QWidget>
#include <QPainter>
using namespace std;
Binary_Visualization::Binary_Visualization(QWidget *parent): Visualization(parent) {
    leftIndex = -1;
    rightIndex = -1;
    midIndex = -1;
}
void Binary_Visualization::setIndex(int leftIndex, int rightIndex, int midIndex){
    this->leftIndex = leftIndex;
    this->rightIndex = rightIndex;
    this->midIndex = midIndex;
}
void Binary_Visualization::visualize(int target) {
    setIndex(-1, -1, -1);
    Visualization::visualize(target);
}

void Binary_Visualization::startVisualization() {
    qTimer->stop();
    int left = 0, right = (int) data.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        setIndex(left, right, mid);
        highlightElement(mid);
        if (data[mid] == target) {
            highlightFoundElement(mid);
            return;
        }
        if (data[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    setIndex(-1, -1, -1);
}

void Binary_Visualization::paintEvent(QPaintEvent *event) {
    Visualization::paintEvent(event);

    QPainter painter(this);
    Visualization::prepareSize();
    int yOffsetForText = 20;
    if (leftIndex != -1) {
        int leftX = xOffset + leftIndex * rectSize;
        painter.drawText(QRect(leftX, yOffset - yOffsetForText, rectSize, 20), Qt::AlignCenter, "left");
    }
    if (rightIndex != -1) {
        if (rightIndex == leftIndex) yOffsetForText += 20;
        int rightX = xOffset + rightIndex * rectSize;
        painter.drawText(QRect(rightX, yOffset - yOffsetForText, rectSize, 20), Qt::AlignCenter, "right");
    }
    if (midIndex != -1) {
        if (leftIndex == midIndex) yOffsetForText += 20;
        int midX = xOffset + midIndex * rectSize;
        painter.drawText(QRect(midX, yOffset - yOffsetForText, rectSize, 20), Qt::AlignCenter, "mid");
    }
}
