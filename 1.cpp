#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <ctime>
#include <io.h> //파일 구조체 헤더
#include <experimental/filesystem>
#include <vector>

namespace fs = std::experimental::filesystem::v1;
using namespace std;

vector<pair<string, string>> t_dList;
vector<pair<string, string>> m_dList;
vector<vector<string>> fList;
string abbreviation[30][3] = { "공개SW 프로젝트", "공개SW프로젝트", "공소",
	"인간 컴퓨터 상호작용 시스템", "인간컴퓨터상호작용시스템", "인컴",
	"컴퓨터 그래픽스 입문", "컴퓨터그래픽스입문", "컴그",
	"컴퓨터 알고리즘과 실습", "컴퓨터알고리즘과실습", "컴알",
	"데이터베이스시스템", "", "데베시",
	"형식언어", "", "형언",
	"운영체제", "", "운체",
	"소프트웨어 공학 개론", "소프트웨어공학개론", "소공개",
	"데이터분석 및 실습", "데이터분석및실습", "데분실",
	"데이터 통신 입문", "데이터통신입문", "데통입",
	"데이터베이스 프로그래밍", "데이터베이스프로그래밍", "데베프",
	"컴퓨터 구조", "컴퓨터구조", "컴구조",
	"컴파일러 구성", "컴파일러구성", "컴구성",
	"임베디드 소프트웨어 입문", "임베디드소프트웨어입문", "임베디드",
	"인공지능", "", "인지",
	"컴퓨터공학 종합설계1", "컴퓨터공학종합설계1", "종설1",
	"컴퓨터공학 종합설계2", "컴퓨터공학종합설계2", "종설2",
	"객체지향 설계와 패턴", "객체지향설계와패턴", "객체설계",
	"S/W 품질관리 및 테스팅", "S/W품질관리및테스팅", "테스팅",
	"컴퓨터 보안", "컴퓨터보안", "컴보",
	"동시성 프로그래밍", "동시성프로그래밍", "동시성",
	"컴퓨터 네트워킹", "컴퓨터네트워킹", "컴네",
	"블록체인 보안", "블록체인보안", "블록체인",
	"머신러닝", "", "머신",
	"양자 컴퓨팅", "양자컴퓨팅", "양컴",
	"암호학과 네트워크 보안", "암호학과네트워크보안", "암호학",
	"빅데이터 분석", "빅데이터분석", "빅데이터"
	"개별연구1", "", "개별1",
	"개별연구2", "", "개별2",
	"개별연구3", "", "개별3" }; //3, 4학년 전공심화과목 대상 약어 리스트

int BruteForce(string text, string pattern) {
	char* T = &text[0];
	char* P = &pattern[0];
	int n = text.length();
	int m = pattern.length();
	int i, j;
	for (i = 0; i <= n - m; i++) {
		for (j = 0; j < m; j++) {
			if (P[j] != T[i + j]) {
				break;
			}
		}
		if (j == m) {
			return i + 1;
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
			if (BruteForce(C, P) != 0)
				return 1;
			else
				return 0;
		}

		if (BruteForce(C, P) != 0 || BruteForce(C, P1) != 0) {
			fclose(fp);
			free(C);
			return 1;
		}
		else if (pattern2 != "" && BruteForce(C, P2) != 0) {
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
		if (BruteForce(C, P) != 0) {
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

void pushD(string path, string pPath, string rPath) {
	string dName;
	dName = path.substr(3);
	dName = dName.substr(BruteForce(dName, "\\"));
	pair<string, string> directory = make_pair(dName, path);

	if (checkDirectory(pPath, rPath)) {
		t_dList.push_back(directory);
	}
	else {
		dName = dName.substr(BruteForce(dName, "\\"));
		pair<string, string> directory = make_pair(dName, path);
		m_dList.push_back(directory);
	}
}

int checkForD(string path) {
	int l = path.length();
	string fForm = path.substr(l - 6, l);

	if (BruteForce(fForm, ".txt") != 0)
		return 1;
	else if (BruteForce(fForm, ".java") != 0)
		return 1;
	else if (BruteForce(fForm, ".cpp") != 0)
		return 1;
	else if (BruteForce(fForm, ".c") != 0)
		return 1;
	else if (BruteForce(fForm, ".py") != 0)
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
			return 1; //위치 유지
		else
			return 2; //파일이동
	}
	else {
		if (checkT == 1 && checkM == 1)
			return 1; //유지
		else
			return 2; //파일이동
	}
}

int checkExistenceT(int i, int j) {
	for (int k = 0; k < t_dList.size(); k++) {
		if (t_dList[k].first != "분류 X" && checkFile(fList[i][0] + "\\" + fList[i][j], t_dList[k].first, 1)) {
			return k;
		}
	}
	return -1;
}

int checkExistenceM(int i, int j) {
	fs::path oPath = fList[i][0] + "\\" + fList[i][j];
	for (int k = 0; k < m_dList.size(); k++) {
		if (checkFile(oPath.string(), m_dList[k].first, 0) == 1) {
			return k;
		}
	}
	return -1;
}

void moveLocation(int i, int j, string rPath) {
	int tLocation = checkExistenceT(i, j);
	int mLocation = checkExistenceM(i, j);

	fs::path oPath = fList[i][0] + "\\" + fList[i][j];
	fs::path nPath;

	if (tLocation >= 0 && mLocation >= 0) {
		string sName = m_dList[mLocation].second.substr(rPath.length() + 1);
		int point = sName.find('\\');
		sName = sName.substr(0, point);

		if (checkFile(oPath.string(), m_dList[mLocation].first, 0) == 1 && checkFile(oPath.string(), sName, 1) == 1) {
			nPath = m_dList[mLocation].second + "\\" + sName + "_" + fList[i][j]; //과목명이랑 그 미들디렉토리로 이동
			cout << oPath << endl;
			cout << nPath << endl;
			rename(oPath, nPath);
			return;
		}

		fs::path nPath = t_dList[tLocation].second + "\\" + t_dList[tLocation].first + "_" + fList[i][j];
		cout << oPath << endl;
		cout << nPath << endl;
		rename(oPath, nPath);
	}
	else if (tLocation >= 0) {
		fs::path nPath = t_dList[tLocation].second + "\\" + t_dList[tLocation].first + "_" + fList[i][j];
		cout << oPath << endl;
		cout << nPath << endl;
		rename(oPath, nPath);
	}
	else if (mLocation >= 0) {
		fs::path nPath = "C:\\input\\분류 X\\" + fList[i][j];
		//fs::path nPath = fs::current_path() += "./분류 X./" + fList[i][j];
		cout << oPath << endl;
		cout << nPath << endl;
		rename(oPath, nPath);
	}
	else {
		fs::path nPath = "C:\\input\\분류 X\\" + fList[i][j];
		//fs::path nPath = fs::current_path() += "./분류 X./" + fList[i][j];
		cout << oPath << endl;
		cout << nPath << endl;
		rename(oPath, nPath);
	}
}

void fileSorting(int i, int j, string rPath) {
	string mName = fList[i][0].substr(rPath.length() + 1); //중분류 폴더 이름
	int point = mName.find('\\');
	if (point >= 0)
		mName = mName.substr(point + 1);
	else
		mName = "";
	string sName = fList[i][0].substr(rPath.length() + 1, point); //과목명

	int caseNum = checkCases(i, j, rPath, sName, mName);

	if (caseNum == 1) {
		fs::path oPath = fList[i][0] + "\\" + fList[i][j];
		fs::path nPath = fList[i][0] + "\\" + sName + "_" + fList[i][j];
		rename(oPath, nPath);
	}
	else if (caseNum == 2) {
		moveLocation(i, j, rPath);
	}
}

void rootSorting(int tdSize, int mdSize, string rPath) {
	int i = tdSize + mdSize;
	for (int j = 1; j < fList[i].size(); j++) {
		moveLocation(i, j, rPath);
	}
}

int main() {

	fs::path cPath = fs::current_path();

	vector<string> file, root, temp;
	string fForm, dName, rPath;

	//rPath = fs::current_path().string();
	rPath = "C:\\input";
	root.push_back(rPath);

	for (auto& p : fs::recursive_directory_iterator(rPath)) {

		string route = p.path().string();
		string pPath = p.path().parent_path().string();
		string ppPath = p.path().parent_path().parent_path().string();

		if (checkForD(route)) {
			string fName = route.substr(pPath.length() + 1);
			if (rPath == pPath) {
				root.push_back(fName);
			}
			else if (rPath == ppPath) {
				if (temp.empty()) {
					temp.push_back(pPath);
				}
				temp.push_back(fName);
			}
			else {
				if (file.empty()) {
					file.push_back(pPath);
				}
				file.push_back(fName);
			}
		}
		else {
			if (t_dList.size() != 0 || m_dList.size() != 0) {
				if (rPath == pPath) {
					fList.push_back(temp);
					temp.clear();
				}
				else if (rPath != pPath) {
					fList.push_back(file);
					file.clear();
				}
			}
			pushD(route, pPath, rPath);
		}
	}
	fList.push_back(temp);
	fList.push_back(file);

	pair<string, string> directory = make_pair("root", rPath);
	t_dList.push_back(directory);
	fList.push_back(root);

	string oPath, nPath;
	int k = 0;
	fs::create_directory("C:\\input\\분류 X");
	//fs::create_directory(cPath / "분류 X");

	int tdSize = t_dList.size();
	int mdSize = m_dList.size();

	for (int i = 1; i < tdSize + mdSize - 1; i++) {
		for (int j = 1; j < fList[i].size(); j++) {
			fileSorting(i, j, rPath);
			cout << endl;
		}
	}
	rootSorting(tdSize, mdSize, rPath);
}