////2016111667허윤회
//컴퓨터그래픽스입문
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool is_palindrome(string line, int start, int end){
   if(line.length() == 1){ //문자열의 길이가 1인 경우
       cout << " error(문장 안에 한글자만 적혀있습니다)" << endl; //error 문자 출력
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
       cout << " is palindrome" << endl; //while문 통과 시, palindrome
       return true;
   }
   return true;
}

int main(){
   string line;
   ifstream file("/Users/heoyoonhwe/algorithmschool/algorithmschool/week4_text.txt"); //파일 열기 시도
   if(file.is_open()){ //파일 열기 성공
       while(getline(file, line)) {
           cout << "\"" << line << "\""; //한 문장 씩 출력
           is_palindrome(line, 0, line.length()-1);//palindrome 검사
       }
       file.close(); // 열었던 파일을 닫는다.
   }
   else{ //파일 열기 실패
       cout << "fail to open the file...";
       return 1;
   }
   return 0;
}
