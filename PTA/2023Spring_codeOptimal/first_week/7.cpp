/*
* @Author: chatting
* @Date:   2023-06-06 10:44:47
* @Last Modified by:   10592
* @Last Modified time: 2023-06-06 11:00:02
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	std::vector<int> a;
	for(int i = 0; i < n; i++){
		int x;	cin >> x;
		a.push_back(x);
	}
	int cnt = 0;
	int idx = 0;
	string s;
	cin >> s;
	while(s != "End"){
		if(cnt / a[idx] == 0){
			if(s == "ChuiZi")	cout<<"Bu\n";
			else if(s == "Bu")	cout<<"JianDao\n";
			else if(s == "JianDao")	cout<<"ChuiZi\n";
			cnt++;	
		}
		else{
			if(s == "ChuiZi")	cout<<"JianDao\n";
			else if(s == "Bu")	cout<<"ChuiZi\n";
			else if(s == "JianDao")	cout<<"Bu\n";
			cnt = 0;
			idx++;
			idx %= n;
		}
		cin >> s;
	}
}