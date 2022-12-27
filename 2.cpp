#define _CRT_SECURE_NO_WARNINGS
#define  _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#pragma once
#include <iostream>
#include <ctime>
#include <chrono>
#include <io.h> //���� ����ü ���
#include <experimental/filesystem>
#include <vector>

namespace fs = std::experimental::filesystem::v1;
using namespace std;
using namespace chrono;

string t_dList[30][2];
string m_dList[150][2];
string fList[180][100];
string abbreviation[30][3] = { "����SW ������Ʈ", "����SW������Ʈ", "����",
	"�ΰ� ��ǻ�� ��ȣ�ۿ� �ý���", "�ΰ���ǻ�ͻ�ȣ�ۿ�ý���", "����",
	"��ǻ�� �׷��Ƚ� �Թ�", "��ǻ�ͱ׷��Ƚ��Թ�", "�ı�",
	"��ǻ�� �˰���� �ǽ�", "��ǻ�;˰�����ǽ�", "�ľ�",
	"�����ͺ��̽��ý���", "", "������",
	"���ľ��", "", "����",
	"�ü��", "", "��ü",
	"����Ʈ���� ���� ����", "����Ʈ������а���", "�Ұ���",
	"�����ͺм� �� �ǽ�", "�����ͺм��׽ǽ�", "���н�",
	"������ ��� �Թ�", "����������Թ�", "������",
	"�����ͺ��̽� ���α׷���", "�����ͺ��̽����α׷���", "������",
	"��ǻ�� ����", "��ǻ�ͱ���", "�ı���",
	"�����Ϸ� ����", "�����Ϸ�����", "�ı���",
	"�Ӻ���� ����Ʈ���� �Թ�", "�Ӻ�������Ʈ�����Թ�", "�Ӻ����",
	"�ΰ�����", "", "����",
	"��ǻ�Ͱ��� ���ռ���1", "��ǻ�Ͱ������ռ���1", "����1",
	"��ǻ�Ͱ��� ���ռ���2", "��ǻ�Ͱ������ռ���2", "����2",
	"��ü���� ����� ����", "��ü���⼳�������", "��ü����",
	"S/W ǰ������ �� �׽���", "S/Wǰ���������׽���", "�׽���",
	"��ǻ�� ����", "��ǻ�ͺ���", "�ĺ�",
	"���ü� ���α׷���", "���ü����α׷���", "���ü�",
	"��ǻ�� ��Ʈ��ŷ", "��ǻ�ͳ�Ʈ��ŷ", "�ĳ�",
	"���ü�� ����", "���ü�κ���", "���ü��",
	"�ӽŷ���", "", "�ӽ�",
	"���� ��ǻ��", "������ǻ��", "����",
	"��ȣ�а� ��Ʈ��ũ ����", "��ȣ�а���Ʈ��ũ����", "��ȣ��",
	"������ �м�", "�����ͺм�", "������"
	"��������1", "", "����1",
	"��������2", "", "����2",
	"��������3", "", "����3" }; //3, 4�г� ������ȭ���� ��� ��� ����Ʈ

int RabinKarp(string text, string pattern) { //Robin-Karp
	char* T = &text[0];
	char* P = &pattern[0];

	int n = strlen(T); //�ؽ�Ʈ�� ����, ������
	int m = strlen(P); //������ ����, ������
	int Thash = 0;
	int Phash = 0;
	int power = 1; //���� ��

	for (int i = 0; i <= n - m; i++) {
		if (i == 0) {
			for (int j = 0; j < m; j++) {
				Thash += T[m - 1 - j] * power;
				Phash += P[m - 1 - j] * power;
				if (j < m - 1) {
					power *= 6;
				}
			}
		}
		else {
			Thash = 6 * (Thash - T[i - 1] * power) + T[m - 1 + i];
		}
		if (Thash == Phash) {
			bool coincidence = false;
			for (int j = 0; j < m; j++) {
				if (T[i + j] != P[j]) {
					coincidence = true;
					break;
				}
			}
			if (!coincidence) {
				return i + 1;
			}
		}
	}
	return 0;
}

int checkFile(string filePath, string pattern, int c) {
	char* C;
	int size, count;

	char* name = &filePath[0];
	FILE* fp = fopen(name, "r");

	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	C = (char*)malloc(size + 1);
	memset(C, 0, size + 1);

	fseek(fp, 0, SEEK_SET);
	count = fread(C, size, 1, fp);

	if (c == 1) {
		string pattern1, pattern2;
		for (int i = 0; i < 30; i++) {
			if (abbreviation[i][0] == pattern) {
				pattern1 = abbreviation[i][2];
				pattern2 = abbreviation[i][1];
			}
		}

		char* P = &pattern[0];
		char* P1 = &pattern1[0];
		char* P2 = &pattern2[0];


		if (pattern == "root") {
			if (RabinKarp(C, P) != 0)
				return 1;
			else
				return 0;
		}

		if (RabinKarp(C, P) != 0 || RabinKarp(C, P1) != 0) {
			fclose(fp);
			free(C);
			return 1;
		}
		else if (pattern2 != "" && RabinKarp(C, P2) != 0) {
			fclose(fp);
			free(C);
			return 1;
		}
		else {
			fclose(fp);
			free(C);
			return 0;
		}
	}
	else {
		char* P = &pattern[0];
		if (RabinKarp(C, P) != 0) {
			fclose(fp);
			free(C);
			return 1;
		}
		else {
			fclose(fp);
			free(C);
			return 0;
		}
	}
}

int checkDirectory(string pPath, string root) {
	if (pPath == root)
		return 1;
	else
		return 0;
}

int pushD(string path, string pPath, string rPath, int ti, int mi) {
	string dName;
	dName = path.substr(3);
	dName = dName.substr(RabinKarp(dName, "\\"));

	if (checkDirectory(pPath, rPath) && path != rPath) {
		t_dList[ti][0] = dName;
		t_dList[ti][1] = path;
		return 1;
	}
	else {
		dName = dName.substr(RabinKarp(dName, "\\"));
		m_dList[mi][0] = dName;
		m_dList[mi][1] = path;
		return 2;
	}
}

int checkForD(string path) {
	int l = path.length();
	string fForm = path.substr(l - 6, l);

	if (RabinKarp(fForm, ".txt") != 0)
		return 1;
	else if (RabinKarp(fForm, ".java") != 0)
		return 1;
	else if (RabinKarp(fForm, ".cpp") != 0)
		return 1;
	else if (RabinKarp(fForm, ".c") != 0)
		return 1;
	else if (RabinKarp(fForm, ".py") != 0)
		return 1;
	else
		return 0;
}

int checkCases(int i, int j, string rPath, string sName, string mName) {

	string fPath = fList[i][0] + "./" + fList[i][j];

	int checkT = checkFile(fPath, sName, 1);
	int checkM = checkFile(fPath, mName, 0);

	if (mName == "") {
		if (checkT == 1)
			return 1; //��ġ ����
		else
			return 2; //�����̵�
	}
	else {
		if (checkT == 1 && checkM == 1)
			return 1; //����
		else
			return 2; //�����̵�
	}
}

int checkExistenceT(int i, int j) {
	for (int k = 0; k < 30; k++) {
		if ((t_dList[k][0] != "") && checkFile(fList[i][0] + "\\" + fList[i][j], t_dList[k][0], 1)) {
			return k;
		}
	}
	return -1;
}

int checkExistenceM(int i, int j) {
	fs::path oPath = fList[i][0] + "\\" + fList[i][j];
	for (int k = 0; k < 150; k++) {
		if ((m_dList[k][0] != "") && checkFile(oPath.string(), m_dList[k][0], 0) == 1) {
			return k;
		}
	}
	return -1;
}

void moveLocation(int i, int j, string rPath) {
	fs::path oPath = fList[i][0] + "\\" + fList[i][j];
	fs::path nPath;

	if (checkExistenceT(i, j) >= 0 && checkExistenceM(i, j) >= 0) {
		string sName = m_dList[checkExistenceM(i, j)][1].substr(rPath.length() + 1);
		int point = sName.find('\\');
		sName = sName.substr(0, point);

		if (checkFile(oPath.string(), m_dList[checkExistenceM(i, j)][0], 0) == 1 && checkFile(oPath.string(), sName, 1) == 1) {
			nPath = m_dList[checkExistenceM(i, j)][1] + "\\" + sName + "_" + fList[i][j]; //������̶� �� �̵���丮�� �̵�
			cout << oPath << endl;
			cout << nPath << endl;
			rename(oPath, nPath);
			return;
		}

		fs::path nPath = t_dList[checkExistenceT(i, j)][1] + "\\" + t_dList[checkExistenceT(i, j)][0] + "_" + fList[i][j];
		cout << oPath << endl;
		cout << nPath << endl;
		rename(oPath, nPath);
	}
	else if (checkExistenceT(i, j) >= 0) {
		if (t_dList[checkExistenceT(i, j)][0] == "�з� X") {
			fs::path nPath = t_dList[checkExistenceT(i, j)][1] + "\\" + fList[i][j];
			cout << oPath << endl;
			cout << nPath << endl;
		}
		else {
			fs::path nPath = t_dList[checkExistenceT(i, j)][1] + "\\" + t_dList[checkExistenceT(i, j)][0] + "_" + fList[i][j];
			cout << oPath << endl;
			cout << nPath << endl;
		}
		rename(oPath, nPath);
	}
	else if (checkExistenceM(i, j) >= 0) {
		fs::path nPath = "C:\\input\\�з� X\\" + fList[i][j];
		//fs::path nPath = fs::current_path() += "./�з� X./" + fList[i][j];
		cout << oPath << endl;
		cout << nPath << endl;
		rename(oPath, nPath);
	}
	else {
		fs::path nPath = "C:\\input\\�з� X\\" + fList[i][j];
		//fs::path nPath = fs::current_path() += "./�з� X./" + fList[i][j];
		cout << oPath << endl;
		cout << nPath << endl;
		rename(oPath, nPath);
	}
}

void fileSorting(int i, int j, string rPath) {
	string mName = fList[i][0].substr(rPath.length() + 1); //�ߺз� ���� �̸�
	int point = mName.find('\\');
	if (point >= 0)
		mName = mName.substr(point + 1);
	else
		mName = "";
	string sName = fList[i][0].substr(rPath.length() + 1, point); //�����

	int caseNum = checkCases(i, j, rPath, sName, mName);

	if (caseNum == 1) {
		fs::path oPath = fList[i][0] + "\\" + fList[i][j];
		fs::path nPath = fList[i][0] + "\\" + sName + "_" + fList[i][j];
		//rename(oPath, nPath);
	}
	else if (caseNum == 2) {
		moveLocation(i, j, rPath);
	}
}

void rootSorting(int ti, int mi, string rPath) {
	int i = ti + mi;
	for (int j = 1; j < 100 && fList[i][j] != ""; j++) {
		moveLocation(i, j, rPath);
	}
}

int main() {
	fs::path cPath = fs::current_path();
	string fForm, dName, rPath;

	//rPath = fs::current_path().string();
	rPath = "C:\\input";

	int ti = 0, mi = 0, fi = 0, ri = 1;
	int init = 0;

	string root[100];
	string temp[100];
	root[0] = rPath;

	for (auto& p : fs::recursive_directory_iterator(rPath)) {
		string route = p.path().string();
		string pPath = p.path().parent_path().string();
		string ppPath = p.path().parent_path().parent_path().string();

		if (checkForD(route)) {
			string fName = route.substr(pPath.length() + 1);
			if (rPath == pPath) {
				root[ri] = fName;
				ri++;
			}
			else if (rPath == ppPath) {
				if (fList[ti + mi][0] == "") {
					temp[0] = pPath;
					init++;
				}
				temp[init] = fName;
				init++;
			}
			else {
				if (fList[ti + mi][0] == "") {
					fList[ti + mi][0] = pPath;
					fi++;
				}
				fList[ti + mi][fi] = fName;
				fi++;
			}
		}
		else {
			if (t_dList[ti][0] != "" || m_dList[mi][0] != "") {
				if (rPath == pPath) {
					for (int i = 0; i < 100; i++) {
						fList[mi + ti][i] = temp[i];
					}
					ti++;
					for (int i = 0; i < 100; i++) {
						temp[i] = "";
					}
					init = 0;
				}
				else if (rPath != pPath) {
					mi++;
					fi = 0;
				}
			}
			pushD(route, pPath, rPath, ti, mi);
		}
	}
	t_dList[ti][0] = "root";
	t_dList[ti][1] = rPath;
	ti++;
	mi++;

	for (int i = 0; i < 100; i++) {
		fList[mi + ti][i] = root[i];
	}

	string oPath, nPath;
	int k = 0;
	fs::create_directory("C:\\input\\�з� X");
	//fs::create_directory(cPath / "�з� X");

	for (int i = 0; i < 180; i++) {
		for (int j = 1; j < 100; j++) {
			//fileSorting(i, j, rPath);
			//cout << endl;
		}
	}
	rootSorting(ti, mi, rPath);
}