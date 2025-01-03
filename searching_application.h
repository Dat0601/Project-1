#ifndef SEARCHING_APPLICATION_H
#define SEARCHING_APPLICATION_H

#include <QMainWindow>
#include "searching_algorithm.h"
#include "search_context.h"
#include "array_generator.h"
#include "visualization.h"
#include <bits/stdc++.h>
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui {
class Searching_Application;
}
QT_END_NAMESPACE

class Searching_Application : public QMainWindow
{
    Q_OBJECT

public:
    Searching_Application(QWidget *parent = nullptr);
    ~Searching_Application();
private slots:
    void on_UploadButton_clicked();
    void on_GenerateInputButton_clicked();
    void on_Search_clicked();
    void on_ViewLinearSearchButton_clicked();
    void on_ViewBinarySearchButton_clicked();
    void on_ViewTernarySearchButton_clicked();
    void on_ViewJumpSearchButton_clicked();
    void on_ViewExponentialSearchButton_clicked();
    void on_ViewInterpolationSearchButton_clicked();
    void on_ViewFibonacciSearchButton_clicked();
    void on_InputArrayButton_clicked();

private:
    Ui::Searching_Application *ui;
    vector<int> inputArray;
    vector<int> values;
    vector<SearchingAlgorithm*> searchers;
    Search_Context contexts;
    string result;
    Array_Generator* array_generator;
    Visualization* visualization;
    static const vector<int> sample;
    void visualize(int target);
};
#endif // SEARCHING_APPLICATION_H
