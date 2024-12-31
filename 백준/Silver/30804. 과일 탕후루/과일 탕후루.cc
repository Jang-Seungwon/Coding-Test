#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N; // 탕후루 갯수
int Left, Right; // index로 활용
int ans, cnt=1;
vector<int> v; // 탕후루 꼬치
vector<int> chk(10,0); // 개수 체크

int main(int argc, char** argv)
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		int k;
		cin >> k;
		v.push_back(k);
	}
	chk[v[Left]]++;
	while (Left<=Right && Right<N) {
		if (cnt <= 2) {
			ans = max(ans, Right - Left + 1);
			Right++;
			if (Right == N) break;
			if (!chk[v[Right]]) cnt++; // v[Right]가 새로운 애면, cnt를 올려주고
			chk[v[Right]]++; // 갯수도 하나 올려준다.
		}
		else {
			chk[v[Left]]--;
			if (!chk[v[Left]]) cnt--;
			Left++;
		}
	}
	cout << ans;

	return 0;
}