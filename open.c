#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#include<windows.h>

#include<stdlib.h>

void setcolor(unsigned short text, unsigned short back)//���� �� ���� �Լ�
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}
int main()

{
	
	FILE* fp;

	fp=malloc(sizeof(FILE));//�����Ҵ�

	int height = 13, width = 32;
	int **date;//2���� �迭 ����
	int i, j;

	date = (int**)malloc(sizeof(int*)*height);
	for (i = 0; i < height; i++)
	{
		date[i] = (int*)malloc(sizeof(int)*width);
	}//�����Ҵ�

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			date[i][j] = 0;
		}
	}//0���� �ʱ�ȭ

	int sum[12] = { 0 };//���� �ܾ�
	int month = 0;//��
	int day = 0;//��
	int max = 0;  //����
	float aver = 0; //��� ����
	float *average = &aver;//��� ������
	int change = 0;
	int spe = 0;  //���� ��
	int min = 0;  //����
	int num = 0;
	int balance = 0;  //�ܾ�
	int *p = &balance; //�ܾ� ������
	int choice = 0;  //���û���

	fp = fopen("C:/Users/proje/list.txt", "w"); //���۰� ���ÿ� list.txt ������ �����ȴ�.
	
	setcolor(14, 0);//�� ����
	printf("     $$============�����=============$$\n");
	setcolor(6, 0);
	printf("\n        (�����Ϸ��� 0�� �Է��Ͻÿ�)");
	setcolor(15, 0);

	while (1)

	{
		
		printf("\n���� �Է��Ͻÿ�: ");
		scanf("%d", &month);
		if (month >12) //����

		{
			setcolor(12, 0);
			printf("���α׷��� ���� �մϴ� \n");
			setcolor(15, 0);
			fclose(fp);

			break;
		}
		if (month == 0) //����

		{
			setcolor(12, 0);
			printf("���α׷��� ���� �մϴ� \n");
			setcolor(15, 0);
			fclose(fp);

			break;
		}
		
		printf("���� �Է��Ͻÿ�: ");
		scanf("%d", &day);
		if (day >31) //����

		{
			setcolor(12, 0);
			printf("���α׷��� ���� �մϴ� \n");
			setcolor(15, 0);
			fclose(fp);

			break;
		}
		if (day == 0) //����

		{
			setcolor(12, 0);
			printf("���α׷��� ���� �մϴ� \n");
			setcolor(15, 0);
			fclose(fp);

			break;

		}
		printf("\n��� ���� (1.���� 2.���� 3.�ܾ� ��ȸ 4.�ܾ� ���� ) : ");

		scanf("%d", &choice);
		if (choice == 0) //����

		{
			setcolor(12, 0);
			printf("���α׷��� ���� �մϴ� \n");
			setcolor(15, 0);
			fclose(fp);

			break;

		}

		if (choice == 1)  //����

		{

			printf("���� �ݾ� : ");

			scanf("%d", &max);

			*p += max;
			date[month][day] += max;
			sum[month] += max;

			fprintf(fp, "\n ���� �ݾ� : %d ��\n", date[month][day]);

			printf("\n�ܾ�: %d\n", date[month][day]);

		}

		if (choice == 2) // ����

		{

			printf("����  �ݾ� : ");

			scanf("%d", &min);
			
			*p  -= min;
			date[month][day] -= min;
			sum[month] -= min;
			spe += min;
			num += 1;
			*average = spe / num;
			fprintf(fp, "\n ���� �ݾ� : %d ��\n", date[month][day]);  //�ݾ��� list.txt ���Ͽ� ���

			printf("\n�ܾ�: %d\n\n", date[month][day]);   //�ݾ��� ȭ�鿡 ���
			
			if (*average < min) {
				setcolor(12, 0);
				printf("��Һ��� ���� ������ �Ͽ����ϴ�!\n\n");
				setcolor(15, 0);
			}
			
		}

		if (choice == 3) //�ܾ���ȸ

		{

			
			
			printf("\n%d�� %d���� �ܾ� ��ȸ : %d\n",month,day, date[month][day]);//�ݾ��� ȭ�鿡  ���
			printf("%d���� �ܾ� ��ȸ : %d\n", month, sum[month]);
			setcolor(14, 0);
			printf("��ü �ܾ�: %d\n", *p);
			setcolor(15, 0);
			fprintf(fp, "\n �ܾ� ��ȸ : %d ��\n\n", date[month][day]); //�ݾ��� list.txt ���Ͽ� ���

		}
		if (choice == 4)//�ܾ� ����
		{
			*p-=date[month][day];
			sum[month] -= date[month][day];
			printf("�����Ϸ��� �ܾ��� �Է��Ͻÿ�: ");
			scanf("%d", &change);
			date[month][day] = change;
			sum[month] += change;
			*p += change;
			fprintf(fp, "\n �ܾ� : %d ��\n", date[month][day]);
			printf("\n�ܾ�: %d\n\n", date[month][day]);   //�ݾ��� ȭ�鿡 ���
		}

		if (!(choice==0||choice == 1 || choice == 2 || choice == 3|| choice==4 )) //����ó��

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