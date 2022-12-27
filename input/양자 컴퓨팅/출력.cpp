////2016111667허윤회
#include <iostream>
#define ARRSIZE 8
using namespace std;

void swap(int arr[], int a, int b){
   int tmp = arr[a];
   arr[a] = arr[b];
   arr[b] = tmp;
}

void print_array(int arr[]){
   cout << "정렬 결과: ";
   for (int i = 0; i < ARRSIZE; i++) {
       cout << arr[i] << " ";
   }
   cout << endl;
}

void selection_sort(int arr[], int size){
   int min = 0;
   for (int i = 1; i < size; i++) {
       if(arr[i] < arr[min]){ //대소관계 비교
           min = i; //min값 수정
       }
   }
   if(min != 0){
       swap(arr, min, 0); //swap 진행
       print_array(arr); //print 오류 but 정렬은 잘 진행
   }

   if(size > 1){
       selection_sort(arr+1, size-1); //size 끝까지 선택 정렬
   }
}

양컴 출력 main

int main() {
   int A[ARRSIZE] = {30, 20, 40, 10, 5, 10, 30, 15};

   cout << "원본 배열: ";
   for (int i = 0; i < ARRSIZE; i++) {
       cout << A[i] << " ";
   }
   cout << endl << endl;
   
   selection_sort(A, ARRSIZE);
   
   cout << endl << "최종 배열: ";
   for (int i = 0; i < ARRSIZE; i++) {
       cout << A[i] << " ";
   }
   cout << endl;
}