#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
struct Point {
	int i, j;
};
int disc[51][50];
int N, M, T;
void rotate_clock(int n, int cnt) {
	for (int i = 1; i <= N; i++) {
		if (i % n == 0) {
			for (int k = 0; k < cnt; k++) {
				int t = disc[i][M - 1];
				for (int j = M - 1; j - 1 >= 0; j--) {
					disc[i][j] = disc[i][j - 1];
				}
				disc[i][0] = t;
			}
		}
	}
}
void rotate_anticlock(int n, int cnt) {
	for (int i = 1; i <= N; i++) {
		if (i % n == 0) {
			for (int k = 0; k < cnt; k++) {
				int t = disc[i][0];
				for (int j = 0; j + 1 < M; j++) {
					disc[i][j] = disc[i][j + 1];
				}
				disc[i][M - 1] = t;
			}
		}
	}
}
bool delete_num() {
	vector<Point> v;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (disc[i][j] == 0) continue;
			if (disc[i][j] == disc[i][(j + 1) % M]) {
				v.push_back({ i,j });
				v.push_back({ i,(j + 1) % M });
			}
		}
	}
	for (int j = 0; j < M; j++) {
		for (int i = 1; i + 1 <= N; i++) {
			if (disc[i][j] == 0) continue;
			if (disc[i][j] == disc[i + 1][j]) {
				v.push_back({ i,j });
				v.push_back({ i + 1,j });
			}
		}
	}
	if (v.size() == 0) return false;
	int size = v.size();
	for (int i = 0; i < size; i++) {
		Point now = v[i];
		disc[now.i][now.j] = 0;
	}
	return true;
}
void bojung() {
	int sum = 0, cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (disc[i][j] != 0) {
				cnt++;
				sum += disc[i][j];
			}
		}
	}
	if (cnt == 0) return;
	double ave = (double)sum / cnt;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (disc[i][j] == 0) continue;
			if (disc[i][j] > ave) {
				disc[i][j]--;
			}
			else if (disc[i][j] < ave) {
				disc[i][j]++;
			}
		}
	}
}
void simulate() {
	for (int t = 0; t < T; t++) {
		int x, d, k;
		cin >> x >> d >> k;
		if (d == 0) rotate_clock(x, k);
		else rotate_anticlock(x, k);
		if (!delete_num()) bojung();
	}
}
int get_sum() {
	int ret = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			ret += disc[i][j];
		}
	}
	return ret;
}
void input() {
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> disc[i][j];
		}
	}
}
int main() {
	input();
	simulate();
	cout << get_sum() << '\n';
	return 0;
}