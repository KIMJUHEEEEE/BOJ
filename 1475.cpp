#include<iostream>
#include<string>
#include <cmath>
using namespace std;

int main()
{
	string a;
	cin >> a;
	int arr[11] = { 0, };
	for (int i = 0; i < a.size(); i++)
	{
		arr[a[i] - 48]++;
	}
	int max = 0;
	for (int i = 0; i < 11; i++)
	{
		if (i == 6 || i == 9)
			continue;
		if (arr[i] > max)
			max = arr[i];
	}
	if (max < (arr[6] + arr[9] + 1) / 2)
		max = (arr[6] + arr[9] + 1) / 2;
	cout << max;
}