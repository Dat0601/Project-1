#include "visualization.h"
#include "exponential_visualization.h"
#include <bits/stdc++.h>
#include <QWidget>
#include <QPainter>
using namespace std;

Exponential_Visualization::Exponential_Visualization(QWidget *parent): Visualization(parent) {
    leftIndex = -1;
    rightIndex = -1;
    midIndex = -1;
    posIndex = -1;
}

void Exponential_Visualization::setIndex(int leftIndex, int rightIndex, int midIndex, int posIndex) {
    this->leftIndex = leftIndex;
    this->rightIndex = rightIndex;
    this->midIndex = midIndex;
    this->posIndex = posIndex;
}

void Exponential_Visualization::visualize(int target) {
    setIndex(-1, -1, -1, -1);
    Visualization::visualize(target);
}

void Exponential_Visualization::startVisualization() {
    qTimer->stop();
    highlightElement(0);
    if (data[0] == target) {
        highlightFoundElement(0);
        return;
    }
    int pos = 1, dataSize = (int) data.size();
    setIndex(-1, -1, -1, pos);
    highlightElement(pos);
    while (pos < dataSize && data[pos] <= target) {
        pos *= 2;
        setIndex(-1, -1, -1, pos);
        highlightElement(pos);
    }
    int left = pos / 2, right = min(pos, dataSize - 1);
    while (left <= right) {
        int mid = left + (right - left) / 2;
        setIndex(left, right, mid, -1);
        highlightElement(mid);
        if (data[mid] == target) {
            highlightFoundElement(mid);
            return;
        }
        if (data[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    setIndex(-1, -1, -1, -1);
}

void Exponential_Visualization::paintEvent(QPaintEvent *event) {
    Visualization::paintEvent(event);

    QPainter painter(this);
    Visualization::prepareSize();
    int yOffsetForText = 20;
    if (leftIndex != -1) {
        int leftX = xOffset + leftIndex * rectSize;
        painter.drawText(QRect(leftX, yOffset - yOffsetForText, rectSize, 20), Qt::AlignCenter, "left");
    }
    if (rightIndex != -1) {
        yOffsetForText = 20;
        if (rightIndex == leftIndex) yOffsetForText += 20;
        int rightX = xOffset + rightIndex * rectSize;
        painter.drawText(QRect(rightX, yOffset - yOffsetForText, rectSize, 20), Qt::AlignCenter, "right");
    }
    if (midIndex != -1) {
        yOffsetForText = 20;
        if (leftIndex == midIndex) yOffsetForText += 20;
        if (rightIndex == midIndex) yOffsetForText += 20;
        int midX = xOffset + midIndex * rectSize;
        painter.drawText(QRect(midX, yOffset - yOffsetForText, rectSize, 20), Qt::AlignCenter, "mid");
    }
    if (posIndex != -1) {
        yOffsetForText = 20;
        int posX = xOffset + posIndex * rectSize;
        painter.drawText(QRect(posX, yOffset - yOffsetForText, rectSize, 20), Qt::AlignCenter, "pos");
    }
}
