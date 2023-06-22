/*
* @Author: chatting
* @Date:   2023-06-20 18:28:28
* @Last Modified by:   10592
* @Last Modified time: 2023-06-20 20:09:24
*/
#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define inf 0x3f3f3f3f
typedef long long ll;



void solve(){
	int n;
	std::cin >> n;
	string s;
	std::cin >> s;
	string ans = "";
	for(int i = 0; i < n;  i++){
		int j = i + 1;
		while(j < n and s[i] != s[j])	j++;
		ans += s[i];
		i = j;
	}
	std::cout << ans << std::endl;
}
int main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t = 1;
	std::cin >> t;
	while(t--){
		solve();
	}
	return 0;
}