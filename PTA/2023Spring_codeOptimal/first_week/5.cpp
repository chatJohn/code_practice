/*
* @Author: chatting
* @Date:   2023-06-05 23:07:03
* @Last Modified by:   10592
* @Last Modified time: 2023-06-06 00:24:51
*/
#include<bits/stdc++.h>
using namespace std;
//完全二叉树
const int maxn = 19;
int tree[1 << maxn];
int a[1 << maxn];
int k;
int tt;
void init(){
	cin >> k;
	int tot = pow(2, k);
	tt = tot;
	for(int i =0 ; i  < tot; i++){
		tree[i] = i + 1;
	}
}
int pan = 1;
void recursion(int tot, int cnt){
	for(int i =0 ; i < tot; i += 2){
		int e;
		cin >> e;
		int p = 0;
		for(int j = 0; j < 2; j++){
			if(a[tree[i+j]] <= e){
				p = 1;
				a[tree[i +j]] = e;
			}
		}
		if(a[tree[i]] > a[tree[i+1]])	tree[cnt++] = tree[i];
		else tree[cnt++] = tree[i+1];
		pan &= p;
	}
	if(cnt == 1){
		int e;
		cin >>e;
		if(e < a[tree[0]])	pan = 0;
		a[tree[0]] = e;
		return;
	}
	recursion(cnt, 0);
}
int main(){
	init();
	recursion(tt, 0);
	if(pan){
		for(int i = 1; i <= tt ; i++){
			printf("%lld%s",a[i],i!=tt?" ":"\n");
		}
	}
	else{
			printf("No Solution\n");
		}
}