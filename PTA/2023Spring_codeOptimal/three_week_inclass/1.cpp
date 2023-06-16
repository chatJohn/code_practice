#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int vis[maxn];

int main(){
    int n, m, s;
    std::cin >> n >> m >> s;
    vector<vector<int>> g(n + 1);
    for(int i = 0; i < m ;i ++){
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1 ; i <= n; i++){
        sort(g[i].begin(), g[i].end());
    }
    function<void(int, int)> dfs = [&](int u, int fa)->void{
      vis[u] = 1;
      cout << u <<" ";
      for(int v: g[u]){
          if(v == fa) continue;
          if(vis[v]) continue;
          dfs(v, u);
      }
    };
    dfs(s, -1);
    int ans = 0;
    for(int i = 1; i<= n; i++){
        if(vis[i]) ans++;
    }
    cout << endl;
    if(ans != n) cout << "Non-connected\n";
    return 0;
}