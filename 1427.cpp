#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	cin >> str; 
	char arr[11] = {' ',};
	for (int i = 0; i < str.size(); i++)
	{
		arr[i] = str[i];
	}
	for (int i = str.size()-1; i >0; i--)
	{
		for (int j = i - 1; j >=0; j--)
		{
			if (arr[i] > arr[j])
			{
				char tmp = ' ';
				tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
		}
	}
	for (int i = 0; i < str.size(); i++)
	{
		cout << arr[i];
	}
}