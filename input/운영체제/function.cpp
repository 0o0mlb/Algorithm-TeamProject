////2016111667허윤회
#include <iostream>
#define ARRSIZE 10
using namespace std;

void merge(int arr[], int left, int mid, int right){
   int temparr[ARRSIZE], i, leftptr, rightptr, tempptr;
   leftptr = left;
   rightptr = mid + 1;
   tempptr = left;

   while(leftptr <= mid && rightptr <= right){
       if(arr[leftptr] < arr[rightptr]){
           temparr[tempptr++] = arr[leftptr++];
       }
       else{
           temparr[tempptr++] = arr[rightptr++];
       }
   }
   if(leftptr > mid){
       for (i = rightptr; i <= right; i++) {
           temparr[tempptr++] = arr[i];
       }
   }
   else{
       for (i = leftptr; i <= mid; i++) {
           temparr[tempptr++] = arr[i];
       }
   }
   for (i = left; i <= right; i++) {
       arr[i] = temparr[i];
   }
}

void mergesort(int arr[], int left, int right){
   for (int i = 1; i < ARRSIZE; i = 2*i) {
       left = 1;
       while(left <= ARRSIZE){
           right = left + 2*i - 1;
           if(right > ARRSIZE){
               right = ARRSIZE;
           }
           int mid = left + i - 1;
           cout << "left: " << left << " right: " << right << " mid: " << mid << endl;
           if(mid <= ARRSIZE){
               merge(arr, left, mid, right);
           }
           left = right + 1;
       }
//        cout << "중간 결과 : ";
//        for (int i = 0; i < ARRSIZE; i++) {
//            cout << arr[i] << " ";
//        }
//        cout << endl;
   }
//    int mid;
//    if(left < right){
//        mid = (left + right) / 2;
//        mergesort(arr, left, mid);
//        mergesort(arr, mid + 1, right);
//        merge(arr, left, mid, right);
//    }

}

int main(){
   int A[ARRSIZE]= {30, 20, 40, 35, 5, 50, 45, 10, 25, 15};

   cout << "원본 배열 : ";
   for (int i = 0; i < ARRSIZE; i++) {
       cout << A[i] << " ";
   }
   cout << endl << endl;

   mergesort(A, 0, ARRSIZE-1);

   cout << endl << "정렬 결과 : ";
   for (int i = 0; i < ARRSIZE; i++) {
       cout << A[i] << " ";
   }
   cout << endl;
}

// 운체 과제 완료 06.12.