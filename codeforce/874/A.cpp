/*
* @Author: chatting
* @Date:   2023-05-20 17:02:53
* @Last Modified by:   10592
* @Last Modified time: 2023-05-20 20:45:56
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t = 1;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		map<string, int> mp;
		int left = 0;
		int len = s.length();
		while(left < len){
			string new_s = s.substr(left, 2);
			if(new_s.length() == 1) break;
			mp[new_s]++;
			left++;
		}
		cout<< mp.size()<<"\n";
	}
	return 0;
}