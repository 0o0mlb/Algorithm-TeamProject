////2016111667����ȸ
#include <iostream>
#include <time.h>
#define ARRSIZE 10
using namespace std;

void swap(int arr[], int a, int b){ //swap �Լ�
   int tmp = arr[a];
   arr[a] = arr[b];
   arr[b] = tmp;
}

int partition(int arr[], int tl, int tr){ //������ ���� partition
   int pivot = arr[tr]; //���� ��
   int i = tl - 1;
   for (int j = tl; j < tr; j++) {
       if(pivot > arr[j]){ //���ذ����� ���� ��
           i++;
           swap(arr, i, j); //swap
       }
   }
   swap(arr, i+1, tr); //swap
   return i+1;
}

void quick_sort(int arr[], int left, int right){ //�� ����
   int stack[ARRSIZE]; //�迭 ������ ����
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

       cout << "�߰� ���: "; //�߰� ��� ���
       for (int i = 0; i < ARRSIZE; i++) {
           cout << arr[i] << " ";
       }
       cout << endl;
   }
}

// �Ұ��� �ǽ� ���Դϴ�...

int main(){
   srand((int)time(0)); //���� �߻�

   int randArr[ARRSIZE] = {}; //ũ�Ⱑ 10�� �迭
   for (int i = 0; i < ARRSIZE; i++) {
       randArr[i] = rand() % 1000000 + 1; //������ ���� �迭�� ����
       for (int j = 0; j < i; j++) { // ���� ���� �ߺ� ����
           if(randArr[i] == randArr[j]){
               i--;
               break;
           }
       }
   }

   cout << "���� �迭: "; //���� �迭 ���
   for (int i = 0; i < ARRSIZE; i++) {
       cout << randArr[i] << " ";
   }
   cout << endl << endl;

   quick_sort(randArr, 0, ARRSIZE-1);

   cout << endl << "���� �迭: "; //���� �迭 ���
   for (int i = 0; i < ARRSIZE; i++) {
       cout << randArr[i] << " ";
   }
   cout << endl;
}
