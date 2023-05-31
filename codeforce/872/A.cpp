/*
* @Author: chatting
* @Date:   2023-05-10 19:19:34
* @Last Modified by:   10592
* @Last Modified time: 2023-05-10 19:38:35
*/
#include<bits/stdc++.h>
using namespace std;
void solve(){
	string s;
	cin >> s;
	int n = s.length();
	std::map<int, int> mp;
	for(int i = 0; i < n; i++){
		mp[s[i] - 'a']++;
	}
	if(mp.size() == 1){
		cout<<-1<<"\n";
	}
	else{
		cout<<n-1<<"\n";
	}
}
int main(){
	int t;
	cin >> t;
	while(t --){
		solve();
	}
}