#include <iostream>
#include <vector>

using namespace std;

void inputArray(vector<int>& arr, int size) {
    cout << "Введите " << size << " элементов: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void changeSign(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = -arr[i]; // смена знака
    }
}

void outputArray(const vector<int>& arr, int arrayNumber) {
    cout << "Элементы " << arrayNumber << " массива: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void outputPROIZV(const vector<int>& arr, int arrayNumber) {
    float PROIZV = 1; 
    for (int i = 0; i < arr.size(); i++) {
       PROIZV *= arr[i];
    } 
    cout << "Произведение " << arrayNumber << " массива: ";
    cout << PROIZV << endl;
}


int main() {
    vector<int> arr1(3), arr2(5), arr3(4), arr4(3);

    inputArray(arr1, 3);
    inputArray(arr2, 5);
    inputArray(arr3, 4);
    inputArray(arr4, 3);

    changeSign(arr1);
    changeSign(arr2);
    changeSign(arr3);
    changeSign(arr4);

    outputArray(arr1, 1);
    outputArray(arr2, 2);
    outputArray(arr3, 3);
    outputArray(arr4, 4);

    outputPROIZV(arr1, 1);
    outputPROIZV(arr2, 2);
    outputPROIZV(arr3, 3);
    outputPROIZV(arr4, 4);
    return 0;
}