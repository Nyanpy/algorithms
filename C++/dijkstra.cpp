#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, int> P;
#define MAX_N 1000000
#define INF 10000001

static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int N, M;
vector<P> adj[MAX_N];
vector<int> ans(MAX_N);

bool dijkstra() {
    priority_queue<P> PQ;
    int color[MAX_N];
    int d[MAX_N];
    for (int i = 0; i < N; i++) {
        d[i] = INF;
        color[i] = WHITE;
        ans.at(i) = -1;
    }
    d[0] = 0;
    PQ.push(make_pair(0, 0));
    color[0] = GRAY;

    while( !PQ.empty() ) {
        P f = PQ.top();
        PQ.pop();
        int u = f.second;
        color[u] = BLACK;

        if (d[u] < f.first * (-1)) continue;

        for (int j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j].first;
            if (color[v] == BLACK) continue;
            if (d[v] > d[u] + adj[u][j].second) {
                d[v] = d[u] + adj[u][j].second;
                ans.at(v) = u + 1;
                PQ.push(make_pair(d[v] * (-1), v));
                color[v] = GRAY;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        if (d[i] == INF) return false;
    }
    return true;
}

int main(){
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        u--;
        v--;
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }
    bool flag = dijkstra();
    if (flag) {
        cout << "Yes" << endl;
        for (int i = 1; i < N; i++) cout << ans.at(i) << endl;
    } else cout << "No" << endl;
    return 0;
}
