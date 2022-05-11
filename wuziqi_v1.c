#if 0
writen by Ziru Zha
2022.05.09
#endif
#include<stdio.h>
#include<stdlib.h>
#define ROW 15
#define COL 15

void QipanInit();
void Read_b();
void Read_w();
void Print();
void AI();
void AI2();
void calculate(int m, int n);
void lianwu(int m, int n);
void huosi(int m, int n);
void huosan(int m, int n);
void huoer(int m, int n);
void chongsi(int m, int n);
void miansan(int m, int n);
void mianer(int m, int n);
int Judge();

int Qipan[ROW][COL];
long average[ROW][COL];
void main() {
	
	QipanInit();
	char input, input_1;
	while (1) {
		printf("Welcome to wuziqi. Press S to start, Q to quit.\n");
		scanf_s("%c", &input);
		if (input == 'S' || input == 's') {
			printf("Press S for Single player, D for Double player.\n");
			scanf_s("%c", &input_1);
			scanf_s("%c", &input_1); 
			//����
			if (input_1 == 'S' || input_1 == 's') {
				Print();
				while (1) {
					Read_b();
					AI2();
					Print();
					if (Judge() == 1) {
						printf("Black Win!\n");
						QipanInit();
						break;
					}
					if (Judge() == 2) {
						printf("White Win!\n");
						QipanInit();
						break;
					}
				}
			}
			//˫��
			if (input_1 == 'D' || input_1 == 'd') {
				Print();
				int BorW = 1;
				while (1) {
					if (BorW) {
						Read_b();
						Print();
						BorW = 0;
					}
					else
					{
						Read_w();
						Print();
						BorW = 1;
					}
					if (Judge() == 1) {
						printf("Black Win!\n");
						QipanInit();
						break;
					}
					if (Judge() == 2) {
						printf("White Win!\n");
						QipanInit();
						break;
					}
				}

			}

			
		}
		else
		{
			if (input == 'q' || input == 'Q') {
				break;
			}
			else
			{

			}
		}
	}
}

void QipanInit() {
	/*���̴�С��ROW * COL
	0---��
	1---����
	2---����*/
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			Qipan[i][j] = 0;
		}
	}
}
void Read_b() {
	int x, y;
	while (1) {
		printf("Input (x,y) for black\n");
		scanf_s("%d%d", &x, &y);
		x--; y--;
		if (x < 0 || x >= ROW || y < 0 || y >= COL) {
			printf("Error! ");
			continue;
		}
		if (Qipan[x][y] == 0) {
			Qipan[x][y] = 1;
			break;
		}
		else {
			printf("Error! ");
		}
	}
	
}
void Read_w() {
	int x, y;
	while (1) {
		printf("Input (x,y) for white\n");
		scanf_s("%d%d", &x, &y);
		x--; y--;
		if (x < 0 || x >= ROW || y < 0 || y >= COL) {
			printf("Error! ");
			continue;
		}
		if (Qipan[x][y] == 0) {
			Qipan[x][y] = 2;
			break;
		}
		else {
			printf("Error! ");
		}
	}

}
void Print() {
	printf("   һ �� �� �� �� �� �� �� �� ʮ һ �� �� �� ��\n");
	for (int i = 0; i < ROW; i++) {
		printf("%d ", (i + 1)%10);
		for (int j = 0; j < COL; j++) {
			if (Qipan[i][j] == 1) {
				printf(" X ");
			}
			else
			{
				if (Qipan[i][j] == 2) {
					printf(" O ");
				}
				else
				{
					printf(" - ");
				}
				
			}
			
		}
		printf("\n");
	}
}
int Judge() {
	/*�ж���Ӯ
	����Ӯ����1
	����Ӯ����2*/

	//�к����
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < (COL - 4); j++) {
			if (Qipan[i][j] * Qipan[i][j + 1] * Qipan[i][j + 2] * Qipan[i][j + 3] * Qipan[i][j + 4] == 1) {
				return 1;
			}
		}
	}
	//�к�����
	for (int i = 0; i < (ROW-4); i++) {
		for (int j = 0; j < COL; j++) {
			if (Qipan[i][j] * Qipan[i + 1][j] * Qipan[i + 2][j] * Qipan[i + 3][j] * Qipan[i + 4][j] == 1) {
				return 1;
			}
		}
	}
	//�к�������
	for (int i = 0; i < (ROW - 4); i++) {
		for (int j = 0; j < (COL - 4); j++) {
			if (Qipan[i][j] * Qipan[i + 1][j + 1] * Qipan[i + 2][j + 2] * Qipan[i + 3][j + 3] * Qipan[i + 4][j + 4] == 1) {
				return 1;
			}
		}
	}
	//�к�������
	for (int i = 0; i < ROW; i++) {
		for (int j = 4; j < COL; j++) {
			if (Qipan[i][j] * Qipan[i + 1][j - 1] * Qipan[i + 2][j - 2] * Qipan[i + 3][j - 3] * Qipan[i + 4][j - 4] == 1) {
				return 1;
			}
		}
	}
	//�а����

	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < (COL - 4); j++) {
			if (Qipan[i][j] * Qipan[i][j + 1] * Qipan[i][j + 2] * Qipan[i][j + 3] * Qipan[i][j + 4] == 32) {
				return 2;
			}
		}
	}
	//�а�����
	for (int i = 0; i < (ROW - 4); i++) {
		for (int j = 0; j < COL; j++) {
			if (Qipan[i][j] * Qipan[i + 1][j] * Qipan[i + 2][j] * Qipan[i + 3][j] * Qipan[i + 4][j] == 32) {
				return 2;
			}
		}
	}
	//�а�������
	for (int i = 0; i < (ROW - 4); i++) {
		for (int j = 0; j < (COL - 4); j++) {
			if (Qipan[i][j] * Qipan[i + 1][j + 1] * Qipan[i + 2][j + 2] * Qipan[i + 3][j + 3] * Qipan[i + 4][j + 4] == 32) {
				return 2;
			}
		}
	}
	//�а�������
	for (int i = 0; i < ROW; i++) {
		for (int j = 4; j < COL; j++) {
			if (Qipan[i][j] * Qipan[i + 1][j - 1] * Qipan[i + 2][j - 2] * Qipan[i + 3][j - 3] * Qipan[i + 4][j - 4] == 32) {
				return 2;
			}
		}
	}
}

void AI() {
	/*
	1.   ���壺���ͬɫ��������һ����11111��22222
	2.   ���ģ�������������γ����壬��011110��022220
	3.   ���ģ���һ��������γ����壬��011112��122220
	4.   �����������γɻ��ĵ����㣬��001110��002220
	5.   ������ֻ���γɳ��ĵ����㣬��001112��002221
	6.   ������ܹ��γɻ����Ķ��㣬��000110��000220
	7.   �߶����ܹ��γ������Ķ��㣬��000112��000221
	����Ȩ��
	����100000000
	����10000000
	����1000000
	����100000
	����10000
	���1000
	�߶�100
	��һ10
	��1
	*/
#define LIANWU 100000000
#define HUOSI 10000000
#define CHONGSI 1000000
#define HUOSAN 100000
#define MIANSAN 10000
#define HUOER 1000
#define MIANER 100
#define JINYI 10
#define WUYI 1

	long average[ROW][COL], max = -1;
	//Ȩ�ؾ����ʼ��
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			average[i][j] = -1;
		}
	}
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (!Qipan[i][j]) {
				average[i][j] = 0;
			}
		}
	}

	//������
	//����
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL - 4; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i][j + 1] * Qipan[i][j + 2] * Qipan[i][j + 3] * Qipan[i][j + 4] == 1) {
					average[i][j] = average[i][j] + LIANWU;
				}
				if (Qipan[i][j + 1] * Qipan[i][j + 2] * Qipan[i][j + 3] * Qipan[i][j + 4] == 16) {
					average[i][j] = average[i][j] + LIANWU;
				}
			}
		}
	}
	//����-1-----10111
	for (int i = 0; i < ROW; i++) {
		for (int j = 1; j < COL - 3; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i][j - 1] * Qipan[i][j + 1] * Qipan[i][j + 2] * Qipan[i][j + 3] == 1) {
					average[i][j] = average[i][j] + LIANWU;
				}
				if (Qipan[i][j - 1] * Qipan[i][j + 1] * Qipan[i][j + 2] * Qipan[i][j + 3] == 16) {
					average[i][j] = average[i][j] + LIANWU;
				}
			}
		}
	}
	//����-2-----11011
	for (int i = 0; i < ROW; i++) {
		for (int j = 2; j < COL - 2; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i][j - 2] * Qipan[i][j - 1] * Qipan[i][j + 1] * Qipan[i][j + 2] == 1) {
					average[i][j] = average[i][j] + LIANWU;
				}
				if (Qipan[i][j - 2] * Qipan[i][j - 1] * Qipan[i][j + 1] * Qipan[i][j + 2] == 16) {
					average[i][j] = average[i][j] + LIANWU;
				}
			}
		}
	}
	//����-3-----11101
	for (int i = 0; i < ROW; i++) {
		for (int j = 3; j < COL - 1; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i][j - 3] * Qipan[i][j - 2] * Qipan[i][j - 1] * Qipan[i][j + 1] == 1) {
					average[i][j] = average[i][j] + LIANWU;
				}
				if (Qipan[i][j - 3] * Qipan[i][j - 2] * Qipan[i][j - 1] * Qipan[i][j + 1] == 16) {
					average[i][j] = average[i][j] + LIANWU;
				}
			}
		}
	}
	//����
	for (int i = 0; i < ROW; i++) {
		for (int j = 1; j < COL - 4; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i][j - 1] == 0 && Qipan[i][j + 1] == 1 && Qipan[i][j + 2] == 1 && Qipan[i][j + 3] == 1 && Qipan[i][j + 4] == 0) {
					average[i][j] = average[i][j] + HUOSI;
				}
				if (Qipan[i][j - 1] == 0 && Qipan[i][j + 1] == 2 && Qipan[i][j + 2] == 2 && Qipan[i][j + 3] == 2 && Qipan[i][j + 4] == 0) {
					average[i][j] = average[i][j] + HUOSI;
				}
			}
		}
	}
	//����
	for (int i = 0; i < ROW; i++) {
		for (int j = 1; j < COL - 4; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i][j - 1] == 0 && Qipan[i][j + 1] == 1 && Qipan[i][j + 2] == 1 && Qipan[i][j + 3] == 1 && Qipan[i][j + 4] == 2) {
					average[i][j] = average[i][j] + CHONGSI;
				}
				if (Qipan[i][j - 1] == 0 && Qipan[i][j + 1] == 2 && Qipan[i][j + 2] == 2 && Qipan[i][j + 3] == 2 && Qipan[i][j + 4] == 1) {
					average[i][j] = average[i][j] + CHONGSI;
				}
			}
		}
	}
	//����-1----010110
	for (int i = 0; i < ROW; i++) {
		for (int j = 2; j < COL - 3; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i][j - 2] == 0 && Qipan[i][j - 1] == 1 && Qipan[i][j + 1] == 1 && Qipan[i][j + 2] == 1 && Qipan[i][j + 3] == 0) {
					average[i][j] = average[i][j] + HUOSI;
				}
				if (Qipan[i][j - 2] == 0 && Qipan[i][j - 1] == 2 && Qipan[i][j + 1] == 2 && Qipan[i][j + 2] == 2 && Qipan[i][j + 3] == 0) {
					average[i][j] = average[i][j] + HUOSI;
				}
			}
		}
	}
	//����
	for (int i = 0; i < ROW; i++) {
		for (int j = 2; j < COL - 3; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i][j - 2] == 0 && Qipan[i][j - 1] == 0 && Qipan[i][j + 1] == 1 && Qipan[i][j + 2] == 1 && Qipan[i][j + 3] == 0) {
					average[i][j] = average[i][j] + HUOSAN;
				}
				if (Qipan[i][j - 2] == 0 && Qipan[i][j - 1] == 0 && Qipan[i][j + 1] == 2 && Qipan[i][j + 2] == 2 && Qipan[i][j + 3] == 0) {
					average[i][j] = average[i][j] + HUOSAN;
				}
			}
		}
	}
	//����
	for (int i = 0; i < ROW; i++) {
		for (int j = 2; j < COL - 3; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i][j - 2] == 0 && Qipan[i][j - 1] == 0 && Qipan[i][j + 1] == 1 && Qipan[i][j + 2] == 1 && Qipan[i][j + 3] == 2) {
					average[i][j] = average[i][j] + MIANSAN;
				}
				if (Qipan[i][j - 2] == 0 && Qipan[i][j - 1] == 0 && Qipan[i][j + 1] == 2 && Qipan[i][j + 2] == 2 && Qipan[i][j + 3] == 1) {
					average[i][j] = average[i][j] + MIANSAN;
				}
			}
		}
	}
	//���
	for (int i = 0; i < ROW; i++) {
		for (int j = 3; j < COL - 2; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i][j - 3] == 0 && Qipan[i][j - 2] == 0 && Qipan[i][j - 1] == 0 && Qipan[i][j + 1] == 1 && Qipan[i][j + 2] == 0) {
					average[i][j] = average[i][j] + HUOER;
				}
				if (Qipan[i][j - 3] == 0 && Qipan[i][j - 2] == 0 && Qipan[i][j - 1] == 0 && Qipan[i][j + 1] == 2 && Qipan[i][j + 2] == 0) {
					average[i][j] = average[i][j] + HUOER;
				}
			}
		}
	}
	//�߶�
	for (int i = 0; i < ROW; i++) {
		for (int j = 3; j < COL - 2; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i][j - 3] == 0 && Qipan[i][j - 2] == 0 && Qipan[i][j - 1] == 0 && Qipan[i][j + 1] == 1 && Qipan[i][j + 2] == 2) {
					average[i][j] = average[i][j] + MIANER;
				}
				if (Qipan[i][j - 3] == 0 && Qipan[i][j - 2] == 0 && Qipan[i][j - 1] == 0 && Qipan[i][j + 1] == 2 && Qipan[i][j + 2] == 1) {
					average[i][j] = average[i][j] + MIANER;
				}
			}
		}
	}
	//��������


	//������
	//����
	for (int i = 0; i < ROW; i++) {
		for (int j = (COL - 1); j > 4; j--)  {
			if (Qipan[i][j] == 0) {
				if (Qipan[i][j - 1] * Qipan[i][j - 2] * Qipan[i][j - 3] * Qipan[i][j - 4] == 1) {
					average[i][j] = average[i][j] + LIANWU;
				}
				if (Qipan[i][j - 1] * Qipan[i][j - 2] * Qipan[i][j - 3] * Qipan[i][j - 4] == 16) {
					average[i][j] = average[i][j] + LIANWU;
				}
			}
		}
	}
	//����
	for (int i = 0; i < ROW; i++) {
		for (int j = (COL - 2); j > 4; j--) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i][j + 1] == 0 && Qipan[i][j - 1] == 1 && Qipan[i][j - 2] == 1 && Qipan[i][j - 3] == 1 && Qipan[i][j - 4] == 0) {
					average[i][j] = average[i][j] + HUOSI;
				}
				if (Qipan[i][j + 1] == 0 && Qipan[i][j - 1] == 2 && Qipan[i][j - 2] == 2 && Qipan[i][j - 3] == 2 && Qipan[i][j - 4] == 0) {
					average[i][j] = average[i][j] + HUOSI;
				}
			}
		}
	}
	//����
	for (int i = 0; i < ROW; i++) {
		for (int j = (COL - 2); j > 4; j--) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i][j + 1] == 0 && Qipan[i][j - 1] == 1 && Qipan[i][j - 2] == 1 && Qipan[i][j - 3] == 1 && Qipan[i][j - 4] == 2) {
					average[i][j] = average[i][j] + CHONGSI;
				}
				if (Qipan[i][j + 1] == 0 && Qipan[i][j - 1] == 2 && Qipan[i][j - 2] == 2 && Qipan[i][j - 3] == 2 && Qipan[i][j - 4] == 1) {
					average[i][j] = average[i][j] + CHONGSI;
				}
			}
		}
	}
	//����-1----010110
	for (int i = 0; i < ROW; i++) {
		for (int j = (COL - 3); j > 3; j--) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i][j + 2] == 0 && Qipan[i][j + 1] == 1 && Qipan[i][j - 1] == 1 && Qipan[i][j - 2] == 1 && Qipan[i][j - 3] == 0) {
					average[i][j] = average[i][j] + HUOSI;
				}
				if (Qipan[i][j + 2] == 0 && Qipan[i][j + 1] == 2 && Qipan[i][j - 1] == 2 && Qipan[i][j - 2] == 2 && Qipan[i][j - 3] == 0) {
					average[i][j] = average[i][j] + HUOSI;
				}
			}
		}
	}
	//����
	for (int i = 0; i < ROW; i++) {
		for (int j = (COL - 3); j > 3; j--) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i][j + 2] == 0 && Qipan[i][j + 1] == 0 && Qipan[i][j - 1] == 1 && Qipan[i][j - 2] == 1 && Qipan[i][j - 3] == 0) {
					average[i][j] = average[i][j] + HUOSAN;
				}
				if (Qipan[i][j + 2] == 0 && Qipan[i][j + 1] == 0 && Qipan[i][j - 1] == 2 && Qipan[i][j - 2] == 2 && Qipan[i][j - 3] == 0) {
					average[i][j] = average[i][j] + HUOSAN;
				}
			}
		}
	}
	//����
	for (int i = 0; i < ROW; i++) {
		for (int j = (COL - 3); j > 3; j--) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i][j + 2] == 0 && Qipan[i][j + 1] == 0 && Qipan[i][j - 1] == 1 && Qipan[i][j - 2] == 1 && Qipan[i][j - 3] == 2) {
					average[i][j] = average[i][j] + MIANSAN;
				}
				if (Qipan[i][j + 2] == 0 && Qipan[i][j + 1] == 0 && Qipan[i][j - 1] == 2 && Qipan[i][j - 2] == 2 && Qipan[i][j - 3] == 1) {
					average[i][j] = average[i][j] + MIANSAN;
				}
			}
		}
	}
	//���
	for (int i = 0; i < ROW; i++) {
		for (int j = (COL - 4); j > 2; j--) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i][j + 3] == 0 && Qipan[i][j + 2] == 0 && Qipan[i][j + 1] == 0 && Qipan[i][j - 1] == 1 && Qipan[i][j - 2] == 0) {
					average[i][j] = average[i][j] + HUOER;
				}
				if (Qipan[i][j + 3] == 0 && Qipan[i][j + 2] == 0 && Qipan[i][j + 1] == 0 && Qipan[i][j - 1] == 2 && Qipan[i][j - 2] == 0) {
					average[i][j] = average[i][j] + HUOER;
				}
			}
		}
	}
	//�߶�
	for (int i = 0; i < ROW; i++) {
		for (int j = (COL - 4); j > 2; j--) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i][j + 3] == 0 && Qipan[i][j + 2] == 0 && Qipan[i][j + 1] == 0 && Qipan[i][j - 1] == 1 && Qipan[i][j - 2] == 2) {
					average[i][j] = average[i][j] + MIANER;
				}
				if (Qipan[i][j + 3] == 0 && Qipan[i][j + 2] == 0 && Qipan[i][j + 1] == 0 && Qipan[i][j - 1] == 2 && Qipan[i][j - 2] == 1) {
					average[i][j] = average[i][j] + MIANER;
				}
			}
		}
	}
	//��������

	//������
	//����
	for (int i = 0; i < ROW - 4; i++) {
		for (int j = 0; j < COL; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i + 1][j] * Qipan[i + 2][j] * Qipan[i + 3][j] * Qipan[i + 4][j] == 1) {
					average[i][j] = average[i][j] + LIANWU;
				}
				if (Qipan[i + 1][j] * Qipan[i + 2][j] * Qipan[i + 3][j] * Qipan[i + 4][j] == 16) {
					average[i][j] = average[i][j] + LIANWU;
				}
			}
		}
	}
	//����-1-----10111
	for (int i = 1; i < ROW - 3; i++) {
		for (int j = 0; j < COL; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 1][j] * Qipan[i + 1][j] * Qipan[i + 2][j] * Qipan[i + 3][j] == 1) {
					average[i][j] = average[i][j] + LIANWU;
				}
				if (Qipan[i - 1][j] * Qipan[i + 1][j] * Qipan[i + 2][j] * Qipan[i + 3][j] == 16) {
					average[i][j] = average[i][j] + LIANWU;
				}
			}
		}
	}
	//����-2-----11011
	for (int i = 2; i < ROW - 2; i++) {
		for (int j = 0; j < COL; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 2][j] * Qipan[i - 1][j] * Qipan[i + 1][j] * Qipan[i + 2][j] == 1) {
					average[i][j] = average[i][j] + LIANWU;
				}
				if (Qipan[i - 2][j] * Qipan[i - 1][j] * Qipan[i + 1][j] * Qipan[i + 2][j] == 16) {
					average[i][j] = average[i][j] + LIANWU;
				}
			}
		}
	}
	//����-3-----11101
	for (int i = 3; i < ROW - 1; i++) {
		for (int j = 0; j < COL; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 3][j] * Qipan[i - 2][j] * Qipan[i - 1][j] * Qipan[i + 1][j] == 1) {
					average[i][j] = average[i][j] + LIANWU;
				}
				if (Qipan[i - 3][j] * Qipan[i - 2][j] * Qipan[i - 1][j] * Qipan[i + 1][j] == 16) {
					average[i][j] = average[i][j] + LIANWU;
				}
			}
		}
	}
	//����
	for (int i = 1; i < ROW - 4; i++) {
		for (int j = 0; j < COL; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 1][j] == 0 && Qipan[i + 1][j] == 1 && Qipan[i + 2][j] == 1 && Qipan[i + 3][j] == 1 && Qipan[i + 4][j] == 0) {
					average[i][j] = average[i][j] + HUOSI;
				}
				if (Qipan[i - 1][j] == 0 && Qipan[i + 1][j] == 2 && Qipan[i + 2][j] == 2 && Qipan[i + 3][j] == 2 && Qipan[i + 4][j] == 0) {
					average[i][j] = average[i][j] + HUOSI;
				}
			}
		}
	}
	//����
	for (int i = 1; i < ROW - 4; i++) {
		for (int j = 0; j < COL; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 1][j] == 0 && Qipan[i + 1][j] == 1 && Qipan[i + 2][j] == 1 && Qipan[i + 3][j] == 1 && Qipan[i + 4][j] == 2) {
					average[i][j] = average[i][j] + CHONGSI;
				}
				if (Qipan[i - 1][j] == 0 && Qipan[i + 1][j] == 1 && Qipan[i + 2][j] == 1 && Qipan[i + 3][j] == 1 && Qipan[i + 4][j] == 1) {
					average[i][j] = average[i][j] + CHONGSI;
				}
			}
		}
	}
	//����-1----010110
	for (int i = 2; i < ROW - 3; i++) {
		for (int j = 0; j < COL; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 2][j] == 0 && Qipan[i - 1][j] == 1 && Qipan[i + 1][j] == 1 && Qipan[i + 2][j] == 1 && Qipan[i + 3][j] == 0) {
					average[i][j] = average[i][j] + HUOSI;
				}
				if (Qipan[i - 2][j] == 0 && Qipan[i - 1][j] == 2 && Qipan[i + 1][j] == 2 && Qipan[i + 2][j] == 2 && Qipan[i + 3][j] == 0) {
					average[i][j] = average[i][j] + HUOSI;
				}
			}
		}
	}
	//����
	for (int i = 2; i < ROW - 3; i++) {
		for (int j = 0; j < COL; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 2][j] == 0 && Qipan[i - 1][j] == 0 && Qipan[i + 1][j] == 1 && Qipan[i + 2][j] == 1 && Qipan[i + 3][j] == 0) {
					average[i][j] = average[i][j] + HUOSAN;
				}
				if (Qipan[i - 2][j] == 0 && Qipan[i - 1][j] == 0 && Qipan[i + 1][j] == 2 && Qipan[i + 2][j] == 2 && Qipan[i + 3][j] == 0) {
					average[i][j] = average[i][j] + HUOSAN;
				}
			}
		}
	}
	//����
	for (int i = 2; i < ROW - 3; i++) {
		for (int j = 0; j < COL; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 2][j] == 0 && Qipan[i - 1][j] == 0 && Qipan[i + 1][j] == 1 && Qipan[i + 2][j] == 1 && Qipan[i + 3][j] == 2) {
					average[i][j] = average[i][j] + MIANSAN;
				}
				if (Qipan[i - 2][j] == 0 && Qipan[i - 1][j] == 0 && Qipan[i + 1][j] == 2 && Qipan[i + 2][j] == 2 && Qipan[i + 3][j] == 1) {
					average[i][j] = average[i][j] + MIANSAN;
				}
			}
		}
	}
	//���
	for (int i = 3; i < ROW - 2; i++) {
		for (int j = 0; j < COL; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 3][j] == 0 && Qipan[i - 2][j] == 0 && Qipan[i - 1][j] == 1 && Qipan[i + 1][j] == 1 && Qipan[i + 2][j] == 0) {
					average[i][j] = average[i][j] + HUOER;
				}
				if (Qipan[i - 3][j] == 0 && Qipan[i - 2][j] == 0 && Qipan[i - 1][j] == 2 && Qipan[i + 1][j] == 1 && Qipan[i + 2][j] == 0) {
					average[i][j] = average[i][j] + HUOER;
				}
			}
		}
	}
	//�߶�
	for (int i = 3; i < ROW - 2; i++) {
		for (int j = 0; j < COL; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 3][j] == 0 && Qipan[i - 2][j] == 0 && Qipan[i - 1][j] == 1 && Qipan[i + 1][j] == 1 && Qipan[i + 2][j] == 2) {
					average[i][j] = average[i][j] + MIANER;
				}
				if (Qipan[i - 3][j] == 0 && Qipan[i - 2][j] == 0 && Qipan[i - 1][j] == 1 && Qipan[i + 1][j] == 2 && Qipan[i + 2][j] == 1) {
					average[i][j] = average[i][j] + MIANER;
				}
			}
		}
	}
	//��������

	//������
	//����
	for (int i = 4; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 1][j] * Qipan[i - 2][j] * Qipan[i - 3][j] * Qipan[i - 4][j] == 1) {
					average[i][j] = average[i][j] + LIANWU;
				}
				if (Qipan[i - 1][j] * Qipan[i - 2][j] * Qipan[i - 3][j] * Qipan[i - 4][j] == 16) {
					average[i][j] = average[i][j] + LIANWU;
				}
			}
		}
	}
	//����
	for (int i = 4; i < ROW - 1; i++) {
		for (int j = 0; j < COL; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i + 1][j] == 0 && Qipan[i - 1][j] == 1 && Qipan[i - 2][j] == 1 && Qipan[i - 3][j] == 1 && Qipan[i - 4][j] == 0) {
					average[i][j] = average[i][j] + HUOSI;
				}
				if (Qipan[i + 1][j] == 0 && Qipan[i - 1][j] == 2 && Qipan[i - 2][j] == 2 && Qipan[i - 3][j] == 2 && Qipan[i - 4][j] == 0) {
					average[i][j] = average[i][j] + HUOSI;
				}
			}
		}
	}
	//����
	for (int i = 4; i < ROW - 1; i++) {
		for (int j = 0; j < COL; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i + 1][j] == 0 && Qipan[i - 1][j] == 1 && Qipan[i - 2][j] == 1 && Qipan[i - 3][j] == 1 && Qipan[i - 4][j] == 2) {
					average[i][j] = average[i][j] + CHONGSI;
				}
				if (Qipan[i + 1][j] == 0 && Qipan[i - 1][j] == 1 && Qipan[i - 2][j] == 1 && Qipan[i - 3][j] == 1 && Qipan[i - 4][j] == 1) {
					average[i][j] = average[i][j] + CHONGSI;
				}
			}
		}
	}
	//����-1----010110
	for (int i = 3; i < ROW - 2; i++) {
		for (int j = 0; j < COL; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i + 2][j] == 0 && Qipan[i + 1][j] == 1 && Qipan[i - 1][j] == 1 && Qipan[i - 2][j] == 1 && Qipan[i - 3][j] == 0) {
					average[i][j] = average[i][j] + HUOSI;
				}
				if (Qipan[i + 2][j] == 0 && Qipan[i + 1][j] == 2 && Qipan[i - 1][j] == 2 && Qipan[i - 2][j] == 2 && Qipan[i - 3][j] == 0) {
					average[i][j] = average[i][j] + HUOSI;
				}
			}
		}
	}
	//����
	for (int i = 3; i < ROW - 2; i++) {
		for (int j = 0; j < COL; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i + 2][j] == 0 && Qipan[i + 1][j] == 0 && Qipan[i - 1][j] == 1 && Qipan[i - 2][j] == 1 && Qipan[i - 3][j] == 0) {
					average[i][j] = average[i][j] + HUOSAN;
				}
				if (Qipan[i + 2][j] == 0 && Qipan[i + 1][j] == 0 && Qipan[i - 1][j] == 2 && Qipan[i - 2][j] == 2 && Qipan[i - 3][j] == 0) {
					average[i][j] = average[i][j] + HUOSAN;
				}
			}
		}
	}
	//����
	for (int i = 3; i < ROW - 2; i++) {
		for (int j = 0; j < COL; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i + 2][j] == 0 && Qipan[i + 1][j] == 0 && Qipan[i - 1][j] == 1 && Qipan[i - 2][j] == 1 && Qipan[i - 3][j] == 2) {
					average[i][j] = average[i][j] + MIANSAN;
				}
				if (Qipan[i + 2][j] == 0 && Qipan[i + 1][j] == 0 && Qipan[i - 1][j] == 2 && Qipan[i - 2][j] == 2 && Qipan[i - 3][j] == 1) {
					average[i][j] = average[i][j] + MIANSAN;
				}
			}
		}
	}
	//���
	for (int i = 2; i < ROW - 3; i++) {
		for (int j = 0; j < COL; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i + 3][j] == 0 && Qipan[i + 2][j] == 0 && Qipan[i + 1][j] == 1 && Qipan[i - 1][j] == 1 && Qipan[i - 2][j] == 0) {
					average[i][j] = average[i][j] + HUOER;
				}
				if (Qipan[i + 3][j] == 0 && Qipan[i + 2][j] == 0 && Qipan[i + 1][j] == 2 && Qipan[i - 1][j] == 1 && Qipan[i - 2][j] == 0) {
					average[i][j] = average[i][j] + HUOER;
				}
			}
		}
	}
	//�߶�
	for (int i = 2; i < ROW - 3; i++) {
		for (int j = 0; j < COL; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i + 3][j] == 0 && Qipan[i + 2][j] == 0 && Qipan[i + 1][j] == 1 && Qipan[i - 1][j] == 1 && Qipan[i - 2][j] == 2) {
					average[i][j] = average[i][j] + MIANER;
				}
				if (Qipan[i + 3][j] == 0 && Qipan[i + 2][j] == 0 && Qipan[i + 1][j] == 1 && Qipan[i - 1][j] == 2 && Qipan[i - 2][j] == 1) {
					average[i][j] = average[i][j] + MIANER;
				}
			}
		}
	}
	//��������

	//����������
	//����
	for (int i = 0; i < ROW - 4; i++) {
		for (int j = 0; j < COL - 4; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i + 1][j + 1] * Qipan[i + 2][j + 2] * Qipan[i + 3][j + 3] * Qipan[i + 4][j + 4] == 1) {
					average[i][j] = average[i][j] + LIANWU;
				}
				if (Qipan[i + 1][j + 1] * Qipan[i + 2][j + 2] * Qipan[i + 3][j + 3] * Qipan[i + 4][j + 4] == 16) {
					average[i][j] = average[i][j] + LIANWU;
				}
			}
		}
	}
	//����-1-----10111
	for (int i = 1; i < ROW - 3; i++) {
		for (int j = 1; j < COL - 3; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 1][j - 1] * Qipan[i + 1][j + 1] * Qipan[i + 2][j + 2] * Qipan[i + 3][j + 3] == 1) {
					average[i][j] = average[i][j] + LIANWU;
				}
				if (Qipan[i - 1][j - 1] * Qipan[i + 1][j + 1] * Qipan[i + 2][j + 2] * Qipan[i + 3][j + 3] == 16) {
					average[i][j] = average[i][j] + LIANWU;
				}
			}
		}
	}
	//����-2-----11011
	for (int i = 2; i < ROW - 2; i++) {
		for (int j = 2; j < COL - 2; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 2][j - 2] * Qipan[i - 1][j - 1] * Qipan[i + 1][j + 1] * Qipan[i + 2][j + 2] == 1) {
					average[i][j] = average[i][j] + LIANWU;
				}
				if (Qipan[i - 2][j - 2] * Qipan[i - 1][j - 1] * Qipan[i + 1][j + 1] * Qipan[i + 2][j + 2] == 16) {
					average[i][j] = average[i][j] + LIANWU;
				}
			}
		}
	}
	//����-3-----11101
	for (int i = 3; i < ROW - 1; i++) {
		for (int j = 3; j < COL - 1; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 3][j - 3] * Qipan[i - 2][j - 2] * Qipan[i - 1][j - 1] * Qipan[i + 1][j + 1] == 1) {
					average[i][j] = average[i][j] + LIANWU;
				}
				if (Qipan[i - 3][j - 3] * Qipan[i - 2][j - 2] * Qipan[i - 1][j - 1] * Qipan[i + 1][j + 1] == 16) {
					average[i][j] = average[i][j] + LIANWU;
				}
			}
		}
	}
	//����
	for (int i = 1; i < ROW - 4; i++) {
		for (int j = 1; j < COL - 4; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 1][j - 1] == 0 && Qipan[i + 1][j + 1] == 1 && Qipan[i + 2][j + 2] == 1 && Qipan[i + 3][j + 3] == 1 && Qipan[i + 4][j + 4] == 0) {
					average[i][j] = average[i][j] + HUOSI;
				}
				if (Qipan[i - 1][j - 1] == 0 && Qipan[i + 1][j + 1] == 2 && Qipan[i + 2][j + 2] == 2 && Qipan[i + 3][j + 3] == 2 && Qipan[i + 4][j + 4] == 0) {
					average[i][j] = average[i][j] + HUOSI;
				}
			}
		}
	}
	//����
	for (int i = 1; i < ROW - 4; i++) {
		for (int j = 1; j < COL - 4; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 1][j - 1] == 0 && Qipan[i + 1][j + 1] == 1 && Qipan[i + 2][j + 2] == 1 && Qipan[i + 3][j + 3] == 1 && Qipan[i + 4][j + 4] == 2) {
					average[i][j] = average[i][j] + CHONGSI;
				}
				if (Qipan[i - 1][j - 1] == 0 && Qipan[i + 1][j + 1] == 2 && Qipan[i + 2][j + 2] == 2 && Qipan[i + 3][j + 3] == 2 && Qipan[i + 4][j + 4] == 1) {
					average[i][j] = average[i][j] + CHONGSI;
				}
			}
		}
	}
	//����-1----010110
	for (int i = 2; i < ROW - 3; i++) {
		for (int j = 2; j < COL - 3; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 2][j - 2] == 0 && Qipan[i - 1][j - 1] == 1 && Qipan[i + 1][j + 1] == 1 && Qipan[i + 2][j + 2] == 1 && Qipan[i + 3][j + 3] == 0) {
					average[i][j] = average[i][j] + HUOSI;
				}
				if (Qipan[i - 2][j - 2] == 0 && Qipan[i - 1][j - 1] == 2 && Qipan[i + 1][j + 1] == 2 && Qipan[i + 2][j + 2] == 2 && Qipan[i + 3][j + 3] == 0) {
					average[i][j] = average[i][j] + HUOSI;
				}
			}
		}
	}
	//����
	for (int i = 2; i < ROW - 3; i++) {
		for (int j = 2; j < COL - 3; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 2][j - 2] == 0 && Qipan[i - 1][j - 1] == 0 && Qipan[i + 1][j + 1] == 1 && Qipan[i + 2][j + 2] == 1 && Qipan[i + 3][j + 3] == 0) {
					average[i][j] = average[i][j] + HUOSAN;
				}
				if (Qipan[i - 2][j - 2] == 0 && Qipan[i - 1][j - 1] == 0 && Qipan[i + 1][j + 1] == 2 && Qipan[i + 2][j + 2] == 2 && Qipan[i + 3][j + 3] == 0) {
					average[i][j] = average[i][j] + HUOSAN;
				}
			}
		}
	}
	//����
	for (int i = 2; i < ROW - 3; i++) {
		for (int j = 2; j < COL - 3; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 2][j - 2] == 0 && Qipan[i - 1][j - 1] == 0 && Qipan[i + 1][j + 1] == 1 && Qipan[i + 2][j + 2] == 1 && Qipan[i + 3][j + 3] == 2) {
					average[i][j] = average[i][j] + MIANSAN;
				}
				if (Qipan[i - 2][j - 2] == 0 && Qipan[i - 1][j - 1] == 0 && Qipan[i + 1][j + 1] == 2 && Qipan[i + 2][j + 2] == 2 && Qipan[i + 3][j + 3] == 1) {
					average[i][j] = average[i][j] + MIANSAN;
				}
			}
		}
	}
	//���
	for (int i = 3; i < ROW - 2; i++) {
		for (int j = 3; j < COL - 2; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 3][j - 3] == 0 && Qipan[i - 2][j - 2] == 0 && Qipan[i - 1][j - 1] == 0 && Qipan[i + 1][j + 1] == 1 && Qipan[i + 2][j + 2] == 0) {
					average[i][j] = average[i][j] + HUOER;
				}
				if (Qipan[i - 3][j - 3] == 0 && Qipan[i - 2][j - 2] == 0 && Qipan[i - 1][j - 1] == 0 && Qipan[i + 1][j + 1] == 2 && Qipan[i + 2][j + 2] == 0) {
					average[i][j] = average[i][j] + HUOER;
				}
			}
		}
	}
	//�߶�
	for (int i = 3; i < ROW - 2; i++) {
		for (int j = 3; j < COL - 2; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 3][j - 3] == 0 && Qipan[i - 2][j - 2] == 0 && Qipan[i - 1][j - 1] == 0 && Qipan[i + 1][j + 1] == 1 && Qipan[i + 2][j + 2] == 2) {
					average[i][j] = average[i][j] + MIANER;
				}
				if (Qipan[i - 3][j - 3] == 0 && Qipan[i - 2][j - 2] == 0 && Qipan[i - 1][j - 1] == 0 && Qipan[i + 1][j + 1] == 2 && Qipan[i + 2][j + 2] == 1) {
					average[i][j] = average[i][j] + MIANER;
				}
			}
		}
	}
	//������������

	//����������
	//����
	for (int i = 4; i < ROW; i++) {
		for (int j = 0; j < COL - 4; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 1][j + 1] * Qipan[i - 2][j + 2] * Qipan[i - 3][j + 3] * Qipan[i - 4][j + 4] == 1) {
					average[i][j] = average[i][j] + LIANWU;
				}
				if (Qipan[i - 1][j + 1] * Qipan[i - 2][j + 2] * Qipan[i - 3][j + 3] * Qipan[i - 4][j + 4] == 16) {
					average[i][j] = average[i][j] + LIANWU;
				}
			}
		}
	}
	//����-1-----10111
	for (int i = 3; i < ROW - 1; i++) {
		for (int j = 1; j < COL - 3; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i + 1][j - 1] * Qipan[i - 1][j + 1] * Qipan[i - 2][j + 2] * Qipan[i - 3][j + 3] == 1) {
					average[i][j] = average[i][j] + LIANWU;
				}
				if (Qipan[i - 1][j + 1] * Qipan[i - 2][j + 2] * Qipan[i - 3][j + 3] * Qipan[i - 4][j + 4] == 16) {
					average[i][j] = average[i][j] + LIANWU;
				}
			}
		}
	}
	//����-2-----11011
	for (int i = 2; i < ROW - 2; i++) {
		for (int j = 2; j < COL - 2; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i + 2][j - 2] * Qipan[i + 1][j - 1] * Qipan[i - 1][j + 1] * Qipan[i - 2][j + 2] == 1) {
					average[i][j] = average[i][j] + LIANWU;
				}
				if (Qipan[i + 2][j - 2] * Qipan[i + 1][j - 1] * Qipan[i - 1][j + 1] * Qipan[i - 2][j + 2] == 16) {
					average[i][j] = average[i][j] + LIANWU;
				}
			}
		}
	}
	//����-3-----11101
	for (int i = 1; i < ROW - 3; i++) {
		for (int j = 3; j < COL - 1; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i + 3][j - 3] * Qipan[i + 2][j - 2] * Qipan[i + 1][j - 1] * Qipan[i - 1][j + 1] == 1) {
					average[i][j] = average[i][j] + LIANWU;
				}
				if (Qipan[i + 3][j - 3] * Qipan[i + 2][j - 2] * Qipan[i + 1][j - 1] * Qipan[i - 1][j + 1] == 16) {
					average[i][j] = average[i][j] + LIANWU;
				}
			}
		}
	}
	//����
	for (int i = 4; i < ROW - 1; i++) {
		for (int j = 1; j < COL - 4; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i + 1][j - 1] == 0 && Qipan[i - 1][j + 1] == 1 && Qipan[i - 2][j + 2] == 1 && Qipan[i - 3][j + 3] == 1 && Qipan[i - 4][j + 4] == 0) {
					average[i][j] = average[i][j] + HUOSI;
				}
				if (Qipan[i + 1][j - 1] == 0 && Qipan[i - 1][j + 1] == 2 && Qipan[i - 2][j + 2] == 2 && Qipan[i - 3][j + 3] == 2 && Qipan[i - 4][j + 4] == 0) {
					average[i][j] = average[i][j] + HUOSI;
				}
			}
		}
	}
	//����
	for (int i = 4; i < ROW - 1; i++) {
		for (int j = 1; j < COL - 4; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i + 1][j - 1] == 0 && Qipan[i - 1][j + 1] == 1 && Qipan[i - 2][j + 2] == 1 && Qipan[i - 3][j + 3] == 1 && Qipan[i - 4][j + 4] == 2) {
					average[i][j] = average[i][j] + CHONGSI;
				}
				if (Qipan[i + 1][j - 1] == 0 && Qipan[i - 1][j + 1] == 2 && Qipan[i - 2][j + 2] == 2 && Qipan[i - 3][j + 3] == 2 && Qipan[i - 4][j + 4] == 1) {
					average[i][j] = average[i][j] + CHONGSI;
				}
			}
		}
	}
	//����-1----010110
	for (int i = 3; i < ROW - 2; i++) {
		for (int j = 2; j < COL - 3; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i + 2][j - 2] == 0 && Qipan[i + 1][j - 1] == 1 && Qipan[i - 1][j + 1] == 1 && Qipan[i - 2][j + 2] == 1 && Qipan[i - 3][j + 3] == 0) {
					average[i][j] = average[i][j] + HUOSI;
				}
				if (Qipan[i + 2][j - 2] == 0 && Qipan[i + 1][j - 1] == 2 && Qipan[i - 1][j + 1] == 2 && Qipan[i - 2][j + 2] == 2 && Qipan[i - 3][j + 3] == 0) {
					average[i][j] = average[i][j] + HUOSI;
				}
			}
		}
	}
	//����
	for (int i = 3; i < ROW - 2; i++) {
		for (int j = 2; j < COL - 3; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i + 2][j - 2] == 0 && Qipan[i + 1][j - 1] == 0 && Qipan[i - 1][j + 1] == 1 && Qipan[i - 2][j + 2] == 1 && Qipan[i - 3][j + 3] == 0) {
					average[i][j] = average[i][j] + HUOSAN;
				}
				if (Qipan[i + 2][j - 2] == 0 && Qipan[i + 1][j - 1] == 0 && Qipan[i - 1][j + 1] == 2 && Qipan[i - 2][j + 2] == 2 && Qipan[i - 3][j + 3] == 0) {
					average[i][j] = average[i][j] + HUOSAN;
				}
			}
		}
	}
	//����
	for (int i = 3; i < ROW - 2; i++) {
		for (int j = 2; j < COL - 3; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i + 2][j - 2] == 0 && Qipan[i + 1][j - 1] == 0 && Qipan[i - 1][j + 1] == 1 && Qipan[i - 2][j + 2] == 1 && Qipan[i - 3][j + 3] == 2) {
					average[i][j] = average[i][j] + MIANSAN;
				}
				if (Qipan[i + 2][j - 2] == 0 && Qipan[i + 1][j - 1] == 0 && Qipan[i - 1][j + 1] == 2 && Qipan[i - 2][j + 2] == 2 && Qipan[i - 3][j + 3] == 1) {
					average[i][j] = average[i][j] + MIANSAN;
				}
			}
		}
	}
	//���
	for (int i = 2; i < ROW - 3; i++) {
		for (int j = 3; j < COL - 2; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i + 3][j - 3] == 0 && Qipan[i + 2][j - 2] == 0 && Qipan[i + 1][j - 1] == 0 && Qipan[i - 1][j + 1] == 1 && Qipan[i - 2][j + 2] == 0) {
					average[i][j] = average[i][j] + HUOER;
				}
				if (Qipan[i + 3][j - 3] == 0 && Qipan[i + 2][j - 2] == 0 && Qipan[i + 1][j - 1] == 0 && Qipan[i - 1][j + 1] == 2 && Qipan[i - 2][j + 2] == 0) {
					average[i][j] = average[i][j] + HUOER;
				}
			}
		}
	}
	//�߶�
	for (int i = 2; i < ROW - 3; i++) {
		for (int j = 3; j < COL - 2; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i + 3][j - 3] == 0 && Qipan[i + 2][j - 2] == 0 && Qipan[i + 1][j - 1] == 0 && Qipan[i - 1][j + 1] == 1 && Qipan[i - 2][j + 2] == 2) {
					average[i][j] = average[i][j] + MIANER;
				}
				if (Qipan[i + 3][j - 3] == 0 && Qipan[i + 2][j - 2] == 0 && Qipan[i + 1][j - 1] == 0 && Qipan[i - 1][j + 1] == 2 && Qipan[i - 2][j + 2] == 1) {
					average[i][j] = average[i][j] + MIANER;
				}
			}
		}
	}
	//������������

	//����������
	//����
	for (int i = 0; i < ROW - 4; i++) {
		for (int j = 4; j < COL; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i + 1][j - 1] * Qipan[i + 2][j - 2] * Qipan[i + 3][j - 3] * Qipan[i + 4][j - 4] == 1) {
					average[i][j] = average[i][j] + LIANWU;
				}
				if (Qipan[i + 1][j - 1] * Qipan[i + 2][j - 2] * Qipan[i + 3][j - 3] * Qipan[i + 4][j - 4] == 16) {
					average[i][j] = average[i][j] + LIANWU;
				}
			}
		}
	}
	//����
	for (int i = 1; i < ROW - 4; i++) {
		for (int j = 4; j < COL - 1; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 1][j + 1] == 0 && Qipan[i + 1][j - 1] == 1 && Qipan[i + 2][j - 2] == 1 && Qipan[i + 3][j - 3] == 1 && Qipan[i + 4][j - 4] == 0) {
					average[i][j] = average[i][j] + HUOSI;
				}
				if (Qipan[i - 1][j + 1] == 0 && Qipan[i + 1][j - 1] == 2 && Qipan[i + 2][j - 2] == 2 && Qipan[i + 3][j - 3] == 2 && Qipan[i + 4][j - 4] == 0) {
					average[i][j] = average[i][j] + HUOSI;
				}
			}
		}
	}
	//����
	for (int i = 1; i < ROW - 4; i++) {
		for (int j = 4; j < COL - 1; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 1][j + 1] == 0 && Qipan[i + 1][j - 1] == 1 && Qipan[i + 2][j - 2] == 1 && Qipan[i + 3][j - 3] == 1 && Qipan[i + 4][j - 4] == 2) {
					average[i][j] = average[i][j] + CHONGSI;
				}
				if (Qipan[i - 1][j + 1] == 0 && Qipan[i + 1][j - 1] == 2 && Qipan[i + 2][j - 2] == 2 && Qipan[i + 3][j - 3] == 2 && Qipan[i + 4][j - 4] == 1) {
					average[i][j] = average[i][j] + CHONGSI;
				}
			}
		}
	}
	//����-1----010110
	for (int i = 2; i < ROW - 3; i++) {
		for (int j = 3; j < COL - 2; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 2][j + 2] == 0 && Qipan[i - 1][j + 1] == 1 && Qipan[i + 1][j - 1] == 1 && Qipan[i + 2][j - 2] == 1 && Qipan[i + 3][j - 3] == 0) {
					average[i][j] = average[i][j] + HUOSI;
				}
				if (Qipan[i - 2][j + 2] == 0 && Qipan[i - 1][j + 1] == 2 && Qipan[i + 1][j - 1] == 2 && Qipan[i + 2][j - 2] == 2 && Qipan[i + 3][j - 3] == 0) {
					average[i][j] = average[i][j] + HUOSI;
				}
			}
		}
	}
	//����
	for (int i = 2; i < ROW - 3; i++) {
		for (int j = 3; j < COL - 2; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 2][j + 2] == 0 && Qipan[i - 1][j + 1] == 0 && Qipan[i + 1][j - 1] == 1 && Qipan[i + 2][j - 2] == 1 && Qipan[i + 3][j - 3] == 0) {
					average[i][j] = average[i][j] + HUOSAN;
				}
				if (Qipan[i - 2][j + 2] == 0 && Qipan[i - 1][j + 1] == 0 && Qipan[i + 1][j - 1] == 2 && Qipan[i + 2][j - 2] == 2 && Qipan[i + 3][j - 3] == 0) {
					average[i][j] = average[i][j] + HUOSAN;
				}
			}
		}
	}
	//����
	for (int i = 2; i < ROW - 3; i++) {
		for (int j = 3; j < COL - 2; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 2][j + 2] == 0 && Qipan[i - 1][j + 1] == 0 && Qipan[i + 1][j - 1] == 1 && Qipan[i + 2][j - 2] == 1 && Qipan[i + 3][j - 3] == 2) {
					average[i][j] = average[i][j] + MIANSAN;
				}
				if (Qipan[i - 2][j + 2] == 0 && Qipan[i - 1][j + 1] == 0 && Qipan[i + 1][j - 1] == 2 && Qipan[i + 2][j - 2] == 2 && Qipan[i + 3][j - 3] == 1) {
					average[i][j] = average[i][j] + MIANSAN;
				}
			}
		}
	}
	//���
	for (int i = 3; i < ROW - 2; i++) {
		for (int j = 2; j < COL - 3; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 3][j + 3] == 0 && Qipan[i - 2][j + 2] == 0 && Qipan[i - 1][j + 1] == 0 && Qipan[i + 1][j - 1] == 1 && Qipan[i + 2][j - 2] == 0) {
					average[i][j] = average[i][j] + HUOER;
				}
				if (Qipan[i - 3][j + 3] == 0 && Qipan[i - 2][j + 2] == 0 && Qipan[i - 1][j + 1] == 0 && Qipan[i + 1][j - 1] == 2 && Qipan[i + 2][j - 2] == 0) {
					average[i][j] = average[i][j] + HUOER;
				}
			}
		}
	}
	//�߶�
	for (int i = 3; i < ROW - 2; i++) {
		for (int j = 2; j < COL - 3; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 3][j + 3] == 0 && Qipan[i - 2][j + 2] == 0 && Qipan[i - 1][j + 1] == 0 && Qipan[i + 1][j - 1] == 1 && Qipan[i + 2][j - 2] == 2) {
					average[i][j] = average[i][j] + MIANER;
				}
				if (Qipan[i - 3][j + 3] == 0 && Qipan[i - 2][j + 2] == 0 && Qipan[i - 1][j + 1] == 0 && Qipan[i + 1][j - 1] == 2 && Qipan[i + 2][j - 2] == 1) {
					average[i][j] = average[i][j] + MIANER;
				}
			}
		}
	}
	//������������

	//����������
	//����
	for (int i = 4; i < ROW; i++) {
		for (int j = 4; j < COL; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 1][j - 1] * Qipan[i - 2][j - 2] * Qipan[i - 3][j - 3] * Qipan[i - 4][j - 4] == 1) {
					average[i][j] = average[i][j] + LIANWU;
				}
				if (Qipan[i - 1][j - 1] * Qipan[i - 2][j - 2] * Qipan[i - 3][j - 3] * Qipan[i - 4][j - 4] == 16) {
					average[i][j] = average[i][j] + LIANWU;
				}
			}
		}
	}
	//����
	for (int i = 4; i < ROW  -1; i++) {
		for (int j = 4; j < COL - 1; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i + 1][j + 1] == 0 && Qipan[i - 1][j - 1] == 1 && Qipan[i - 2][j - 2] == 1 && Qipan[i - 3][j - 3] == 1 && Qipan[i - 4][j - 4] == 0) {
					average[i][j] = average[i][j] + HUOSI;
				}
				if (Qipan[i + 1][j + 1] == 0 && Qipan[i - 1][j - 1] == 2 && Qipan[i - 2][j - 2] == 2 && Qipan[i - 3][j - 3] == 2 && Qipan[i - 4][j - 4] == 0) {
					average[i][j] = average[i][j] + HUOSI;
				}
			}
		}
	}
	//����
	for (int i = 4; i < ROW - 1; i++) {
		for (int j = 4; j < COL - 1; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i + 1][j + 1] == 0 && Qipan[i - 1][j - 1] == 1 && Qipan[i - 2][j - 2] == 1 && Qipan[i - 3][j - 3] == 1 && Qipan[i - 4][j - 4] == 2) {
					average[i][j] = average[i][j] + CHONGSI;
				}
				if (Qipan[i + 1][j + 1] == 0 && Qipan[i - 1][j - 1] == 2 && Qipan[i - 2][j - 2] == 2 && Qipan[i - 3][j - 3] == 2 && Qipan[i - 4][j - 4] == 1) {
					average[i][j] = average[i][j] + CHONGSI;
				}
			}
		}
	}
	//����-1----010110
	for (int i = 3; i < ROW - 2; i++) {
		for (int j = 3; j < COL - 2; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i + 2][j + 2] == 0 && Qipan[i + 1][j + 1] == 1 && Qipan[i - 1][j - 1] == 1 && Qipan[i - 2][j - 2] == 1 && Qipan[i - 3][j - 3] == 0) {
					average[i][j] = average[i][j] + HUOSI;
				}
				if (Qipan[i + 2][j + 2] == 0 && Qipan[i + 1][j + 1] == 2 && Qipan[i - 1][j - 1] == 2 && Qipan[i - 2][j - 2] == 2 && Qipan[i - 3][j - 3] == 0) {
					average[i][j] = average[i][j] + HUOSI;
				}
			}
		}
	}
	//����
	for (int i = 3; i < ROW - 2; i++) {
		for (int j = 3; j < COL - 2; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i + 2][j + 2] == 0 && Qipan[i + 1][j + 1] == 0 && Qipan[i - 1][j - 1] == 1 && Qipan[i - 2][j - 2] == 1 && Qipan[i - 3][j - 3] == 0) {
					average[i][j] = average[i][j] + HUOSAN;
				}
				if (Qipan[i + 2][j + 2] == 0 && Qipan[i + 1][j + 1] == 0 && Qipan[i - 1][j - 1] == 2 && Qipan[i - 2][j - 2] == 2 && Qipan[i - 3][j - 3] == 0) {
					average[i][j] = average[i][j] + HUOSAN;
				}
			}
		}
	}
	//����
	for (int i = 3; i < ROW - 2; i++) {
		for (int j = 3; j < COL - 2; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i + 2][j + 2] == 0 && Qipan[i + 1][j + 1] == 0 && Qipan[i - 1][j - 1] == 1 && Qipan[i - 2][j - 2] == 1 && Qipan[i - 3][j - 3] == 2) {
					average[i][j] = average[i][j] + MIANSAN;
				}
				if (Qipan[i + 2][j + 2] == 0 && Qipan[i + 1][j + 1] == 0 && Qipan[i - 1][j - 1] == 2 && Qipan[i - 2][j - 2] == 2 && Qipan[i - 3][j - 3] == 1) {
					average[i][j] = average[i][j] + MIANSAN;
				}
			}
		}
	}
	//���
	for (int i = 2; i < ROW - 3; i++) {
		for (int j = 2; j < COL - 3; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i + 3][j + 3] == 0 && Qipan[i + 2][j + 2] == 0 && Qipan[i + 1][j + 1] == 0 && Qipan[i - 1][j - 1] == 1 && Qipan[i - 2][j - 2] == 0) {
					average[i][j] = average[i][j] + HUOER;
				}
				if (Qipan[i + 3][j + 3] == 0 && Qipan[i + 2][j + 2] == 0 && Qipan[i + 1][j + 1] == 0 && Qipan[i - 1][j - 1] == 2 && Qipan[i - 2][j - 2] == 0) {
					average[i][j] = average[i][j] + HUOER;
				}
			}
		}
	}
	//�߶�
	for (int i = 2; i < ROW - 3; i++) {
		for (int j = 2; j < COL - 3; j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i + 3][j + 3] == 0 && Qipan[i + 2][j + 2] == 0 && Qipan[i + 1][j + 1] == 0 && Qipan[i - 1][j - 1] == 1 && Qipan[i - 2][j - 2] == 2) {
					average[i][j] = average[i][j] + MIANER;
				}
				if (Qipan[i + 3][j + 3] == 0 && Qipan[i + 2][j + 2] == 0 && Qipan[i + 1][j + 1] == 0 && Qipan[i - 1][j - 1] == 2 && Qipan[i - 2][j - 2] == 1) {
					average[i][j] = average[i][j] + MIANER;
				}
			}
		}
	}
	//������������

	int x = 0, y = 0;
	//�����ֵ
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (average[i][j] > max && Qipan[i][j] == 0) {
				max = average[i][j];
				x = i;
				y = j;
			}
		}
	}
	Qipan[x][y] = 2;
}

void AI2() {
	/*
1.   ���壺���ͬɫ��������һ����11111��22222
2.   ���ģ�������������γ����壬��011110��022220
3.   ���ģ���һ��������γ����壬��011112��122220
4.   �����������γɻ��ĵ����㣬��001110��002220
5.   ������ֻ���γɳ��ĵ����㣬��001112��002221
6.   ������ܹ��γɻ����Ķ��㣬��000110��000220
7.   �߶����ܹ��γ������Ķ��㣬��000112��000221
����Ȩ��
����100000000
����10000000
����1000000
����100000
����10000
���1000
�߶�100
��һ10
��1
*/
#define LIANWU 100000000
#define HUOSI 10000000
#define CHONGSI 1000000
#define HUOSAN 100000
#define MIANSAN 10000
#define HUOER 1000
#define MIANER 100
#define JINYI 10
#define WUYI 1

	long max = -1;
	//Ȩ�ؾ����ʼ��
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			average[i][j] = -1;
		}
	}
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (!Qipan[i][j]) {
				average[i][j] = 0;
			}
		}
	}
	int m = 0, n = 0;//��m��n����ʾ����m----�У�n----�У�m+1----����һ�У�n+1����һ��
	

	//���ң�m��n��=��0��1��
	m = 0; n = 1;
	calculate(m, n);

	//���£�m��n��=��1��0��
	m = 1; n = 0;
	calculate(m, n);

	//�����£�m��n��=��1��1��
	m = 1; n = 1;
	calculate(m, n);

	//�����ϣ�m��n��=��1��-1��
	m = -1; n = 1;
	calculate(m, n);


	int x = 0, y = 0;
	//�����ֵ
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (average[i][j] > max && Qipan[i][j] == 0) {
				max = average[i][j];
				x = i;
				y = j;
			}
		}
	}
	Qipan[x][y] = 2;
}
void calculate(int m, int n) {
	//����
	lianwu(m, n);
	//����
	huosi(m, n);
	//����
	huosan(m, n);
	//���
	huoer(m, n);
	//����
	chongsi(m, n);
	//����
	miansan(m, n);
	//�߶�
	mianer(m, n);
}

void lianwu(int m, int n) {
	//����x1111
	for (int i = 0 + 0 * m; i < (ROW - 4 * m); i++) {
		for (int j = 0 + 0 * n; j < (COL - 4 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i + 1 * m][j + 1 * n] * Qipan[i + 2 * m][j + 2 * n] * Qipan[i + 3 * m][j + 3 * n] * Qipan[i + 4 * m][j + 4 * n] == 1) {
					average[i][j] = average[i][j] + LIANWU;
				}
				if (Qipan[i + 1 * m][j + 1 * n] * Qipan[i + 2 * m][j + 2 * n] * Qipan[i + 3 * m][j + 3 * n] * Qipan[i + 4 * m][j + 4 * n] == 16) {
					average[i][j] = average[i][j] + LIANWU;
				}
			}
		}
	}
	//����1x111
	for (int i = 0 + 1 * m; i < (ROW - 3 * m); i++) {
		for (int j = 0 + 1 * n; j < (COL - 3 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 1 * m][j - 1 * n] * Qipan[i + 1 * m][j + 1 * n] * Qipan[i + 2 * m][j + 2 * n] * Qipan[i + 3 * m][j + 3 * n] == 1) {
					average[i][j] = average[i][j] + LIANWU;
				}
				if (Qipan[i - 1 * m][j - 1 * n] * Qipan[i + 1 * m][j + 1 * n] * Qipan[i + 2 * m][j + 2 * n] * Qipan[i + 3 * m][j + 3 * n] == 16) {
					average[i][j] = average[i][j] + LIANWU;
				}
			}
		}
	}
	//����11x11
	for (int i = 0 + 2 * m; i < (ROW - 2 * m); i++) {
		for (int j = 0 + 2 * n; j < (COL - 2 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 2 * m][j - 2 * n] * Qipan[i - 1 * m][j - 1 * n] * Qipan[i + 1 * m][j + 1 * n] * Qipan[i + 2 * m][j + 2 * n] == 1) {
					average[i][j] = average[i][j] + LIANWU;
				}
				if (Qipan[i - 2 * m][j - 2 * n] * Qipan[i - 1 * m][j - 1 * n] * Qipan[i + 1 * m][j + 1 * n] * Qipan[i + 2 * m][j + 2 * n] == 16) {
					average[i][j] = average[i][j] + LIANWU;
				}
			}
		}
	}
	//����111x1
	for (int i = 0 + 3 * m; i < (ROW - 1 * m); i++) {
		for (int j = 0 + 3 * n; j < (COL - 1 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 3 * m][j - 3 * n] * Qipan[i - 2 * m][j - 2 * n] * Qipan[i - 1 * m][j - 1 * n] * Qipan[i + 1 * m][j + 1 * n] == 1) {
					average[i][j] = average[i][j] + LIANWU;
				}
				if (Qipan[i - 3 * m][j - 3 * n] * Qipan[i - 2 * m][j - 2 * n] * Qipan[i - 1 * m][j - 1 * n] * Qipan[i + 1 * m][j + 1 * n] == 16) {
					average[i][j] = average[i][j] + LIANWU;
				}
			}
		}
	}
	//����111x1
	for (int i = 0 + 3 * m; i < (ROW - 1 * m); i++) {
		for (int j = 0 + 3 * n; j < (COL - 1 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 3 * m][j - 3 * n] * Qipan[i - 2 * m][j - 2 * n] * Qipan[i - 1 * m][j - 1 * n] * Qipan[i + 1 * m][j + 1 * n] == 1) {
					average[i][j] = average[i][j] + LIANWU;
				}
				if (Qipan[i - 3 * m][j - 3 * n] * Qipan[i - 2 * m][j - 2 * n] * Qipan[i - 1 * m][j - 1 * n] * Qipan[i + 1 * m][j + 1 * n] == 16) {
					average[i][j] = average[i][j] + LIANWU;
				}
			}
		}
	}
	//����1111x
	for (int i = 0 + 4 * m; i < (ROW - 0 * m); i++) {
		for (int j = 0 + 4 * n; j < (COL - 0 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 4 * m][j - 4 * n] * Qipan[i - 3 * m][j - 3 * n] * Qipan[i - 2 * m][j - 2 * n] * Qipan[i - 1 * m][j - 1 * n] == 1) {
					average[i][j] = average[i][j] + LIANWU;
				}
				if (Qipan[i - 4 * m][j - 4 * n] * Qipan[i - 3 * m][j - 3 * n] * Qipan[i - 2 * m][j - 2 * n] * Qipan[i - 1 * m][j - 1 * n] == 16) {
					average[i][j] = average[i][j] + LIANWU;
				}
			}
		}
	}
}

void huosi(int m, int n) {
	//����0x1110
	for (int i = 0 + 1 * m; i < (ROW - 4 * m); i++) {
		for (int j = 0 + 1 * n; j < (COL - 4 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 1 * m][j - 1 * n] == 0 && Qipan[i + 1 * m][j + 1 * n] == 1 && Qipan[i + 2 * m][j + 2 * n] == 1 && Qipan[i + 3 * m][j + 3 * n] == 1 && Qipan[i + 4 * m][j + 4 * n] == 0) {
					average[i][j] = average[i][j] + HUOSI;
				}
				if (Qipan[i - 1 * m][j - 1 * n] == 0 && Qipan[i + 1 * m][j + 1 * n] == 2 && Qipan[i + 2 * m][j + 2 * n] == 2 && Qipan[i + 3 * m][j + 3 * n] == 2 && Qipan[i + 4 * m][j + 4 * n] == 0) {
					average[i][j] = average[i][j] + HUOSI;
				}
			}
		}
	}
	//����01x110
	for (int i = 0 + 2 * m; i < (ROW - 3 * m); i++) {
		for (int j = 0 + 2 * n; j < (COL - 3 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 2 * m][j - 2 * n] == 0 && Qipan[i - 1 * m][j - 1 * n] == 1 && Qipan[i + 1 * m][j + 1 * n] == 1 && Qipan[i + 2 * m][j + 2 * n] == 1 && Qipan[i + 3 * m][j + 3 * n] == 0) {
					average[i][j] = average[i][j] + HUOSI;
				}
				if (Qipan[i - 2 * m][j - 2 * n] == 0 && Qipan[i - 1 * m][j - 1 * n] == 2 && Qipan[i + 1 * m][j + 1 * n] == 2 && Qipan[i + 2 * m][j + 2 * n] == 2 && Qipan[i + 3 * m][j + 3 * n] == 0) {
					average[i][j] = average[i][j] + HUOSI;
				}
			}
		}
	}
	//����011x10
	for (int i = 0 + 3 * m; i < (ROW - 2 * m); i++) {
		for (int j = 0 + 3 * n; j < (COL - 2 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 3 * m][j - 3 * n] == 0 && Qipan[i - 2 * m][j - 2 * n] == 1 && Qipan[i - 1 * m][j - 1 * n] == 1 && Qipan[i + 1 * m][j + 1 * n] == 1 && Qipan[i + 2 * m][j + 2 * n] == 0) {
					average[i][j] = average[i][j] + HUOSI;
				}
				if (Qipan[i - 3 * m][j - 3 * n] == 0 && Qipan[i - 2 * m][j - 2 * n] == 2 && Qipan[i - 1 * m][j - 1 * n] == 2 && Qipan[i + 1 * m][j + 1 * n] == 2 && Qipan[i + 2 * m][j + 2 * n] == 0) {
					average[i][j] = average[i][j] + HUOSI;
				}
			}
		}
	}
	//����0111x0
	for (int i = 0 + 4 * m; i < (ROW - 1 * m); i++) {
		for (int j = 0 + 4 * n; j < (COL - 1 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 4 * m][j - 4 * n] == 0 && Qipan[i - 3 * m][j - 3 * n] == 1 && Qipan[i - 2 * m][j - 2 * n] == 1 && Qipan[i - 1 * m][j - 1 * n] == 1 && Qipan[i + 1 * m][j + 1 * n] == 0) {
					average[i][j] = average[i][j] + HUOSI;
				}
				if (Qipan[i - 4 * m][j - 4 * n] == 0 && Qipan[i - 3 * m][j - 3 * n] == 2 && Qipan[i - 2 * m][j - 2 * n] == 2 && Qipan[i - 1 * m][j - 1 * n] == 2 && Qipan[i + 1 * m][j + 1 * n] == 0) {
					average[i][j] = average[i][j] + HUOSI;
				}
			}
		}
	}
}

void huosan(int m, int n) {
	//����0x1100
	for (int i = 0 + 1 * m; i < (ROW - 4 * m); i++) {
		for (int j = 0 + 1 * n; j < (COL - 4 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 1 * m][j - 1 * n] == 0 && Qipan[i + 1 * m][j + 1 * n] == 1 && Qipan[i + 2 * m][j + 2 * n] == 1 && Qipan[i + 3 * m][j + 3 * n] == 0 && Qipan[i + 4 * m][j + 4 * n] == 0) {
					average[i][j] = average[i][j] + HUOSAN;
				}
				if (Qipan[i - 1 * m][j - 1 * n] == 0 && Qipan[i + 1 * m][j + 1 * n] == 2 && Qipan[i + 2 * m][j + 2 * n] == 2 && Qipan[i + 3 * m][j + 3 * n] == 0 && Qipan[i + 4 * m][j + 4 * n] == 0) {
					average[i][j] = average[i][j] + HUOSAN;
				}
			}
		}
	}
	//����01x100
	for (int i = 0 + 2 * m; i < (ROW - 3 * m); i++) {
		for (int j = 0 + 2 * n; j < (COL - 3 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 2 * m][j - 2 * n] == 0 && Qipan[i - 1 * m][j - 1 * n] == 1 && Qipan[i + 1 * m][j + 1 * n] == 1 && Qipan[i + 2 * m][j + 2 * n] == 0 && Qipan[i + 3 * m][j + 3 * n] == 0) {
					average[i][j] = average[i][j] + HUOSAN;
				}
				if (Qipan[i - 2 * m][j - 2 * n] == 0 && Qipan[i - 1 * m][j - 1 * n] == 2 && Qipan[i + 1 * m][j + 1 * n] == 2 && Qipan[i + 2 * m][j + 2 * n] == 0 && Qipan[i + 3 * m][j + 3 * n] == 0) {
					average[i][j] = average[i][j] + HUOSAN;
				}
			}
		}
	}
	//����011x00
	for (int i = 0 + 3 * m; i < (ROW - 2 * m); i++) {
		for (int j = 0 + 3 * n; j < (COL - 2 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 3 * m][j - 3 * n] == 0 && Qipan[i - 2 * m][j - 2 * n] == 1 && Qipan[i - 1 * m][j - 1 * n] == 1 && Qipan[i + 1 * m][j + 1 * n] == 0 && Qipan[i + 2 * m][j + 2 * n] == 0) {
					average[i][j] = average[i][j] + HUOSAN;
				}
				if (Qipan[i - 3 * m][j - 3 * n] == 0 && Qipan[i - 2 * m][j - 2 * n] == 2 && Qipan[i - 1 * m][j - 1 * n] == 2 && Qipan[i + 1 * m][j + 1 * n] == 0 && Qipan[i + 2 * m][j + 2 * n] == 0) {
					average[i][j] = average[i][j] + HUOSAN;
				}
			}
		}
	}
	//����00x110
	for (int i = 0 + 2 * m; i < (ROW - 3 * m); i++) {
		for (int j = 0 + 2 * n; j < (COL - 3 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 2 * m][j - 2 * n] == 0 && Qipan[i - 1 * m][j - 1 * n] == 0 && Qipan[i + 1 * m][j + 1 * n] == 1 && Qipan[i + 2 * m][j + 2 * n] == 1 && Qipan[i + 3 * m][j + 3 * n] == 0) {
					average[i][j] = average[i][j] + HUOSAN;
				}
				if (Qipan[i - 2 * m][j - 2 * n] == 0 && Qipan[i - 1 * m][j - 1 * n] == 0 && Qipan[i + 1 * m][j + 1 * n] == 2 && Qipan[i + 2 * m][j + 2 * n] == 2 && Qipan[i + 3 * m][j + 3 * n] == 0) {
					average[i][j] = average[i][j] + HUOSAN;
				}
			}
		}
	}
	//����001x10
	for (int i = 0 + 3 * m; i < (ROW - 2 * m); i++) {
		for (int j = 0 + 3 * n; j < (COL - 2 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 3 * m][j - 3 * n] == 0 && Qipan[i - 2 * m][j - 2 * n] == 0 && Qipan[i - 1 * m][j - 1 * n] == 1 && Qipan[i + 1 * m][j + 1 * n] == 1 && Qipan[i + 2 * m][j + 2 * n] == 0) {
					average[i][j] = average[i][j] + HUOSAN;
				}
				if (Qipan[i - 3 * m][j - 3 * n] == 0 && Qipan[i - 2 * m][j - 2 * n] == 0 && Qipan[i - 1 * m][j - 1 * n] == 2 && Qipan[i + 1 * m][j + 1 * n] == 2 && Qipan[i + 2 * m][j + 2 * n] == 0) {
					average[i][j] = average[i][j] + HUOSAN;
				}
			}
		}
	}
	//����0011x0
	for (int i = 0 + 4 * m; i < (ROW - 1 * m); i++) {
		for (int j = 0 + 4 * n; j < (COL - 1 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 4 * m][j - 4 * n] == 0 && Qipan[i - 3 * m][j - 3 * n] == 0 && Qipan[i - 2 * m][j - 2 * n] == 1 && Qipan[i - 1 * m][j - 1 * n] == 1 && Qipan[i + 1 * m][j + 1 * n] == 0) {
					average[i][j] = average[i][j] + HUOSAN;
				}
				if (Qipan[i - 4 * m][j - 4 * n] == 0 && Qipan[i - 3 * m][j - 3 * n] == 0 && Qipan[i - 2 * m][j - 2 * n] == 2 && Qipan[i - 1 * m][j - 1 * n] == 2 && Qipan[i + 1 * m][j + 1 * n] == 0) {
					average[i][j] = average[i][j] + HUOSAN;
				}
			}
		}
	}
}

void huoer(int m, int n) {
	//���0x1000
	for (int i = 0 + 1 * m; i < (ROW - 4 * m); i++) {
		for (int j = 0 + 1 * n; j < (COL - 4 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 1 * m][j - 1 * n] == 0 && Qipan[i + 1 * m][j + 1 * n] == 1 && Qipan[i + 2 * m][j + 2 * n] == 0 && Qipan[i + 3 * m][j + 3 * n] == 0 && Qipan[i + 4 * m][j + 4 * n] == 0) {
					average[i][j] = average[i][j] + HUOER;
				}
				if (Qipan[i - 1 * m][j - 1 * n] == 0 && Qipan[i + 1 * m][j + 1 * n] == 2 && Qipan[i + 2 * m][j + 2 * n] == 0 && Qipan[i + 3 * m][j + 3 * n] == 0 && Qipan[i + 4 * m][j + 4 * n] == 0) {
					average[i][j] = average[i][j] + HUOER;
				}
			}
		}
	}
	//���01x000
	for (int i = 0 + 2 * m; i < (ROW - 3 * m); i++) {
		for (int j = 0 + 2 * n; j < (COL - 3 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 2 * m][j - 2 * n] == 0 && Qipan[i - 1 * m][j - 1 * n] == 1 && Qipan[i + 1 * m][j + 1 * n] == 0 && Qipan[i + 2 * m][j + 2 * n] == 0 && Qipan[i + 3 * m][j + 3 * n] == 0) {
					average[i][j] = average[i][j] + HUOER;
				}
				if (Qipan[i - 2 * m][j - 2 * n] == 0 && Qipan[i - 1 * m][j - 1 * n] == 2 && Qipan[i + 1 * m][j + 1 * n] == 0 && Qipan[i + 2 * m][j + 2 * n] == 0 && Qipan[i + 3 * m][j + 3 * n] == 0) {
					average[i][j] = average[i][j] + HUOER;
				}
			}
		}
	}
	//���000x10
	for (int i = 0 + 3 * m; i < (ROW - 2 * m); i++) {
		for (int j = 0 + 3 * n; j < (COL - 2 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 3 * m][j - 3 * n] == 0 && Qipan[i - 2 * m][j - 2 * n] == 0 && Qipan[i - 1 * m][j - 1 * n] == 0 && Qipan[i + 1 * m][j + 1 * n] == 1 && Qipan[i + 2 * m][j + 2 * n] == 0) {
					average[i][j] = average[i][j] + HUOER;
				}
				if (Qipan[i - 3 * m][j - 3 * n] == 0 && Qipan[i - 2 * m][j - 2 * n] == 0 && Qipan[i - 1 * m][j - 1 * n] == 0 && Qipan[i + 1 * m][j + 1 * n] == 2 && Qipan[i + 2 * m][j + 2 * n] == 0) {
					average[i][j] = average[i][j] + HUOER;
				}
			}
		}
	}
	//���0001x0
	for (int i = 0 + 4 * m; i < (ROW - 1 * m); i++) {
		for (int j = 0 + 4 * n; j < (COL - 1 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 4 * m][j - 4 * n] == 0 && Qipan[i - 3 * m][j - 3 * n] == 0 && Qipan[i - 2 * m][j - 2 * n] == 0 && Qipan[i - 1 * m][j - 1 * n] == 1 && Qipan[i + 1 * m][j + 1 * n] == 0) {
					average[i][j] = average[i][j] + HUOER;
				}
				if (Qipan[i - 4 * m][j - 4 * n] == 0 && Qipan[i - 3 * m][j - 3 * n] == 0 && Qipan[i - 2 * m][j - 2 * n] == 0 && Qipan[i - 1 * m][j - 1 * n] == 2 && Qipan[i + 1 * m][j + 1 * n] == 0) {
					average[i][j] = average[i][j] + HUOER;
				}
			}
		}
	}
}

void chongsi(int m, int n) {
	//����0x1112
	for (int i = 0 + 1 * m; i < (ROW - 4 * m); i++) {
		for (int j = 0 + 1 * n; j < (COL - 4 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 1 * m][j - 1 * n] == 0 && Qipan[i + 1 * m][j + 1 * n] == 1 && Qipan[i + 2 * m][j + 2 * n] == 1 && Qipan[i + 3 * m][j + 3 * n] == 1 && Qipan[i + 4 * m][j + 4 * n] == 2) {
					average[i][j] = average[i][j] + CHONGSI;
				}
				if (Qipan[i - 1 * m][j - 1 * n] == 0 && Qipan[i + 1 * m][j + 1 * n] == 2 && Qipan[i + 2 * m][j + 2 * n] == 2 && Qipan[i + 3 * m][j + 3 * n] == 2 && Qipan[i + 4 * m][j + 4 * n] == 1) {
					average[i][j] = average[i][j] + CHONGSI;
				}
			}
		}
	}
	//����01x112
	for (int i = 0 + 2 * m; i < (ROW - 3 * m); i++) {
		for (int j = 0 + 2 * n; j < (COL - 3 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 2 * m][j - 2 * n] == 0 && Qipan[i - 1 * m][j - 1 * n] == 1 && Qipan[i + 1 * m][j + 1 * n] == 1 && Qipan[i + 2 * m][j + 2 * n] == 1 && Qipan[i + 3 * m][j + 3 * n] == 2) {
					average[i][j] = average[i][j] + CHONGSI;
				}
				if (Qipan[i - 2 * m][j - 2 * n] == 0 && Qipan[i - 1 * m][j - 1 * n] == 2 && Qipan[i + 1 * m][j + 1 * n] == 2 && Qipan[i + 2 * m][j + 2 * n] == 2 && Qipan[i + 3 * m][j + 3 * n] == 1) {
					average[i][j] = average[i][j] + CHONGSI;
				}
			}
		}
	}
	//����011x12
	for (int i = 0 + 3 * m; i < (ROW - 2 * m); i++) {
		for (int j = 0 + 3 * n; j < (COL - 2 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 3 * m][j - 3 * n] == 0 && Qipan[i - 2 * m][j - 2 * n] == 1 && Qipan[i - 1 * m][j - 1 * n] == 1 && Qipan[i + 1 * m][j + 1 * n] == 1 && Qipan[i + 2 * m][j + 2 * n] == 2) {
					average[i][j] = average[i][j] + CHONGSI;
				}
				if (Qipan[i - 3 * m][j - 3 * n] == 0 && Qipan[i - 2 * m][j - 2 * n] == 2 && Qipan[i - 1 * m][j - 1 * n] == 2 && Qipan[i + 1 * m][j + 1 * n] == 2 && Qipan[i + 2 * m][j + 2 * n] == 1) {
					average[i][j] = average[i][j] + CHONGSI;
				}
			}
		}
	}
	//����0111x2
	for (int i = 0 + 4 * m; i < (ROW - 1 * m); i++) {
		for (int j = 0 + 4 * n; j < (COL - 1 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 4 * m][j - 4 * n] == 0 && Qipan[i - 3 * m][j - 3 * n] == 1 && Qipan[i - 2 * m][j - 2 * n] == 1 && Qipan[i - 1 * m][j - 1 * n] == 1 && Qipan[i + 1 * m][j + 1 * n] == 2) {
					average[i][j] = average[i][j] + CHONGSI;
				}
				if (Qipan[i - 4 * m][j - 4 * n] == 0 && Qipan[i - 3 * m][j - 3 * n] == 2 && Qipan[i - 2 * m][j - 2 * n] == 2 && Qipan[i - 1 * m][j - 1 * n] == 2 && Qipan[i + 1 * m][j + 1 * n] == 1) {
					average[i][j] = average[i][j] + CHONGSI;
				}
			}
		}
	}
	//����2x1110
	for (int i = 0 + 1 * m; i < (ROW - 4 * m); i++) {
		for (int j = 0 + 1 * n; j < (COL - 4 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 1 * m][j - 1 * n] == 2 && Qipan[i + 1 * m][j + 1 * n] == 1 && Qipan[i + 2 * m][j + 2 * n] == 1 && Qipan[i + 3 * m][j + 3 * n] == 1 && Qipan[i + 4 * m][j + 4 * n] == 0) {
					average[i][j] = average[i][j] + CHONGSI;
				}
				if (Qipan[i - 1 * m][j - 1 * n] == 1 && Qipan[i + 1 * m][j + 1 * n] == 2 && Qipan[i + 2 * m][j + 2 * n] == 2 && Qipan[i + 3 * m][j + 3 * n] == 2 && Qipan[i + 4 * m][j + 4 * n] == 0) {
					average[i][j] = average[i][j] + CHONGSI;
				}
			}
		}
	}
	//����21x110
	for (int i = 0 + 2 * m; i < (ROW - 3 * m); i++) {
		for (int j = 0 + 2 * n; j < (COL - 3 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 2 * m][j - 2 * n] == 2 && Qipan[i - 1 * m][j - 1 * n] == 1 && Qipan[i + 1 * m][j + 1 * n] == 1 && Qipan[i + 2 * m][j + 2 * n] == 1 && Qipan[i + 3 * m][j + 3 * n] == 0) {
					average[i][j] = average[i][j] + CHONGSI;
				}
				if (Qipan[i - 2 * m][j - 2 * n] == 1 && Qipan[i - 1 * m][j - 1 * n] == 2 && Qipan[i + 1 * m][j + 1 * n] == 2 && Qipan[i + 2 * m][j + 2 * n] == 2 && Qipan[i + 3 * m][j + 3 * n] == 0) {
					average[i][j] = average[i][j] + CHONGSI;
				}
			}
		}
	}
	//����211x10
	for (int i = 0 + 3 * m; i < (ROW - 2 * m); i++) {
		for (int j = 0 + 3 * n; j < (COL - 2 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 3 * m][j - 3 * n] == 2 && Qipan[i - 2 * m][j - 2 * n] == 1 && Qipan[i - 1 * m][j - 1 * n] == 1 && Qipan[i + 1 * m][j + 1 * n] == 1 && Qipan[i + 2 * m][j + 2 * n] == 0) {
					average[i][j] = average[i][j] + CHONGSI;
				}
				if (Qipan[i - 3 * m][j - 3 * n] == 1 && Qipan[i - 2 * m][j - 2 * n] == 2 && Qipan[i - 1 * m][j - 1 * n] == 2 && Qipan[i + 1 * m][j + 1 * n] == 2 && Qipan[i + 2 * m][j + 2 * n] == 0) {
					average[i][j] = average[i][j] + CHONGSI;
				}
			}
		}
	}
	//����2111x0
	for (int i = 0 + 4 * m; i < (ROW - 1 * m); i++) {
		for (int j = 0 + 4 * n; j < (COL - 1 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 4 * m][j - 4 * n] == 2 && Qipan[i - 3 * m][j - 3 * n] == 1 && Qipan[i - 2 * m][j - 2 * n] == 1 && Qipan[i - 1 * m][j - 1 * n] == 1 && Qipan[i + 1 * m][j + 1 * n] == 0) {
					average[i][j] = average[i][j] + CHONGSI;
				}
				if (Qipan[i - 4 * m][j - 4 * n] == 1 && Qipan[i - 3 * m][j - 3 * n] == 2 && Qipan[i - 2 * m][j - 2 * n] == 2 && Qipan[i - 1 * m][j - 1 * n] == 2 && Qipan[i + 1 * m][j + 1 * n] == 0) {
					average[i][j] = average[i][j] + CHONGSI;
				}
			}
		}
	}
}

void miansan(int m, int n) {
	//����2x1100
	for (int i = 0 + 1 * m; i < (ROW - 4 * m); i++) {
		for (int j = 0 + 1 * n; j < (COL - 4 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 1 * m][j - 1 * n] == 2 && Qipan[i + 1 * m][j + 1 * n] == 1 && Qipan[i + 2 * m][j + 2 * n] == 1 && Qipan[i + 3 * m][j + 3 * n] == 0 && Qipan[i + 4 * m][j + 4 * n] == 0) {
					average[i][j] = average[i][j] + MIANSAN;
				}
				if (Qipan[i - 1 * m][j - 1 * n] == 1 && Qipan[i + 1 * m][j + 1 * n] == 2 && Qipan[i + 2 * m][j + 2 * n] == 2 && Qipan[i + 3 * m][j + 3 * n] == 0 && Qipan[i + 4 * m][j + 4 * n] == 0) {
					average[i][j] = average[i][j] + MIANSAN;
				}
			}
		}
	}
	//����21x100
	for (int i = 0 + 2 * m; i < (ROW - 3 * m); i++) {
		for (int j = 0 + 2 * n; j < (COL - 3 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 2 * m][j - 2 * n] == 2 && Qipan[i - 1 * m][j - 1 * n] == 1 && Qipan[i + 1 * m][j + 1 * n] == 1 && Qipan[i + 2 * m][j + 2 * n] == 0 && Qipan[i + 3 * m][j + 3 * n] == 0) {
					average[i][j] = average[i][j] + MIANSAN;
				}
				if (Qipan[i - 2 * m][j - 2 * n] == 1 && Qipan[i - 1 * m][j - 1 * n] == 2 && Qipan[i + 1 * m][j + 1 * n] == 2 && Qipan[i + 2 * m][j + 2 * n] == 0 && Qipan[i + 3 * m][j + 3 * n] == 0) {
					average[i][j] = average[i][j] + MIANSAN;
				}
			}
		}
	}
	//����211x00
	for (int i = 0 + 3 * m; i < (ROW - 2 * m); i++) {
		for (int j = 0 + 3 * n; j < (COL - 2 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 3 * m][j - 3 * n] == 2 && Qipan[i - 2 * m][j - 2 * n] == 1 && Qipan[i - 1 * m][j - 1 * n] == 1 && Qipan[i + 1 * m][j + 1 * n] == 0 && Qipan[i + 2 * m][j + 2 * n] == 0) {
					average[i][j] = average[i][j] + MIANSAN;
				}
				if (Qipan[i - 3 * m][j - 3 * n] == 1 && Qipan[i - 2 * m][j - 2 * n] == 2 && Qipan[i - 1 * m][j - 1 * n] == 2 && Qipan[i + 1 * m][j + 1 * n] == 0 && Qipan[i + 2 * m][j + 2 * n] == 0) {
					average[i][j] = average[i][j] + MIANSAN;
				}
			}
		}
	}
	//����00x112
	for (int i = 0 + 2 * m; i < (ROW - 3 * m); i++) {
		for (int j = 0 + 2 * n; j < (COL - 3 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 2 * m][j - 2 * n] == 0 && Qipan[i - 1 * m][j - 1 * n] == 0 && Qipan[i + 1 * m][j + 1 * n] == 1 && Qipan[i + 2 * m][j + 2 * n] == 1 && Qipan[i + 3 * m][j + 3 * n] == 2) {
					average[i][j] = average[i][j] + MIANSAN;
				}
				if (Qipan[i - 2 * m][j - 2 * n] == 0 && Qipan[i - 1 * m][j - 1 * n] == 0 && Qipan[i + 1 * m][j + 1 * n] == 2 && Qipan[i + 2 * m][j + 2 * n] == 2 && Qipan[i + 3 * m][j + 3 * n] == 1) {
					average[i][j] = average[i][j] + MIANSAN;
				}
			}
		}
	}
	//����001x12
	for (int i = 0 + 3 * m; i < (ROW - 2 * m); i++) {
		for (int j = 0 + 3 * n; j < (COL - 2 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 3 * m][j - 3 * n] == 0 && Qipan[i - 2 * m][j - 2 * n] == 0 && Qipan[i - 1 * m][j - 1 * n] == 1 && Qipan[i + 1 * m][j + 1 * n] == 1 && Qipan[i + 2 * m][j + 2 * n] == 2) {
					average[i][j] = average[i][j] + MIANSAN;
				}
				if (Qipan[i - 3 * m][j - 3 * n] == 0 && Qipan[i - 2 * m][j - 2 * n] == 0 && Qipan[i - 1 * m][j - 1 * n] == 2 && Qipan[i + 1 * m][j + 1 * n] == 2 && Qipan[i + 2 * m][j + 2 * n] == 1) {
					average[i][j] = average[i][j] + MIANSAN;
				}
			}
		}
	}
	//����0011x2
	for (int i = 0 + 4 * m; i < (ROW - 1 * m); i++) {
		for (int j = 0 + 4 * n; j < (COL - 1 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 4 * m][j - 4 * n] == 0 && Qipan[i - 3 * m][j - 3 * n] == 0 && Qipan[i - 2 * m][j - 2 * n] == 1 && Qipan[i - 1 * m][j - 1 * n] == 1 && Qipan[i + 1 * m][j + 1 * n] == 2) {
					average[i][j] = average[i][j] + MIANSAN;
				}
				if (Qipan[i - 4 * m][j - 4 * n] == 0 && Qipan[i - 3 * m][j - 3 * n] == 0 && Qipan[i - 2 * m][j - 2 * n] == 2 && Qipan[i - 1 * m][j - 1 * n] == 2 && Qipan[i + 1 * m][j + 1 * n] == 1) {
					average[i][j] = average[i][j] + MIANSAN;
				}
			}
		}
	}
}

void mianer(int m, int n) {
	//�߶�2x1000
	for (int i = 0 + 1 * m; i < (ROW - 4 * m); i++) {
		for (int j = 0 + 1 * n; j < (COL - 4 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 1 * m][j - 1 * n] == 2 && Qipan[i + 1 * m][j + 1 * n] == 1 && Qipan[i + 2 * m][j + 2 * n] == 0 && Qipan[i + 3 * m][j + 3 * n] == 0 && Qipan[i + 4 * m][j + 4 * n] == 0) {
					average[i][j] = average[i][j] + MIANER;
				}
				if (Qipan[i - 1 * m][j - 1 * n] == 1 && Qipan[i + 1 * m][j + 1 * n] == 2 && Qipan[i + 2 * m][j + 2 * n] == 0 && Qipan[i + 3 * m][j + 3 * n] == 0 && Qipan[i + 4 * m][j + 4 * n] == 0) {
					average[i][j] = average[i][j] + MIANER;
				}
			}
		}
	}
	//�߶�21x000
	for (int i = 0 + 2 * m; i < (ROW - 3 * m); i++) {
		for (int j = 0 + 2 * n; j < (COL - 3 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 2 * m][j - 2 * n] == 2 && Qipan[i - 1 * m][j - 1 * n] == 1 && Qipan[i + 1 * m][j + 1 * n] == 0 && Qipan[i + 2 * m][j + 2 * n] == 0 && Qipan[i + 3 * m][j + 3 * n] == 0) {
					average[i][j] = average[i][j] + MIANER;
				}
				if (Qipan[i - 2 * m][j - 2 * n] == 1 && Qipan[i - 1 * m][j - 1 * n] == 2 && Qipan[i + 1 * m][j + 1 * n] == 0 && Qipan[i + 2 * m][j + 2 * n] == 0 && Qipan[i + 3 * m][j + 3 * n] == 0) {
					average[i][j] = average[i][j] + MIANER;
				}
			}
		}
	}
	//�߶�000x12
	for (int i = 0 + 3 * m; i < (ROW - 2 * m); i++) {
		for (int j = 0 + 3 * n; j < (COL - 2 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 3 * m][j - 3 * n] == 0 && Qipan[i - 2 * m][j - 2 * n] == 0 && Qipan[i - 1 * m][j - 1 * n] == 0 && Qipan[i + 1 * m][j + 1 * n] == 1 && Qipan[i + 2 * m][j + 2 * n] == 2) {
					average[i][j] = average[i][j] + MIANER;
				}
				if (Qipan[i - 3 * m][j - 3 * n] == 0 && Qipan[i - 2 * m][j - 2 * n] == 0 && Qipan[i - 1 * m][j - 1 * n] == 0 && Qipan[i + 1 * m][j + 1 * n] == 2 && Qipan[i + 2 * m][j + 2 * n] == 1) {
					average[i][j] = average[i][j] + MIANER;
				}
			}
		}
	}
	//�߶�0001x2
	for (int i = 0 + 4 * m; i < (ROW - 1 * m); i++) {
		for (int j = 0 + 4 * n; j < (COL - 1 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 4 * m][j - 4 * n] == 0 && Qipan[i - 3 * m][j - 3 * n] == 0 && Qipan[i - 2 * m][j - 2 * n] == 0 && Qipan[i - 1 * m][j - 1 * n] == 1 && Qipan[i + 1 * m][j + 1 * n] == 2) {
					average[i][j] = average[i][j] + MIANER;
				}
				if (Qipan[i - 4 * m][j - 4 * n] == 0 && Qipan[i - 3 * m][j - 3 * n] == 0 && Qipan[i - 2 * m][j - 2 * n] == 0 && Qipan[i - 1 * m][j - 1 * n] == 2 && Qipan[i + 1 * m][j + 1 * n] == 1) {
					average[i][j] = average[i][j] + MIANER;
				}
			}
		}
	}
}

#define HUOSANGAI 100000

void huosangai(int m, int n) {
	//������0x0110
	for (int i = 0 + 1 * m; i < (ROW - 4 * m); i++) {
		for (int j = 0 + 1 * n; j < (COL - 4 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 1 * m][j - 1 * n] == 0 && Qipan[i + 1 * m][j + 1 * n] == 0 && Qipan[i + 2 * m][j + 2 * n] == 1 && Qipan[i + 3 * m][j + 3 * n] == 1 && Qipan[i + 4 * m][j + 4 * n] == 0) {
					average[i][j] = average[i][j] + HUOSANGAI;
				}
				if (Qipan[i - 1 * m][j - 1 * n] == 0 && Qipan[i + 1 * m][j + 1 * n] == 0 && Qipan[i + 2 * m][j + 2 * n] == 2 && Qipan[i + 3 * m][j + 3 * n] == 2 && Qipan[i + 4 * m][j + 4 * n] == 0) {
					average[i][j] = average[i][j] + HUOSANGAI;
				}
			}
		}
	}
	//������010x10
	for (int i = 0 + 3 * m; i < (ROW - 2 * m); i++) {
		for (int j = 0 + 3 * n; j < (COL - 2 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 3 * m][j - 3 * n] == 0 && Qipan[i - 2 * m][j - 2 * n] == 1 && Qipan[i - 1 * m][j - 1 * n] == 0 && Qipan[i + 1 * m][j + 1 * n] == 1 && Qipan[i + 2 * m][j + 2 * n] == 0) {
					average[i][j] = average[i][j] + HUOSANGAI;
				}
				if (Qipan[i - 3 * m][j - 3 * n] == 0 && Qipan[i - 2 * m][j - 2 * n] == 2 && Qipan[i - 1 * m][j - 1 * n] == 0 && Qipan[i + 1 * m][j + 1 * n] == 2 && Qipan[i + 2 * m][j + 2 * n] == 0) {
					average[i][j] = average[i][j] + HUOSANGAI;
				}
			}
		}
	}
	//������0101x0
	for (int i = 0 + 4 * m; i < (ROW - 1 * m); i++) {
		for (int j = 0 + 4 * n; j < (COL - 1 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 4 * m][j - 4 * n] == 0 && Qipan[i - 3 * m][j - 3 * n] == 1 && Qipan[i - 2 * m][j - 2 * n] == 0 && Qipan[i - 1 * m][j - 1 * n] == 1 && Qipan[i + 1 * m][j + 1 * n] == 0) {
					average[i][j] = average[i][j] + HUOSANGAI;
				}
				if (Qipan[i - 4 * m][j - 4 * n] == 0 && Qipan[i - 3 * m][j - 3 * n] == 2 && Qipan[i - 2 * m][j - 2 * n] == 0 && Qipan[i - 1 * m][j - 1 * n] == 2 && Qipan[i + 1 * m][j + 1 * n] == 0 ) {
					average[i][j] = average[i][j] + HUOSANGAI;
				}
			}
		}
	}
	//������01x010
	for (int i = 0 + 2 * m; i < (ROW - 3 * m); i++) {
		for (int j = 0 + 2 * n; j < (COL - 3 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 2 * m][j - 2 * n] == 0 && Qipan[i - 1 * m][j - 1 * n] == 1 && Qipan[i + 1 * m][j + 1 * n] == 0 && Qipan[i + 2 * m][j + 2 * n] == 1 && Qipan[i + 3 * m][j + 3 * n] == 0) {
					average[i][j] = average[i][j] + HUOSANGAI;
				}
				if (Qipan[i - 2 * m][j - 2 * n] == 0 && Qipan[i - 1 * m][j - 1 * n] == 2 && Qipan[i + 1 * m][j + 1 * n] == 0 && Qipan[i + 2 * m][j + 2 * n] == 2 && Qipan[i + 3 * m][j + 3 * n] == 0) {
					average[i][j] = average[i][j] + HUOSANGAI;
				}
			}
		}
	}
	//������0x1010
	for (int i = 0 + 1 * m; i < (ROW - 4 * m); i++) {
		for (int j = 0 + 1 * n; j < (COL - 4 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 1 * m][j - 1 * n] == 0 && Qipan[i + 1 * m][j + 1 * n] == 1 && Qipan[i + 2 * m][j + 2 * n] == 0 && Qipan[i + 3 * m][j + 3 * n] == 1 && Qipan[i + 4 * m][j + 4 * n] == 0) {
					average[i][j] = average[i][j] + HUOSANGAI;
				}
				if (Qipan[i - 1 * m][j - 1 * n] == 0 && Qipan[i + 1 * m][j + 1 * n] == 2 && Qipan[i + 2 * m][j + 2 * n] == 0 && Qipan[i + 3 * m][j + 3 * n] == 2 && Qipan[i + 4 * m][j + 4 * n] == 0) {
					average[i][j] = average[i][j] + HUOSANGAI;
				}
			}
		}
	}
	//������0110x0
	for (int i = 0 + 4 * m; i < (ROW - 1 * m); i++) {
		for (int j = 0 + 4 * n; j < (COL - 1 * n); j++) {
			if (Qipan[i][j] == 0) {
				if (Qipan[i - 4 * m][j - 4 * n] == 0 && Qipan[i - 3 * m][j - 3 * n] == 1 && Qipan[i - 2 * m][j - 2 * n] == 1 && Qipan[i - 1 * m][j - 1 * n] == 0 && Qipan[i + 1 * m][j + 1 * n] == 0) {
					average[i][j] = average[i][j] + HUOSANGAI;
				}
				if (Qipan[i - 4 * m][j - 4 * n] == 0 && Qipan[i - 3 * m][j - 3 * n] == 2 && Qipan[i - 2 * m][j - 2 * n] == 2 && Qipan[i - 1 * m][j - 1 * n] == 0 && Qipan[i + 1 * m][j + 1 * n] == 0) {
					average[i][j] = average[i][j] + HUOSANGAI;
				}
			}
		}
	}
}