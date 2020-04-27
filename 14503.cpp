#include<iostream>
#include<string.h>
using namespace std;
int n, m, r, c, d;
int map[51][51];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int ans;
void solve(int x,int y,int cnt,int d)
{
	int check = 0;
	map[x][y] = 2;
	ans = cnt;
	if (d == 0)
	{
		if (map[x][y - 1] == 0)
		{
			solve(x, y - 1, cnt + 1, 3);
		}
		else
		{
			if (map[x + 1][y] == 0)
			{
				solve(x + 1, y, cnt + 1, 2);
			}
			else
			{
				if (map[x][y + 1] == 0)
				{
					solve(x, y + 1, cnt + 1, 1);
				}
				else
				{
					if (map[x - 1][y] == 0)
					{
						solve(x - 1, y, cnt + 1, 0);
					}
					else
					{
						if (map[x + 1][y] != 1)
						{
							solve(x + 1, y, cnt, d);
						}
						else
							return;
					}
				}
			}
		}
	}
	else if (d == 1)
	{
		if (map[x-1][y] == 0)
		{
			solve(x-1, y, cnt + 1, 0);
		}
		else
		{
			if (map[x ][y-1] == 0)
			{
				solve(x, y-1, cnt + 1, 3);
			}
			else
			{
				if (map[x+1][y] == 0)
				{
					solve(x+1, y, cnt + 1, 2);
				}
				else
				{
					if (map[x][y+1] == 0)
					{
						solve(x, y+1, cnt + 1, 1);
					}
					else
					{
						if (map[x ][y-1] !=1)
						{
							solve(x, y-1, cnt, d);
						}
						else
							return;
					}
				}
			}
		}
	}
	else if (d == 2)
	{
		if (map[x][y + 1] == 0)
		{
			solve(x, y + 1, cnt + 1, 1);
		}
		else
		{
			if (map[x - 1][y] == 0)
			{
				solve(x - 1, y, cnt + 1, 0);
			}
			else
			{
				if (map[x][y-1] == 0)
				{
					solve(x, y-1, cnt + 1, 3);
				}
				else
				{
					if (map[x + 1][y] == 0)
					{
						solve(x +1, y, cnt + 1, 2);
					}
					else
					{
						if (map[x - 1][y] != 1)
						{
							solve(x - 1, y, cnt, d);
						}
						else
							return;
					}
				}
			}
		}
	}
	else
	{
		if (map[x + 1][y] == 0)
		{
			solve(x + 1, y, cnt + 1, 2);
		}
		else
		{
			if (map[x][y + 1] == 0)
			{
				solve(x, y + 1, cnt + 1, 1);
			}
			else
			{
				if (map[x - 1][y] == 0)
				{
					solve(x - 1, y, cnt + 1, 0);
				}
				else
				{
					if (map[x][y - 1] == 0)
					{
						solve(x, y - 1, cnt + 1, 3);
					}
					else
					{
						if (map[x][y + 1] != 1)
						{
							solve(x, y + 1, cnt, d);
						}
						else
							return;
					}
				}
			}
		}
	}
}
int main()
{
	memset(map, 1, sizeof(map));
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
	solve(r,c,1, d);
	cout << ans;
}