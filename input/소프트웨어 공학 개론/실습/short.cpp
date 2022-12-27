////2016111667허윤회
#include <iostream>
#include <time.h>
#define ARRSIZE 10
using namespace std;

void swap(int arr[], int a, int b){ //swap 함수
   int tmp = arr[a];
   arr[a] = arr[b];
   arr[b] = tmp;
}

int partition(int arr[], int tl, int tr){ //분할을 위한 partition
   int pivot = arr[tr]; //기준 값
   int i = tl - 1;
   for (int j = tl; j < tr; j++) {
       if(pivot > arr[j]){ //기준값보다 작을 때
           i++;
           swap(arr, i, j); //swap
       }
   }
   swap(arr, i+1, tr); //swap
   return i+1;
}

void quick_sort(int arr[], int left, int right){ //퀵 정렬
   int stack[ARRSIZE]; //배열 형태의 스택
   int top = -1;
   stack[++top] = left;
   stack[++top] = right;

   while (top >= 0){
       int tr = stack[top--];
       int tl = stack[top--];

       int p = partition(arr, tl, tr);

       if(p - 1 > tl){
           stack[++top] = tl;
           stack[++top] = p - 1;
       }
       if(p + 1 < tr){
           stack[++top] = p + 1;
           stack[++top] = tr;
       }

       cout << "중간 결과: "; //중간 결과 출력
       for (int i = 0; i < ARRSIZE; i++) {
           cout << arr[i] << " ";
       }
       cout << endl;
   }
}

// 소공개 실습 중입니다...

int main(){
   srand((int)time(0)); //난수 발생

   int randArr[ARRSIZE] = {}; //크기가 10인 배열
   for (int i = 0; i < ARRSIZE; i++) {
       randArr[i] = rand() % 1000000 + 1; //랜덤한 숫자 배열에 저장
       for (int j = 0; j < i; j++) { // 랜덤 숫자 중복 방지
           if(randArr[i] == randArr[j]){
               i--;
               break;
           }
       }
   }

   cout << "원본 배열: "; //원본 배열 출력
   for (int i = 0; i < ARRSIZE; i++) {
       cout << randArr[i] << " ";
   }
   cout << endl << endl;

   quick_sort(randArr, 0, ARRSIZE-1);

   cout << endl << "정렬 배열: "; //정렬 배열 출력
   for (int i = 0; i < ARRSIZE; i++) {
       cout << randArr[i] << " ";
   }
   cout << endl;
}
