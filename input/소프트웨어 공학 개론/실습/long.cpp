////2016111667허윤회
//실습실습
#include <iostream>
#include <time.h>
#define ARRSIZE 10
using namespace std;

void swap(int arr[], int a, int b){ //swap 함수
   int tmp = arr[a];
   arr[a] = arr[b];
   arr[b] = tmp;
}

void quick_sort(int arr[], int left, int right){ //퀵 정렬
   if(left >= right){ //왼쪽이 오른쪽보다 커지면(순회 완료)
       return; //정렬 종료
   }
   int pivot = left; //기준 값
   int start = left+1;
   int end = right;

   while(start <= end){
       while(arr[start] <= arr[pivot] && start <= right){ //키 값보다 큰 값을 만날 때까지 start를 오른쪽으로 이동
           start++;
       }
       while(arr[pivot] <= arr[end] && left < end){ //키 값보다 작은 값 만날 때까지 end를 왼쪽으로 이동
           end--;
       }
       if(end < start){ //start와 end가 엇갈린 상태
           swap(arr, pivot, end);
       }
       else{
           swap(arr, start, end);
       }
       cout << "중간 결과: "; //중간 결과 출력
       for (int i = 0; i < ARRSIZE; i++) {
           cout << arr[i] << " ";
       }
       cout << endl;
   }
   quick_sort(arr, left, end-1); //퀵 정렬 재귀 호출
   quick_sort(arr, end+1, right); //퀵 정렬 재귀 호출
}

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
   
   cout << endl << "정렬 배열: "; //정렬된 결과 배열 출력
   for (int i = 0; i < ARRSIZE; i++) {
       cout << randArr[i] << " ";
   }
   cout << endl;
}

//소프트웨어 공학 개론