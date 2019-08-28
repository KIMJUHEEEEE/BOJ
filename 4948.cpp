#include<iostream>
using namespace std;

int main()
{
	int arr[123457*2] = { 0, };
	int cnt[123457*2] = { 0, };
	for (int i = 1; i <= 2*123456; i++)
	{
		arr[i] = i;
	}
	cnt[1] = 1;
	for (int i = 2; i <= 2*123456; i++)
	{
		if (arr[i] == 0)
		{
			cnt[i] = cnt[i - 1];
			continue;
		}
		else
			cnt[i] = cnt[i - 1] + 1;
		for (int j = i + i; j <= 2*123456; j += i)
			arr[j] = 0;
	}
	while (1)
	{
		int n = 0;
		cin >> n;
		if (n == 0)
			break;
		cout << cnt[2*n]-cnt[n]<<endl;
	}
}