#include<iostream>
#include<algorithm>
#include<stack>
#include<string>
#include<cmath>
#include <stdio.h>
#include<queue>
using namespace std;
char arr[11][11];
int map[11][11];
int n = 0, m = 0;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int rx = 0, ry = 0, bx = 0, by = 0, hx = 0, hy = 0;
bool check[11][11][11][11];

int move()
{
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {rx, ry}, { bx,by } });
	int ans = 0;
	check[rx][ry][bx][by] = 1;
	while (q.size() != 0)
	{
		int qs = q.size();
		while (qs--)
		{
			int rrx = q.front().first.first;
			int rry = q.front().first.second;
			int bbx = q.front().second.first;
			int bby = q.front().second.second;
			q.pop();
			if (arr[rrx][rry] == 'O'&&arr[rrx][rry]!=arr[bbx][bby])
				return ans;
			for (int i = 0; i < 4; i++)
			{
				int nr = 0, nb = 0;
				int nrx = rrx, nry = rry, nbx = bbx, nby = bby;
				while (arr[nrx + dx[i]][nry + dy[i]] != '#'&&arr[nrx][nry]!='O')
				{
					nrx += dx[i];
					nry += dy[i];
					nr++;
				}
				while (arr[nbx + dx[i]][nby + dy[i]] != '#'&&arr[nbx][nby]!='O')
				{
					nbx += dx[i];
					nby += dy[i];
					nb++;
				}
				if (nrx == nbx && nry == nby)
				{
					if (arr[nrx][nry] == 'O') continue;
					if (nr > nb)
					{
						nrx -= dx[i];
						nry -= dy[i];
					}
					else
					{
						nbx -= dx[i];
						nby -= dy[i];
					}
				}
				if (check[nrx][nry][nbx][nby]==1)continue;
				q.push({ {nrx,nry},{nbx,nby} });
				check[nrx][nry][nbx][nby] = 1;				
			}
		}
		if (ans == 10)
				return -1;
		ans++;
	}
	return -1;
}

int main() {
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'R')
				rx = i, ry = j;
			else if (arr[i][j] == 'B')
				bx = i, by = j;
		}
	}
	cout << move();
}