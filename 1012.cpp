#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;
int map[51][51];
int m = 0, n = 0, cab = 0;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1, -1, 0, 0 };

int bfs()
{
	queue<pair<int, int>> q;
	int w = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 1)
			{
				w++;
				q.push({ i,j });
				//map[i][j] = 0;

				while (q.size() > 0)
				{
					int mx = q.front().first, my = q.front().second;
					map[mx][my] = 0;
					q.pop();
					for (int z = 0; z < 4; z++)
					{
						int mmx = mx; int mmy = my;
						while (map[mmx + dx[z]][mmy + dy[z]] == 1)
						{
							mmx += dx[z], mmy += dy[z];
							map[mmx][mmy] = 0;
							q.push({ mmx,mmy });
						}

					}
				}
			}
		}
	}

	return w;
}
int main() {
	int tc = 0;
	cin >> tc;
	for (int i = 0; i < tc; i++)
	{

		cin >> m >> n >> cab;
		for (int i = 0; i < cab; i++)
		{
			int x = 0, y = 0;
			cin >> x >> y;
			map[y][x] = 1;
		}
		cout << bfs();
		if (i < tc - 1)
			cout << endl;
	}
	return 0;
}