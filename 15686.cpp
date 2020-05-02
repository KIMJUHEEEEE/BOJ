#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int n, m;
int map[51][51];
int visit[14];
vector<pair<int, int>> chicken;
int ans=9999;
int count()
{
	int numcount = 0;
	for (int a = 0; a < n; a++)
	{
		for (int b = 0; b < n; b++)
		{
			if (map[a][b] == 1)
			{
				int mini = 9999;
				for (int i = 0; i < chicken.size(); i++)
				{
					if (visit[i] == 1)
					{
						int count = 0;
						int x = chicken[i].first;
						int y = chicken[i].second;
						count = abs(a - x) + abs(b - y);
						if (count < mini)
							mini = count;
					}
				}
				numcount += mini;
			}
		}
	}
	return numcount;
}
void dfs(int cnt,int index)
{
	if (cnt == m)
	{
		int a=count();
		if (a < ans)
			ans = a;
		return;
	}
	if (index >= chicken.size()) return;
	visit[index] = 1;
	dfs(cnt + 1, index + 1);
	visit[index] = 0;
	dfs(cnt, index + 1);
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2)
			{
				chicken.push_back( { i,j });
			}
		}
	}
	dfs(0,0);
	cout << ans;
}