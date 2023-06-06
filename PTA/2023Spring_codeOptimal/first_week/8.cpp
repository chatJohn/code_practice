/*
* @Author: chatting
* @Date:   2023-06-06 11:00:07
* @Last Modified by:   10592
* @Last Modified time: 2023-06-06 12:36:28
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, m, k;
	cin >> n >> m >> k;
	queue<int> q;
	for(int i = 0;i < n;i ++){
		int x;
		cin >> x;
		q.push(x);
	}

	stack<int> stk;//盒子
	while(1){
		std::vector<int> branch;
		int flag = 0;
		while(1){
			if(branch.size() == 0){
				if(stk.size() != 0){
					branch.push_back(stk.top());
					stk.pop();
				}
				else if(q.size() != 0){
					branch.push_back(q.front());
					q.pop();
				}else{
					break;
				}
			}else{
				if(stk.size() != 0 and stk.top() <= branch.back()){
					branch.push_back(stk.top());
					stk.pop();
				}else{
					while(!q.empty() and stk.size() <= m){
						auto t = q.front();
						if(branch.back() >= t){
							q.pop();
							branch.push_back(t);
							break;
						}else{
							if(stk.size() == m){
								flag = 1;
								break;
							}else{
								stk.push(t);
								q.pop();
							}
						}
					}
					if(q.empty() and (stk.empty()||stk.top() > branch.back()))	break;
				}
			}
			if(flag == 1 || branch.size() == k){
				break;
			}
		}
		for(int i = 0;i < branch.size(); i++){
			if(i != branch.size() -1){
				cout<<branch[i]<<" ";
			}else{
				cout<<branch[i]<<endl;
			}
		}
    if(stk.empty() && q.empty()){
      break;
    }
	}
}