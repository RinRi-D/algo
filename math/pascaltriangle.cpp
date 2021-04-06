#include <bits/stdc++.h>

using namespace std ;

long long c[200][20000] ;

main()
{
	freopen("combination.in","r",stdin) ; 
	freopen("combination.out","w",stdout) ;
	int n , k ;
	cin >> n >> k;
	for(int i = 0 ; i <= n ; ++i)
	{
		c[i][0] = 1 ; c[i][i] = 1 ;
		for(int j = 1 ; j < i ; ++j)
		c[i][j] = c[i-1][j-1]+c[i-1][j] ;
	}
	cout << c[n][k] ;
}
