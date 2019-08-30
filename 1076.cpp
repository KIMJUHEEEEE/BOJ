#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

int main() {
	int ans = 0;

	string a, b, c;
	string color[10] = { "black","brown","red","orange","yellow","green","blue","violet","grey","white" };
	cin >> a >> b >> c;
	for (int i = 0; i < 10; i++)
	{
		if (a == color[i]) ans += i * 10;
		if (b == color[i]) ans += i;
	}
	for (int i = 0; i < 10; i++)
	{
		if (c == color[i]) ans *= pow(10, i);
	}
	cout << ans;
}