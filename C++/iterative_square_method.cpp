#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
#define MOD 1000000007

int modPow(ll a, ll n) {
  if (n == 0) return 1;
  if (n == 1) return a % MOD;
  if (n % 2 == 1) return (a * modPow(a, n - 1)) % MOD;
  ll t = modPow(a, n / 2);
  return (t * t) % MOD;
}

int main(){
    ll n, a, b;
    cin >> n >> a >> b;

    ll ans = modPow(2, n) - 1;
    ll tmp_a = 1, tmp_b = 1;

    for (int i = n; i > n - a; i--) {
        tmp_a *= i;
        tmp_a %= MOD;
    }
    for (int i = n; i > n - b; i--) {
        tmp_b *= i;
        tmp_b %= MOD;
    }

    ll div_a = 1, div_b = 1;
    for (int i = a; i > 0; i--) {
        div_a *= i;
        div_a %= MOD;
    }
    for (int i = b; i > 0; i--) {
        div_b *= i;
        div_b %= MOD;
    }

    tmp_a *= modPow(div_a, MOD - 2);
    tmp_b *= modPow(div_b, MOD - 2);

    ans = ((ans % MOD) - (tmp_a % MOD) - (tmp_b % MOD)) % MOD;
    if (ans < 0) ans += MOD;

    cout << ans << endl;
    return 0;
}
