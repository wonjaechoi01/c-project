#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// git test

void main()
{
	int id[100]; //주문번호라고 한다면, 0이나 문자가 올수 잇으니까 문자열로 받아라. 
	char orderNum[100][255]; // 255문자를 쓰는 100개 데이터 >> 문자열을 여러개 쓰려면 ''2차원 배열''을 쓴다고 알아두자. 
	int orderAmount[100];
	int orderDate[100]; // 10번줄 주석 이후에 추가되었음.
	int menuSelect = 0;
	int orderNumCount = 0;  // 원래 dataCount 엿음
	// int orderAmountCount = 0;  한 개 인덱스에서 복수 자료 관리/호출되므로, 지금 디자인-기능에서는 불필요
							 // 1-데이터 입력 , 2-데이터 리스트
	char orderNumSearch[255]; // 검색은 다중입력이 필요 업으므로, 5번줄과 달리 ''1차원 배열''을 사용한다. 

	for (; ;) {
		printf("주문내용 입력은 1, 전체조회는 2, 특정주문조회는 3, 수정은 4, 종료는 0을 입력 : ");
		scanf_s("%d", &menuSelect);

		if (menuSelect == 1) {
			printf("주문번호를 입력합니다. : ");
			scanf_s("%s", orderNum[orderNumCount], 255);
			printf("주문금액을 입력합니다. : ");
			scanf_s("%d", &orderAmount[orderNumCount]);
			printf("주문일자를 입력합니다. : ");
			scanf_s("%d", &orderDate[orderNumCount]);
			id[orderNumCount] = orderNumCount + 1;
			// orderAmount[orderAmountCount] = orderAmountCount + 1; 필요하다고 생각하고 썼는데 필요가 없다! 원래 입력받은 값이 아닌 스스로 재입력중
			orderNumCount++;
			//orderAmountCount++;
			// 한 개 인덱스에 여러 자료를 관리한다. 흠.. 
		}
			
		else if (menuSelect == 2) {
			printf("입력된 자료를 불러옵니다.\n");
			printf("id		주문번호		주문금액		주문일자\n");
			for (int i = 0; i < orderNumCount; i++) {
				printf("%d		%s			%d			%d\n", id[i], orderNum[i], orderAmount[i], orderDate[i]);
			}
		}

		else if (menuSelect == 3) {
			printf("조회를 원하는 주문번호를 입력하세요 : ");
			scanf_s("%s", orderNumSearch, 255);
			for (int i = 0; i < orderNumCount; i++) {
				int result = strcmp(orderNumSearch, orderNum[i]);
				if (result == 0)	{
					printf("id		주문번호		주문금액		주문일자\n");
					printf("%d		%s			%d			%d\n", id[i], orderNum[i], orderAmount[i], orderDate[i]);
				}
				
			}
		}

		else if (menuSelect == 4) {
			printf("수정하려는 주문번호를 입력하세요 : ");
			scanf_s("%s", orderNumSearch, 255);
			for (int i = 0; i < orderNumCount; i++) {
				int result = strcmp(orderNumSearch, orderNum[i]);
				if (result == 0) {
					printf("id		주문번호		주문금액		주문일자\n");
					printf("%d		%s			%d			%d\n", id[i], orderNum[i], orderAmount[i], orderDate[i]);
					printf("새로운 주문금액을 입력하세요 : ");
					scanf_s("%d", &orderAmount[i]);

				}

			}
		}

		else if (menuSelect == 0) {
			return;
		}

		system("pause");
		system("cls");

	}

}