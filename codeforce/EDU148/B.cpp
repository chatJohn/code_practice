/*
* @Author: chatting
* @Date:   2023-05-13 19:50:37
* @Last Modified by:   10592
* @Last Modified time: 2023-05-13 20:37:32
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	int n, k;
	cin >> n >> k;
	std::vector<int> v;
	for(int i = 0;i < n; i++){
		int a;
		cin >>a;
		v.emplace_back(a);
	}
	sort(v.begin(), v.end());
	std::vector<int> pre(n+1);
	for(int i =0 ;i < n;i++){
		pre[i+1] = pre[i ]  + v[i];
	}
	int ans = 0;
	for(int i = 0 ;i  <= k; i++){
		int y = k - i;
		ans = max(ans, pre[n - y] - pre[2 * i]);
	}
	cout<<ans<<endl;

}
signed main(){
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}