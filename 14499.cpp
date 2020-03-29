#include<iostream>
using namespace std;
int dx[4] = {0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int map[20][20];
int dice[7] = { 0, };
int n, m;	int x, y, k;
bool check(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}
int main()
{

	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i <n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}	
	for (int z = 0; z < k; z++)
	{
		int u = 0;
		cin >> u;
		int ndice[7] = { 0, };
		int ddx = x + dx[u - 1];
		int ddy = y + dy[u - 1];
		if (!check(ddx, ddy)) continue;
		if (u == 1)
		{
			ndice[1] = dice[4];
			ndice[3] = dice[1];
			ndice[4] = dice[6];
			ndice[6] = dice[3];
			ndice[2] = dice[2];
			ndice[5] = dice[5];
		}
		else if (u == 2)
		{
			ndice[4] = dice[1];
			ndice[1] = dice[3];
			ndice[6] = dice[4];
			ndice[3] = dice[6];
			ndice[2] = dice[2];
			ndice[5] = dice[5];
		}
		else if (u == 3)
		{
			ndice[3] = dice[3];
			ndice[4] = dice[4];
			ndice[1] = dice[5];
			ndice[5] = dice[6];
			ndice[6] = dice[2];
			ndice[2] = dice[1];
		}
		else
		{
			ndice[3] = dice[3];
			ndice[4] = dice[4];
			ndice[5] = dice[1];
			ndice[6] = dice[5];
			ndice[2] = dice[6];
			ndice[1] = dice[2];
		}
		if (map[ddx][ddy] == 0)
		{
			map[ddx][ddy] = ndice[6];
		}
		else
		{
			ndice[6] = map[ddx][ddy];
			map[ddx][ddy] = 0;
		}
		cout << ndice[1]<<endl;
		for (int i = 0; i <= 6; i++)
			dice[i] = ndice[i];
		x = ddx;
		y = ddy;
	}
}