#include<iostream>
#include<vector>
using namespace std;
int n, m;
int map[8][8];
int copymap[8][8];
vector<pair<pair<int,int>,pair<int,int>>> v;
int ans;

void input()
{
	ans = 99999999;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (1<=map[i][j]  && map[i][j] <= 5)
				v.push_back({ {i,j},{map[i][j],-1} });
		}
	}
}
void copyM()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			copymap[i][j] = map[i][j];
		}
	}
}
void left(int x,int y)
{
	for (int i = y - 1; i >= 0; i--)
	{
		if (copymap[x][i] == 6) break;
		if (1 <= copymap[x][i] && copymap[x][i] <= 5) continue;
		copymap[x][i] = -1;
	}
}
void right(int x, int y)
{
	for (int i = y + 1; i <m; i++)
	{
		if (copymap[x][i] == 6) break;
		if (1 <= copymap[x][i] && copymap[x][i] <= 5) continue;
		copymap[x][i] = -1;
	}
}
void up(int x, int y)
{
	for (int i = x - 1; i >=0; i--)
	{
		if (copymap[i][y] == 6) break;
		if (1 <= copymap[i][y] && copymap[i][y] <= 5) continue;
		copymap[i][y] = -1;
	}
}
void down(int x, int y)
{
	for (int i = x +1; i <n; i++)
	{
		if (copymap[i][y] == 6) break;
		if (1 <= copymap[i][y] && copymap[i][y] <= 5) continue;
		copymap[i][y] = -1;
	}
}
void check()
{
	copyM();
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].second.first == 1)
		{
			if (v[i].second.second == 0)right(v[i].first.first, v[i].first.second);
			else if(v[i].second.second==1) left(v[i].first.first, v[i].first.second);
			else if(v[i].second.second==2) down(v[i].first.first, v[i].first.second);
			else if(v[i].second.second==3) up(v[i].first.first, v[i].first.second);
		}
		else if (v[i].second.first == 2)
		{
			if (v[i].second.second == 0 || v[i].second.second == 1)
			{
				right(v[i].first.first, v[i].first.second);
				left(v[i].first.first, v[i].first.second);
			}
			else if (v[i].second.second == 2 || v[i].second.second == 3)
			{
				up(v[i].first.first, v[i].first.second);
				down(v[i].first.first, v[i].first.second);
			}
		}
		else if (v[i].second.first == 3)
		{
			if (v[i].second.second == 0)
			{
				up(v[i].first.first, v[i].first.second);
				right(v[i].first.first, v[i].first.second);
			}
			else if (v[i].second.second == 1)
			{
				right(v[i].first.first, v[i].first.second);
				down(v[i].first.first, v[i].first.second);
			}
			else if (v[i].second.second == 2)
			{
				down(v[i].first.first, v[i].first.second);
				left(v[i].first.first, v[i].first.second);
			}
			else if (v[i].second.second == 3)
			{
				left(v[i].first.first, v[i].first.second);
				up(v[i].first.first, v[i].first.second);
			}
		}
		else if (v[i].second.first == 4)
		{
			if (v[i].second.second == 0)
			{left(v[i].first.first, v[i].first.second);
				up(v[i].first.first, v[i].first.second);
				right(v[i].first.first, v[i].first.second);
				
			}
			else if (v[i].second.second == 1)
			{
				up(v[i].first.first, v[i].first.second);
				right(v[i].first.first, v[i].first.second);
				down(v[i].first.first, v[i].first.second);
			}
			else if (v[i].second.second == 2)
			{
				right(v[i].first.first, v[i].first.second);
				down(v[i].first.first, v[i].first.second);
				left(v[i].first.first, v[i].first.second);
			}
			else if (v[i].second.second == 3)
			{
				down(v[i].first.first, v[i].first.second);
				left(v[i].first.first, v[i].first.second);
				up(v[i].first.first, v[i].first.second);
			}
		}
		else if (v[i].second.first == 5)
		{
			right(v[i].first.first, v[i].first.second);
			up(v[i].first.first, v[i].first.second);
			down(v[i].first.first, v[i].first.second);
			left(v[i].first.first, v[i].first.second);
		}
	}
}
int count()
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (copymap[i][j] == 0) sum++;
		}
	}
	return sum;
}
int min(int a, int b)
{
	if (a < b) return a;
	return b;
}
void dir(int cnt)
{
	if (cnt == v.size())
	{
		check();
		ans=min(ans, count());
		return;
	}
	v[cnt].second.second = 0;
	dir(cnt + 1);
	v[cnt].second.second = 1;
	dir(cnt + 1);
	v[cnt].second.second = 2;
	dir(cnt + 1);
	v[cnt].second.second = 3;
	dir(cnt + 1);
}
int main()
{
	input();
	dir(0);
	cout << ans;
}