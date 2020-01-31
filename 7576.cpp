#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
int tm[1001][1001];
queue<pair<int, int>> q;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int ans = -1;
int bfs()
{
	while (q.size() != 0)
	{
		int qs = q.size();
		ans++;
		while (qs--)
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				if (x + dx[i] >= 0 && y + dy[i] >= 0 && x + dx[i] < m && y + dy[i] < n)
				{
					if (tm[x + dx[i]][y + dy[i]] == 0)
					{
						tm[x + dx[i]][y + dy[i]] = 1;
						q.push({ x + dx[i],y + dy[i] });
					}
				}

			}
		}
	}
	return ans;
}

int main()
{
	cin >> n >> m;
	int zn = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> tm[i][j];
			if (tm[i][j] == 1)
				q.push({ i,j });
			if (tm[i][j] == 0)
				zn++;
		}
	}
	if (zn == 0) {
		cout << 0;
	}
	else {
		int ans = bfs();
		int k = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (tm[i][j] == 0)
					k = 1;
			}
		}
		if (k == 1)
			cout << -1;
		else
			cout << ans;
	}
}