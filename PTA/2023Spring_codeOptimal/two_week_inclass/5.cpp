/*
* @Author: chatting
* @Date:   2023-06-13 09:15:49
* @Last Modified by:   10592
* @Last Modified time: 2023-06-13 20:52:55
*/
#include<bits/stdc++.h>
using namespace std;

int fourSum(vector<int>& nums, int target) {
        int res = 0;
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0; i < nums.size(); i++){
            if(nums[i] > target){
                break;
            }
            for(int j = 0; j <= i; j++){
                mp[nums[i] + nums[j]] ++;
            }
            for(int j = i; j < n; j++){
                int sum = nums[i] + nums[j];
                res += mp[target - sum];
            }
        }
        return res;
    }
int main(){
	int n, t;
	std::cin >> n >> t;
	std::vector<int> a(n);
	for(int &x: a){
		std::cin >> x;
	}
	sort(a.begin(), a.end());
	int ans = fourSum(a, t);
	// set<vector<int>> s;
	// for(int i = 0; i < ans.size(); i++){
	// 	s.insert(ans[i]);
	// }
	// for(auto it = s.begin(); it != s.end(); it++){
	// 	vector<int> temp = *it;
	// 	for(int j = 0; j < 4; j++){
	// 		cout << temp[j] <<" ";
	// 	}
	// 	cout << endl;
	// }
	cout << ans << "\n";
}