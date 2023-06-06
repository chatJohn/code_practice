/*
* @Author: chatting
* @Date:   2023-06-06 14:44:59
* @Last Modified by:   10592
* @Last Modified time: 2023-06-06 16:28:27
*/
#include<bits/stdc++.h>
using namespace std;
#define inf 0x7fffffff
typedef long long ll;
const int maxn=1e3;
vector<int> male;
vector<int> female;
int n;
ll dis[maxn][maxn];
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
}
bool com(ll a,ll b){
    return a>b;
}
bool com1(pair<int,ll> a,pair<int,ll > b){
    if(a.second==b.second)  return a.first<b.first;
    return a.second<b.second;
}
int main() 
{
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)  dis[i][j]=0;
            else dis[i][j]=inf;
        }
    }
    for(int i=1;i<=n;i++){
        char c;
        int nums;
        cin>>c>>nums;
        if(c=='M'){
            male.push_back(i);
        }
        else if(c=='F'){
            female.push_back(i);
        }
        for(int j=0;j<nums;j++){
           int a;
            ll b;
            scanf("%d:%lld",&a,&b);
            dis[i][a]=b;
        }
    }
    floyd();
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<dis[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    //female
   vector<int> ve[maxn];
   for(int i=0;i<female.size();i++){
        for(int j=0;j<male.size();j++){
            ve[female[i]].push_back(dis[male[j]][female[i]]);
        }
   }
   for(int i=0;i<female.size();i++){
        sort(ve[female[i]].begin(),ve[female[i]].end(),com);
   }

//    for(int i=0;i<female.size();i++){
//         for(int j=0;j<ve[female[i]].size();j++){
//             cout<<female[i]<<": "<<ve[female[i]][j]<<" ";
//     }
//         cout<<endl;
//    }
   vector<pair<int,ll>> ans;
   for(int i=0;i<female.size();i++){
        ans.push_back({female[i],ve[female[i]][0]});
   }
//    for(int i=0;i<female.size();i++){
//         cout<<ans[i].first<<": "<<ans[i].second<<endl;
//    }
    sort(ans.begin(),ans.end(),com1);
//     cout<<"   ______"<<endl;
//    for(int i=0;i<female.size();i++){
//         cout<<ans[i].first<<": "<<ans[i].second<<endl;
//    }
//    cout<<"______"<<endl;
   for(int i=0;i<female.size();i++){
        if(ans[i].second==ans[0].second){
           if(i==0)  cout<<ans[i].first;
           else  cout<<" "<<ans[i].first;
        }
       else break;
   }
   cout<<endl;
   //male
   vector<int> ve1[maxn];
   memset(ve1,0,sizeof ve1);
   for(int i=0;i<male.size();i++){
        for(int j=0;j<female.size();j++){
            ve1[male[i]].push_back(dis[female[j]][male[i]]);
        }
   }
   for(int i=0;i<male.size();i++){
        sort(ve1[male[i]].begin(),ve1[male[i]].end(),com);
   }

//    for(int i=0;i<male.size();i++){
//         for(int j=0;j<ve1[male[i]].size();j++){
//             cout<<male[i]<<": "<<ve1[male[i]][j]<<" ";
//     }
//         cout<<endl;
//    }
   vector<pair<int,ll>> ans1;
   for(int i=0;i<male.size();i++){
        ans1.push_back({male[i],ve1[male[i]][0]});
   }
//    for(int i=0;i<male.size();i++){
//         cout<<ans1[i].first<<": "<<ans1[i].second<<endl;
//    }
    sort(ans1.begin(),ans1.end(),com1);
//     cout<<"   ______"<<endl;
//    for(int i=0;i<male.size();i++){
//         cout<<ans1[i].first<<": "<<ans1[i].second<<endl;
//    }
//    cout<<"______"<<endl;
   for(int i=0;i<male.size();i++){
        if(ans1[i].second==ans1[0].second){
            if(i==0)  cout<<ans1[0].first;
            else  cout<<" "<<ans1[i].first;
        }
       else break;
   }
    cout<<endl;
    system("PAUSE");
    return 0;
}