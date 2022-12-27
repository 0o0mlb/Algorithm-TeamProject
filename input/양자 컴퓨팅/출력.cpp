////2016111667����ȸ
#include <iostream>
#define ARRSIZE 8
using namespace std;

void swap(int arr[], int a, int b){
   int tmp = arr[a];
   arr[a] = arr[b];
   arr[b] = tmp;
}

void print_array(int arr[]){
   cout << "���� ���: ";
   for (int i = 0; i < ARRSIZE; i++) {
       cout << arr[i] << " ";
   }
   cout << endl;
}

void selection_sort(int arr[], int size){
   int min = 0;
   for (int i = 1; i < size; i++) {
       if(arr[i] < arr[min]){ //��Ұ��� ��
           min = i; //min�� ����
       }
   }
   if(min != 0){
       swap(arr, min, 0); //swap ����
       print_array(arr); //print ���� but ������ �� ����
   }

   if(size > 1){
       selection_sort(arr+1, size-1); //size ������ ���� ����
   }
}

���� ��� main

int main() {
   int A[ARRSIZE] = {30, 20, 40, 10, 5, 10, 30, 15};

   cout << "���� �迭: ";
   for (int i = 0; i < ARRSIZE; i++) {
       cout << A[i] << " ";
   }
   cout << endl << endl;
   
   selection_sort(A, ARRSIZE);
   
   cout << endl << "���� �迭: ";
   for (int i = 0; i < ARRSIZE; i++) {
       cout << A[i] << " ";
   }
   cout << endl;
}