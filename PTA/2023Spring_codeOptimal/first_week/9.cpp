/*
* @Author: chatting
* @Date:   2023-06-06 12:36:41
* @Last Modified by:   10592
* @Last Modified time: 2023-06-06 12:54:14
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	set<pair<string, string>> s;
	string a, b;
	string start = "00:00:00";
	for(int i = 0; i < n; i ++){
    string t;
    cin >> a >> t >> b;
    s.insert({a, b});
	}
	s.insert({"23:59:59", ""});
	for(auto [f, se]: s){
		if(f > start){
			cout<<start<<" - "<<f<<endl;
		}
    start = se;
	}	
}