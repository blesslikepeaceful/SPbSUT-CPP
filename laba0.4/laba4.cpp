#include <iostream>
#include <vector>

using namespace std;
void inputArray(vector<int>& arr, int size) {
    cout << "Введите " << size << " элементов: ";
    for (int i = 0; i < size; i++) 
    {
        cin >> arr[i];
    } 
}

void incseaseByTen(vector<int>& arr){
    for(int i=0; i<arr.size();i++){
        arr[i] += -1; // смена знака
    }
}
int countneg(const vector<int>&arr){
    int count=0;
    for (int i=0; i<arr.size();i++){
        if (arr[i]>=0){
            count++;
        }
    }
    return count;
}
void outputArray(vector<int>& arr, int size) {
    cout << "Элементы " << size-3 << " массива: ";
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i]<<" ";
    } 
}
int main() {
    vector<int> arr1(4), arr2(5), arr3(6);
    
    inputArray(arr1, 4);
    inputArray(arr2, 5);
    inputArray(arr3, 6);
    incseaseByTen(arr1);
    incseaseByTen(arr2);
    incseaseByTen(arr3);
    
    int countnegCount = countneg(arr1) + countneg(arr2) + countneg(arr3);
    cout << "Количество неотрицательных элементов: " << countnegCount << endl;
    outputArray(arr1, 4);
    outputArray(arr2, 5);
    outputArray(arr3, 6);
    return 0;
}