////2016111667����ȸ
//�ǽ��ǽ�
#include <iostream>
#include <time.h>
#define ARRSIZE 10
using namespace std;

void swap(int arr[], int a, int b){ //swap �Լ�
   int tmp = arr[a];
   arr[a] = arr[b];
   arr[b] = tmp;
}

void quick_sort(int arr[], int left, int right){ //�� ����
   if(left >= right){ //������ �����ʺ��� Ŀ����(��ȸ �Ϸ�)
       return; //���� ����
   }
   int pivot = left; //���� ��
   int start = left+1;
   int end = right;

   while(start <= end){
       while(arr[start] <= arr[pivot] && start <= right){ //Ű ������ ū ���� ���� ������ start�� ���������� �̵�
           start++;
       }
       while(arr[pivot] <= arr[end] && left < end){ //Ű ������ ���� �� ���� ������ end�� �������� �̵�
           end--;
       }
       if(end < start){ //start�� end�� ������ ����
           swap(arr, pivot, end);
       }
       else{
           swap(arr, start, end);
       }
       cout << "�߰� ���: "; //�߰� ��� ���
       for (int i = 0; i < ARRSIZE; i++) {
           cout << arr[i] << " ";
       }
       cout << endl;
   }
   quick_sort(arr, left, end-1); //�� ���� ��� ȣ��
   quick_sort(arr, end+1, right); //�� ���� ��� ȣ��
}

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
   
   cout << endl << "���� �迭: "; //���ĵ� ��� �迭 ���
   for (int i = 0; i < ARRSIZE; i++) {
       cout << randArr[i] << " ";
   }
   cout << endl;
}

//����Ʈ���� ���� ����