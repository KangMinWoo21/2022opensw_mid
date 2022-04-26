#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#include<windows.h>

#include<stdlib.h>

void setcolor(unsigned short text, unsigned short back)//글자 색 변경 함수
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}
int main()

{
	
	FILE* fp;

	fp=malloc(sizeof(FILE));//동적할당

	int height = 13, width = 32;
	int **date;//2차원 배열 선언
	int i, j;

	date = (int**)malloc(sizeof(int*)*height);
	for (i = 0; i < height; i++)
	{
		date[i] = (int*)malloc(sizeof(int)*width);
	}//동적할당

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			date[i][j] = 0;
		}
	}//0으로 초기화

	int sum[12] = { 0 };//월별 잔액
	int month = 0;//월
	int day = 0;//일
	int max = 0;  //수입
	float aver = 0; //평균 지출
	float *average = &aver;//평균 포인터
	int change = 0;
	int spe = 0;  //지출 합
	int min = 0;  //지출
	int num = 0;
	int balance = 0;  //잔액
	int *p = &balance; //잔액 포인터
	int choice = 0;  //선택사항

	fp = fopen("C:/Users/proje/list.txt", "w"); //시작과 동시에 list.txt 파일이 생성된다.
	
	setcolor(14, 0);//색 지정
	printf("     $$============가계부=============$$\n");
	setcolor(6, 0);
	printf("\n        (종료하려면 0을 입력하시오)");
	setcolor(15, 0);

	while (1)

	{
		
		printf("\n월을 입력하시오: ");
		scanf("%d", &month);
		if (month >12) //종료

		{
			setcolor(12, 0);
			printf("프로그램을 종료 합니다 \n");
			setcolor(15, 0);
			fclose(fp);

			break;
		}
		if (month == 0) //종료

		{
			setcolor(12, 0);
			printf("프로그램을 종료 합니다 \n");
			setcolor(15, 0);
			fclose(fp);

			break;
		}
		
		printf("일을 입력하시오: ");
		scanf("%d", &day);
		if (day >31) //종료

		{
			setcolor(12, 0);
			printf("프로그램을 종료 합니다 \n");
			setcolor(15, 0);
			fclose(fp);

			break;
		}
		if (day == 0) //종료

		{
			setcolor(12, 0);
			printf("프로그램을 종료 합니다 \n");
			setcolor(15, 0);
			fclose(fp);

			break;

		}
		printf("\n기능 선택 (1.수입 2.지출 3.잔액 조회 4.잔액 수정 ) : ");

		scanf("%d", &choice);
		if (choice == 0) //종료

		{
			setcolor(12, 0);
			printf("프로그램을 종료 합니다 \n");
			setcolor(15, 0);
			fclose(fp);

			break;

		}

		if (choice == 1)  //수입

		{

			printf("수입 금액 : ");

			scanf("%d", &max);

			*p += max;
			date[month][day] += max;
			sum[month] += max;

			fprintf(fp, "\n 수입 금액 : %d 원\n", date[month][day]);

			printf("\n잔액: %d\n", date[month][day]);

		}

		if (choice == 2) // 지출

		{

			printf("지출  금액 : ");

			scanf("%d", &min);
			
			*p  -= min;
			date[month][day] -= min;
			sum[month] -= min;
			spe += min;
			num += 1;
			*average = spe / num;
			fprintf(fp, "\n 지출 금액 : %d 원\n", date[month][day]);  //금액을 list.txt 파일에 출력

			printf("\n잔액: %d\n\n", date[month][day]);   //금액을 화면에 출력
			
			if (*average < min) {
				setcolor(12, 0);
				printf("평소보다 많은 지출을 하였습니다!\n\n");
				setcolor(15, 0);
			}
			
		}

		if (choice == 3) //잔액조회

		{

			
			
			printf("\n%d월 %d일의 잔액 조회 : %d\n",month,day, date[month][day]);//금액을 화면에  출력
			printf("%d월의 잔액 조회 : %d\n", month, sum[month]);
			setcolor(14, 0);
			printf("전체 잔액: %d\n", *p);
			setcolor(15, 0);
			fprintf(fp, "\n 잔액 조회 : %d 원\n\n", date[month][day]); //금액을 list.txt 파일에 출력

		}
		if (choice == 4)//잔액 변경
		{
			*p-=date[month][day];
			sum[month] -= date[month][day];
			printf("변경하려는 잔액을 입력하시오: ");
			scanf("%d", &change);
			date[month][day] = change;
			sum[month] += change;
			*p += change;
			fprintf(fp, "\n 잔액 : %d 원\n", date[month][day]);
			printf("\n잔액: %d\n\n", date[month][day]);   //금액을 화면에 출력
		}

		if (!(choice==0||choice == 1 || choice == 2 || choice == 3|| choice==4 )) //예외처리

		{
			break;
		}

	}

	free(fp);
	for (i = 0; i < height; i++)
	{
		free(date[i]);
	}
	free(date);
	return 0;
}