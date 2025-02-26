#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 51
using namespace std;

int board[MAX][MAX];
bool visited[14];
int N, M;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<pair<int, int>> v;
int ans = 100000000;

int dist() {
	int answer = 0;
	for (int i = 0; i < house.size(); i++) {
		int Distance = 10000000;
		for (int j = 0; j < v.size(); j++) {
			Distance = min(Distance,abs(house[i].first - v[j].first) + abs(house[i].second - v[j].second));
		}
		answer += Distance;
	}
	return answer;
}

void select_chicken(int idx, int cnt) {
	if (cnt == M) {
		ans = min(ans, dist());
		return;
	}
	for (int i = idx; i < chicken.size(); i++) {
		if(visited[i] == false){
			visited[i] = true;
			v.push_back(chicken[i]);
			select_chicken(i,cnt + 1);
			v.pop_back();
			visited[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++){
			cin >> board[i][j];
			if (board[i][j] == 1) house.push_back(make_pair(i,j));
			if (board[i][j] == 2) chicken.push_back(make_pair(i, j));
		}
	}
	select_chicken(0,0);
	cout << ans;
}