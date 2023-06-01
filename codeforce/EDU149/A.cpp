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
		int n, k;
		cin >> n >> k;
		if(n < k){
			cout<<"1\n"<<n<<endl;
		}
		else if(n % k){
			cout<<"1\n" <<n<<endl; 
		}else{
			cout<<"2\n"<<1<<" "<< n - 1<<endl;
		}
	}
}