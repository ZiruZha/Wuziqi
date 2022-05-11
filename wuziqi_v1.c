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
			//单人
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
			//双人
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
	/*棋盘大小：ROW * COL
	0---空
	1---黑棋
	2---白棋*/
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
	printf("   一 二 三 四 五 六 七 八 九 十 一 二 三 四 五\n");
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
	/*判断输赢
	黑棋赢返回1
	白棋赢返回2*/

	//判黑棋横
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < (COL - 4); j++) {
			if (Qipan[i][j] * Qipan[i][j + 1] * Qipan[i][j + 2] * Qipan[i][j + 3] * Qipan[i][j + 4] == 1) {
				return 1;
			}
		}
	}
	//判黑棋竖
	for (int i = 0; i < (ROW-4); i++) {
		for (int j = 0; j < COL; j++) {
			if (Qipan[i][j] * Qipan[i + 1][j] * Qipan[i + 2][j] * Qipan[i + 3][j] * Qipan[i + 4][j] == 1) {
				return 1;
			}
		}
	}
	//判黑棋右下
	for (int i = 0; i < (ROW - 4); i++) {
		for (int j = 0; j < (COL - 4); j++) {
			if (Qipan[i][j] * Qipan[i + 1][j + 1] * Qipan[i + 2][j + 2] * Qipan[i + 3][j + 3] * Qipan[i + 4][j + 4] == 1) {
				return 1;
			}
		}
	}
	//判黑棋右上
	for (int i = 0; i < ROW; i++) {
		for (int j = 4; j < COL; j++) {
			if (Qipan[i][j] * Qipan[i + 1][j - 1] * Qipan[i + 2][j - 2] * Qipan[i + 3][j - 3] * Qipan[i + 4][j - 4] == 1) {
				return 1;
			}
		}
	}
	//判白棋横

	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < (COL - 4); j++) {
			if (Qipan[i][j] * Qipan[i][j + 1] * Qipan[i][j + 2] * Qipan[i][j + 3] * Qipan[i][j + 4] == 32) {
				return 2;
			}
		}
	}
	//判白棋竖
	for (int i = 0; i < (ROW - 4); i++) {
		for (int j = 0; j < COL; j++) {
			if (Qipan[i][j] * Qipan[i + 1][j] * Qipan[i + 2][j] * Qipan[i + 3][j] * Qipan[i + 4][j] == 32) {
				return 2;
			}
		}
	}
	//判白棋右下
	for (int i = 0; i < (ROW - 4); i++) {
		for (int j = 0; j < (COL - 4); j++) {
			if (Qipan[i][j] * Qipan[i + 1][j + 1] * Qipan[i + 2][j + 2] * Qipan[i + 3][j + 3] * Qipan[i + 4][j + 4] == 32) {
				return 2;
			}
		}
	}
	//判白棋右上
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
	1.   连五：五颗同色棋子连在一起，如11111，22222
	2.   活四：有两个点可以形成连五，如011110，022220
	3.   冲四：有一个点可以形成连五，如011112，122220
	4.   活三：可以形成活四的三点，如001110，002220
	5.   眠三：只能形成冲四的三点，如001112，002221
	6.   活二：能够形成活三的二点，如000110，000220
	7.   眠二：能够形成眠三的二点，如000112，000221
	棋型权重
	连五100000000
	活四10000000
	冲四1000000
	活三100000
	眠三10000
	活二1000
	眠二100
	仅一10
	无1
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
	//权重矩阵初始化
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

	//左向右
	//连五
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
	//连五-1-----10111
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
	//连五-2-----11011
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
	//连五-3-----11101
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
	//活四
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
	//冲四
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
	//活四-1----010110
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
	//活三
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
	//眠三
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
	//活二
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
	//眠二
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
	//左向右完


	//右向左
	//连五
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
	//活四
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
	//冲四
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
	//活四-1----010110
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
	//活三
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
	//眠三
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
	//活二
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
	//眠二
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
	//右向左完

	//上向下
	//连五
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
	//连五-1-----10111
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
	//连五-2-----11011
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
	//连五-3-----11101
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
	//活四
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
	//冲四
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
	//活四-1----010110
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
	//活三
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
	//眠三
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
	//活二
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
	//眠二
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
	//上向下完

	//下向上
	//连五
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
	//活四
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
	//冲四
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
	//活四-1----010110
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
	//活三
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
	//眠三
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
	//活二
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
	//眠二
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
	//下向上完

	//左上向右下
	//连五
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
	//连五-1-----10111
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
	//连五-2-----11011
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
	//连五-3-----11101
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
	//活四
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
	//冲四
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
	//活四-1----010110
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
	//活三
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
	//眠三
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
	//活二
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
	//眠二
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
	//左上向右下完

	//左下向右上
	//连五
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
	//连五-1-----10111
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
	//连五-2-----11011
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
	//连五-3-----11101
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
	//活四
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
	//冲四
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
	//活四-1----010110
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
	//活三
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
	//眠三
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
	//活二
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
	//眠二
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
	//左下向右上完

	//右上向左下
	//连五
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
	//活四
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
	//冲四
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
	//活四-1----010110
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
	//活三
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
	//眠三
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
	//活二
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
	//眠二
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
	//右上向左下完

	//右下向左上
	//连五
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
	//活四
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
	//冲四
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
	//活四-1----010110
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
	//活三
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
	//眠三
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
	//活二
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
	//眠二
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
	//右下向左上完

	int x = 0, y = 0;
	//求最大值
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
1.   连五：五颗同色棋子连在一起，如11111，22222
2.   活四：有两个点可以形成连五，如011110，022220
3.   冲四：有一个点可以形成连五，如011112，122220
4.   活三：可以形成活四的三点，如001110，002220
5.   眠三：只能形成冲四的三点，如001112，002221
6.   活二：能够形成活三的二点，如000110，000220
7.   眠二：能够形成眠三的二点，如000112，000221
棋型权重
连五100000000
活四10000000
冲四1000000
活三100000
眠三10000
活二1000
眠二100
仅一10
无1
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
	//权重矩阵初始化
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
	int m = 0, n = 0;//（m，n）表示方向，m----行，n----列，m+1----向下一行，n+1向右一列
	

	//向右（m，n）=（0，1）
	m = 0; n = 1;
	calculate(m, n);

	//向下（m，n）=（1，0）
	m = 1; n = 0;
	calculate(m, n);

	//向右下（m，n）=（1，1）
	m = 1; n = 1;
	calculate(m, n);

	//向右上（m，n）=（1，-1）
	m = -1; n = 1;
	calculate(m, n);


	int x = 0, y = 0;
	//求最大值
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
	//连五
	lianwu(m, n);
	//活四
	huosi(m, n);
	//活三
	huosan(m, n);
	//活二
	huoer(m, n);
	//冲四
	chongsi(m, n);
	//眠三
	miansan(m, n);
	//眠二
	mianer(m, n);
}

void lianwu(int m, int n) {
	//连五x1111
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
	//连五1x111
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
	//连五11x11
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
	//连五111x1
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
	//连五111x1
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
	//连五1111x
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
	//活四0x1110
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
	//活四01x110
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
	//活四011x10
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
	//活四0111x0
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
	//活三0x1100
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
	//活三01x100
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
	//活三011x00
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
	//活三00x110
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
	//活三001x10
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
	//活三0011x0
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
	//活二0x1000
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
	//活二01x000
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
	//活二000x10
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
	//活二0001x0
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
	//冲四0x1112
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
	//冲四01x112
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
	//冲四011x12
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
	//冲四0111x2
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
	//冲四2x1110
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
	//冲四21x110
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
	//冲四211x10
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
	//冲四2111x0
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
	//眠三2x1100
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
	//眠三21x100
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
	//眠三211x00
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
	//眠三00x112
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
	//眠三001x12
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
	//眠三0011x2
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
	//眠二2x1000
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
	//眠二21x000
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
	//眠二000x12
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
	//眠二0001x2
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
	//活三改0x0110
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
	//活三改010x10
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
	//活三改0101x0
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
	//活三改01x010
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
	//活三改0x1010
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
	//活三改0110x0
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