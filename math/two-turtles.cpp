#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
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
 
char c[3001][3001] ;
L dp[3001][3001], pd[3001][3001] ;
bool ok[3001][3001], ok2[3001][3001] ;
 
int32_t main()
{
    iosb ;
    int n, m ;
    cin >> n >> m ;
    for(int i = 1 ; i <= n ; ++i)
        for(int j = 1 ; j <= m ; ++j)
            cin >> c[i][j] ;
    
    dp[2][1] = 1, pd[1][2] = 1 ;
    if(c[2][1]!='#')
        ok[2][1] = 1, ok2[2][1] = 1 ;
    if(c[1][2]!='#')
        ok[1][2] = 1, ok2[1][2] = 1 ;
    for(int i = 2 ; i <= n ; ++i)
        for(int j = 1 ; j <= m ; ++j)
        {
            if(i==2&&j==1)
                continue ;
            if(i==2)
            {
                if(c[i][j] == '#')
                    ok[i][j] = 0 ;
                else if(!ok[i][j-1])
                    ok[i][j] = 0 ;
                else
                    dp[i][j] = dp[i][j-1], dp[i][j]%=MOD, ok[i][j] = 1 ;
                continue ;
            }
            if(j==1)
            {
                if(c[i][j] == '#')
                    ok[i][j] = 0 ;
                else if(!ok[i-1][j])
                    ok[i][j] = 0 ;
                else
                    dp[i][j] = dp[i-1][j], dp[i][j]%=MOD, ok[i][j] = 1 ;
                continue ;
            }
            if(c[i][j] == '#')
                ok[i][j] = 0 ;
            else if(!ok[i][j-1] && !ok[i-1][j])
                ok[i][j] = 0 ;
            else
                dp[i][j] = dp[i][j-1] + dp[i-1][j], dp[i][j]%=MOD, ok[i][j] = 1 ;
        }
 
    for(int i = 1 ; i <= n ; ++i)
        for(int j = 2 ; j <= m ; ++j)
        {
            if(i==1&&j==2)
                continue ;
            if(i==1)
            {
                if(c[i][j] == '#')
                    ok2[i][j] = 0 ;
                else if(!ok2[i][j-1])
                    ok2[i][j] = 0 ;
                else
                    pd[i][j] = pd[i][j-1], pd[i][j]%=MOD, ok2[i][j] = 1 ;
                continue ;
            }
            if(j==2)
            {
                if(c[i][j] == '#')
                    ok2[i][j] = 0 ;
                else if(!ok2[i-1][j])
                    ok2[i][j] = 0 ;
                else
                    pd[i][j] = pd[i-1][j], pd[i][j]%=MOD, ok2[i][j] = 1 ;
                continue ;
            }
            if(c[i][j] == '#')
                ok2[i][j] = 0 ;
            else if(!ok2[i][j-1] && !ok2[i-1][j])
                ok2[i][j] = 0 ;
            else
                pd[i][j] = pd[i][j-1] + pd[i-1][j], pd[i][j]%=MOD, ok2[i][j] = 1 ;
        }
 
    if(ok[n][m-1] && ok2[n-1][m])
    {
        L ans = (((dp[n][m-1]*pd[n-1][m])%MOD)-((dp[n-1][m]*pd[n][m-1])%MOD)) ;
        if(ans<0)
        ans = MOD+ans ;
        cout << ans << '\n' ;
    }
    else
        cout << 0 << '\n' ;
}