// 2018112600 ������ : PJ1

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>
using namespace std; //����� ������ϵ� ����

void randomACGT(int n) { //�������� A/C/G/T�� �߻����� input ������ �����ϴ� �Լ�, n = ������ ����
	ofstream inputFile;
	inputFile.open("input.txt"); //input.txt ������ ����

	srand((unsigned int)time(NULL)); //�õ尪�� �ٸ��� �ֱ� ���� time ���

	for (int i = 0; i < n; i++) {
		int dna = rand() % 4; //������ �߻�����,
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
		} //������ ���� ���� A/C/G/T �߿� �ϳ��� input ���Ͽ� ���
	} //n�� �ݺ��Ѵ�
	inputFile.close(); //input.txt ������ �ݰ� �������Ѵ�
}

void RabinKarp(char T[], char P[], int d, int q) { //��Ʈ�� ��Ī �˰��� �� Rabin-Karp �˰���
	int n = strlen(T); //�ؽ�Ʈ�� ����, ������
	int m = 15; //������ ����, ������

	int h = 0;
	int t = 0;
	int D = 1; //�ؽð��� ������ ������ ���� ����

	int i;

	ofstream outputFile;
	outputFile.open("output.txt"); //output.txt ������ ����

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
				cout << "  ������ �ؽ�Ʈ�� " << s << "��°���� ��Ÿ��" << endl; //��𿡼� �߰ߵǾ������� �ܼ�â�� ����ϰ�,
				outputFile << s;
				outputFile << "\n"; //output ���Ͽ� ������ ��Ÿ�� �ؽ�Ʈ�� �ε��� ���� ������ش�
			}
		}

		if (s < n - m) {
			t = (d * (t - T[s] * D) + T[s + m]) % q;

			if (t < 0) {
				t = t + q; //���̳ʽ� �������� �ؽð� ���� ����
			}
		} //�ؽð� ���
	}

	outputFile.close(); //output.txt ������ �ݰ� �������Ѵ�
}

int main() {
	int n = 1000000; //������ ã�� ���ڿ��� ����, �迭�� ũ��
	int m = 15; //���� ���ڿ��� ����, ���� �迭�� ũ��
	randomACGT(n); //n���� ���ڸ� ������ A/C/G/T �ؽ�Ʈ

	string DNA; //�ؽ�Ʈ�� ������ ���ڿ� DNA ����
	ifstream readFile;
	readFile.open("input.txt");
	getline(readFile, DNA); //input.txt ������ �о�� DNA�� ����
	readFile.close();
	char* D = &DNA[0]; //�ؽ�Ʈ ���ڿ� DNA�� 1�� �迭 D�� �Է�

	char* P = (char*)malloc(sizeof(char) * m); //���� �迭 P�� �����Ҵ�

	srand((unsigned int)time(NULL)); //�õ尪�� �ٸ��� �ֱ� ���� time ���

	for (int i = 0; i < m; i++) {
		int RN = rand() % 4; //������ �߻�����
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
		} //������ ���� ���� A/C/G/T �߿� �ϳ��� ���
	} //m�� �ݺ��Ͽ� ���̰� m�� ������ �����

	clock_t start, finish;
	double duration = 0; //���� �ð��� ���� �ð�, ����ð��� ������ ���� ����

	cout << "\n--------------------------------------------------" << endl;
	cout << " Pattern --> ";
	for (int i = 0; i < m; i++) {
		cout << P[i]; //������ ���� �ܼ�â�� ���
	}
	cout << endl;
	cout << "--------------------------------------------------" << endl;
	cout << " n = " << n << " & m = " << m << endl; //n�� m�� ���� ���
	cout << "--------------------------------------------------" << endl;
	cout << " [ �� �ǿ��� �˰��� ]" << endl;
	cout << "\n Rabin-Karp �˰����� ��� : " << endl;

	start = clock();
	RabinKarp(D, P, 4, 131071);
	finish = clock();

	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\n Rabin-Karp �˰����� ����ð� : " << duration << "��" << endl;
	cout << "--------------------------------------------------\n\n" << endl;
	//Rabin Karp �Լ��� �����ϰ� ������ ��ġ�� ����� ��, �ҿ�ð��� ����Ͽ� ����� ���

	free(P); //�迭 P�� �����Ҵ� ����
 
}

// �ľ� PJ1