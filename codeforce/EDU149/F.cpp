/*
* @Author: chatting
* @Date:   2023-06-01 19:59:22
* @Last Modified by:   10592
* @Last Modified time: 2023-06-01 20:17:17
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 3 << 17;
int n, k;
int a[maxn];


typedef long long ll;
void solve(){
	cin >> n >> k;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	function<vector<int>(ll)> get = [&](ll mid)->std::vector<int> {
		std::vector<int> res(n+1);
		priority_queue<int> q;
		for(int i = 0; i < n; i++){
			//前缀选
			q.push(a[i]);
			mid -= a[i];
			while(mid < 0){
				assert(!q.empty());
				mid += q.top();
				q.pop();
			}
			res[i+1] = q.size();
		}
		return res;
	};
	function<bool(ll)> check = [&](ll mid)->bool{
		vector<int> before = get(mid);
		reverse(a, a + n);
		vector<int> after = get(mid);
		reverse(a, a + n);
		reverse(after.begin(), after.end());
		for(int i = 0; i < n; i++){
			if(before[i] + after[i] >= k)	return true;
		}
		return false;
	};
	ll left = 0;
	ll right = (ll) 1e15;
	while(left + 1 < right){
		ll mid = (left + right) / 2;
		if(check(mid))	right = mid;
		else left = mid;
	}
	cout<<right<<"\n";
}

int main(){
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
}