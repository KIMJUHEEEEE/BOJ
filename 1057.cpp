#include<iostream>
using namespace std;

int main()
{
	int n = 0;
	int a, b;
	int ans = 0;
	cin>>n >> a >> b;
	int i=0;
	while (++i)
		{
		a+=1; b+=1;
			if (a/2==b/2)
			{
				ans = i;
				break;
			}
			a /= 2; b/= 2;
		}

	cout << ans;
}