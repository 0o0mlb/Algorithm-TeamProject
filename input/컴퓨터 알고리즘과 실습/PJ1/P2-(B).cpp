// 2018112600 장지원 : PJ1

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>
using namespace std; //사용할 헤더파일들 선언

void randomACGT(int n) { //랜덤으로 A/C/G/T를 발생시켜 input 파일을 생성하는 함수, n = 문자의 갯수
	ofstream inputFile;
	inputFile.open("input.txt"); //input.txt 파일을 연다

	srand((unsigned int)time(NULL)); //시드값을 다르게 주기 위해 time 사용

	for (int i = 0; i < n; i++) {
		int dna = rand() % 4; //난수를 발생시켜,
		if (dna == 0) {
			inputFile << "A";
		}
		else if (dna == 1) {
			inputFile << "C";
		}
		else if (dna == 2) {
			inputFile << "G";
		}
		else {
			inputFile << "T";
		} //난수의 값에 따라 A/C/G/T 중에 하나를 input 파일에 출력
	} //n번 반복한다
	inputFile.close(); //input.txt 파일을 닫고 마무리한다
}

void RabinKarp(char T[], char P[], int d, int q) { //스트링 매칭 알고리즘 중 Rabin-Karp 알고리즘
	int n = strlen(T); //텍스트의 길이, 사이즈
	int m = 15; //패턴의 길이, 사이즈

	int h = 0;
	int t = 0;
	int D = 1; //해시값과 제곱을 저장할 변수 생성

	int i;

	ofstream outputFile;
	outputFile.open("output.txt"); //output.txt 파일을 연다

	for (i = 1; i <= m - 1; i++) {
		D = (d * D) % q;
	} //d의 m-1제곱 mod q 연산
	for (i = 0; i <= m - 1; i++) {
		h = (d * h + P[i]) % q;
		t = (d * t + T[i]) % q;
	} //해시값 계산
	for (int s = 0; s < n - m + 1; s++) {
		if (h == t) { //해시값이 같을 때
			for (i = 0; i < m; i++) {
				if (P[i] != T[s + i]) { //순차적으로 비교하다가 패턴과 텍스트가 다르면
					break; //탈출
				}
			}
			if (i == m) { //텍스트에서 패턴이 발견되면
				cout << "  패턴이 텍스트의 " << s << "번째부터 나타남" << endl; //어디에서 발견되었는지를 콘솔창에 출력하고,
				outputFile << s;
				outputFile << "\n"; //output 파일에 패턴이 나타난 텍스트의 인덱스 값을 출력해준다
			}
		}

		if (s < n - m) {
			t = (d * (t - T[s] * D) + T[s + m]) % q;

			if (t < 0) {
				t = t + q; //마이너스 과정에서 해시값 음수 방지
			}
		} //해시값 계산
	}

	outputFile.close(); //output.txt 파일을 닫고 마무리한다
}

int main() {
	int n = 1000000; //패턴을 찾을 문자열의 길이, 배열의 크기
	int m = 15; //패턴 문자열의 길이, 패턴 배열의 크기
	randomACGT(n); //n개의 문자를 가지는 A/C/G/T 텍스트

	string DNA; //텍스트를 저장할 문자열 DNA 생성
	ifstream readFile;
	readFile.open("input.txt");
	getline(readFile, DNA); //input.txt 파일을 읽어와 DNA에 저장
	readFile.close();
	char* D = &DNA[0]; //텍스트 문자열 DNA를 1차 배열 D에 입력

	char* P = (char*)malloc(sizeof(char) * m); //패턴 배열 P를 동적할당

	srand((unsigned int)time(NULL)); //시드값을 다르게 주기 위해 time 사용

	for (int i = 0; i < m; i++) {
		int RN = rand() % 4; //난수를 발생시켜
		if (RN == 0) {
			P[i] = 'A';
		}
		else if (RN == 1) {
			P[i] = 'C';
		}
		else if (RN == 2) {
			P[i] = 'G';
		}
		else {
			P[i] = 'T';
		} //난수의 값에 따라 A/C/G/T 중에 하나를 출력
	} //m번 반복하여 길이가 m인 패턴을 만든다

	clock_t start, finish;
	double duration = 0; //시작 시간과 종료 시간, 수행시간을 저장할 변수 선언

	cout << "\n--------------------------------------------------" << endl;
	cout << " Pattern --> ";
	for (int i = 0; i < m; i++) {
		cout << P[i]; //패턴의 값을 콘솔창에 출력
	}
	cout << endl;
	cout << "--------------------------------------------------" << endl;
	cout << " n = " << n << " & m = " << m << endl; //n과 m의 값을 출력
	cout << "--------------------------------------------------" << endl;
	cout << " [ 그 의외의 알고리즘 ]" << endl;
	cout << "\n Rabin-Karp 알고리즘의 결과 : " << endl;

	start = clock();
	RabinKarp(D, P, 4, 131071);
	finish = clock();

	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\n Rabin-Karp 알고리즘의 수행시간 : " << duration << "초" << endl;
	cout << "--------------------------------------------------\n\n" << endl;
	//Rabin Karp 함수를 실행하고 패턴의 위치를 출력한 뒤, 소요시간을 계산하여 결과를 출력

	free(P); //배열 P의 동적할당 해제
 
}

// 컴알 PJ1