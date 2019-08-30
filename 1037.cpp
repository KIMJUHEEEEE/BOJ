#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int ca;
	cin >> ca;
	int a[51];
	int n = 0;
	for (int i = 0; i < ca; i++)
	{
		cin >> a[i];
	}
	sort(a, a + ca);
	if (ca % 2 == 0)
		n = a[ca / 2 - 1] * a[ca/2];
	else
		n = a[ca / 2] * a[ca / 2];
	cout << n;
}