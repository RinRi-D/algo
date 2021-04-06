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
 
L ans[3001], anss, ansss, f[3001], pascal[3001][3001] ;
 
L binpow (L a, L n) {
	if (n == 0)
		return 1;
	if (n % 2 == 1)
		return (binpow (a, n-1) * a)%MOD;
	else {
		L b = binpow (a, n/2);
		return (b * b) % MOD;
	}
}
 
L cnk(L n, L k)
{
    return (f[n] * binpow(f[k]*f[n-k]%MOD,MOD-2)) % MOD ;
}
 
int32_t main()
{
    //freopen(".in" , "r" , stdin) ;
    //freopen(".out" , "w" , stdout) ;
    pascal[1][1] = 1 ;
    for(int i = 1 ; i <= 3000 ; ++i)
    {
        for(int j = 1 ; j <= i ; ++j)
        {
            if(j == 1 || j == i)
                pascal[i][j] = 1 ;
            else
                pascal[i][j] = pascal[i-1][j-1]+pascal[i-1][j], pascal[i][j] %= MOD ;
        }
    }

    f[0] = 1 ;
    for(L i = 1 ; i <= 3000 ; ++i)
        f[i] = i * f[i-1], f[i] %= MOD ;
 
 
 
    string s ;
    L c ;
    cin >> s >> c ;
    
    

    int cnt = 0 ;
    for(int i = 0 ; i < s.size() ; ++i)
        if(s[i] == '1')
            cnt ++ ;
 
    for(L i = 1, j = cnt-1; i <= s.size() ; i++)
    {
        ans[i] = c ;
        for(L j = 1 ; j < i ; ++j)
        {
            ans[i]+=binpow(c, j)*pascal[i][j+1];
            ans[i]%=MOD;
        }
        if(s[s.size()-i] == '1')
            anss+=ans[i]*binpow(c, j--), anss %= MOD ;
    }
 
    cout << anss+1 ;
}