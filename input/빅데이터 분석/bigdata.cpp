//������ �м� ����
#include <iostream>
using namespace std;

int main() {

	int n, m, max = 0;
	cin >> n >> m;

	int* arr = new int[n]; //�����Ҵ�

	for (int i = 0; i < n; i++) {
		cin >> arr[i];

		if (max < arr[i])
			max = arr[i]; //���� ���� �� ���� �� ���̸� �ִ����� ����
	}

	while (1) {
		int sum = 0;

		for (int i = 0; i < n; i++) {
			if (arr[i] > max)
				sum += (arr[i] - max); //�߸� ���� ����
		}

		if (sum >= m)
			break;
		else
			max -= 1; //���̸� 1�� ����
	}

	cout << max;

	return 0;
}