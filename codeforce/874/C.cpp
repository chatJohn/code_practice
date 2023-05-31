/*
* @Author: chatting
* @Date:   2023-05-20 19:07:45
* @Last Modified by:   10592
* @Last Modified time: 2023-05-20 20:03:31
*/
#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	std::vector<int> a;
	for(int i = 0;i < n; i++){
		int x;
		cin >>x;
		a.push_back(x);
	}
	int odd = 0;
	int  even = 0;
	int mo = INT_MAX;
	int me = INT_MAX;
	for(int i: a){
		if(i & 1){
			odd++;
			mo = min(mo, i);
		}else{
			even++;
			me = min(me, i);
		}
	}
	if(!odd || !even || me - mo >= 0){
		cout<<"yes\n";
	}else{
		cout<<"no\n";
	}
}
int main(){
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}