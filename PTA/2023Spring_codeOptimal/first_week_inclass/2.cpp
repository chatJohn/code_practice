/*
* @Author: chatting
* @Date:   2023-06-12 09:19:58
* @Last Modified by:   10592
* @Last Modified time: 2023-06-12 13:22:45
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n;
    cin >> n;
    std::vector<int> v;
    std::vector<int> vv;
    for(int i = 0;i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    int idx = 1;
    int mm = INT_MIN;
    int floors = 0;
    int pre = 0;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = pre; j < min(n - pre, (idx << i)) + pre && (idx << i) > 0 && pre < n; j++){
            sum += v[j];
            floors++;
        }
        pre += min(n - pre, (idx << i));
        mm = max(mm, sum);
        vv.push_back(sum);
        if(pre >= n)    break;
    }
    cout << mm <<endl;
    std::vector<int> ans;
    for(int i = 0; i < floors && i < vv.size(); i++){
        if(vv[i] == mm) ans.push_back(i+1);
    }
    for(int i = 0 ; i < ans.size(); i++){
        if(i != ans.size() - 1) cout << ans[i] << " ";
        else cout << ans[i];
    }
}