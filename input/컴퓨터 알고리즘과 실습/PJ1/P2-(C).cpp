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
	outputFile.open("output.txt"); //output.txt ������ ���

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
// �ľ�

// n = 100000, pattern = "ACCGTAT" �� ��
int main() {
	int n = 100000; //������ ã�� ���ڿ��� ���� = 10��
	randomACGT(n); //10������ ���ڸ� ������ A/C/G/T �ؽ�Ʈ

	string DNA; //text�� ������ ���ڿ� DNA ����
	ifstream readFile;
	readFile.open("input.txt");
	getline(readFile, DNA); //input.txt ������ �о�� DNA�� ����
	readFile.close();

	// PJ1

	char* D = &DNA[0]; //text ���ڿ� DNA�� 1�� �迭 D�� �Է�

	string pattern = "ACCGTAT";
	char* P = &pattern[0]; //���� ���ڿ� pattern�� 1�� �迭 P�� �Է�
	int m = pattern.length(); //m�� ������ ����

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

	start = clock();
	BruteForce(D, P, n, m);
	finish = clock();

	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\n Brute-Force �˰����� ����ð� : " << duration << "��" << endl;
	cout << "--------------------------------------------------\n\n" << endl;
	//������ ����� BruteForce �Լ��� �����ϰ� �ҿ�ð��� ����Ͽ� ����� ���
}