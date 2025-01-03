#include "visualization.h"
#include "fibonacci_visualization.h"
#include <bits/stdc++.h>
#include <QWidget>
#include <QPainter>
using namespace std;

Fibonacci_Visualization::Fibonacci_Visualization(QWidget *parent): Visualization(parent) {
    nowIndex = -1;
}

void Fibonacci_Visualization::setIndex(int nowIndex) {
    this->nowIndex = nowIndex;
}

void Fibonacci_Visualization::visualize(int target) {
    setIndex(-1);
    Visualization::visualize(target);
}

void Fibonacci_Visualization::startVisualization() {
    qTimer->stop();
    int size = (int) data.size() - 1;

    fib2 = 0; //m-2 th
    fib1 = 1; //m-1 th
    fib0 = fib1 + fib2; //m
    while (fib0 < size) {
        fib2 = fib1;
        fib1 = fib0;
        fib0 = fib1 + fib2;
    }
    for (int i = size; i <= fib0; i++) {
        data.push_back(INT_MAX);
    }
    int idx = fib1 - 1; fib0 = fib1; fib1 = fib2; fib2 = fib0 - fib1;
    while (true) {
        setIndex(idx);
        highlightElement(idx);
        if (data[idx] == target) {
            highlightFoundElement(idx);
            return;
        }
        if (data[idx] < target) {
            if (fib1 == 1) break;
            idx += fib2;
            fib0 = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib0 - fib1;
        } else {
            if (fib2 == 0) break;
            idx -= fib2;
            fib0 = fib1;
            fib1 = fib2;
            fib2 = fib0 - fib1;
        }
    }
    highlightElement(idx);
    if (data[idx] == target) {
        highlightFoundElement(idx);
        return;
    }
}

void Fibonacci_Visualization::paintEvent(QPaintEvent *event) {
    Visualization::paintEvent(event);

    QPainter painter(this);
    Visualization::prepareSize();
    int yOffsetForText = 20;
    if (nowIndex != -1) {
        yOffsetForText = 20;
        int posX = xOffset + nowIndex * rectSize;
        painter.drawText(QRect(posX, yOffset - yOffsetForText, rectSize, 20), Qt::AlignCenter, "now");
        QString labelText = QString("now = fib1 - 1 = %4, fib0 = %1, fib1 = %2, fib2 = %3").arg(QString::number(fib0), QString::number(fib1), QString::number(fib2), QString::number(nowIndex));
        painter.drawText(QRect(xOffset + 100, yOffset - 75, 500, 20), Qt::AlignCenter, labelText);
    }
}
