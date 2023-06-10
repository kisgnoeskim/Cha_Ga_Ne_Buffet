/*
조건
- 단, 최소 2가지 이상의 자료구조를 이용해야 함.
- 1시나리오 1구조로 2가지 시나리오 구성 가능
- ‘배열스택’은 스택에 해당. 배열과 스택 두가지로 보지 않음
*/
#include <iostream>
#include <string>
#include <random>

using namespace std;
#define SIZE 10000  // 배열의 사이즈

void queuee();
void stackk();

//메인 부분 구현(성식)
int main() {
	int select;

	while (1) {
        cout << endl;
		cout << "(1) 성재의 싱글벙글 큐로 접시 치우기 (2) 성재의 두근두근 스택으로 짐 싣기 (3) 끝내기" << endl;
		cin >> select;

		if (select == 1) {
			queuee();
		}

		else if (select == 2) {
			stackk();
		}

		else if (select == 3) {
			cout << "빠빠이~";
			break;
		}

		else {
			cout << "다시 입력하삼" << endl;
			continue;
		}
	}
}

//큐 부분 구현(성재)
/*
큐(Queue)를 활용한 시나리오:
성재는 손님들에게 접시를 치워달라는 요청을 받고, 요청 받은 순서대로 접시를 치우러 가는 역할을 가진 직원입니다.

시나리오:
1. 손님들이 접시를 치워달라고 성재에게 요청을 합니다.
2. 요청을 받은 성재는 요청을 받은 순서대로 큐에 손님을 추가합니다.
   요청은 큐의 뒤에 추가되고, 큐는 "선입선출"의 원칙에 따라 관리됩니다.
3. 접시를 치워달라는 요청이 접시 치우기 대기열의 맨 앞에 오면, 성재 해당 주문을 받아 접시를 치우러 갑니다.
4. 성재가 접시를 치우면 성재는 완료된 요청을 큐에서 제거합니다.
이러한 방식으로 큐를 활용하면 주문의 도착 순서에 따라 요리가 준비되고 완료될 수 있습니다.
*/
void queuee() {
    int request_num[SIZE];
    int top_num = -1;  // 초기값 변경
    int queue_select;

    //랜덤한 숫자를 뽑기 위해 만듦
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 20);

    //여러개 뽑을라고
    while (top_num < 10) {
        int num = dist(mt);
        bool isDuplicate = false;

        // 중복된 숫자가 없을 때까지 반복
        for (int i = 0; i < top_num; i++) {  // top_num을 범위로 수정
            if (request_num[i] == num) {
                isDuplicate = true;
                break;
            }
        }

        //중복 안되면 추가 ㄱㄱ
        if (!isDuplicate) {
            request_num[top_num++] = num;  // top_num 증가시키기
        }
    }

    std::cout << std::endl;
    std::cout << "현재 요청된 번호" << std::endl;

    for (int i = 0; i < top_num; i++) {  // top_num을 범위로 수정
        std::cout << request_num[i] << "번 테이블, ";
    }
    std::cout << std::endl;

    //이제 여기서 큐로 요청을 처리할거임
    while (1) {
        cout << endl;
        cout << "(1) 접시 치우기 (2) 메인 화면으로 돌아가기" << endl;
        cin >> queue_select;

        if (queue_select == 1) {

            /*
            // stack에 값이 있는지 없는지 확인하는 부분
            if (top_num == -1) {
                cout << "요청 처리할게 없슴" << endl;
                continue;
            }

            cout << endl;
            // 꺼낸 짐을 보여주고 없에버리는 부분
            cout << "꺼낸 짐: " << car[top_num] << endl;
            top_num--;

            cout << endl;
            // 현재 안에 있는 짐 출력
            cout << "현재 차 안에 있는 짐" << endl;
            for (int i = 0; i <= top_num; i++) {
                cout << car[i] << " ";
            }
            cout << endl;
        }
            */

        }

        else if (queue_select == 2) { // 메인 화면으로 돌아가기
            break;
        }

        // 이상한거 넣으면 다시 넣으라고 하는 부분
        else {
            cout << "다시 넣으라고~~" << endl;
            cin.clear(); // 입력 버퍼를 비우고
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 개행문자까지 무시
            continue;
        }
    }
}



//스택 부분 구현(진영 & 성식)
/*
스택(Stack)을 활용한 시나리오:
성재는 용달차에 순서대로 짐을 실는 역할을 가진 직원입니다. 내릴때는 가장 앞에 있는 짐부터 내려야 합니다.

시나리오:
성재는 스택(용달차)에 짐을 추가합니다.
짐은 스택(용달차)의 맨 위에 쌓이고, 스택은 "후입선출"의 원칙에 따라 관리됩니다.
차가 목적지에 도착해 짐을 내려야 할때, 성재는 스택(용달차)의 맨 앞에 있는 짐을 가져옵니다.
성재가 짐을 꺼내면, 해당 짐은 스택에서 제거됩니다.
모든 짐을 내리고 스택이 비게 되면, 성재의 일이 완료됩니다.
*/

void stackk() {
    int stack_select;
    string car[SIZE];
    int top_num = -1;

    while (1) {
        cout << endl;
        cout << "(1) 짐 싣기 (2) 짐 빼기 (3) 메인 화면으로 돌아가기" << endl;
        cin >> stack_select;

        // Stack이 꽉 찼는지 확인하는 부분
        if (stack_select == 1) { // push 부분
            if (top_num == SIZE - 1) {
                cout << "용달차가 꽉 찼슴~" << endl;
                continue;
            }

            cout << endl;
            // 짐을 싣는 부분
            string item;
            cout << "짐을 넣어주세요" << endl;
            cin >> item;

            //car stack에 item을 넣는 부분
            car[++top_num] = item;

            cout << endl;
            // 현재 안에 있는 짐 출력
            cout << "현재 차 안에 있는 짐" << endl;
            for (int i = 0; i <= top_num; i++) {
                cout << car[i] << " ";
            }
            cout << endl;

        }

        else if (stack_select == 2) { // pop 부분

            // stack에 값이 있는지 없는지 확인하는 부분
            if (top_num == -1) {
                cout << "짐 뺄게 없슴" << endl;
                continue;
            }

            cout << endl;
            // 꺼낸 짐을 보여주고 없에버리는 부분
            cout << "꺼낸 짐: " << car[top_num] << endl;
            top_num--;

            cout << endl;
            // 현재 안에 있는 짐 출력
            cout << "현재 차 안에 있는 짐" << endl;
            for (int i = 0; i <= top_num; i++) {
                cout << car[i] << " ";
            }
            cout << endl;
        }

        else if (stack_select == 3) { // 메인 화면으로 돌아가기
            break;
        }

        // 이상한거 넣으면 다시 넣으라고 하는 부분
        else {
            cout << "다시 넣으라고~~" << endl;
            cin.clear(); // 입력 버퍼를 비우고
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 개행문자까지 무시
            continue;
        }
    }
}