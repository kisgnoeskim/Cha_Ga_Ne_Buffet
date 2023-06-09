/*
조건
- 단, 최소 2가지 이상의 자료구조를 이용해야 함.
- 1시나리오 1구조로 2가지 시나리오 구성 가능
- ‘배열스택’은 스택에 해당. 배열과 스택 두가지로 보지 않음
*/
#include <iostream>
using namespace std;

//메인 부분 구현(성식)
int main() {
	int select;

	while (1) {
		cout << "(1) 성재의 싱글벙글 큐로 짐 싣기 (2) 성재의 두근두근 스택으로 접시 치우기 (3) 끝내기" << endl;
		cin >> select;

		if (select == 1) {
			stackk();
		}

		else if (select == 2) {
			queuee();
		}

		else if (select == 3) {
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
	int queuee_select;

	int car[10000]; //차 안에 짐을 넣기 위해 차라는 배열을 만들었셈
	int top_num = -1; //이걸로 왔다리 갔다리 할거라서

	char item; //짐을 저장하기 위해 만들었셈
	
	while (1) {
		cout << "(1) 짐 싣기 (2) 짐 빼기 (3) 메인 화면으로 돌아가기" << endl;
		cin >> queuee_select;

		if (queuee_select == 1) { //push

				//item을 받기 위해 만든 부분
				cout << "짐을 넣어주세요" << endl;
				cin >> item;

				car[++top_num] = item; //car의 0번째부터 item을 넣겠다
				
				//현재 차 안에 있는 짐을 출력하기 위해 만든 부분
				cout << "현재 차 안에 있는 짐" << endl;
				cout << car[top_num] << endl;
		}

		else if (queuee_select == 2) { //pop

			//만약 큐 안에 아무것도 없는지??
			if (car < 0) {
				cout << "짐 뺄게 없슴";
			}

			car[--top_num];

			cout << "현재 차 안에 있는 짐" << endl;
			cout << car[top_num] << endl;
		}

		else if (queuee_select == 3) {
			main();
		}

		else {
			cout << "다시 입력하삼" << endl;
			continue;
		}
	}
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

}

void printStack(int top, int car) {
	for (int i = 0; i <= top; i++) {
		cout << car[i];
	}
}