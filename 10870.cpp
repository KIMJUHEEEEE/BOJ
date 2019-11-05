#include <iostream>
using namespace std;

int arr[21];
int fib(int n) {
	arr[1] = 1;
	for (int i = 2; i < 21; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	return arr[n];
}

int main() {
	int n = 0;
	cin >> n;
	cout << fib(n);
}
