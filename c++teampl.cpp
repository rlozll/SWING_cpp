#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ����� {
    string ���̵�;
    string ��й�ȣ;
};

struct ��ȭ {
    string ����;
    string ����;
    string �帣;
    string �󿵽ð�;

    ��ȭ(string _����, string _����, string _�帣, string _�󿵽ð�)
        : ����(_����), ����(_����), �帣(_�帣), �󿵽ð�(_�󿵽ð�) {}
};

struct ���� {
    ��ȭ ��ȭ����;
    string �¼�;

    ����(��ȭ _��ȭ����, string _�¼�)
        : ��ȭ����(_��ȭ����), �¼�(_�¼�) {}
};

int main() {
    vector<�����> ����ڸ��;
    vector<��ȭ> ��ȭ���;
    vector<����> ������;
    �����* �������� = nullptr;

    while (true) {
        cout << "====== ��ȭ ���� ���α׷� ======" << endl;
        cout << "1. ȸ������" << endl;
        cout << "2. �α���" << endl;
        cout << "3. ������ ���" << endl;
        cout << "4. ����" << endl;
        cout << "===============================" << endl;
        cout << "�޴��� �����ϼ���: ";

        int ����;
        cin >> ����;

        if (���� == 1) {
            // ȸ������
            string ���̵�, ��й�ȣ;
            cout << "����� ���̵� �Է��ϼ���: ";
            cin >> ���̵�;
            cout << "����� ��й�ȣ�� �Է��ϼ���: ";
            cin >> ��й�ȣ;

            ����� newUser;
            newUser.���̵� = ���̵�;
            newUser.��й�ȣ = ��й�ȣ;
            ����ڸ��.push_back(newUser);
            cout << "ȸ�������� �Ϸ�Ǿ����ϴ�." << endl;
            cout << endl;
        }

        else if (���� == 2) {
            // �α���
            string ���̵�, ��й�ȣ;
            cout << "���̵� �Է��ϼ���: ";
            cin >> ���̵�;
            cout << "��й�ȣ�� �Է��ϼ���: ";
            cin >> ��й�ȣ;

            �����* �������� = nullptr;
            for (auto& ����� : ����ڸ��) {
                if (�����.���̵� == ���̵� && �����.��й�ȣ == ��й�ȣ) {
                    �������� = &�����;
                    break;
                }
            }

            if (�������� != nullptr) {
                cout << "�α��εǾ����ϴ�." << endl;
                cout << endl;

                while (true) {
                    cout << "====== ��ȭ ���� ���α׷� �޴� ======" << endl;
                    cout << "1. �� ���� ��ȭ ���" << endl;
                    cout << "2. ��ȭ Ƽ�� ����" << endl;
                    cout << "3. ���� ��� ��ȸ" << endl;
                    cout << "4. ���� ���" << endl;
                    cout << "5. �α׾ƿ�" << endl;
                    cout << "=================================" << endl;
                    cout << "�޴��� �����ϼ���: ";

                    int ����;
                    cin >> ����;

                    if (���� == 1) {
                        // �� ���� ��ȭ ���
                        cout << "\n=== �� ���� ��ȭ ��� ===" << endl;
                        for (const auto& ��ȭ : ��ȭ���) {
                            cout << "����: " << ��ȭ.���� << endl;
                            cout << "����: " << ��ȭ.���� << endl;
                            cout << "�帣: " << ��ȭ.�帣 << endl;
                            cout << "�� �ð�: " << ��ȭ.�󿵽ð� << endl;
                            cout << "===========================" << endl;
                        }
                        cout << endl;
                    }
                    else if (���� == 2) {
                        // ��ȭ Ƽ�� ����
                        string ����, �¼�;
                        cout << "\n������ ��ȭ ������ �Է��ϼ���: ";
                        cin.ignore();
                        getline(cin, ����);
                        cout << "�¼��� �����ϼ���: ";

                        //�¼� ��ġ�� ���
                        cout << "\n========================= �¼� ��ġ�� =========================" << endl;
                        cout << "\n                            screen                             " << endl;
                        int �¼���ȣ = 1;
                        for (int i = 1; i <= 10; ++i) {
                            for (int j = 1; j <= 10; ++j) {
                                cout << �¼���ȣ << "[ ] ";
                                �¼���ȣ++;
                            }
                            cout << endl;
                        }
                        getline(cin, �¼�);

                        // �ߺ� ���� Ȯ��
                        bool �ߺ����� = false;
                        for (const auto& ���� : ������) {
                            if (����.�¼� == �¼�) {
                                �ߺ����� = true;
                                break;
                            }
                        }

                        if (�ߺ�����) {
                            cout << "�̹� ����� �¼��Դϴ�.\n" << endl;
                        }
                        else {
                            // ���� ���� �� ���� ��Ͽ� �߰��ϴ� �ڵ�
                            ���� ����(��ȭ(����, "", "", ""), �¼�);
                            ������.push_back(����);
                            cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
                        }

                    }
                    else if (���� == 3) {
                        // ���� ��� ��ȸ
                        cout << "\n=== ���� ��� ===" << endl;
                        for (const auto& ���� : ������) {
                            cout << "��ȭ ����: " << ����.��ȭ����.���� << endl;
                            cout << "�� �ð�: " << ����.��ȭ����.�󿵽ð� << endl;
                            cout << "�¼�: " << ����.�¼� << endl;
                            cout << "================" << endl;
                        }
                        cout << endl;
                    }
                    else if (���� == 4) {
                        // ���� ���
                        string ����, �¼�;
                        cout << "\n���� ����� ��ȭ ������ �Է��ϼ���: ";
                        cin.ignore();
                        getline(cin, ����);
                        cout << "����� �¼��� �Է��ϼ���: ";
                        getline(cin, �¼�);
                        bool �������� = false;
                        for (auto it = ������.begin(); it != ������.end(); ++it) {
                            if (it->��ȭ����.���� == ���� && it->�¼� == �¼�) {
                                ������.erase(it);
                                �������� = true;
                                break;
                            }
                        }

                        if (��������) {
                            cout << "������ ��ҵǾ����ϴ�." << endl;
                        }
                        else {
                            cout << "������ ã�� �� �����ϴ�." << endl;
                        }
                        cout << endl;
                    }
                    else if (���� == 5) {
                        // �α׾ƿ�
                        �������� = nullptr;
                        cout << "�α׾ƿ��Ǿ����ϴ�." << endl;
                        cout << endl;
                        break;
                    }
                    else {
                        cout << "�߸��� �����Դϴ�." << endl;
                        cout << endl;
                    }
                }
            }
            else {
                cout << "���̵� �Ǵ� ��й�ȣ�� �߸��Ǿ����ϴ�." << endl;
                cout << endl;
            }
        }

        else if (���� == 3) {
            //������ ��� �α���
            string username, password;

            // ������ ���ǵ� ���̵�� ��й�ȣ
            string SuperUsername = "admin";
            string SuperPassword = "swing";

            // ���̵� �Է� �ޱ�
            cout << "���̵�: ";
            cin >> username;

            // ��й�ȣ �Է� �ޱ�
            cout << "��й�ȣ: ";
            cin >> password;

            while (true) {

                // �Էµ� ���̵�� ��й�ȣ�� ������ ���ǵ� ���� ��ġ�ϴ��� Ȯ��
                if (username == SuperUsername && password == SuperPassword) {
                    // ������ ���
                    cout << "====== ������ ��� ======" << endl;
                    cout << "1. ��ȭ ��� �߰�" << endl;
                    cout << "2. ��ȭ ����" << endl;
                    cout << "3. ���� ��Ȳ Ȯ��" << endl;
                    cout << "4. �ڷ� ����" << endl;
                    cout << "=========================" << endl;
                    cout << "�޴��� �����ϼ���: ";

                    int �����ڼ���;
                    cin >> �����ڼ���;

                    if (�����ڼ��� == 1) {
                        // ��ȭ ��� �߰�
                        string ����, ����, �帣, �󿵽ð�;
                        cin.ignore();
                        cout << "\n�߰��� ��ȭ ������ �Է��ϼ���" << endl;
                        cout << "������ �Է��ϼ���: ";
                        getline(cin, ����);
                        cout << "������ �Է��ϼ���: ";
                        getline(cin, ����);
                        cout << "�帣�� �Է��ϼ���: ";
                        getline(cin, �帣);
                        cout << "�� �ð��� �Է��ϼ���: ";
                        getline(cin, �󿵽ð�);

                        ��ȭ �߰���ȭ(����, ����, �帣, �󿵽ð�);
                        ��ȭ���.push_back(�߰���ȭ);

                        cout << "��ȭ�� �߰��Ǿ����ϴ�." << endl;
                        cout << endl;
                    }
                    else if (�����ڼ��� == 2) {
                        // ��ȭ ����
                        string ����;
                        cin.ignore();
                        cout << "\n������ ��ȭ ������ �Է��ϼ���: ";
                        getline(cin, ����);
                        bool ��ȭ���� = false;
                        for (auto it = ��ȭ���.begin(); it != ��ȭ���.end(); ++it) {
                            if (it->���� == ����) {
                                ��ȭ���.erase(it);
                                ��ȭ���� = true;
                                break;
                            }
                        }

                        if (��ȭ����) {
                            cout << "��ȭ�� �����Ǿ����ϴ�." << endl;
                        }
                        else {
                            cout << "��ȭ�� ã�� �� �����ϴ�." << endl;
                        }
                        cout << endl;
                    }
                    else if (�����ڼ��� == 3) {
                        // ���� ��Ȳ Ȯ��
                        cout << "\n=== ���� ��Ȳ ===" << endl;
                        for (const auto& ���� : ������) {
                            cout << "��ȭ ����: " << ����.��ȭ����.���� << endl;
                            cout << "�� �ð�: " << ����.��ȭ����.�󿵽ð� << endl;
                            cout << "�¼�: " << ����.�¼� << endl;
                            cout << "================" << endl;
                        }
                        cout << endl;
                    }
                    else if (�����ڼ��� == 4) {
                        // �ٽ� ���� �޴� â���� ���ư���
                        break;
                    }
                    else {
                        cout << "�߸��� �����Դϴ�." << endl;
                        cout << endl;
                    }
                }
            }
        }

        else if (���� == 4) {
            // ����
            cout << "���α׷��� �����մϴ�." << endl;
            break;
        }
        else {
            cout << "�߸��� �����Դϴ�." << endl;
            cout << endl;
        }
    }

    return 0;
}

//���� ���� �� 1, 4: ������ �� ��� | 2, 6: ������ �� ��� | 3, 5, 7: ������ �� ���
//���� �κ� �ڵ带 ���� § �� ������ ���� 123�ڵ� �̾� ���̱�, 4567 �κ��� ������ ���� �̾���̱�, ��ǥ�� ������ ���� �� ����
//�ϼ��� �ڵ带 ���� �� ���� ������ �κ� �ǳ��ϸ� �����ϰ� ��üȭ�Ͽ���. ������ ���ư��鼭 �ۼ�.