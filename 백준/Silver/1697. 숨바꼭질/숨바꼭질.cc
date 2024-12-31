#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int N, K; // 수빈이 위치 동생 위치
int ans;
bool visited[100001];
queue<pair<int, int>> q; // 큐

void BFS(int n, int k) {
	visited[n] = true;
	q.push({ n, 0 });
	while (!q.empty()) {
		pair<int, int> m = q.front();
		q.pop();
		if (m.first == k) {
			ans = m.second;
			break;
		}

		if (m.first + 1 <= 100000 && visited[m.first + 1] == 0) {
			visited[m.first + 1] = true;
			q.push(make_pair(m.first + 1, m.second + 1));
		}
		if (m.first - 1  >= 0 && visited[m.first - 1] == 0) {
			visited[m.first -1] = true;
			q.push(make_pair(m.first - 1, m.second + 1));
		}
		if (m.first *2 <= 100000 && visited[m.first * 2] == 0) {
			visited[m.first * 2] = true;
			q.push(make_pair(m.first * 2, m.second + 1));
		}
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	BFS(N, K);
	cout << ans;
	return 0;
}