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

L t[4*MaxN], mod[4*MaxN], a[MaxN], n, m ;

void update(int v, int tl, int tr, int l, int x)
{
    if(tl == tr && tl == l)
    {
        t[v] = x ;
        return ;
    }
    
    if(tr < l || l < tl)
        return ;

    int tm = (tl + tr) >> 1 ;
    update(v*2, tl, tm, l, x) ;
    update(v*2+1, tm+1, tr, l, x) ;
    t[v] = t[v*2] + t[v*2+1] ;
}

L get(int v, int tl, int tr, int l, int r)
{
    if(l <= tl && tr <= r)
        return t[v] ;

    if(l > tr || r < tl)
        return 0 ;

    int tm = (tl + tr) >> 1 ;
    return get(v*2, tl, tm, l, r) + get(v*2+1, tm+1, tr, l, r) ;
}

int32_t main(int argc, char *argv[])
{
    if(argc > 1)
        freopen(argv[1], "r", stdin) ;
    //freopen(".in" , "r" , stdin) ;
    //freopen(".out" , "w" , stdout) ;
    cin >> n ;
    for(int i = 0 ; i < n ; ++i)
    {
        cin >> a[i] ;
        cout << get(1, 1, n, a[i], n) << ' ' ;
        update(1, 1, n, a[i], 1) ;
    }
}