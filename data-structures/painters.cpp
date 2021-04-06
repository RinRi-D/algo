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
 
const I MaxN =      8e6+123 ;
const I MOD =       1e9+7 ;
const I inf =       2e9+7 ;
const L INF = 2e18+7 ;

struct item{
    int cnt = 0, pref = 0, suff = 0, sum = 0 ;
} t[MaxN] ;
int m[MaxN] ;

void push(int v, int x, int y)
{
    if (m[v] != -1 && v*2+1 < 4000004)
    {
        m[v*2] = m[v*2+1] = m[v] ;
        m[v] = -1 ;

        int z = (x+y)/2 ;
        t[v*2].sum    = (z*1ll-x*1ll+1ll) * (m[v*2]*1ll) ;
        t[v*2].pref   = m[v*2] ;
        t[v*2].cnt    = m[v*2] ;
        t[v*2].suff   = m[v*2] ;
        t[v*2+1].sum  = (y*1ll-z*1ll) * (m[v*2+1]*1ll) ;
        t[v*2+1].pref = m[v*2+1] ;
        t[v*2+1].cnt  = m[v*2+1] ;
        t[v*2+1].suff = m[v*2+1] ;
    }
}

void update(int l, int r, int c, int v, int x, int y)
{
    if (l <= x && y <= r) {
        t[v].sum  = c*1ll * (y*1ll-x*1ll+1ll) ;
        t[v].cnt  = c ;
        t[v].pref = c ;
        t[v].suff = c ;
        m[v] = c ;
        return ;
    }

    if (y < l || r < x)
        return ;

    push(v, x, y) ;
    int z = (x+y)/2 ;
    update(l, r, c, v * 2, x, z) ;
    update(l, r, c, v * 2 + 1, z+1, y) ;
    t[v].pref = t[v*2].pref,
    t[v].suff = t[v*2+1].suff,
    t[v].sum  = t[v*2].sum + t[v*2+1].sum,
    t[v].cnt  = t[v*2].cnt + t[v*2+1].cnt - (t[v*2].suff && t[v*2+1].pref?1:0);
}

int main()
{
    freopen("painter.in", "r", stdin) ;
    freopen("painter.out", "w", stdout) ;
    for(int i = 0 ; i < MaxN ; ++i)
        m[i] = -1 ;
    int n ;
    cin >> n ;
    while(n--)
    {
        char c ;
        int l, r ;
        cin >> c >> l >> r ;
        if(c == 'W') c = 0 ;
        else c = 1 ;
        update(l+500001, l+r-1+500001, int(c), 1, 1, 2000000);
        cout << t[1].cnt << ' ' << t[1].sum << '\n' ;
    }
}
/*
7
W 2 3
B 2 2
B 4 2
B 3 2
B 7 2
W 3 1
W 0 10
*/