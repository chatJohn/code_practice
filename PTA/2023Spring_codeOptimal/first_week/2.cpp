/*
* @Author: chatting
* @Date:   2023-06-05 22:14:26
* @Last Modified by:   10592
* @Last Modified time: 2023-06-05 22:27:00
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	function<long long(long long)>	get = [&](long long num)->long long{
		long long sum = 0;
		while(num){
			sum += num % 10;
			num /= 10;
		}
		return sum;
	};
	for(int i = 0; i < n; i++){
		long long a, b;
		cin >> a >> b;
		if(a % get(b) == 0 and b % get(a) != 0){
			cout<<"A\n";
		}else if(b % get(a) == 0 and a % get(b) != 0){
			cout<<"B\n";
		}else{ 
			cout<<((a > b)? "A\n" : "B\n");
		}
	}
}