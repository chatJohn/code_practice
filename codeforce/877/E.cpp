#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mode = 1e9 + 7;
ll qpow(ll a, ll b){
	ll res = 1;
	a %= mode;
	while(b){
		if(b & 1)	res = (res * a) % mode;
		a = (a * a) % mode;
		b >>= 1;
	}
	return res % mode;
}
int main(){
	int t = 1;
	cin >> t;
	while(t--){
		__int64 n, m, k;
		cin >> n >> m >> k;
		std::vector<__int64> a(n);
		for(__int64 &x: a){
			cin >> x;
		}
		ll ans = qpow(k, m);
        ll mult = 1;
        for(int i=0; i<n; i++){
            if(i) {
                mult = (m+1-i) * mult % mode;
                mult = mult * qpow(i, mode-2) % mode;
            }
            ll sub = mult * qpow(k-1, m-i) % mode;
            ans = (ans - sub + mode )% mode;
        }
        cout << ans << '\n';
	}

}
