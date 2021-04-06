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
const float INF =       1e9+7 ;

pair<int,int> a[5001] ;
int p[5001] ;
float g[5001][5001], cost ;

int32_t main()
{
    freopen("unionday.in" , "r" , stdin) ;
    freopen("unionday.out" , "w" , stdout) ;
    int n ;
    cin >> n ;
    for(int i = 0 ; i < n ; ++i)
    {
        cin >> a[i].F >> a[i].S ;
        for(int j = 0 ; j < i ; ++j)
        {
            float d = (a[i].F-a[j].F)*(a[i].F-a[j].F)+(a[i].S-a[j].S)*(a[i].S-a[j].S) ;
            d = sqrt(d) ;
            g[i][j] = d ;
            g[j][i] = d ;
        }
    }
    vector<bool> used (n);
    vector<float> min_e (n, INF);
    vector<int> sel_e (n, -1);
    min_e[0] = 0;
    for (int i=0; i<n; ++i) {
        int v = -1;
        for (int j=0; j<n; ++j)
            if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
                v = j;
        if (min_e[v] == INF) {
            cout << "No MST!";
            exit(0);
        }
     
        used[v] = true;
        if (sel_e[v] != -1)
            cost += g[v][sel_e[v]];
     
        for (int to=0; to<n; ++to)
            if (g[v][to] < min_e[to]) {
                min_e[to] = g[v][to];
                sel_e[to] = v;
            }
    }
    cout.precision(4) ;
    cout << fixed << cost << '\n' ;
}