#include<iostream>

using namespace std;

bool ac(int map[][8], int queen, int h)
{
	int flag = true;
	int y;
	for (int i = 0; i < 8; i++)
	{
		flag = map[i][queen] == -1 && flag;
		flag = map[h][i] == -1 && flag;
		y = queen + h - i;
		if (y<8 && y>-1)
		{
			flag = map[i][y] == -1 && flag;
		}
		y = i + queen - h;
		if (y<8 && y>-1)
		{
			flag = map[i][y] == -1 && flag;
		}
	}
	return flag;
}

void output(int map[][8],int count)
{
	cout << count << endl;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << ((map[i][j] == -1) ? '*' : 'Q') << ',';
		}
		cout << endl;
	}
}
int main(int argc, char** argv)
{
	int map[8][8];
	int * p[8];

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			map[i][j] = -1;
		}
	}
	system("mode con:cols=100 lines=1500");
	int queen = 0, h = 0, count = 1;
	while (true)
	{

		while (!ac(map, queen, h))
		{
			h++;
			while (h >= 8)
			{
				if (queen == 0)
				{
					system("pause");
					return 0;
				}
				h = *p[queen - 1] + 1;
				*p[queen - 1] = -1;
				queen--;
			}
		}

		if (++queen == 8)
		{
			output(map,count++);
			queen--;
			h++;
		}
		else
		{
			map[h][queen - 1] = h;
			p[queen - 1] = &map[h][queen - 1];
			h = 0;
		}


	}



}
