#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct 사용자 {
    string 아이디;
    string 비밀번호;
};

struct 영화 {
    string 제목;
    string 감독;
    string 장르;
    string 상영시간;

    영화(string _제목, string _감독, string _장르, string _상영시간)
        : 제목(_제목), 감독(_감독), 장르(_장르), 상영시간(_상영시간) {}
};

struct 예약 {
    영화 영화정보;
    string 좌석;

    예약(영화 _영화정보, string _좌석)
        : 영화정보(_영화정보), 좌석(_좌석) {}
};

int main() {
    vector<사용자> 사용자목록;
    vector<영화> 영화목록;
    vector<예약> 예약목록;
    사용자* 현재사용자 = nullptr;

    while (true) {
        cout << "====== 영화 관리 프로그램 ======" << endl;
        cout << "1. 회원가입" << endl;
        cout << "2. 로그인" << endl;
        cout << "3. 관리자 모드" << endl;
        cout << "4. 종료" << endl;
        cout << "===============================" << endl;
        cout << "메뉴를 선택하세요: ";

        int 선택;
        cin >> 선택;

        if (선택 == 1) {
            // 회원가입
            string 아이디, 비밀번호;
            cout << "사용할 아이디를 입력하세요: ";
            cin >> 아이디;
            cout << "사용할 비밀번호를 입력하세요: ";
            cin >> 비밀번호;

            사용자 newUser;
            newUser.아이디 = 아이디;
            newUser.비밀번호 = 비밀번호;
            사용자목록.push_back(newUser);
            cout << "회원가입이 완료되었습니다." << endl;
            cout << endl;
        }

        else if (선택 == 2) {
            // 로그인
            string 아이디, 비밀번호;
            cout << "아이디를 입력하세요: ";
            cin >> 아이디;
            cout << "비밀번호를 입력하세요: ";
            cin >> 비밀번호;

            사용자* 현재사용자 = nullptr;
            for (auto& 사용자 : 사용자목록) {
                if (사용자.아이디 == 아이디 && 사용자.비밀번호 == 비밀번호) {
                    현재사용자 = &사용자;
                    break;
                }
            }

            if (현재사용자 != nullptr) {
                cout << "로그인되었습니다." << endl;
                cout << endl;

                while (true) {
                    cout << "====== 영화 관리 프로그램 메뉴 ======" << endl;
                    cout << "1. 상영 중인 영화 목록" << endl;
                    cout << "2. 영화 티켓 예약" << endl;
                    cout << "3. 예약 목록 조회" << endl;
                    cout << "4. 예약 취소" << endl;
                    cout << "5. 로그아웃" << endl;
                    cout << "=================================" << endl;
                    cout << "메뉴를 선택하세요: ";

                    int 선택;
                    cin >> 선택;

                    if (선택 == 1) {
                        // 상영 중인 영화 목록
                        cout << "\n=== 상영 중인 영화 목록 ===" << endl;
                        for (const auto& 영화 : 영화목록) {
                            cout << "제목: " << 영화.제목 << endl;
                            cout << "감독: " << 영화.감독 << endl;
                            cout << "장르: " << 영화.장르 << endl;
                            cout << "상영 시간: " << 영화.상영시간 << endl;
                            cout << "===========================" << endl;
                        }
                        cout << endl;
                    }
                    else if (선택 == 2) {
                        // 영화 티켓 예약
                        string 제목, 좌석;
                        cout << "\n예약할 영화 제목을 입력하세요: ";
                        cin.ignore();
                        getline(cin, 제목);
                        cout << "좌석을 선택하세요: ";

                        //좌석 배치도 출력
                        cout << "\n========================= 좌석 배치도 =========================" << endl;
                        cout << "\n                            screen                             " << endl;
                        int 좌석번호 = 1;
                        for (int i = 1; i <= 10; ++i) {
                            for (int j = 1; j <= 10; ++j) {
                                bool 예약됨 = false;
                                for (const auto& 예약 : 예약목록) {
                                    if (예약.좌석 == to_string(좌석번호)) {
                                        예약됨 = true;
                                        break;
                                    }
                                }
                                if (예약됨) {
                                    cout << "[" << 좌석번호 << "](X) ";
                                }
                                else {
                                    cout << "[" << 좌석번호 << "]( ) ";
                                }
                                좌석번호++;
                            }
                            cout << endl;
                        }
                        getline(cin, 좌석);

                        // 중복 예약 확인
                        bool 중복예약 = false;
                        for (const auto& 예약 : 예약목록) {
                            if (예약.좌석 == 좌석) {
                                중복예약 = true;
                                break;
                            }
                        }

                        if (중복예약) {
                            cout << "이미 예약된 좌석입니다.\n" << endl;
                        }
                        else {
                            // 예약 생성 및 예약 목록에 추가하는 코드
                            예약 예약(영화(제목, "", "", ""), 좌석);
                            예약목록.push_back(예약);
                            cout << "예약이 완료되었습니다." << endl;
                        }
                    }

                    else if (선택 == 3) {
                        // 예약 목록 조회
                        cout << "\n=== 예약 목록 ===" << endl;
                        for (const auto& 예약 : 예약목록) {
                            cout << "영화 제목: " << 예약.영화정보.제목 << endl;
                            cout << "상영 시간: " << 예약.영화정보.상영시간 << endl;
                            cout << "좌석: " << 예약.좌석 << endl;
                            cout << "================" << endl;
                        }
                        cout << endl;
                    }
                    else if (선택 == 4) {
                        // 예약 취소
                        string 제목, 좌석;
                        cout << "\n예약 취소할 영화 제목을 입력하세요: ";
                        cin.ignore();
                        getline(cin, 제목);
                        cout << "취소할 좌석을 입력하세요: ";
                        getline(cin, 좌석);
                        bool 예약존재 = false;
                        for (auto it = 예약목록.begin(); it != 예약목록.end(); ++it) {
                            if (it->영화정보.제목 == 제목 && it->좌석 == 좌석) {
                                예약목록.erase(it);
                                예약존재 = true;
                                break;
                            }
                        }

                        if (예약존재) {
                            cout << "예약이 취소되었습니다." << endl;
                        }
                        else {
                            cout << "예약을 찾을 수 없습니다." << endl;
                        }
                        cout << endl;
                    }
                    else if (선택 == 5) {
                        // 로그아웃
                        현재사용자 = nullptr;
                        cout << "로그아웃되었습니다." << endl;
                        cout << endl;
                        break;
                    }
                    else {
                        cout << "잘못된 선택입니다." << endl;
                        cout << endl;
                    }
                }
            }
            else {
                cout << "아이디 또는 비밀번호가 잘못되었습니다." << endl;
                cout << endl;
            }
        }

        else if (선택 == 3) {
            //관리자 모드 로그인
            string username, password;

            // 사전에 정의된 아이디와 비밀번호
            string SuperUsername = "admin";
            string SuperPassword = "swing";

            // 아이디 입력 받기
            cout << "아이디: ";
            cin >> username;

            // 비밀번호 입력 받기
            cout << "비밀번호: ";
            cin >> password;

            while (true) {

                // 입력된 아이디와 비밀번호가 사전에 정의된 값과 일치하는지 확인
                if (username == SuperUsername && password == SuperPassword) {
                    // 관리자 모드
                    cout << "====== 관리자 모드 ======" << endl;
                    cout << "1. 영화 목록 추가" << endl;
                    cout << "2. 영화 삭제" << endl;
                    cout << "3. 예매 현황 확인" << endl;
                    cout << "4. 뒤로 가기" << endl;
                    cout << "=========================" << endl;
                    cout << "메뉴를 선택하세요: ";

                    int 관리자선택;
                    cin >> 관리자선택;

                    if (관리자선택 == 1) {
                        // 영화 목록 추가
                        string 제목, 감독, 장르, 상영시간;
                        cin.ignore();
                        cout << "\n추가할 영화 정보를 입력하세요" << endl;
                        cout << "제목을 입력하세요: ";
                        getline(cin, 제목);
                        cout << "감독을 입력하세요: ";
                        getline(cin, 감독);
                        cout << "장르를 입력하세요: ";
                        getline(cin, 장르);
                        cout << "상영 시간을 입력하세요: ";
                        getline(cin, 상영시간);

                        영화 추가영화(제목, 감독, 장르, 상영시간);
                        영화목록.push_back(추가영화);

                        cout << "영화가 추가되었습니다." << endl;
                        cout << endl;
                    }
                    else if (관리자선택 == 2) {
                        // 영화 삭제
                        string 제목;
                        cin.ignore();
                        cout << "\n삭제할 영화 제목을 입력하세요: ";
                        getline(cin, 제목);
                        bool 영화존재 = false;
                        for (auto it = 영화목록.begin(); it != 영화목록.end(); ++it) {
                            if (it->제목 == 제목) {
                                영화목록.erase(it);
                                영화존재 = true;
                                break;
                            }
                        }

                        if (영화존재) {
                            cout << "영화가 삭제되었습니다." << endl;
                        }
                        else {
                            cout << "영화를 찾을 수 없습니다." << endl;
                        }
                        cout << endl;
                    }
                    else if (관리자선택 == 3) {
                        // 예매 현황 확인
                        cout << "\n=== 예매 현황 ===" << endl;
                        for (const auto& 예약 : 예약목록) {
                            cout << "영화 제목: " << 예약.영화정보.제목 << endl;
                            cout << "상영 시간: " << 예약.영화정보.상영시간 << endl;
                            cout << "좌석: " << 예약.좌석 << endl;
                            cout << "================" << endl;
                        }
                        cout << endl;
                    }
                    else if (관리자선택 == 4) {
                        // 다시 메인 메뉴 창으로 돌아가기
                        break;
                    }
                    else {
                        cout << "잘못된 선택입니다." << endl;
                        cout << endl;
                    }
                }
            }
        }

        else if (선택 == 4) {
            // 종료
            cout << "프로그램을 종료합니다." << endl;
            break;
        }
        else {
            cout << "잘못된 선택입니다." << endl;
            cout << endl;
        }
    }

    return 0;
}

//보고서 내용 중 1, 4: 함은지 님 담당 | 2, 6: 이유진 님 담당 | 3, 5, 7: 지현아 님 담당
//맡은 부분 코드를 각자 짠 후 함은지 님이 123코드 이어 붙이기, 4567 부분을 지현아 님이 이어붙이기, 발표는 이유진 님이 할 예정
//완성된 코드를 보며 세 명이 수정할 부분 의논하며 수정하고 구체화하였음. 보고서는 돌아가면서 작성.
