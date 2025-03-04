#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;
vector<vector<pair<int, int>>> graph(1001); // (도착 정점, 가중치)
vector<int> value(1001, INF); // start에서 각 노드까지의 최소 거리 저장
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // (가중치, 도착점)
int N, M; // N : 도시의 개수, M : 버스의 개수 
int start, last;

void min_dist(int start) {
	value[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int cw = pq.top().first;
		int cu = pq.top().second;
		pq.pop();

		if (cw > value[cu]) continue; // 기존 비용보다 크면 무시

		for (auto next : graph[cu]) {
			int nu = next.first;
			int nw = next.second;

			if (value[cu] + nw < value[nu]) {
				value[nu] = value[cu] + nw;
				pq.push({ value[nu], nu });
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
	}

	cin >> start >> last;

	min_dist(start);

	cout << value[last] << "\n"; // start에서 last까지의 최소 비용 출력
}
