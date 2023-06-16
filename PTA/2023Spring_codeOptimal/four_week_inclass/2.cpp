/*
* @Author: chatting
* @Date:   2023-06-15 08:37:27
* @Last Modified by:   10592
* @Last Modified time: 2023-06-15 08:47:22
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
// char a[maxn],b[maxn],mp[maxn];
string a, b;
int dp[maxn][maxn];
void LCS_common(int n,int m) {  //n为数组a长度，m为数组b长度
	memset(dp, 0, sizeof dp);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) {
            if(a[i-1]==b[j-1]) {
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    // stack<char>q;
    // int ii=n-1,jj=m-1;
    // while(ii>=0&&jj>=0) {   //打印出来LCS
    //     if(a[ii]==b[jj]) {
    //         q.push(a[ii]);
    //         ii--;jj--;
    //     }else if(dp[ii][jj+1]>dp[ii+1][jj]) {
    //         ii--;//说明dp[i][j]是由dp[i-1][j]得来的
    //     }else {
    //         jj--;//说明dp[i][j]是由dp[i][j-1]得来的
    //     }
    // }
    // while(!q.empty()) {
    //     cout<<q.top();q.pop();
    // }
    // cout<<endl;
}
void solve(){
	while(cin >> a >> b){
		
		int al = a.length();
		int bl = b.length();
		LCS_common(al, bl);
		cout << dp[al][bl] << endl;
	}
}
int main()
{
 	solve();   
}