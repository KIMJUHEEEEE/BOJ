#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

int main() {
	int n = 0;
	int m = 0;
	cin >> n >> m;
	vector <int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int h = v[n - 1] - 1;
	int ans = n - 1;
	int sum = 0;
		while (1)
		{
			while (v[ans] > h)
				sum += v[ans--] - h;
			if (sum >= m)
			{
				break;
			}
			else
			{
				h--;
				sum += n-1-ans;
			}
		}
	printf("%d", h);
}
