#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define MAX 8
using namespace std;

int N, M;
int ans = -100000;
int board[MAX][MAX];
int test_board[MAX][MAX];
int selected[MAX*MAX];
bool visited[MAX][MAX];
vector<pair<int, int>> virus;
vector<pair<int, int>> hole;
vector<pair<int, int>> v;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void board_init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			test_board[i][j] = board[i][j];
			visited[i][j] = 0;
		}
	}
}

void bfs() {
	queue <pair<int, int>> q;
	for (int i = 0; i < virus.size(); i++) {
		int virus_x = virus[i].first;
		int virus_y = virus[i].second;
		q.push(make_pair(virus_x, virus_y));
		visited[virus_x][virus_y] = true;
	}

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int j = 0; j < 4; j++) {
			int nx = cx + dx[j];
			int ny = cy + dy[j];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny] && test_board[nx][ny] == 0) {
				visited[nx][ny] = true;
				test_board[nx][ny] = 2;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

int zone() {
	board_init(); // 테스트 보드랑 visited 모두 초기화
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;
		test_board[x][y] = 1;
	}
	bfs();
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (test_board[i][j] == 0) {
				cnt++;
			}
		}
	}
	return cnt;
}

void select_research(int idx, int cnt) {
	if (cnt == 3) {
		ans = max(ans, zone());
		return;
	}
	for (int i = idx; i < hole.size(); i++) {
		if (!selected[i]) {
			selected[i] = true;
			v.push_back(hole[i]);
			select_research(i + 1, cnt + 1);
			v.pop_back();
			selected[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j]; 
			if (board[i][j] == 2) virus.push_back(make_pair(i, j));
			if (board[i][j] == 0) hole.push_back(make_pair(i, j));
		}
	}
	select_research(0,0);
	cout << ans;
}