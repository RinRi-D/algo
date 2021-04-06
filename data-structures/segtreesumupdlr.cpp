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

int t[4*MaxN], mod[4*MaxN], a[MaxN], n ;

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
    t[v] = t[v*2] + t[v*2+1] ;
}

void push(int v, int tl, int tr)
{
    if(mod[v] != 0 && v*2+1 < 4*MaxN)
    {
        mod[v*2] = mod[v*2+1] = mod[v] ;
        mod[v] = 0 ;

        int tm = (tl + tr) >> 1 ;
        t[v*2] = (tm-tl+1) * mod[v*2] ;
        t[v*2+1] = (tr-tm) * mod[v*2+1] ;
    }
}

void update(int v, int tl, int tr, int l, int r, int x)
{
    if(l <= tl && tr <= r)
    {
        t[v] = x * (tr-tl+1) ;
        mod[v] = x ;
        return ;
    }
    
    if(tr < l || r < tl)
        return ;

    push(v, tl, tr) ;
    int tm = (tl + tr) >> 1 ;
    update(v*2, tl, tm, l, r, x) ;
    update(v*2+1, tm+1, tr, l, r, x) ;
    t[v] = t[v*2] + t[v*2+1] ;
}

int get(int v, int tl, int tr, int l, int r)
{
    if(l <= tl && tr <= r)
        return t[v] ;

    if(l > tr || r < tl)
        return 0 ;

    push(v, tl, tr) ;
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
    for(int i = 1 ; i <= n ; ++i)
        cin >> a[i] ;

    build(1, 1, n) ;

    int t ;
    cin >> t ;
    while(t--)
    {
        int type, l, r, x ;
        cin >> type ;
        if(type == 1)
        {
            cin >> l >> r >> x ;
            update(1, 1, n, l, r, x) ;
        }
        else
        {
            cin >> l >> r ;
            cout << get(1, 1, n, l, r) << '\n' ;
        }
    }
}