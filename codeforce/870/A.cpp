/*
* @Author: 
* @Date:   2023-05-07 10:06:29
* @Last Modified by:   10592
* @Last Modified time: 2023-05-07 10:26:56
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
	sort(v.begin(), v.end());
	int flag = 0;
	for(int i = 0; i < n; i++){
		int c = v.end() - upper_bound(v.begin(), v.end(), i);
		if(i == c){
			cout<<i<<endl;
			flag = 1;
			break;
		}
	}
	if(!flag){
		puts("-1");
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}

	return 0;
}