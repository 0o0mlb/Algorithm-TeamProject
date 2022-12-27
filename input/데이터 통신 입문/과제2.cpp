////2016111667허윤회 
#include <iostream>
#define ARRSIZE 10
using namespace std;

void merge(int arr[], int left, int mid, int right){ //merge 함수
   int temparr[ARRSIZE], i, leftptr, rightptr, tempptr; //임시 배열 및 왼,오,임시 포인터 생성
   
   leftptr = left; //포인터 배정
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

void mergesort(int arr[], int left, int right){ //합병정렬 함수
   int mid;
   if(left < right){ //교차되지 않았을 때
       mid = (left + right) / 2;
       mergesort(arr, left, mid); //재귀 호출(왼쪽)
       mergesort(arr, mid + 1, right); //재귀 호출(오른쪽)
       merge(arr, left, mid, right); //합병
   }
   
   cout << "중간 결과 : "; //중간 결과 출력
   for (int i = 0; i < ARRSIZE; i++) {
       cout << arr[i] << " ";
   }
   cout << endl;
}

int main(){
   int A[ARRSIZE]= {30, 20, 40, 35, 5, 50, 45, 10, 25, 15};
   
   cout << "원본 배열 : "; //원본 배열 출력
   for (int i = 0; i < ARRSIZE; i++) {
       cout << A[i] << " ";
   }
   cout << endl << endl;
   
   mergesort(A, 0, ARRSIZE-1);
   
   cout << endl << "정렬 결과 : "; //데이터 통신 입문 정렬 결과 출력
   for (int i = 0; i < ARRSIZE; i++) {
       cout << A[i] << " ";
   }
   cout << endl;
}
