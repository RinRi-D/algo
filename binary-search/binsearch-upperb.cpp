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
 
int32_t main(int argc, char *argv[])
{
    if(argc > 1)
        freopen(argv[1], "r", stdin) ;
    //freopen(".in" , "r" , stdin) ;
    //freopen(".out" , "w" , stdout) ;
    int n, k ;
    cin >> n >> k ;

    //presorted array
    int a[n] ;
    for(int i = 0 ; i < n ; ++i)
        cin >> a[i] ;
    
    while(k--)
    {
        int x ;
        cin >> x ;
        int l = 0, r = n ;
        while(l < r)
        {
            int m = (l+r) >> 1 ;
            if(a[m] < x)
                l = m+1 ;
            else
                r = m ;
        }
        cout << l+1 << '\n' ;
    }
    
    
}