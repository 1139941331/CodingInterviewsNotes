#ifndef SORT_H
#define SORT_H
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class Sort
{
public:
    Sort();
    Sort(int size);
    Sort(int size,int minValue,int maxValue);

    void swap(vector<int> &arr ,int i,int j);
    void stdSort(const vector<int> &arr);
    void stdswap(vector<int> &arr, int i, int j);
    void printf(const vector<int> &arr);
    void generateRandomArray(int size,int minValue,int maxValue);
    bool check_result(vector<int> &arr,vector<int> &arr2);

public:
    vector<int> arr;
    vector<int> arr2;
    vector<int> getArr() const;
    void setArr(const vector<int> &value);


    void BubbleSort(vector<int> &arr);              // ð������
    void insertionSort(vector<int> &arr);           // ��������
    void selectionSort(vector<int> &arr);           // ѡ������
    void heapSort(vector<int> &arr);                // ������
    void quickSort(vector<int> &arr);               // ������
    void mergeSort(vector<int> &arr);               // �鲢����
    void bucketSort(vector<int> &arr);              // Ͱ����
    void radixSort(vector<int> &arr);               // ��������
    void shellSort(vector<int> &arr);               // shell����
    void countingSort(vector<int> &arr);            // ��������
private:
    void heapInsert(vector<int> &arr, int index);
    void heapify(vector<int> &arr, int index, int size);
    int partition(vector<int> &arr, int l, int r);
    void mergeSort(vector<int> &arr, int l, int r);
    void merge(vector<int> &arr, int l, int m, int r);
    void quickSort(vector<int> &arr, int l, int r);
    int maxbits(vector<int> &arr);
    void radixSort(vector<int> &arr, int begin, int end, int digit);
    int getDigit(int x, int d);
    void shellInsert(vector<int> &arr, int beg, int gap);
};

#endif // SORT_H
