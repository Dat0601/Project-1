#include "visualization.h"
#include "interpolation_visualization.h"
#include <bits/stdc++.h>
#include <QWidget>
#include <QPainter>
using namespace std;

Interpolation_Visualization::Interpolation_Visualization(QWidget *parent): Visualization(parent) {
    leftIndex = -1;
    rightIndex = -1;
    posIndex = -1;
}

void Interpolation_Visualization::setIndex(int leftIndex, int rightIndex, int posIndex) {
    this->leftIndex = leftIndex;
    this->rightIndex = rightIndex;
    this->posIndex = posIndex;
}

void Interpolation_Visualization::visualize(int target) {
    setIndex(-1, -1, -1);
    Visualization::visualize(target);
}

void Interpolation_Visualization::startVisualization() {
    qTimer->stop();
    int left = 0, right = (int) data.size() - 1;
    while (left <= right) {
        if (left == right) {
            highlightElement(left);
            if (data[left] == target) {
                highlightFoundElement(left);
                return;
            } else return;
        }
        int leftValue = data[left], rightValue = data[right];
        int pos = left + floor(((target - leftValue) * 1.0) / (rightValue - leftValue) * (right - left));
        setIndex(left, right, pos);
        highlightElement(pos);
        if (data[pos] == target) {
            highlightFoundElement(pos);
            return;
        }
        if (data[pos] < target) left = pos + 1;
        else right = pos - 1;
    }
    setIndex(-1, -1, -1);
}

void Interpolation_Visualization::paintEvent(QPaintEvent *event) {
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
    if (posIndex != -1) {
        yOffsetForText = 20;
        if (posIndex == leftIndex) yOffsetForText += 20;
        if (posIndex == rightIndex) yOffsetForText += 20;
        int posX = xOffset + posIndex * rectSize;
        painter.drawText(QRect(posX, yOffset - yOffsetForText, rectSize, 20), Qt::AlignCenter, "pos");
    }
    if (leftIndex != -1 && rightIndex != -1) {
        int leftValue = data[leftIndex], rightValue = data[rightIndex];
        QString labelText = QString("pos = %1 + (%5 - %3) / (%4 - %3) * (%2 - %1) = %6")
                                .arg(QString::number(leftIndex),
                                     QString::number(rightIndex),
                                     QString::number(leftValue),
                                     QString::number(rightValue),
                                     QString::number(target),
                                     QString::number(posIndex));
        painter.drawText(QRect(xOffset + 100, yOffset - 75, 500, 20), Qt::AlignCenter, labelText);
    }
}
