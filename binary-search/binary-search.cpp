#include <iostream>
#include <algorithm>

using namespace std ;

int main()
{
	int n ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; ++i) cin >> a[i] ;
	sort(a,a+n) ;
	int x ;
	cin >> x ;
	int l = 0 , r = n ;
	while(r-l>1)
	{
		int mid = (r+l)/2 ;
		if(a[mid] <= x)
			l = mid ;
		else r = mid ;
	}
	if(a[l]==x)
	cout << l ;
	else
	cout << -1 ;
}


