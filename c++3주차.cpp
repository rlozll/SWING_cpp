#include <iostream>
#include <string>
using namespace std;

int main() {
    int choice;
    string id, pw;

    while (true) {
        cout << "********** swing ���� **********" << endl;
        cout << "1. ȸ������" << endl;
        cout << "2. �α���" << endl;
        cout << "��ȣ�� �Է��ϼ��� >> ";
        cin >> choice;

        if (choice == 1) {
            string name;
            cout << "�̸�: ";
            cin >> name;

            cout << "���̵�: ";
            cin >> id;

            cout << "��й�ȣ: ";
            cin >> pw;

            cout << "==== ȸ������ ���� ====" << endl;
            break;
        }
        else if (choice == 2) {
            cout << "���̵�: ";
            cin >> id;

            cout << "��й�ȣ: ";
            cin >> pw;

            if (id == "swing" && pw == "31") {
                cout << "==== �α��� ���� ====" << endl;
                cout <<  "ȯ���մϴ�." << endl;
                break;
            }
            else {
                cout << "���̵� Ȥ�� ��й�ȣ�� Ʋ�Ƚ��ϴ�." << endl;
            }
        }
        else {
            cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl;
        }
    }

    return 0;
}
