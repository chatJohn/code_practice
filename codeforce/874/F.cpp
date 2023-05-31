/*
* @Author: chatting
* @Date:   2023-05-20 22:38:08
* @Last Modified by:   10592
* @Last Modified time: 2023-05-20 23:03:53
*/
#include<bits/stdc++.h>
using namespace std;
const int mode = 1e9 + 7;
typedef long long ll;
ll qpow(ll a, ll b){
	ll res = 1;
	a %= mode;
	while(b){
		if(b & 1)	res = (res * a) %mode;
		a = (a * a) % mode;
		b >>= 1;
	}
	return res % mode;
}
void solve(){
	int n, m;
	cin >> n >> m;
	std::vector<int> a(n);
	for(int &i: a){
		cin >> i;
	}
	map<ll, ll> mp;
	sort(a.begin(), a.end());
	for(int i = 0;i < n; i++){
		mp[a[i]]++;
	}
	a.resize(n = unique(a.begin(), a.end()) - a.begin());
	ll c = 1;
	ll ans = 0;
	for(int i =0, j = 0; i < n;){
		while(j < n and a[j] < a[i] + m){
			c = c * (mp[a[j++]]) % mode;
		}
		if(j - i == m){
			ans += c;
		}
		c = c * qpow(mp[a[i++]], mode - 2) % mode;
	}
	cout<<ans%mode<<endl;
}
int main(){

	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
}