#include "visualization.h"
#include "ternary_visualization.h"
#include <bits/stdc++.h>
#include <QWidget>
#include <QPainter>
using namespace std;

Ternary_Visualization::Ternary_Visualization(QWidget *parent): Visualization(parent) {
    leftIndex = -1;
    rightIndex = -1;
    mid1Index = -1;
    mid2Index = -1;
}

void Ternary_Visualization::setIndex(int leftIndex, int rightIndex, int mid1Index, int mid2Index) {
    this->leftIndex = leftIndex;
    this->rightIndex = rightIndex;
    this->mid1Index = mid1Index;
    this->mid2Index = mid2Index;
}

void Ternary_Visualization::visualize(int target) {
    setIndex(-1, -1, -1, -1);
    Visualization::visualize(target);
}

void Ternary_Visualization::startVisualization() {
    qTimer->stop();
    int left = 0, right = (int) data.size() - 1;
    while (left <= right) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;
        setIndex(left, right, mid1, mid2);
        highlightElement(mid1);
        if (data[mid1] == target) {
            highlightFoundElement(mid1);
            return;
        }
        highlightElement(mid2);
        if (data[mid2] == target) {
            highlightFoundElement(mid2);
            return;
        }
        if (target < data[mid1]) {
            right = mid1 - 1;
        } else if (target > data[mid2]) {
            left = mid2 + 1;
        } else {
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }
    setIndex(-1, -1, -1, -1);
}

void Ternary_Visualization::paintEvent(QPaintEvent *event) {
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
    if (mid1Index != -1) {
        if (leftIndex == mid1Index || rightIndex == mid1Index) yOffsetForText += 20;
        int midX = xOffset + mid1Index * rectSize;
        painter.drawText(QRect(midX, yOffset - yOffsetForText, rectSize, 20), Qt::AlignCenter, "mid1");
    }
    if (mid2Index != -1) {
        if (leftIndex == mid2Index || rightIndex == mid2Index || mid1Index == mid2Index) yOffsetForText += 20;
        int midX = xOffset + mid2Index * rectSize;
        painter.drawText(QRect(midX, yOffset - yOffsetForText, rectSize, 20), Qt::AlignCenter, "mid2");
    }
}
