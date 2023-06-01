/*
* @Author: chatting
* @Date:   2023-06-01 16:02:17
* @Last Modified by:   10592
* @Last Modified time: 2023-06-01 16:15:04
*/
/*
* @Author: chatting
* @Date:   2023-06-01 15:44:18
* @Last Modified by:   10592
* @Last Modified time: 2023-06-01 16:02:13
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t = 1;
	cin >> t;
	while(t --){
		int n;
		string s;
		cin >> n >> s;
		int ans = 0;
		//寻找最长的连续子串
		for(int i = 0, j = 0; i < n; i = j){
			while(j < n and s[i] == s[j])	j++;
			ans = max(ans, j - i);
		}
		cout << ans + 1 << endl;
	}
}