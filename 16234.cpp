#include<iostream>
#include<queue>
#include<cmath>
#include<string.h>
using namespace std;
int N, L, R;
int map[51][51];
int visit[51][51];
int vvisit[51][51];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int ans;

bool bfs(int x,int y)
{
	queue<pair<pair<int, int>, int>> country;
	country.push({ {x,y},map[x][y] });
	int cnt = map[x][y];
	int num = 1;
	visit[x][y] = 1;
	while (country.size() != 0)
	{
		int cs = country.size();
		while (cs--)
		{
			int x = country.front().first.first;
			int y = country.front().first.second;
			int c = country.front().second;
			country.pop();
			for (int i = 0; i < 4; i++)
			{
				if (x + dx[i] >= 0 && x + dx[i] < N && y + dy[i] >= 0 && y + dy[i] < N && visit[x + dx[i]][y + dy[i]] == 0&&abs(c-map[x+dx[i]][y+dy[i]])>=L&&abs(c-map[x+dx[i]][y+dy[i]])<=R)
				{
					visit[x + dx[i]][y + dy[i]] = 1;
					country.push({ {x + dx[i],y + dy[i]},map[x + dx[i]][y + dy[i]] });
					cnt += map[x + dx[i]][y + dy[i]];
					num++;
				}
			}
		}
	}

	if (num > 1)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (visit[i][j] == 1&&vvisit[i][j]==0)
				{
					map[i][j] = cnt / num;
					vvisit[i][j] = 1;
				}
			}
		}
		return 1;
	}
	else
	{
		visit[x][y] = 0;
		return 0;
	}

}
int main()
{
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}
	while (1)
	{
		memset(visit, 0, sizeof(visit));
		memset(vvisit, 0, sizeof(vvisit));
		int ct = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (visit[i][j] == 0)
				{
					bool check=bfs(i, j);
					if(check==1)
						ct++;
				}
			}
		}
		if (ct == 0)
			break;
		else
			ans++;
	}
	cout << ans;
}