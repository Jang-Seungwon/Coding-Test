#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;

int N, M, B;
int ans;
int board[501][501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> B;
	int Min = 2147000000;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i <= 256; i++) {
		int height = i;
		int sum = B;
		int Time = 0;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (board[j][k] >= height) {
					Time += (board[j][k] - height) * 2;
					sum += board[j][k] - height;
				}
				else {
					Time += height - board[j][k];
					sum -= height - board[j][k];
				}
			}
		}
		if (sum>=0) {
			if (Min >= Time) {
				Min = Time;
				ans = height;
			}
		}
	}
	cout << Min << " " << ans;
}