#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int INF = 1e9; // 무한대로 나타내는 값
int V,E; // V: 정점의 갯수, E : 간선의 갯수
int K; // K : 시작점
vector<vector<pair<int,int>>> graph(20001); //(도착 정점, 가중치))
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
int value[20001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> V >> E;
    cin >> K;
    for(int i = 0 ; i < E;i++){
        int u, v, w; // u->v 로 가는 가중치 w
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v,w));
    }
    for(int i=1;i<=V;i++){
        value[i] = INF;
    }
    value[K] = 0;
    pq.push(make_pair(0,K));
    while(!pq.empty()){
        int x = pq.top().first;
        int U = pq.top().second;
        pq.pop();
        for(int i=0;i<graph[U].size();i++){
            int V = graph[U][i].first;
            int W = graph[U][i].second;
            if(x+W<value[V]){
                value[V] = x + W;
                pq.push(make_pair(x+W,V));
            }
        }
    }
    for(int i=1;i<=V;i++)
		if(value[i]==INF) cout << "INF" << "\n";
		else cout << value[i] << "\n";
	
	return 0;
}