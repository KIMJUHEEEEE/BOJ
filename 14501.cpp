#include<iostream>
#include<algorithm>
using namespace std;
int t[16] = { 0, };
int p[16] = { 0, };
int n = 0;
int m = 0;
void solve(int da, int sum)
{
	if (da == n + 1) {
		if (m < sum)
			m = sum;
		return;
	}
	if (da + t[da] <= n + 1) solve(da + t[da], sum + p[da]);
	if (da + 1 <= n + 1) solve(da + 1, sum);
}
int main()
{

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> t[i] >> p[i];
	}
	solve(1, 0);
	cout << m;
}