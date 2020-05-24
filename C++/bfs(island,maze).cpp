#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> P
static const int MAX_N = 1000;
static const int MAX_M = 1000;
static const int INF = 1000000001;

int d[MAX_M][MAX_N];

int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void start_up(){
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_M; j++) {
            d[i][j] = INF;
        }
    }
}

int bfs(vector<P> input, P s, P g){
    
    queue<P> q;
    q.push(s);
    check[s.first][s.second] = 1;
    
    while(!q.empty()) {
        P tmp = q.front();
        q.pop();
        if (tmp.first == g.first && tmp.second = g.second) break;
        for (int i = 0; i < 4; i++) {
            int x = tmp.first + dx[i];
            int y = tmp.second + dy[i];
            // 今回は、inputが1のときが"通れる場所"としている
            if (x >= 0 && x < n && y >= 0 && y < m && input.at(x).at(y) == 1 && d[x][y] == INF) {
                d[x][y] = d[tmp.first][tmp.second] + 1;
                q.push({x, y});
            }
        }
    }
    return d[g.first][g.second];
}

int main(void){
    start_up();
    cin >> m >> n;
    
    // 島、もしくは迷路の地形を2次元配列でinputする
    vector<vector<int>> input(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> input.at(i).at(j);
        }
    }
    
    // 迷路のゴールへの最短経路を測定する時
    int ans = bfs(input, {0, 0});
    cout << ans << endl;
    
    // 島の数を数えるとき
    /*
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (input.at(i).at(j) == 1 && check[i][j] == 0) {
                int a = bfs(input, {i, j});
                ans++;
            }
        }
    }
    cout << ans << endl;
    */
    
    return 0;
}
