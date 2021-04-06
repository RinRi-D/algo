#include <bits/stdc++.h>

#define F first
#define S second
#define pb(x) push_back(x)
#define iosb ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define BIT(x) __builtin_popcount(x)

using namespace std ;

const int MAXN =      1e6+1 ;
const int MaxN =      1e5+1 ;
const int N =         1e4+1 ;
const int M =         1e3+1 ;
const int MOD =       1e9+7 ;
const int inf =       2e9+7 ;
const long long INF = 2e18+7 ;

int t[MaxN] , n , a[MaxN] ;

int sum(int v)
{
	int res = 0 ;
	
	if(v==-1)
		return 0 ;
		
	for(; v > 0 ; v = (v & (v + 1)) - 1)
		res += t[v] ;
	
	return res ;
}

void upd(int pos , int delta)
{
	a[pos] += delta ;
	for( ; pos < n ; pos |= pos+1)
		t[pos] += delta ;
}

/*
int get_min(int v)
{
    int res = inf ;

    for (; v >= 0; v = (v & (v + 1)) - 1)
        res = min(res , f[v]) ;

    return res ;
}

void assign(int pos, int delta)
{
    a[pos] = delta ;

    for (; pos < n ; pos |= pos + 1)
        f[pos] = min(f[pos] , delta) ;
}
*/

main()
{
//	freopen(".in" , "r" , stdin) ;
//	freopen(".out" , "w" , stdout) ;
	cin >> n ;
	
	for(int i = 0 ; i < n ; ++i)
	{
		int x ;
		cin >> x ;
		upd(i , x) ;
	}
	/*
	for(int i = 0 ; i < n ; ++i)
		f[i] = inf ;                                  

    for(int i = 0 ; i < n ; ++i)
	{
		int t ;
		cin >> t ;
		assign(i , t) ;
    }
	*/
	int q ;
	cin >> q ;
	while(q--)
	{
		int l , r ;
		cin >> l >> r ;
		cout << sum(r-1) - sum(l-2) << '\n' ;
	}
	return 0 ;
}

