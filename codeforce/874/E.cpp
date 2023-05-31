/*
* @Author: chatting
* @Date:   2023-05-20 20:56:42
* @Last Modified by:   10592
* @Last Modified time: 2023-05-20 22:38:02
*/
#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	std::vector<int> a(n);
	for(int i = 0;i < n; i++){
		cin >> a[i];
		a[i] -= 1;
	}
	int more = 0;
	int two = 0;
	int time[n];
	memset(time, 0, sizeof time);
	for(int i = 0, clock = 1; i < n ; i ++){
		if(time[i]) continue;
		for(int x = i, start_time = clock; x >= 0; x = a[x]){
			if(time[x]){
				if(time[x] >= start_time){
					if(clock - time[x] == 2)	two++;
					else if(clock - time[x] > 2)	more++;
				}
				break;
			}
			time[x] = clock++;
		}
	}
	cout<<(more + (two > 0? 1 : 0))<<" "<<(two + more)<<endl;
}
int main(){
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;

}