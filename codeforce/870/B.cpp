/*
* @Author: 
* @Date:   2023-05-07 10:35:36
* @Last Modified by:   10592
* @Last Modified time: 2023-05-07 10:58:57
*/

#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	std::vector<int> v;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		v.push_back(a);
	}
	int g = 0;
	for(int i = 0; i < n; i++){
		g = __gcd(g, abs(v[i] - v[n-i-1]));
	}
	cout<<g<<"\n";

}

int main(){
	int t;
	cin >> t;
	while(t --){
		solve();
	}
	return 0;
}