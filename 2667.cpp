#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
string arr[25];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1, -1, 0, 0 };
int n;
int bfs(int x,int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	int num = 1; int c=0;
	while (q.size() != 0)
	{
		int qs = q.size();
		while (qs--)
		{
			int nx = q.front().first;
			int ny = q.front().second;
			arr[nx][ny] = '0';
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nnx = nx; int nny = ny;
				if (nnx + dx[i] >= 0 && nny + dy[i] >= 0&&nnx+dx[i]<n&&nny+dy[i]<n)
				{
					while (arr[nnx + dx[i]][nny + dy[i]] == '1')
					{
						arr[nnx + dx[i]][nny + dy[i]] = '0';
						nnx += dx[i], nny += dy[i];
						for (int i = 0; i < 4; i++)
						{
							if (nnx + dx[i] >= 0 && nny + dy[i] >= 0 && nnx + dx[i] < n && nny + dy[i] < n)
							{
								if (arr[nnx + dx[i]][nny + dy[i]] != '0')
								{
									c = 1; break;
								}
							}
						}
						if(c==1)
							q.push({ nnx,nny });
						num++;
						c = 0;
						if ((nnx + dx[i] < 0 || nny + dy[i] < 0 )||( nnx + dx[i] >= n|| nny + dy[i] >= n))
							break;
					}
				}
			}
		}
	}
	return num;
}

int main()
{

	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == '1')
				v.push_back(bfs(i,j));
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];
		if (i != v.size() - 1)
			cout << endl;
	}
}