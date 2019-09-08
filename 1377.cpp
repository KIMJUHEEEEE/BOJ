#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	vector<pair<int,int>> v;
	int a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(pair<int, int>(a, i));
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i].second - i > ans)
			ans = v[i].second - i;
	}
	cout << ans + 1 << '\n';
}