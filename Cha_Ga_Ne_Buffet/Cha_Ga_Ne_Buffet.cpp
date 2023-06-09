/*
조건
- 단, 최소 2가지 이상의 자료구조를 이용해야 함.
- 1시나리오 1구조로 2가지 시나리오 구성 가능
- ‘배열스택’은 스택에 해당. 배열과 스택 두가지로 보지 않음
*/
#include <iostream>
#include <string>

using namespace std;
#define SIZE 10000  // 배열의 사이즈

void queuee();
void stackk();

//메인 부분 구현(성식)
int main() {
	int select;

	while (1) {
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
	
}


//스택 부분 구현(진영)
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
        cout << "(1) 짐 싣기 (2) 짐 빼기 (3) 메인 화면으로 돌아가기" << endl;
        cin >> stack_select;

        if (stack_select == 1) { // push 부분
            if (top_num == SIZE - 1) {
                cout << "용달차가 꽉 찼습니다." << endl;
                continue;
            }

            string item;
            cout << "짐을 넣어주세요" << endl;
            cin >> item;

            car[++top_num] = item;

            // 현재 안에 있는 짐 출력
            cout << "현재 차 안에 있는 짐" << endl;
            for (int i = 0; i <= top_num; i++) {
                cout << car[i] << " ";
            }
            cout << endl;

        }

        else if (stack_select == 2) { // pop 부분
            if (top_num == -1) {
                cout << "짐 뺄게 없슴" << endl;
                continue;
            }

            cout << "꺼낸 짐: " << car[top_num] << endl;
            top_num--;

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

        else {
            cout << "올바른 선택지를 입력해주세요." << endl;
            cin.clear(); // 입력 버퍼를 비우고
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 개행문자까지 무시
            continue;
        }
    }
}