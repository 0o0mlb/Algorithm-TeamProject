//빅데이터 분석 과제
#include <iostream>
using namespace std;

int main() {

	int n, m, max = 0;
	cin >> n >> m;

	int* arr = new int[n]; //동적할당

	for (int i = 0; i < n; i++) {
		cin >> arr[i];

		if (max < arr[i])
			max = arr[i]; //떡의 길이 중 가장 긴 길이를 최댓값으로 설정
	}

	while (1) {
		int sum = 0;

		for (int i = 0; i < n; i++) {
			if (arr[i] > max)
				sum += (arr[i] - max); //잘린 떡의 길이
		}

		if (sum >= m)
			break;
		else
			max -= 1; //높이를 1씩 감소
	}

	cout << max;

	return 0;
}