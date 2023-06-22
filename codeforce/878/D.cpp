/*
* @Author: chatting
* @Date:   2023-06-20 20:40:18
* @Last Modified by:   10592
* @Last Modified time: 2023-06-20 21:23:34
*/
#include<bits/stdc++.h>
using namespace std;
//#define int long long
typedef long long ll;

void solve(){
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for(int &x: a){
		std::cin >> x;
	}

	std::sort(a.begin(), a.end());

	function<bool(int)> check = [&](int mid)->bool{
		int p = 0;
		for(int i = 0; i < 3; i++){
			p = upper_bound(a.begin(), a.end(), a[p] + 2 * mid) - a.begin();
			if(p == n){
				return true;
			}
		}
		return false;
	};
	int left = -1;
	int right = 1000000010;
	while(left + 1 < right){
		int mid = (left + right) / 2;
		if(check(mid))	right = mid;
		else left = mid;
	}
	std::cout << right << std::endl;
}
int main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t = 1;
	std::cin >> t;
	while(t--){
		solve();
	}
}