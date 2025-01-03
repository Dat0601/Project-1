#ifndef VISUALIZATION_H
#define VISUALIZATION_H

#include <bits/stdc++.h>
#include <QWidget>
#include <QTimer>
using namespace std;

class Visualization: public QWidget {
    Q_OBJECT
protected:
    virtual void paintEvent(QPaintEvent *event) override;
    void prepareSize();
    void highlightElement(int index);
    void highlightFoundElement(int index);
    vector<int> data;
    int highlightedIndex;
    QTimer* qTimer;
    int target;
    int foundIndex;
    int rectSize;
    int xOffset;
    int yOffset;
public slots:
    virtual void startVisualization() = 0;
public:
    explicit Visualization(QWidget *parent = nullptr);
    virtual void visualize(int target);
    void setData(vector<int> data);
    virtual ~Visualization() = default;
};


#endif // VISUALIZATION_H
