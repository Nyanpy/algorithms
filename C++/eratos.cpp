#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
#define MAX 1000000

ll N;
vector<bool> IsPrime;

void eratos() {
    if (MAX + 1 > IsPrime.size()) IsPrime.resize(MAX + 1, true);
    IsPrime[0] = false;
    IsPrime[1] = false;

    for (size_t i = 2; i * i < MAX; i++) {
        if (IsPrime[i]) {
            for (size_t j = 2; i * j < MAX; j++) IsPrime[i * j] = false;
        }
    }
}

int main(){
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);
    
    eratos();
    for (int i = 0; i < N; i++) {
        if (IsPrime.at(A.at(i)) {
            cout << "Yes" <<endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
