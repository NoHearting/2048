# include<stdio.h>
# include<time.h>
# include<stdlib.h>
# include<conio.h>
# include<Windows.h>
# include<process.h>
# include<string.h>

const int NUM = 4;
int Board[NUM][NUM] = { 0 };


void assingment();     //重开局赋初值
void ShowGame();       //初始化显示界面
void AddRand();        //随机初始数和随机位置
void InitGame();       //初始化游戏
void StartGame();      //开始游戏
void MoveLeft();       //向左
void MoveRight();      //向右
void MoveUp();         //向上
void MoveDown();       //向下
int  GetNUll();        //获取空位置
void GameOver();       //判断周围位置是否相同
int  TotalSc();        //总分

bool IsRand;           //是否生成随机数
bool Isover;           //游戏是否结束
int  TotalScore;       //总分
int  TotalKey;         //按的总次数


int main(void)
{
		//InitGame();
	StartGame();
		//AddRand();

	if (TotalScore < 1024)
	{
		printf("\n\n太菜了！\n");
	}
	else
	{
		printf("\n\n牛逼！\n");
	}
	getchar();
	getchar();
	return 0;
}
void InitGame()
{
	assingment();
	IsRand = 1;   //需要生成
	Isover = 1;   //没有结束
	TotalKey = 0;
	TotalScore = 0;
	AddRand();
	AddRand();
	ShowGame();
}
void StartGame()
{
	InitGame();
	while (1)
	{
		IsRand = 0;
		char ch;
		//接收一个按键消息
		switch (ch = getch())
		{
		case 'a':
		case 'A':
		case 75:
			MoveLeft();
			TotalKey++;
			break;
		case 'D':
		case 'd':
		case 77:
			MoveRight();
			TotalKey++;
			break;
		case 'w':
		case 'W':
		case 72:
			MoveUp();
			TotalKey++;
			break;
		case 'S':
		case 's':
		case 80:
			MoveDown();
			TotalKey++;
			break;
		default:
			break;
		}
		if (IsRand)
		{
			AddRand();
			system("cls");  //清除屏幕
			ShowGame();
		}
		if (GetNUll() == 0)
		{
			GameOver();
			if (!Isover)
			{
				if (MessageBox(NULL, L"是否重来一局？回车重开", L"游戏结束", MB_YESNO) == IDYES)
				{
					while (getchar() != '\n')
					{
						continue;
					}
					system("cls");
					StartGame();
				}
				else
				{
					return ;
				}
			}
		}
	}
}
void ShowGame()
{
	TotalScore = TotalSc();
	printf("********************************************************************\n\n");
	printf("-----------游戏名称：2048-----------\n\n\n");
	printf("----分数：%d------移动次数：%d------\n", TotalScore, TotalKey);
	printf("┏━━━━━┳━━━━━┳━━━━━┳━━━━━┓\n");
	for (int i = 0; i < NUM; i++)
	{
		printf("┃");
		for (int j = 0; j < NUM; j++)
		{
			if (Board[i][j] == 0)
			{
				printf("     ┃");
			}
			else
			{
				printf("%4d ┃", Board[i][j]);
			}
		}
		if (i < NUM - 1)
		{
			printf("\n┣━━━━━╋━━━━━╋━━━━━╋━━━━━┫\n");
		}
		else
		{
			printf("\n┗━━━━━┻━━━━━┻━━━━━┻━━━━━┛\n\n");
		}
	}
	printf("----------------------操作方法--------------------------\n\n");
	printf("上（↑,W,w）--下（↓,S,s）--左（←,A,a）--右（→,D,d）--\n\n\n");
	printf("*********************************************************************\n");

}
void AddRand()
{
	srand(time(nullptr));
	while (1)
	{
		int Row = rand() % NUM;
		int Col = rand() % NUM;
		int val = rand() % 2;
		if (Board[Row][Col] == 0)
		{
			switch (val)
			{
			case 0:
				Board[Row][Col] = 2;
				break;
			case 1:
				Board[Row][Col] = 4;
				break;
			}
			break;
		}
		else
		{
			continue;
		}
	}
}
void MoveLeft()    //左移
{
	for (int i = 0; i < NUM; i++)
	{
		for (int j = 1, k = 0; j < NUM; j++)
		{
			if (Board[i][j] != 0)
			{
				//k项和j项的值相等
				if (Board[i][k] == Board[i][j])
				{
					Board[i][k++] *= 2;  //  <<左移运算符速率大于*号
					Board[i][j] = 0;
					IsRand = 1;
				}
				//k项为0
				else if (Board[i][k] == 0)
				{
					Board[i][k++] = Board[i][j];
					Board[i][j] = 0;
					IsRand = 1;
				}
				//k项不为0  j和k不相等
				else
				{
					Board[i][++k] = Board[i][j];
					if (k  != j)  //k已经加1了
					{
						Board[i][j] = 0;
						IsRand = 1;
					}
					
				}
			}
		}
	}



}
void MoveRight()       //右移
{
	for (int i = 0; i < NUM; i++)
	{
		for (int j = NUM-2, k = NUM-1; j >=0; j--)
		{
			if (Board[i][j] != 0)
			{
				//k项和j项的值相等
				if (Board[i][k] == Board[i][j])
				{
					Board[i][k--] *= 2;  //  <<左移运算符速率大于*号
					Board[i][j] = 0;
					IsRand = 1;
				}
				//k项为0
				else if (Board[i][k] == 0)
				{
					Board[i][k--] = Board[i][j];
					Board[i][j] = 0;
					IsRand = 1;
				}
				//k项不为0  j和k不相等
				else
				{
					Board[i][--k] = Board[i][j];
					if (k != j)  //k已经加1了
					{
						Board[i][j] = 0;
						IsRand = 1;
					}

				}
			}
		}
	}
}
void MoveUp()    //上移
{
	for (int i = 0; i < NUM; i++)
	{
		for (int j = 1, k = 0; j < NUM; j++)
		{
			if (Board[j][i] != 0)
			{
				//k项和j项的值相等
				if (Board[k][i] == Board[j][i])
				{
					Board[k++][i] *= 2;  //  <<左移运算符速率大于*号
					Board[j][i] = 0;
					IsRand = 1;
				}
				//k项为0
				else if (Board[k][i] == 0)
				{
					Board[k++][i] = Board[j][i];
					Board[j][i] = 0;
					IsRand = 1;
				}
				//k项不为0  j和k不相等
				else
				{
					Board[++k][i] = Board[j][i];
					if (k != j)  //k已经加1了
					{
						Board[j][i] = 0;
						IsRand = 1;
					}

				}
			}
		}
	}



}
void MoveDown()       //下移
{
	for (int i = 0; i < NUM; i++)
	{
		for (int j = NUM-2, k = NUM-1; j >=0; j--)
		{
			if (Board[j][i] != 0)
			{
				//k项和j项的值相等
				if (Board[k][i] == Board[j][i])
				{
					Board[k--][i] *= 2;  //  <<左移运算符速率大于*号
					Board[j][i] = 0;
					IsRand = 1;
				}
				//k项为0
				else if (Board[k][i] == 0)
				{
					Board[k--][i] = Board[j][i];
					Board[j][i] = 0;
					IsRand = 1;
				}
				//k项不为0  j和k不相等
				else
				{
					Board[--k][i] = Board[j][i];
					if (k != j)  //k已经加1了
					{
						Board[j][i] = 0;
						IsRand = 1;
					}

				}
			}
		}
	}
}
int  GetNUll()
{
	int sum = 0;
	for (int i = 0; i < NUM; i++)
	{
		for (int j = 0; j < NUM; j++)
		{
			if (Board[i][j] == 0)
			{
				sum++;
			}
		}
	}
	return sum;
}
void GameOver()
{
	for (int i = 0; i < NUM; i++)
	{
		for (int j = 0; j < NUM-1; j++)
		{
			if (Board[i][j] == Board[i][j + 1] || Board[j][i] == Board[j + 1][i])
			{
				Isover = 1;
				return;
			}	
		}
	}
	Isover = 0;
}
void assingment()
{
	for (int i = 0; i < NUM; i++)
	{
		for (int j = 0; j < NUM; j++)
		{
			Board[i][j] = 0;
		}
	}
}

int  TotalSc()
{
	int sum = 0;
	for (int i = 0; i < NUM; i++)
	{
		for (int j = 0; j < NUM; j++)
		{
			sum += Board[i][j];
		}
	}
	return sum;
}