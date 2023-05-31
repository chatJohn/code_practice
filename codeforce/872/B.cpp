/*
* @Author: chatting
* @Date:   2023-05-10 19:39:12
* @Last Modified by:   10592
* @Last Modified time: 2023-05-10 21:37:03
*/
#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n, m;
	cin >> n >> m;
	std::vector<int> v;
	for(int i = 0; i < n * m; i++){
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	int ans = 0;
	int mm  = v.back();
	int mn = v[0];
	int smm = v[v.size()-2];
	int smn = v[1];
	ans = (mm - mn) * (m * n - min(n, m)) + max(smm - mn, mm - smn) * (min(n, m) - 1);
	cout<<ans<<endl;
}
int main(){
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
}
