#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

int bit_search(int N, vector<int> a) {
    int sum = 0;
    for (int bit = 0; bit < (1 << N); ++bit) {
        for (int i = 0; i < N; i++) {
            if (bit & (1 << i)) {
                // ここで処理をする
                // たとえば、sum += a.at(i) など…
                sum += a.at(i);
            }
        }
    }
    return sum;
}

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a.at(i);
    
    // bit全探索
    int ans = bit_search(N, a);
    cout << ans << endl;
    return 0;
}
