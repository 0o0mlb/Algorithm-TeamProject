// 2018112600 ������
// �ľ� PJ1

#include <iostream>
#include <math.h>
#include <ctime>
#include <string>
#include <stdlib.h>
using namespace std; //����� ������ϵ� ����

void BruteForce(char T[], char P[], int n, int m) { //��Ʈ�� ��Ī �˰��� �� ������ ���
	int i, j;
	for (i = 0; i <= n - m; i++) {
		for (j = 0; j < m; j++) {
			if (P[j] != T[i + j]) {
				break;
			}
		} //���� Ž������ �ؽ�Ʈ�� ���� Ž���Ͽ� ������ ã�´�
		if (j == m) { //�ؽ�Ʈ���� ������ �߰ߵǸ�
			cout << "  ������ �ؽ�Ʈ�� " << i << "��°���� ��Ÿ��" << endl;
		} //��𿡼� �߰ߵǾ������� �ܼ�â�� ���
	}
}

void ComputeSP(char P[], char SP[], int m) { //�������� �Լ�
	SP[0] = -1;
	int k = -1;
	int j = 0;

	for (int j = 1; j <= m - 1; j++) {
		while ((k >= 0) && (P[j] != P[k])) {
			k = SP[k-1];
		}
		if (P[k + 1] == P[j]) { //���λ� ���̻� ��
			SP[j] = ++j;
		}
	} //���λ� ���̻� ��ġ ���� ���̺� ����
}

void KMP(char T[], char P[], int n, int m) { //KMP �Լ� (���ڿ� ��)
	int i = 0, j = 0;
	while (i < n) { //�ؽ�Ʈ�� ���̺��� ���� ��
		if (j == -1 || T[i] == P[j]) { //���λ�� ���̻縦 ���Ͽ�
			i++;
			j++;
		} //������Ű�� �ε��� �� ����
		else {
			j = T[j];
		} //j �ε��� ����

		if (j == m) { //������ ã����
			cout << "  ������ �ؽ�Ʈ�� " << i - m << "��°���� ��Ÿ��" << endl;
			j = T[j];
			//��� ��� �� j �ε��� ����
		}
	}
}

void RabinKarp(char T[], char P[], int d, int q) { //��Ʈ�� ��Ī �˰��� �� Rabin-Karp �˰���
	int n = strlen(T); //�ؽ�Ʈ�� ����, ������
	int m = strlen(P); //������ ����, ������

	int h = 0;
	int t = 0;
	int D = 1; //�ؽð��� ������ ������ ���� ����

	int i;
	 
	for (i = 1; i <= m - 1; i++) {
		D = (d * D) % q;
	} //d�� m-1���� mod q ����
	for (i = 0; i <= m - 1; i++) {
		h = (d * h + P[i]) % q;
		t = (d * t + T[i]) % q;
	} //�ؽð� ���
	for (int s = 0; s < n - m + 1; s++) {
		if (h == t) { //�ؽð��� ���� ��
			for (i = 0; i < m; i++) {
				if (P[i] != T[s + i]) { //���������� ���ϴٰ� ���ϰ� �ؽ�Ʈ�� �ٸ���
					break; //Ż��
				}
			}
			if (i == m) { //�ؽ�Ʈ���� ������ �߰ߵǸ�
				cout << "  ������ �ؽ�Ʈ�� " << s << "��°���� ��Ÿ��" << endl;
			} //��𿡼� �߰ߵǾ������� �ܼ�â�� ���
		}

		if (s < n - m) {
			t = (d * (t - T[s] * D) + T[s + m]) % q;

			if (t < 0) {
				t = t + q; //���̳ʽ� �������� �ؽð� ���� ����
			}
		} //�ؽð� ���
	}
}

int main() {
	string text, pattern; //�ؽ�Ʈ�� ������ ������ ���ڿ� ����
	cout << "\n\n Text String �Է� --> ";
	getline(cin, text); //�ؽ�Ʈ�� �Է¹޾� text ���ڿ��� ����
	cout << "\n Pattern String �Է� --> ";
	getline(cin, pattern); //������ �Է¹޾� pattern ���ڿ��� ����

	int n = text.length();
	int m = pattern.length(); //text�� pattern�� ũ�� ���
	char* T = &text[0]; //�ؽ�Ʈ ���ڿ� text�� 1�� �迭 T�� �Է�
	char* P = &pattern[0]; //���� ���ڿ� pattern�� 1�� �迭 P�� �Է�

	clock_t start, finish;
	double duration = 0; //���� �ð��� ���� �ð�, ����ð��� ������ ���� ����

	cout << "\n\n--------------------------------------------------" << endl;
	cout << " Brute-Force �˰����� ��� : " << endl;
	start = clock(); //���۽ð� ����

	BruteForce(T, P, n, m); //�Լ� ����

	finish = clock(); //����ð� ����

	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout <<"\n Brute-Force �˰����� ����ð� : "<< duration << "��" << endl;
	cout << "--------------------------------------------------\n\n" << endl;
	//������ ����� BruteForce �Լ��� �����ϰ� ����� ����� ��, �ҿ�ð��� ����Ͽ� ���

	cout << "--------------------------------------------------" << endl;
	cout << " KMP �˰����� ��� : " << endl;
	start = clock(); //���۽ð� �缳��

	ComputeSP(P, T, m);
	KMP(T, P, n, m);

	finish = clock(); //����ð� �缳��

	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\n KMP �˰����� ����ð� : " << duration << "��" << endl;
	cout << "--------------------------------------------------\n\n" << endl;
	//KMP �˰��� �Լ��� �����ϰ� ������ ��ġ�� ����� ��, �ҿ�ð��� ����Ͽ� ���

	cout << "--------------------------------------------------" << endl;
	cout << " Rabin-Karp �˰����� ��� : " << endl;
	start = clock(); //���۽ð� �缳��

	RabinKarp(T, P, 27, 131071);

	finish = clock(); //����ð� �缳��

	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\n Rabin-Karp �˰����� ����ð� : " << duration << "��" << endl;
	cout << "--------------------------------------------------\n\n" << endl;
	//Rabin Karp �˰��� �Լ��� �����ϰ� ������ ��ġ�� ����� ��, �ҿ�ð��� ����Ͽ� ���
}