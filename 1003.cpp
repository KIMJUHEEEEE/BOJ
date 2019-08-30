#include<iostream>
#include<vector>
using namespace std;




int main() {
	int ca;
	cin >> ca;
	int v[41][2];
	for (int i = 0; i < ca; i++) {
		int n;
		cin >> n;
		v[0][0] = 1; v[0][1] = 0;
		v[1][0] = 0; v[1][1] = 1;
		if (n >= 2)
		{
			for (int i = 2; i <= n; i++)
			{
				v[i][0] = v[i - 1][0] + v[i - 2][0];
				v[i][1] = v[i - 1][1] + v[i - 2][1];
			}
		}
	cout << v[n][0]<<' '<<v[n][1]<<endl;
	
	}
}