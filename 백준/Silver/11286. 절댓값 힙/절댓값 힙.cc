#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N;

struct cmp {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b)) return a > b;
		return abs(a) > abs(b);
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	priority_queue<int, vector<int>, cmp> pq;
	int N; cin >> N;
	int in = 0;
	while (N--) {
		cin >> in;
		if (in == 0) {
			if (pq.empty()) { cout << 0 << "\n"; continue; }
			cout << pq.top() << "\n"; pq.pop();
		}
		else {
			pq.push(in);
		}
	}
	return 0;
}