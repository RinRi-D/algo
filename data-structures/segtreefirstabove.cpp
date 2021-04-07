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

void build(int v, int tl, int tr)
{
    if(tl == tr)
    {
        t[v] = a[tl] ;
        return ;
    }

    int tm = (tl + tr) >> 1 ;
    build(v*2, tl, tm) ;
    build(v*2+1, tm+1, tr) ;
    t[v] = max(t[v*2], t[v*2+1]) ;
}

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
    t[v] = max(t[v*2], t[v*2+1]) ;
}

int above(int v, int tl, int tr, int l, int x)
{
    if(l > tr)
        return -1 ;

    if(tl == tr)
    {
        if(x > t[v])
            return -1 ;
        return tl ;
    }

    int tm = (tl + tr) >> 1 ;
    if(t[v*2] >= x)
    {
        int ab = above(v*2, tl, tm, l, x) ;
        if(ab == -1)
            return above(v*2+1, tm+1, tr, l, x) ;
    }
    else
        return above(v*2+1, tm+1, tr, l, x) ;
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

    while(m--)
    {
        int type, l, x ;
        cin >> type ;
        if(type == 1)
        {
            cin >> l >> x ;
            update(1, 0, n-1, l, x) ;
        }
        else
        {
            cin >> x >> l ;
            cout << above(1, 0, n-1, l, x) << '\n' ;
        }
    }
}