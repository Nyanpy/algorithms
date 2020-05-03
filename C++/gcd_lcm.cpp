#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

ll gcd (ll a, ll b) {
    if (b > a) {
        ll tmp = b;
        b = a;
        a = tmp;
    }
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm (ll a, ll b) {
    return a * b / gcd (a, b);
}

int main(){
  ll a, b;
  cin >> a >> b;
  // 最大公約数を求める
  ll gcd = gcd(a, b);
  // 最小公倍数を求める
  ll lcm = lcm(a, b);
  
  cout << gcd << endl;
  cout << lcm << endl;
  
  return 0;
}
