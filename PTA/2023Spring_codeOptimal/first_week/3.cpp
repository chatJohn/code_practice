/*
* @Author: chatting
* @Date:   2023-06-05 22:27:05
* @Last Modified by:   10592
* @Last Modified time: 2023-06-05 22:44:15
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	std::vector<int> a;
	for(int i = 0; i < n; i++){
		int x; 
		cin >>x;
		a.push_back(x);
	}
	stack<int> sa;
	stack<int> sb;
	sa.push(a[0]);
	int i = 1;
	int ans = 0;
	int sz = 0;
	while(i < n){
		int num = a[i];
		if(num < sa.top()){
			sa.push(num);
			i++;
		}
		else{
			if(sb.size() == 0 or num > sb.top()){
				sb.push(num);
				i++;
			}else{
				ans++;
				sz = max(sz, int(sa.size()));
				while(sa.size() != 0){
					sa.pop();
				}
				while(sb.size() != 0 and sb.top() > num){
					sa.push(sb.top());
					sb.pop();
				}
				sa.push(num);
				i++;
			}
		}
	}
	sz = max(sz, max(int(sa.size()), int(sb.size())));
	int re = 0;
	if(sa.size() != 0)re++;
	if(sb.size() != 0)re++;
	cout<<ans + re<<" "<<sz <<endl;
}