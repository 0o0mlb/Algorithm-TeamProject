////2016111667����ȸ 
#include <iostream>
#define ARRSIZE 10
using namespace std;

void merge(int arr[], int left, int mid, int right){ //merge �Լ�
   int temparr[ARRSIZE], i, leftptr, rightptr, tempptr; //�ӽ� �迭 �� ��,��,�ӽ� ������ ����
   
   leftptr = left; //������ ����
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

void mergesort(int arr[], int left, int right){ //�պ����� �Լ�
   int mid;
   if(left < right){ //�������� �ʾ��� ��
       mid = (left + right) / 2;
       mergesort(arr, left, mid); //��� ȣ��(����)
       mergesort(arr, mid + 1, right); //��� ȣ��(������)
       merge(arr, left, mid, right); //�պ�
   }
   
   cout << "�߰� ��� : "; //�߰� ��� ���
   for (int i = 0; i < ARRSIZE; i++) {
       cout << arr[i] << " ";
   }
   cout << endl;
}

int main(){
   int A[ARRSIZE]= {30, 20, 40, 35, 5, 50, 45, 10, 25, 15};
   
   cout << "���� �迭 : "; //���� �迭 ���
   for (int i = 0; i < ARRSIZE; i++) {
       cout << A[i] << " ";
   }
   cout << endl << endl;
   
   mergesort(A, 0, ARRSIZE-1);
   
   cout << endl << "���� ��� : "; //������ ��� �Թ� ���� ��� ���
   for (int i = 0; i < ARRSIZE; i++) {
       cout << A[i] << " ";
   }
   cout << endl;
}
