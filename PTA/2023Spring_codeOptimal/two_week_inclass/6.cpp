/*
* @Author: chatting
* @Date:   2023-06-13 09:15:49
* @Last Modified by:   10592
* @Last Modified time: 2023-06-13 20:52:57
*/

#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int table_size = 1e5+1;
vector<int> ha[table_size];

int hash_func(int key) {
    const int P = 131;
    const int Q = 233;
    size_t h = 0;
    for (int i = 0; i < sizeof(key); i++) {
        h = h * P + ((char*)(&key))[i];
    }
    return (h ^ Q) % table_size;
}

void solve(){
    int n, target ; cin >> n >> target ;
    vector<int> nums(n) ;
    for(int i =  0 ; i < n ; ++ i) {
        cin >> nums[i] ;
    }
    int ret = 0 ; //unordered_map<int, int, MyHashFunc> mp(table_size) ;
    for(int i = 0 ; i < n ; ++ i) {
        for(int j = i ; j < n ; ++ j) {
            int sum = nums[i] + nums[j] ;
            //mp[sum] ++ ;
            ha[hash_func(sum)].push_back(sum);
        }
        for(int j = i ; j < n ; ++ j) {
            int sum = nums[i] + nums[j] ;
            //ret += mp[target - sum] ;
            if(target < sum) continue ;
            int idx = hash_func(target - sum) ;
            for(int k = 0 ; k < ha[idx].size() ; ++ k) {
                if(ha[idx][k] == target - sum) {
                    ret ++ ;
                }
            }
        }
    }
    cout << ret << '\n' ;
}

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);
    int t = 1 ; // cin >> t ;
    while(t --) solve();
    return 0;
}
