#include<iostream>
#include<queue>
using namespace std;
int arr[101][101];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n = 0;

queue<pair<int, int>> q;
int bfs(int num)
{
	int ans = 0;
	int check[101][101] = { {0}, };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] <= num)
			{
				arr[i][j] = 0;
				check[i][j] = 1;
			}

		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] != 0&&check[i][j]==0)
			{
				q.push({ i,j });
				check[i][j] = 1;
				while (q.size() != 0)
				{
					int qs = q.size();
					while (qs--) {
						int qx = q.front().first;
						int qy = q.front().second;
						q.pop();
						for (int z = 0; z < 4; z++)
						{
							int x = qx, y = qy;
							while (check[x + dx[z]][y + dy[z]] != 1&&x+dx[z]>=0&&y+dy[z]>=0
								&&x+dx[z]<n&&y+dy[z]<n)
							{
								x += dx[z], y += dy[z];
								check[x][y] = 1;
								q.push({ x,y });
							}

						}
					}
				}
				ans++;
			}
			
		}
	}
	return ans;
}

int main()
{
	cin >> n;
	int min = 999;
	int max = 0;
	int pm = 0;
	int x = 0; int y = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] < min)
			{
				min = arr[i][j];
			}
			if (arr[i][j] > max)
			{
				max = arr[i][j];
				x = i; y = j;
			}
		}
	}

	for (int i = min-1; i <= max; i++)
	{
		int s=bfs(i);
		if (s > pm)
			pm = s;
	}
	cout << pm;
}