/*
* @Author: chatting
* @Date:   2023-06-12 09:54:58
* @Last Modified by:   10592
* @Last Modified time: 2023-06-12 15:10:07
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 10;
const int l = 2e5 + 10;

int n, m, la, mi, b, ans, lm;
int a[maxn], tree[maxn << 2], tag[maxn << 2];
char s[10];

void pushup(int rt)
{
    tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
}

void insert(int rt, int l, int r, int x, int y)//单点修改
{
    if(l == r)
    {
        tree[rt] += y;
        return;
    }
    int mid = (l + r) >> 1;
    if(x <= mid) insert(rt << 1, l, mid, x, y);
    else insert(rt << 1 | 1, mid + 1, r, x, y);
    pushup(rt);
}

int query(int rt, int l, int r, int x, int y)//求值域内的数量
{
    if(x <= l && r <= y) return tree[rt];
    int mid = (l + r) >> 1, res = 0;
    if(x <= mid) res += query(rt << 1, l, mid, x, y);
    if(y > mid) res += query(rt << 1 | 1, mid + 1, r, x, y);
    return res;
}


void solve(){
	function<void(int, int, int, int, int)> reMove = [&](int rt, int left, int right, int x, int y){
		if(left == right){
	        tree[rt] = 0;
	        return;
	    }
	    int mid = (left + right) >> 1;
	    if(x <= mid && tree[rt << 1]) reMove(rt << 1, left, mid, x, y);
	    if(y > mid && tree[rt << 1 | 1]) reMove(rt << 1 | 1, mid + 1, right, x, y);
	    pushup(rt);
	};
	function<int(int, int, int, int)> query_k = [&](int rt, int l, int r, int x){
		if(l == r) return l;
	    int mid = (l + r) >> 1, l1 = -1, r1 = -1;
	    if(mi < l) l1 = tree[rt << 1];
	    else if(l <= mi && mi <= mid) l1 = query(rt << 1, l, mid, mi, mid);
	    else if(mid < mi && mi <= r) r1 = query(rt << 1 | 1, mid + 1, r, mi, r);
	    else r1 = tree[rt << 1 | 1];
	    //左边数量与右边数量
	    if(r1 == -1) r1 = tree[rt] - l1;
	    l1 = tree[rt] - r1;
	    if(r1 >= x) return query_k(rt << 1 | 1, mid + 1, r, x);
	    else return query_k(rt << 1, l, mid, x - r1);
	};
	scanf("%d%d", &n, &m), lm = m, m += l;
    for(int i = 1; i <= n; i++)
    {
        int x;
        scanf("%s%d", s, &x);
        if(s[0] == 'I')
        {
            if(x < lm) continue;
            insert(1, 0, maxn - 1, x - b + l, 1);//加入员工
        }
        else if(s[0] == 'A') m -= x, b += x;//增加工资
        else if(s[0] == 'S')
        {
            m += x, b -= x;
            if(m >= 1 && query(1, 0, maxn - 1, 0, m - 1) > 0){
            	ans += query(1, 0, maxn - 1, 0, m - 1);
        	    reMove(1, 0, maxn - 1, 0, m - 1);//踢出员工
            }
        }
        else
        {
            if(x > query(1, 1, maxn - 1, m, maxn - 1)) puts("-1");//工资大于k的数量
            else printf("%d\n", query_k(1, 0, maxn - 1, x) + b - l);
        }
    }
    printf("%d\n", ans);
}
int main()
{
    solve();
    return 0;
}