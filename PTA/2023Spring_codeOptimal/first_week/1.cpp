/*
* @Author: chatting
* @Date:   2023-06-05 21:58:48
* @Last Modified by:   10592
* @Last Modified time: 2023-06-05 22:14:22
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n0, n1, n;
	cin >> n0 >> n1 >> n;
	if(n0 == 0){	cout<<"0 "<< n1 / n;
		return 0;
	}else if(n1 == 0){
		cout<<n0 / n<<" 0";
		return 0;
	}
	int ans = 0x3f3f3f3f;
	int w = -1;
	int m = -1;
	for(int i = 1; i < n ; i++){
		if(n0 % i || n1 % (n - i))	continue;
		else if(n0 / i == 1 || n1 / (n - i) == 1)continue;
		if(ans > abs(n0 / i - n1 / (n - i))){
			w = i;
			m = n - i;
			ans = abs(n0 / i - n1 / (n - i));
		}
	}
	if(ans == 0x3f3f3f3f)	cout<<"No Solution";
	else{
		cout<<w<<" "<<m;
	}
}