#include <iostream>
using namespace std;

int main() {

	char name[12];

	cout << "이름: ";
	cin.getline(name, 12, '\n');

	char id[12];

	cout << "학번: ";
	cin >> id, '\n';

	cout << "반갑습니다. 함 은지님" << std::endl;
	cout << "학점 입력을 시작합니다." << std::endl;
	cout << "===============SWING 31===============" << std::endl;

	char s1, s2, s3, s4 = 0;

	cout << "C프로그래밍(3학점): ";
	cin >> s1;  //C프로그래밍 학점 입력
	cout << "컴퓨터및정보보호개론(3학점): ";
	cin >> s2;  //컴퓨터정보보호개론 학점 입력
	cout << "소프트웨어개발실무영어I(1학점): ";
	cin >> s3;   //소프트웨어개발실무영어I 학점 입력
	cout << "대학고급영어(2학점): ";
	cin >> s4;   //대학고급영어 학점 입력
	cout << "======================================" << endl << endl;
	cout << name << "(" << id << ")" << "님의 전체 학점은" << (s1 * 3 + s2 * 3 + s3 * 1 + s4 * 2) / 9.0 << "입니다." << endl;

}