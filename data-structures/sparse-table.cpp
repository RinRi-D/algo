#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define sc(x) scanf("%I64d",&x)
#define pr(x) printf("%I64d\n",x)
#define int long long

using namespace std ;

const int MAXN = 1e9+1 ;
const int N = 1e6+1 ;
int n , m , k , x , y , z , gt ;
int a[N] , d[30][N] , p[N] ;

void build ()
{
    for (int i = 1 ; i <= n ; ++i )
        d[0][i] = a[i] ;
    for (int i = 2 ; i < N ; ++i )
        p[i] = p[i / 2] + 1;
    for (int i = 1 ; i <= p[n] ; ++i )
        for (int j = 1 ; j <= n - (1 << p[i]) + 1 ; ++j )
            d[i][j] = min (d[i - 1][j] , d[i - 1][j + (1 << (i - 1))]) ;
}

int get (int l , int r)
{
	int rr = max(r,l) ;
	int ll = min(r,l) ;
    int m = rr-ll + 1 ;
    m = p[m] ;
    return min (d[m][ll] , d[m][rr - (1 << m) + 1]) ;
}

main()
{
	cin >> n >> m >> a[1] ;
	for ( int i = 2 ; i <= n ; ++i )
	{
		a[i] = (23*a[i-1]+21563) % 16714589 ;
	}
	build() ;
	int l , r ;
	cin >> l >> r ;
	for ( int i = 2 ; i <= m ; ++i )
	{
		gt = get(l,r) ;
		l = ((17*l+751+gt+2*(i-1))%n)+1 ;
		r = ((13*r+593+gt+5*(i-1))%n)+1 ;
	}
	gt = get(l,r) ;
	cout << l << ' ' << r << ' ' << gt ;
}
