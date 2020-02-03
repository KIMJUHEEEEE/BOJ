#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int arr[10002];

void cal()
{
	arr[1] = 0;
	for (int i = 1; i < 10000; i++)
	{
		int s = i;
		int ans = s;
		while (s > 0)
		{
			ans += s % 10;
			s /= 10;
		}
		arr[ans] = 1;
	}
}

int main()
{
	cal();
	for (int i = 1; i <= 10000; i++)
	{
		if (arr[i] == 0)
			cout << i << endl;
	}
}
