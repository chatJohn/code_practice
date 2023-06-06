/*
* @Author: chatting
* @Date:   2023-06-06 16:07:03
* @Last Modified by:   10592
* @Last Modified time: 2023-06-06 16:25:40
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 300;
int f1[maxn];
int f2[maxn];
int main(){
	int n, k, s;
	cin >> n >> k >> s;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		if(a >= 175){
			f1[a]++;
		}
    if(b >= s){
			f2[a]++;
		}
	}

	int ans = 0;
	while(k--){
		for(int i = 175; i <= 290; i++){  
            if(f1[i] > 0){
                ans++;
                f1[i]--;    
                while(f1[i] > 0 and f2[i] > 0){
                    ans++;
                    f1[i]--;
                    f2[i]--;
                }
            }
        }
	}
	cout<<ans;
}

