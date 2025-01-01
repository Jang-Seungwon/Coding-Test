#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int N, M;
int ans,cnt;
string str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i=0;
	cin >> N >> M;
	cin >> str;
	while (i < M) {
		if (str.substr(i, 3) == "IOI") {
			cnt++;
			if (cnt == N) {
				ans++; // 패턴발견
				cnt--;
			}
			i += 2;
		}
		else {
			cnt = 0;
			i++;
		}
	}
	cout << ans;
}
