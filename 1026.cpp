#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int ca;
	cin >> ca;
	int a[51];
	int b[51];
	int c[51];
	for (int i = 0; i < ca; i++)
	{
		cin >> a[i];
	}
	sort(a, a + ca);
	for (int i = 0; i < ca; i++)
	{
		cin >> b[i];
		c[i] = b[i];
	}
	sort(c, c + ca);
	int sum = 0;
	for (int i = 0; i < ca; i++)
	{
		sum += a[i] * c[ca - i - 1];
	}
	cout << sum;
}