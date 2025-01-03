#include "searching_application.h"
#include "./ui_searching_application.h"
#include <bits/stdc++.h>
#include "linear_search.h"
#include "binary_search.h"
#include "ternary_search.h"
#include "jump_search.h"
#include "exponential_search.h"
#include "interpolation_search.h"
#include "fibonacci_search.h"
#include "QFileDialog"
#include "filereader.h"
#include "fieldreader.h"
#include "ascending_array.h"
#include "descending_array.h"
#include "random_array.h"
#include "linear_visualization.h"
#include "binary_visualization.h"
#include "ternary_visualization.h"
#include "jump_visualization.h"
#include "exponential_visualization.h"
#include "interpolation_visualization.h"0
#include "fibonacci_visualization.h"
using namespace std;

Searching_Application::Searching_Application(QWidget *parent): QMainWindow(parent), ui(new Ui::Searching_Application) {
    ui->setupUi(this);
}

Searching_Application::~Searching_Application() {
    delete ui;
}

void Searching_Application::on_UploadButton_clicked() {
    QString qFileDir = QFileDialog::getOpenFileName(this, "Open file", "", "All Files (*.*)");
    string fileDir = qFileDir.toStdString();
    string data = FileReader::read(fileDir);
    if (ui->inputIntoFieldCheck->isChecked()) {
        ui->inputArrayEdit->setPlainText(QString::fromStdString(data));
    } else {
        FieldReader reader;
        reader.read(data);
        inputArray = reader.getInputArray();
    }
}

void Searching_Application::on_GenerateInputButton_clicked() {
    string sizeStr = ui->inputSizeEdit->text().toStdString();
    FieldReader reader;
    reader.read(sizeStr);
    int size = reader.getInputArray()[0];

    string generator = ui->generateTypeBox->currentText().toStdString();
    if (generator == "Ascending") {
        array_generator = new Ascending_Array();
    } else if (generator == "Descending") {
        array_generator = new Descending_Array();
    } else {
        array_generator = new Random_Array();
    }
    array_generator->generate(size);
    if (ui->inputIntoFieldCheck->isChecked()) {
        string inputArrStr = array_generator->generatedArrayString();
        ui->inputArrayEdit->setPlainText(QString::fromStdString(inputArrStr));
    } else {
        inputArray = array_generator->generatedArray();
    }
}


void Searching_Application::on_InputArrayButton_clicked() {
    QString qData = ui->inputArrayEdit->toPlainText();
    string data = qData.toStdString();
    FieldReader reader;
    reader.read(data);
    inputArray = reader.getInputArray();
}

void Searching_Application::on_Search_clicked() {
    string searchValuesStr = ui->searchValueEdit->text().toStdString();
    FieldReader reader;
    reader.read(searchValuesStr);
    values = reader.getInputArray();
    searchers.clear();
    if (ui->linearSearchCheck->isChecked()) {
        searchers.push_back(new Linear_Search(inputArray));
    }
    if (ui->binarySearchCheck->isChecked()) {
        searchers.push_back(new Binary_Search(inputArray));
    }
    if (ui->ternarySearchCheck->isChecked()) {
        searchers.push_back(new Ternary_Search(inputArray));
    }
    if (ui->jumpSearchCheck->isChecked()) {
        searchers.push_back(new Jump_Search(inputArray));
    }
    if (ui->exponentialSearchCheck->isChecked()) {
        searchers.push_back(new Exponential_Search(inputArray));
    }
    if (ui->interpolationSearchCheck->isChecked()) {
        searchers.push_back(new Interpolation_Search(inputArray));
    }
    if (ui->fibonacciSearchCheck->isChecked()) {
       searchers.push_back(new Fibonacci_Search(inputArray));
    }
    result = "";
    for (SearchingAlgorithm* searcher: searchers) {
        result += "<<<" + searcher->algorithm() + ">>>" + "\n";
        Search_Context().setSearching(searcher);
        for (int value: values) {
            result += Search_Context().searchValue(value);
        }
        result += "..Total: ";
        ostringstream outSearch;
        double totalSearchTime = Search_Context().getSearch()->totalSearchTime();
        outSearch << fixed << setprecision(3) << totalSearchTime;
        result += ", search time = " + outSearch.str() + " ms";
        result += ".\n";
    }
    ui->resultLog->setPlainText(QString::fromStdString(result));
}

const vector<int> Searching_Application::sample = {1289, 1975, 2632, 2794, 3510, 4125, 4516, 5186, 5963, 8002, 9183, 9843, 10000, 13399, 13425, 14115, 14746, 16420, 17819, 19268, 19897};

void Searching_Application::visualize(int target) {
    visualization->setData(sample);
    visualization->visualize(target);
    visualization->show();
}

void Searching_Application::on_ViewLinearSearchButton_clicked() {
    visualization = new Linear_Visualization();
    visualize(10000);
}


void Searching_Application::on_ViewBinarySearchButton_clicked() {
    visualization = new Binary_Visualization();
    visualize(10000);
}


void Searching_Application::on_ViewTernarySearchButton_clicked() {
    visualization = new Ternary_Visualization();
    visualize(10000);
}


void Searching_Application::on_ViewJumpSearchButton_clicked() {
    visualization = new Jump_Visualization();
    visualize(10000);
}


void Searching_Application::on_ViewExponentialSearchButton_clicked() {
    visualization = new Exponential_Visualization();
    visualize(10000);
}


void Searching_Application::on_ViewInterpolationSearchButton_clicked() {
    visualization = new Interpolation_Visualization();
    visualize(10000);
}


void Searching_Application::on_ViewFibonacciSearchButton_clicked() {
    visualization = new Fibonacci_Visualization();
    visualize(10000);
}
