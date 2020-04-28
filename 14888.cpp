#include<iostream>
using namespace std;
int arr[13];
int n;
long long ma=-1000000001;
long long mi = 1000000001;
int plu, minu, mul, divi;
void dfs(int p,int mnn, int mu, int d , int sum, int index,int cnt)
{
	if (cnt == n - 1)
	{
		if (ma < sum) ma = sum;
		if (mi > sum) mi = sum;
		return;
	}
	if (p < plu)dfs(p + 1, mnn, mu, d, sum + arr[index], index + 1, cnt + 1);
	if (mnn < minu) dfs(p, mnn + 1, mu, d, sum - arr[index], index + 1, cnt + 1);
	if (mu < mul) dfs(p, mnn, mu + 1, d, sum * arr[index], index + 1, cnt + 1);
	if (d < divi)dfs(p, mnn, mu, d + 1, sum / arr[index], index + 1, cnt + 1);

}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cin >> plu >> minu >> mul >> divi;
	dfs(0, 0, 0, 0, arr[0], 1, 0);
	cout << ma << endl << mi;
}
