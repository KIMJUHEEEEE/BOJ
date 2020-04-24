#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
using namespace std;
int n,m;
int map[8][8];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
queue<pair<int, int>> v;
vector<pair<int, int>> cv;
int ans;
int ma;
void makecopy(int arr[8][8],int carr[8][8])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			carr[i][j] = arr[i][j];
		}
	}
}
void virus()
{
	ma = 0;
	int copymap[8][8];
	memset(copymap, 0, sizeof(copymap));
	makecopy(map, copymap);
	for (int i = 0; i < cv.size(); i++)
	{
		v.push({ cv[i].first,cv[i].second });
	}

	while (v.size() > 0)
	{
		int x = v.front().first;
		int y = v.front().second;
		v.pop();
		for (int i = 0; i < 4; i++)
		{
			if (map[x + dx[i]][y + dy[i]] == 0 && x + dx[i] >= 0 && y + dy[i] >= 0 && x + dx[i] < n && y + dy[i] < m)
			{
				map[x + dx[i]][y + dy[i]] = 2;
				v.push({ x + dx[i],y + dy[i] });
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0)
				ma++;
		}
	}
	if (ans < ma)
		ans = ma;
	makecopy(copymap, map);
}

void wall(int cnt)
{
	if (cnt == 3)
	{
		virus();
		return;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0)
			{
				map[i][j] = 1;
				wall(cnt + 1);
				map[i][j] = 0;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2)
			{
				cv.push_back({ i,j });
			}
		}
	}
	int copymap[8][8];
	memset(copymap, 0, sizeof(copymap));
	makecopy(map, copymap);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0)
			{
				
				map[i][j] = 1;
				wall(1);
				map[i][j] = 0;
			}
		}
	}
	cout << ans << endl;
}