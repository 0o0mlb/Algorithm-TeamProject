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
		int RN = rand() % 4; //������ �߻�����,
		if (RN == 0) {
			inputFile << "A";
		}
		else if (RN == 1) {
			inputFile << "C";
		}
		else if (RN == 2) {
			inputFile << "G";
		}
		else {
			inputFile << "T";
		} //������ ���� ���� A/C/G/T �߿� �ϳ��� input ���Ͽ� ���
	} //n�� �ݺ��Ѵ�
	inputFile.close(); //input.txt ������ �ݰ� �������Ѵ�
}

void BruteForce(char T[], char P[], int n, int m) { //��Ʈ�� ��Ī �˰��� �� ������ ���
	ofstream outputFile;
	outputFile.open("output.txt"); //output.txt ������ ����

	int i, j;
	for (i = 0; i <= n - m; i++) {
		for (j = 0; j < m; j++) {
			if (P[j] != T[i + j]) {
				break;
			}
		} //���� Ž������ �ؽ�Ʈ�� ���� Ž���Ͽ� ������ ã�´�
		if (j == m) { //�ؽ�Ʈ���� ������ �߰ߵǸ�
			cout << "  ������ �ؽ�Ʈ�� " << i << "��°���� ��Ÿ��" << endl; //��𿡼� �߰ߵǾ������� �ܼ�â�� ����ϰ�,
			outputFile << i;
			outputFile << "\n"; //output ���Ͽ� ������ ��Ÿ�� �ؽ�Ʈ�� �ε��� ���� ������ش�
		}
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

	srand((unsigned int)time(NULL)); //�õ尪�� �ٸ��� �ֱ� ���� time ���

	char* P = (char*)malloc(sizeof(char) * m); //���� �迭 P�� �����Ҵ�
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
	cout << " [ ������ ��� ]" << endl;
	cout << "\n Brute-Force �˰����� ��� : " << endl;

	// �ľ� PJ1

	start = clock();
	BruteForce(D, P, n, m);
	finish = clock();

	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\n Brute-Force �˰����� ����ð� : " << duration << "��" << endl;
	cout << "--------------------------------------------------\n\n" << endl;
	//������ ����� BruteForce �Լ��� �����ϰ� �ҿ�ð��� ����Ͽ� ����� ���

	free(P); //�迭 P�� �����Ҵ� ����
}