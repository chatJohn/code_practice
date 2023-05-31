/*
* @Author: chatting
* @Date:   2023-05-13 19:26:23
* @Last Modified by:   10592
* @Last Modified time: 2023-05-13 19:50:32
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t = 1;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int len = s.length();
		if(len % 2 == 1){
			s.erase(s.begin()+len/2);
		}
		cout<< ((s == string(s.size(), s[0])) ? "NO\n" : "YES\n");
	}
	return 0;
}