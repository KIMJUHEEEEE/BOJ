#include<iostream>
#include<vector>
using namespace std;
int map[51][51];
int cmap[51][51];
int r, c, t;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
vector<int> air;

void copymap()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			map[i][j] = cmap[i][j];
			cmap[i][j] = 0;
		}
	}
}
int count()
{
	int cnt = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (map[i][j] > 0)
				cnt += map[i][j];
		}
	}
	return cnt;
}
void move()
{
	int ax = air[0];
	int ay = 0;
	while (ax >= 0)
	{
		if (map[ax + 1][0] != -1)
		{
			map[ax + 1][0] = map[ax][0];
		}
		ax--;
	}
	while (ay < c - 1)
	{
		map[0][ay] = map[0][ay + 1];
		ay++;
	}
	ax = 0;
	while (ax < air[0])
	{
		map[ax][c - 1] = map[ax + 1][c - 1];
		ax++;
	}
	ay = c - 1;
	while (ay >= 1)
	{
		if (map[air[0]][ay - 1] != -1)
		{
			map[air[0]][ay] = map[air[0]][ay - 1];
		}
		else
			map[air[0]][ay] = 0;
		ay--;
	}
	ax = air[1] + 1;
	ay = 0;
	while (ax < r - 1)
	{
		map[ax][0] = map[ax + 1][0];
		ax++;
	}
	while (ay < c - 1)
	{
		map[r - 1][ay] = map[r - 1][ay + 1];
		ay++;
	}
	ax = r - 1;
	while (ax > air[1])
	{
		map[ax][c - 1] = map[ax - 1][c - 1];
		ax--;
	}
	ay = c - 1;
	while (ay >= 1)
	{
		if (map[air[1]][ay - 1] != -1)
		{
			map[air[1]][ay] = map[air[1]][ay - 1];
		}
		else
			map[air[1]][ay] = 0;
		ay--;
	}
}
void mise()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (map[i][j] > 0)
			{
				int num = 0;
				for (int a = 0; a < 4; a++)
				{
					if (i + dx[a] >= 0 && i + dx[a] < r && j + dy[a] >= 0 && j + dy[a] < c && map[i + dx[a]][j + dy[a]] != -1)
					{
						cmap[i + dx[a]][j + dy[a]] += map[i][j] / 5;
						num++;
					}
				}
				int div = map[i][j] / 5;
				cmap[i][j] += map[i][j] - num * div;
			}
			else if (map[i][j] == -1)
				cmap[i][j] = -1;
		}
	}
	copymap();
}
int main()
{
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == -1)
				air.push_back(i);
		}
	}
	while (t--)
	{
		mise();
		move();
	}
	cout << count();
}