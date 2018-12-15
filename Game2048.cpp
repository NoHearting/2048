# include<stdio.h>
# include<time.h>
# include<stdlib.h>
# include<conio.h>
# include<Windows.h>
# include<process.h>
# include<string.h>

const int NUM = 4;
int Board[NUM][NUM] = { 0 };


void assingment();     //�ؿ��ָ���ֵ
void ShowGame();       //��ʼ����ʾ����
void AddRand();        //�����ʼ�������λ��
void InitGame();       //��ʼ����Ϸ
void StartGame();      //��ʼ��Ϸ
void MoveLeft();       //����
void MoveRight();      //����
void MoveUp();         //����
void MoveDown();       //����
int  GetNUll();        //��ȡ��λ��
void GameOver();       //�ж���Χλ���Ƿ���ͬ
int  TotalSc();        //�ܷ�

bool IsRand;           //�Ƿ����������
bool Isover;           //��Ϸ�Ƿ����
int  TotalScore;       //�ܷ�
int  TotalKey;         //�����ܴ���


int main(void)
{
		//InitGame();
	StartGame();
		//AddRand();

	if (TotalScore < 1024)
	{
		printf("\n\n̫���ˣ�\n");
	}
	else
	{
		printf("\n\nţ�ƣ�\n");
	}
	getchar();
	getchar();
	return 0;
}
void InitGame()
{
	assingment();
	IsRand = 1;   //��Ҫ����
	Isover = 1;   //û�н���
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
		//����һ��������Ϣ
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
			system("cls");  //�����Ļ
			ShowGame();
		}
		if (GetNUll() == 0)
		{
			GameOver();
			if (!Isover)
			{
				if (MessageBox(NULL, L"�Ƿ�����һ�֣��س��ؿ�", L"��Ϸ����", MB_YESNO) == IDYES)
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
	printf("-----------��Ϸ���ƣ�2048-----------\n\n\n");
	printf("----������%d------�ƶ�������%d------\n", TotalScore, TotalKey);
	printf("�������������ש����������ש����������ש�����������\n");
	for (int i = 0; i < NUM; i++)
	{
		printf("��");
		for (int j = 0; j < NUM; j++)
		{
			if (Board[i][j] == 0)
			{
				printf("     ��");
			}
			else
			{
				printf("%4d ��", Board[i][j]);
			}
		}
		if (i < NUM - 1)
		{
			printf("\n�ǩ����������贈���������贈���������贈����������\n");
		}
		else
		{
			printf("\n�������������ߩ����������ߩ����������ߩ�����������\n\n");
		}
	}
	printf("----------------------��������--------------------------\n\n");
	printf("�ϣ���,W,w��--�£���,S,s��--�󣨡�,A,a��--�ң���,D,d��--\n\n\n");
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
void MoveLeft()    //����
{
	for (int i = 0; i < NUM; i++)
	{
		for (int j = 1, k = 0; j < NUM; j++)
		{
			if (Board[i][j] != 0)
			{
				//k���j���ֵ���
				if (Board[i][k] == Board[i][j])
				{
					Board[i][k++] *= 2;  //  <<������������ʴ���*��
					Board[i][j] = 0;
					IsRand = 1;
				}
				//k��Ϊ0
				else if (Board[i][k] == 0)
				{
					Board[i][k++] = Board[i][j];
					Board[i][j] = 0;
					IsRand = 1;
				}
				//k�Ϊ0  j��k�����
				else
				{
					Board[i][++k] = Board[i][j];
					if (k  != j)  //k�Ѿ���1��
					{
						Board[i][j] = 0;
						IsRand = 1;
					}
					
				}
			}
		}
	}



}
void MoveRight()       //����
{
	for (int i = 0; i < NUM; i++)
	{
		for (int j = NUM-2, k = NUM-1; j >=0; j--)
		{
			if (Board[i][j] != 0)
			{
				//k���j���ֵ���
				if (Board[i][k] == Board[i][j])
				{
					Board[i][k--] *= 2;  //  <<������������ʴ���*��
					Board[i][j] = 0;
					IsRand = 1;
				}
				//k��Ϊ0
				else if (Board[i][k] == 0)
				{
					Board[i][k--] = Board[i][j];
					Board[i][j] = 0;
					IsRand = 1;
				}
				//k�Ϊ0  j��k�����
				else
				{
					Board[i][--k] = Board[i][j];
					if (k != j)  //k�Ѿ���1��
					{
						Board[i][j] = 0;
						IsRand = 1;
					}

				}
			}
		}
	}
}
void MoveUp()    //����
{
	for (int i = 0; i < NUM; i++)
	{
		for (int j = 1, k = 0; j < NUM; j++)
		{
			if (Board[j][i] != 0)
			{
				//k���j���ֵ���
				if (Board[k][i] == Board[j][i])
				{
					Board[k++][i] *= 2;  //  <<������������ʴ���*��
					Board[j][i] = 0;
					IsRand = 1;
				}
				//k��Ϊ0
				else if (Board[k][i] == 0)
				{
					Board[k++][i] = Board[j][i];
					Board[j][i] = 0;
					IsRand = 1;
				}
				//k�Ϊ0  j��k�����
				else
				{
					Board[++k][i] = Board[j][i];
					if (k != j)  //k�Ѿ���1��
					{
						Board[j][i] = 0;
						IsRand = 1;
					}

				}
			}
		}
	}



}
void MoveDown()       //����
{
	for (int i = 0; i < NUM; i++)
	{
		for (int j = NUM-2, k = NUM-1; j >=0; j--)
		{
			if (Board[j][i] != 0)
			{
				//k���j���ֵ���
				if (Board[k][i] == Board[j][i])
				{
					Board[k--][i] *= 2;  //  <<������������ʴ���*��
					Board[j][i] = 0;
					IsRand = 1;
				}
				//k��Ϊ0
				else if (Board[k][i] == 0)
				{
					Board[k--][i] = Board[j][i];
					Board[j][i] = 0;
					IsRand = 1;
				}
				//k�Ϊ0  j��k�����
				else
				{
					Board[--k][i] = Board[j][i];
					if (k != j)  //k�Ѿ���1��
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