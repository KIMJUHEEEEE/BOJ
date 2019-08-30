#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	string s[51];
	string ans;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	for (int i = 0; i < s[0].size(); i++)
	{
		int a =1;
		for (int j = 0; j < n-1; j++)
		{
			if (s[j][i] == s[j + 1][i])
				a++;
		}
		if (a == n)
			ans += s[0][i];
		else
			ans += "?";
	}
	cout << ans;
}