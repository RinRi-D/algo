/*
#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
*/
#include "bits/stdc++.h"
 
#define iosb ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define BIT(x) __builtin_popcount(x)
#define all(x) x.begin() , x.end()
#define F first
#define S second
#define pb push_back
 
using namespace std ;
 
typedef unsigned long long UL ;
typedef long long L ;
typedef string T ;
typedef int I ;
 
const I MaxN =      1e5+1 ;
const I MOD =       1e9+7 ;
const I inf =       2e9+7 ;
const L INF = 2e18+7 ;

L a[MaxN], n, m ;

struct{
    L pref = -INF, suff = -INF, sum = -INF, ans = -INF ;
} t[MaxN*4] ;

void build(int v, int tl, int tr)
{
    if(tl == tr)
    {
        t[v].sum = a[tl] ;
        t[v].ans = a[tl] ;
        t[v].pref = a[tl] ;
        t[v].suff = a[tl] ;
        return ;
    }

    int tm = (tl + tr) >> 1 ;
    build(v*2, tl, tm) ;
    build(v*2+1, tm+1, tr) ;
    t[v].ans = max(max(t[v*2].ans, t[v*2+1].ans), t[v*2].suff + t[v*2+1].pref) ;
    t[v].sum = t[v*2].sum + t[v*2+1].sum ;
    t[v].pref = max(t[v*2].pref, t[v*2].sum + t[v*2+1].pref) ;
    t[v].suff = max(t[v*2+1].suff, t[v*2].suff + t[v*2+1].sum) ;
}

void update(int v, int tl, int tr, int l, int x)
{
    if(tl == tr && tl == l)
    {
        t[v].sum = x ;
        t[v].ans = x ;
        t[v].pref = x ;
        t[v].suff = x ;
        return ;
    }
    
    if(tr < l || l < tl)
        return ;

    int tm = (tl + tr) >> 1 ;
    update(v*2, tl, tm, l, x) ;
    update(v*2+1, tm+1, tr, l, x) ;
    t[v].ans = max(max(t[v*2].ans, t[v*2+1].ans), t[v*2].suff + t[v*2+1].pref) ;
    t[v].sum = t[v*2].sum + t[v*2+1].sum ;
    t[v].pref = max(t[v*2].pref, t[v*2].sum + t[v*2+1].pref) ;
    t[v].suff = max(t[v*2+1].suff, t[v*2].suff + t[v*2+1].sum) ;
}

int32_t main(int argc, char *argv[])
{
    if(argc > 1)
        freopen(argv[1], "r", stdin) ;
    //freopen(".in" , "r" , stdin) ;
    //freopen(".out" , "w" , stdout) ;
    cin >> n >> m ;
    for(int i = 0 ; i < n ; ++i)
        cin >> a[i] ;

    build(1, 0, n-1) ;
    
    cout << max(0ll, t[1].ans) << '\n' ;
    while(m--)
    {
        int l, x ;
        cin >> l >> x ;
        update(1, 0, n-1, l, x) ;
        cout << max(0ll, t[1].ans) << '\n' ;
    }
}