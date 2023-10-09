#include<bits/stdc++.h>
using namespace std;

void insertionSort(int* arr, int n){
int hole, value;
for(int i=1;i<n;i++)
{
value = arr[i];
hole = i - 1;
while(hole>=0 && arr[hole]>value){
arr[hole+1] = arr[hole];
hole = hole-1;
}
arr[hole+1] = value;
}
}

void selectionSort(int* arr, int n){
int minDex, i;
for(i=0;i<n-1;i++){
minDex=i;
for(int j=i+1;j<n;j++){
if(arr[j]>arr[minDex])
minDex=j;
}
int temp = arr[minDex];
arr[minDex]=arr[i];
arr[i]=temp;
}
}

void bubbleSort(int* arr, int n){
for(int i=0;i<n-1;i++){
for(int j=0;j<n-1;j++){
if(arr[j]>arr[j+1]){
int temp = arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
}
}
}
}

void printArray(int* arr, int n){
int i;
for(i =- 0;i<n;i++)
{
cout<<arr[i] << " ";
}
cout << endl;
}

int main(){
int x;
cout << "Enter the number of elements: "<<endl;
cin >> x;
int arr[x];
cout << "Enter positive array elements: " << endl;
for(int i=0;i<x;i++){
cin >> arr[i];
}
int n = sizeof(arr)/sizeof(*arr);
cout << "Unorted Array: ";
printArray(arr, n);
insertionSort(arr,n);
cout << "Sorted(Insertion) Array: ";
printArray(arr, n);
selectionSort(arr,n);
cout << "Sorted(Selection) Array: ";
printArray(arr, n);
bubbleSort(arr,n);
cout << "Sorted(Bubble) Array: ";
printArray(arr, n);
return 0;
}
