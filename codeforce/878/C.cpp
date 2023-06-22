/*
* @Author: chatting
* @Date:   2023-06-20 20:28:01
* @Last Modified by:   10592
* @Last Modified time: 2023-06-22 20:14:38
*/
#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define pb(x) push_back(x)
typedef long long ll;
void solve(){
	int n, k, q;
	std::cin >> n >> k >> q;
	std::vector<int> a(n);
	vector<int> p;
	p.pb(-1);
	for(int &x: a){
		std::cin >> x;
	}
	for(int i = 0;i < n; i++){
		if(a[i] > q){
			p.pb(i);
		}		
	}
	p.pb(n);
	ll ans = 0;
	for(int i = 0; i < p.size() - 1; i ++){
		int d = p[i + 1] - p[i];
		if(d >= k){
			ans += (ll)(d - k + 1)*(d - k) / 2;
		}
	}
	std::cout << ans << "\n";	
}
int main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t = 1;
	std::cin >> t;
	while(t--){
		solve();
	}
}