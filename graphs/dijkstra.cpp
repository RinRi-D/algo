#include <bits/stdc++.h>
 
using namespace std ;
 
const long long MaxN = 1e6 + 17;
const long long INF = 1e14 + 17;
 
long long n , m ;
vector <pair<int,int> > g[MaxN] ;
set <pair<int,int> > S ;
long long s , f ;
long long d[MaxN] ;
 
int main ()
{
    scanf ("%d%d", &n, &m);
    s = 1 ;
    for (int i = 1; i <= m; ++ i) {
        int x, y, w;
        scanf ("%d%d%d", &x, &y, &w);
        g[x].push_back (make_pair (y, w));
        g[y].push_back (make_pair (x, w));
    }
    for (int i = 1 ; i <= n ; ++i)
        d[i] = INF ;
    d[s] = 0 ;
    vector<int> p(n+1) ;
    S.insert (make_pair (0,s)) ;
    while (!S.empty()) {
        int v = S.begin() -> second;
        S.erase (*S.begin());
        for (int i = 0 ; i < g[v].size() ; ++ i) {
            int to = g[v][i].first;
            int w = g[v][i].second;
            if (d[v] + w < d[to])
			{
                S.erase(make_pair(d[to] , to)) ;
                d[to] = d[v] + w ;
                p[to] = v ;
                S.insert(make_pair(d[to] , to)) ;
            }
        }
    }
    if(d[n] == INF)
    	return (cout << -1 , 0) ;
	vector<int> ans ;
	for(int v = n ; v != 1 ; v = p[v])
	{
		if(p[v] == 0)
			return(cout << -1,0) ;
		ans.push_back(v) ;
	}
	ans.push_back(1) ;
    for(int i = ans.size() - 1 ; i >= 0 ; --i)
    	cout << ans[i] << ' ' ;
}
