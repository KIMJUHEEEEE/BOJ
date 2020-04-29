#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int n;
int arr[21][21];
int visit[21];
int ta;
int tb;
int ans=9999999;
vector<int> teama;
vector<int> teamb;
void dfs(int index, int cnt)
{
	if (index > n) return;
	if (cnt == n/2)
	{
		teama.clear();
		teamb.clear();
		ta = 0, tb = 0;
		for (int i = 1; i <= n; i++)
		{
			if (visit[i] == 1)
			{
				teama.push_back(i);
			}
			else
				teamb.push_back(i);
		}
		for (int i = 0; i < n / 2-1; i++)
		{
			for (int j = i + 1; j < n / 2; j++)
			{
				ta += arr[teama[i]][teama[j]];
				ta += arr[teama[j]][teama[i]];
				tb += arr[teamb[i]][teamb[j]];
				tb += arr[teamb[j]][teamb[i]];
			}
		}
		if (abs(ta - tb) < ans)
			ans = abs(ta - tb);
		return;
	}
	visit[index + 1] = 1;
	dfs(index + 1, cnt + 1);
	visit[index + 1] = 0;
	dfs(index + 1, cnt);
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
		}
	}
	visit[1] = 1;
	dfs(1, 1);
	visit[1] = 0;
	dfs(1, 0);
	cout << ans;
}