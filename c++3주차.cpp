#include <iostream>
#include <string>
using namespace std;

int main() {
    int choice;
    string id, pw;

    while (true) {
        cout << "********** swing 은행 **********" << endl;
        cout << "1. 회원가입" << endl;
        cout << "2. 로그인" << endl;
        cout << "번호를 입력하세요 >> ";
        cin >> choice;

        if (choice == 1) {
            string name;
            cout << "이름: ";
            cin >> name;

            cout << "아이디: ";
            cin >> id;

            cout << "비밀번호: ";
            cin >> pw;

            cout << "==== 회원가입 성공 ====" << endl;
            break;
        }
        else if (choice == 2) {
            cout << "아이디: ";
            cin >> id;

            cout << "비밀번호: ";
            cin >> pw;

            if (id == "swing" && pw == "31") {
                cout << "==== 로그인 성공 ====" << endl;
                cout <<  "환영합니다." << endl;
                break;
            }
            else {
                cout << "아이디 혹은 비밀번호가 틀렸습니다." << endl;
            }
        }
        else {
            cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
        }
    }

    return 0;
}
