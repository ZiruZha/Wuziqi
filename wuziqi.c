#include<stdio.h>
#include<stdlib.h>
#define ROW 15
#define COL 15

void QipanInit();
void Read_b();
void Read_w();
void Print();
void AI();
int Judge();

int Qipan[ROW][COL];
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
					AI();
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
