// 2018112600 장지원
// 컴알 PJ1

#include <iostream>
#include <math.h>
#include <ctime>
#include <string>
#include <stdlib.h>
using namespace std; //사용할 헤더파일들 선언

void BruteForce(char T[], char P[], int n, int m) { //스트링 매칭 알고리즘 중 직선적 방식
	int i, j;
	for (i = 0; i <= n - m; i++) {
		for (j = 0; j < m; j++) {
			if (P[j] != T[i + j]) {
				break;
			}
		} //순차 탐색으로 텍스트를 완전 탐색하여 패턴을 찾는다
		if (j == m) { //텍스트에서 패턴이 발견되면
			cout << "  패턴이 텍스트의 " << i << "번째부터 나타남" << endl;
		} //어디에서 발견되었는지를 콘솔창에 출력
	}
}

void ComputeSP(char P[], char SP[], int m) { //상태전이 함수
	SP[0] = -1;
	int k = -1;
	int j = 0;

	for (int j = 1; j <= m - 1; j++) {
		while ((k >= 0) && (P[j] != P[k])) {
			k = SP[k-1];
		}
		if (P[k + 1] == P[j]) { //접두사 접미사 비교
			SP[j] = ++j;
		}
	} //접두사 접미사 일치 개수 테이블 생성
}

void KMP(char T[], char P[], int n, int m) { //KMP 함수 (문자열 비교)
	int i = 0, j = 0;
	while (i < n) { //텍스트의 길이보다 작을 때
		if (j == -1 || T[i] == P[j]) { //접두사와 접미사를 비교하여
			i++;
			j++;
		} //만족시키면 인덱스 값 증가
		else {
			j = T[j];
		} //j 인덱스 수정

		if (j == m) { //패턴을 찾으면
			cout << "  패턴이 텍스트의 " << i - m << "번째부터 나타남" << endl;
			j = T[j];
			//결과 출력 및 j 인덱스 수정
		}
	}
}

void RabinKarp(char T[], char P[], int d, int q) { //스트링 매칭 알고리즘 중 Rabin-Karp 알고리즘
	int n = strlen(T); //텍스트의 길이, 사이즈
	int m = strlen(P); //패턴의 길이, 사이즈

	int h = 0;
	int t = 0;
	int D = 1; //해시값과 제곱을 저장할 변수 생성

	int i;
	 
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
				cout << "  패턴이 텍스트의 " << s << "번째부터 나타남" << endl;
			} //어디에서 발견되었는지를 콘솔창에 출력
		}

		if (s < n - m) {
			t = (d * (t - T[s] * D) + T[s + m]) % q;

			if (t < 0) {
				t = t + q; //마이너스 과정에서 해시값 음수 방지
			}
		} //해시값 계산
	}
}

int main() {
	string text, pattern; //텍스트와 패턴을 저장할 문자열 생성
	cout << "\n\n Text String 입력 --> ";
	getline(cin, text); //텍스트를 입력받아 text 문자열에 저장
	cout << "\n Pattern String 입력 --> ";
	getline(cin, pattern); //패턴을 입력받아 pattern 문자열에 저장

	int n = text.length();
	int m = pattern.length(); //text와 pattern의 크기 계산
	char* T = &text[0]; //텍스트 문자열 text를 1차 배열 T에 입력
	char* P = &pattern[0]; //패턴 문자열 pattern을 1차 배열 P에 입력

	clock_t start, finish;
	double duration = 0; //시작 시간과 종료 시간, 수행시간을 저장할 변수 선언

	cout << "\n\n--------------------------------------------------" << endl;
	cout << " Brute-Force 알고리즘의 결과 : " << endl;
	start = clock(); //시작시간 설정

	BruteForce(T, P, n, m); //함수 실행

	finish = clock(); //종료시간 설정

	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout <<"\n Brute-Force 알고리즘의 수행시간 : "<< duration << "초" << endl;
	cout << "--------------------------------------------------\n\n" << endl;
	//직선적 방법인 BruteForce 함수를 실행하고 결과를 출력한 뒤, 소요시간을 계산하여 출력

	cout << "--------------------------------------------------" << endl;
	cout << " KMP 알고리즘의 결과 : " << endl;
	start = clock(); //시작시간 재설정

	ComputeSP(P, T, m);
	KMP(T, P, n, m);

	finish = clock(); //종료시간 재설정

	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\n KMP 알고리즘의 수행시간 : " << duration << "초" << endl;
	cout << "--------------------------------------------------\n\n" << endl;
	//KMP 알고리즘 함수를 실행하고 패턴의 위치를 출력한 뒤, 소요시간을 계산하여 출력

	cout << "--------------------------------------------------" << endl;
	cout << " Rabin-Karp 알고리즘의 결과 : " << endl;
	start = clock(); //시작시간 재설정

	RabinKarp(T, P, 27, 131071);

	finish = clock(); //종료시간 재설정

	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\n Rabin-Karp 알고리즘의 수행시간 : " << duration << "초" << endl;
	cout << "--------------------------------------------------\n\n" << endl;
	//Rabin Karp 알고리즘 함수를 실행하고 패턴의 위치를 출력한 뒤, 소요시간을 계산하여 출력
}