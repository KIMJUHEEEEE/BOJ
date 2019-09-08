#include<iostream>
#include<stack>
#include <string>
#include<vector>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	stack <int> s;
	for (int i = 0; i < n; i++)
	{
		string a;
		int b;
		cin >> a;
		if (a == "push")
		{
			cin >> b;
			s.push(b);
		}
		else if (a == "pop")
		{
			if (s.size() == 0)
				cout << -1<<endl;
			else
			{
				cout << s.top()<<endl;
				s.pop();
			}
		}
		else if (a == "size")
		{
			cout << s.size()<<endl;
		}
		else if (a == "empty")
		{
			if (s.size() == 0)
				cout << 1 << endl;
			else
				cout << 0<<endl;
		}
		else
		{
			if (s.size() == 0)
				cout << -1<<endl;
			else
				cout << s.top() << endl;
		}
	}
}