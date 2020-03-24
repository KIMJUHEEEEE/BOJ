#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	int b, c;
	cin >> b >> c;
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans++;
		v[i] -= b;
		if (v[i] > 0)
		{
			ans += v[i] / c;
			if (v[i] % c != 0)
				ans++;
		}
	}
	cout << ans;
}