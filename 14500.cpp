#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int map[501][501];
int dx[][4] = { {0, 0, 0, 0}, {0, 1, 2, 3}, {0, 0, 1, 1}, {0, 1, 2, 2},
			   {1, 0, 0, 0}, {0, 0, 1, 2}, {1, 1, 1, 0}, {2, 2, 1, 0},
			   {0, 0, 0, 1}, {2, 1, 0, 0}, {0, 1, 1, 1}, {0, 1, 1, 2},
			   {1, 1, 0, 0}, {2, 1, 1, 0}, {0, 0, 1, 1}, {1, 1, 1, 0},
			   {1, 0, 1, 2}, {0, 0, 0, 1}, {0, 1, 2, 1} };

int dy[][4] = { {0, 1, 2, 3}, {0, 0, 0, 0}, {0, 1, 0, 1}, {0, 0, 0, 1},
			   {0, 0, 1, 2}, {0, 1, 1, 1}, {0, 1, 2, 2}, {0, 1, 1, 1},
			   {0, 1, 2, 2}, {0, 0, 0, 1}, {0, 0, 1, 2}, {0, 0, 1, 1},
			   {0, 1, 1, 2}, {0, 0, 1, 1}, {0, 1, 1, 2}, {0, 1, 2, 1},
			   {0, 1, 1, 1}, {0, 1, 2, 1}, {0, 0, 0, 1} };
int n, m;
int solve(int x,int y)
{
	int max = 0;
	for (int i = 0; i < 19; i++)
	{
		int sum = 0;
		for (int j = 0; j < 4; j++)
		{
			int nx = x + dx[i][j];
			int ny = y + dy[i][j];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) break;
			sum += map[nx][ny];
		}
		if (sum > max)
			max = sum;
	}
	return max;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (max < solve(i, j))
				max = solve(i, j);
		}
	}
	cout << max;
}