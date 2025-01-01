#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<string>
using namespace std;

unordered_map<string, int> dict;
int N, M;
string str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	cin >> str;
	string a = "IOI";
	string b = "OI";
	for (int i = 0; i < N - 1; i++) {
		a += b;
	}
	int length = 3 + 2 * (N - 1);
	for (int i = 0; i < M - length + 1; i++) {
		dict[str.substr(i, length)]++;
	}
	cout << dict[a];
}
