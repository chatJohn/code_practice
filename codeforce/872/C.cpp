/*
* @Author: chatting
* @Date:   2023-05-10 20:09:11
* @Last Modified by:   10592
* @Last Modified time: 2023-05-13 19:25:47
*/
#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n, m;
	cin >> n >> m;
	std::vector<int> v;
	int cnt1 = 0;
	int cnt2 = 0;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		if(a == -1){
			cnt1++;
		}else if(a == -2){
			cnt2++;
		}else{
			v.push_back(a);
		}
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	int ans = 0;
	ans = max(ans, (int)v.size() + cnt1);
	ans = max(ans, (int)v.size() + cnt2);
	ans = min(ans, m);
	for(int i  = 0; i < v.size();i++){
		int left = min(v[i] - 1, i + cnt1);
		int right = min(m - v[i], (int)v.size() - 1 - i + cnt2);
		ans = max(ans, left + 1 + right);
	}
	cout << ans<<"\n";
}
int main(){
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
}