////2016111667����ȸ
//��ǻ�ͱ׷��Ƚ��Թ�
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool is_palindrome(string line, int start, int end){
   if(line.length() == 1){ //���ڿ��� ���̰� 1�� ���
       cout << " error(���� �ȿ� �ѱ��ڸ� �����ֽ��ϴ�)" << endl; //error ���� ���
       return false; //not palindrome
   }
//    int end = line.length() - start - 1;
   while((line[end] >= 33 && line[end] <= 47) || (line[end] >= 58 && line[end] <= 64) || (line[end] >= 91 && line[end] <= 96) || (line[end] >= 123 && line[end] <= 126)){
       end--;
   }
   if(start < end){
       if(line[start] != line[end]){
           cout << " is not palindrome" << endl; //not palindrome
           return false;
       }
       else{
           start++;
           end--;
           is_palindrome(line, start, end);
       }
   }
   else{
       cout << " is palindrome" << endl; //while�� ��� ��, palindrome
       return true;
   }
   return true;
}

int main(){
   string line;
   ifstream file("/Users/heoyoonhwe/algorithmschool/algorithmschool/week4_text.txt"); //���� ���� �õ�
   if(file.is_open()){ //���� ���� ����
       while(getline(file, line)) {
           cout << "\"" << line << "\""; //�� ���� �� ���
           is_palindrome(line, 0, line.length()-1);//palindrome �˻�
       }
       file.close(); // ������ ������ �ݴ´�.
   }
   else{ //���� ���� ����
       cout << "fail to open the file...";
       return 1;
   }
   return 0;
}
