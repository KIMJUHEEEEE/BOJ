#include<iostream>
#include<queue>
using namespace std;
int map[101][101];
int snake[101][101];
queue<pair<int, char>> q;
queue<pair<int, int>> s;
int n;

int move()
{
	snake[1][1] = 1;
	int x = 1, y = 1;
	s.push({ x,y });
	char fc = 'S';
	int time = 0;
	int cnt = 0;
	while (1)
	{
			int t = 999999;
			char c = fc;
		if(q.size()>0)
		{
			t = q.front().first;
			c = q.front().second;
			q.pop();
		}
		while (cnt< t)
		{
			cnt++;
			if (fc == 'S')//오른쪽 진행
			{
				if (snake[x][y+1] == 1) return cnt;
				if (y + 1 > n) return cnt;
				snake[x][y+1] = 1;
				y += 1;
				s.push({ x,y });
				if (map[x][y] == 0)
				{
					int a, b;
					a = s.front().first;
					b = s.front().second;
					s.pop();
					snake[a][b] = 0;
				}
				else
					map[x][y] = 0;
			}
			else if (fc == 'A')//왼쪽 진행
			{
				if (snake[x][y-1] == 1) return cnt;
				if (y-1 ==0) return cnt;
				snake[x][y-1] = 1;
				y -= 1;
				s.push({ x,y });
				if (map[x][y] ==0)
				{
					int a, b;
					a = s.front().first;
					b = s.front().second;
					s.pop();
					snake[a][b] = 0;
				}
				else
					map[x][y] = 0;
			}
			else if (fc == 'W')//위쪽 진행
			{
				if (snake[x-1][y] == 1) return cnt;
				if (x - 1 == 0) return cnt;
				snake[x-1][y] = 1;
				x-= 1;
				s.push({ x,y });
				if (map[x][y] ==0)
				{
					int a, b;
					a = s.front().first;
					b = s.front().second;
					s.pop();
					snake[a][b] = 0;
				}
				else
					map[x][y] = 0;
			}
			else if (fc == 'Z')//아래쪽 진행
			{
				if (snake[x+1][y] == 1) return cnt;
				if (x + 1 > n) return cnt;
				snake[x+1][y] = 1;
				x += 1;
				s.push({ x,y });
				if (map[x][y] ==0)
				{
					int a, b;
					a = s.front().first;
					b = s.front().second;
					s.pop();
					snake[a][b] = 0;
				}
				else
					map[x][y] = 0;
			}
		}
		if (c == 'D')
		{
			if (fc == 'S') fc = 'Z';
			else if (fc == 'A') fc = 'W';
			else if (fc == 'W') fc = 'S';
			else if (fc == 'Z') fc = 'A';
		}
		else if (c == 'L')
		{
			if (fc == 'A') fc = 'Z';
			else if (fc == 'W') fc = 'A';
			else if (fc == 'S') fc = 'W';
			else if (fc == 'Z') fc = 'S';
		}
	}
	int a,b;
	while (s.size() > 1)
	{
		s.pop();
	}
	a = s.front().first;
	b= s.front().second;
	if (fc == 'A') cnt =cnt+ b+1;
	else if (fc == 'S') cnt = cnt + n - b+1;
	else if (fc == 'W') cnt =cnt+ a+1;
	else cnt = cnt + n - a+1;
	return cnt;
}

int main()
{
	cin >> n;
	int k = 0;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
	}
	int l = 0;
	cin >> l;
	for (int i = 0; i < l; i++)
	{
		int a; char c;
		cin >> a >> c;
		q.push({ a,c });
	}
	cout << move();
}
