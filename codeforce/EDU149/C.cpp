/*
* @Author: chatting
* @Date:   2023-06-01 16:15:13
* @Last Modified by:   10592
* @Last Modified time: 2023-06-01 16:53:19
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t = 1;
	cin >> t;
	while(t --){
		string s;
		cin >> s;
		char last = '0';
		for(auto &c: s){
			if(c == '?'){
				c = last;
			}
			last = c;
		}
		cout<< s<<endl;
	}
}