/*
* @Author: chatting
* @Date:   2023-06-06 12:54:18
* @Last Modified by:   10592
* @Last Modified time: 2023-06-06 13:48:21
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
unordered_map<int, int> d2u;
unordered_map<int, int>	p2n;
unordered_map<string, int>	n2idx;
int num[maxn];
void p(int c){
	if(c == 0)	return;
	num[c]++;
	p(d2u[c]);
}
void pu(int a, int b){
	if(a == 0)	return;
	num[a] += b;
	pu(d2u[a], b);
}
int main(){
	int n, m;
	cin >> n >> m;
	
	int idx = 0;//中心编号
	for(int i = 0; i < m; i++){
		string a, b;
		cin >> a >> b;
		if(!n2idx[b])	n2idx[b] = ++idx;
		if(a[0] >= '0' and a[0] <= '9'){
			p2n[stoi(a)] = n2idx[b];
			//增加人数
			p(n2idx[b]);
		}else{
			if(!n2idx[a])	n2idx[a] = ++idx;
			d2u[n2idx[a]] = n2idx[b];
			//增加人数
			pu(n2idx[b], num[n2idx[a]]);
		}
	}
	function<void(int)> del = [&](int a){
		if(a == 0)	return;
		num[a]--;
		del(d2u[a]);
	};
	char c;
	while(1){
	    cin >> c;
	    if(c == 'E')  break;
		if(c == 'Q'){
			string a;
			cin >> a;
			cout << num[n2idx[a]]<<endl;
		}else if(c == 'T'){
			int a;
			string b;
			cin >> a >> b;
			if(p2n[a]) del(p2n[a]);
			p2n[a] = n2idx[b];
			p(n2idx[b]);
		}
	}
}