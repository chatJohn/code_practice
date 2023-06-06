/*
* @Author: chatting
* @Date:   2023-06-05 22:44:19
* @Last Modified by:   10592
* @Last Modified time: 2023-06-06 00:24:26
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<string,int> PII;
vector <int> v;
unordered_map <string,int> m;
vector <PII> s;
string name[5010];
bool cmp(const  PII & a,const  PII &  b){
    return a.second<b.second;
}
int main(){
    int n,c;
    cin>>n>>c;
    int sum=0;//记录单开的考场
    for(int i=0;i<n;i++){
        string str;
        int x;
        cin>>str;
        scanf("%d",&x);
        if(x%c)	s.push_back(make_pair(str,x%c));
        m[str]+=x/c;
        name[i]=str;
        sum+=x/c;
    }
    
    sort(s.begin(),s.end(),cmp);
    
    int ma;
    while(s.size()){
            if(s.back().second>ma||s.size()==0){//坐不下
                int res=c-s.back().second;
                ma=max(ma,res);
				m[s.back().first]++;
                s.pop_back();
                v.push_back(res);
                
            }else {//放的下
                for(int i=0;i<v.size();i++){
                	int it = v[i];
                    if(it>=s.back().second) {
                        v[i]-=s.back().second;
						 m[s.back().first]++;
                        s.pop_back();
                    }
                }
               
                for(auto it: v) ma=max(ma,it);
            }
    
    }

	for(int i=0;i<n;i++){
		cout<<name[i]<<" "<<m[name[i]]<<endl;
		
	}
    cout<<sum+v.size();
 
}
