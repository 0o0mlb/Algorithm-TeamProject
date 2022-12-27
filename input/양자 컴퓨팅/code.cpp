//양자컴퓨팅 과제
////2016111667허윤회
#include <iostream>
#define ARRSIZE 8
using namespace std;

void swap(int arr[], int a, int b){
   int tmp = arr[a];
   arr[a] = arr[b];
   arr[b] = tmp;
}

void print_array(int arr[], int size){
   cout << "정렬 결과: ";
   for (int i = 0; i < size; i++) {
       cout << arr[i] << " ";
   }
   cout << endl;
}

void selection_sort(int arr[], int size){
   for (int i = 0; i < size-1; i++) {
       int min = i;
       for (int j = i+1; j < size; j++) {
           if(arr[j] < arr[min]){
               min = j;
           }
       }
       if(i != min){
           swap(arr, i, min);
           print_array(arr, size);
       }
   }
}

int main() {
   int A[ARRSIZE] = {30, 20, 40, 10, 5, 10, 30, 15};

   cout << "원본 배열: ";
   print_array(A, ARRSIZE);

   selection_sort(A, ARRSIZE);

   return 0;
}
