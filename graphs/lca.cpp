#include <bits/stdc++.h>

using namespace std ;

vector <int> g[500001] ;

int n , m , lvl[500001] , used[500001] , k , up[500001][21] ;

void dfs(int v , int p)
{
	used[v] = 1 ;
	up[v][0] = p ;
	for (int jump = 20 ; jump >= 1 ; --jump)
		up[v][jump] = up[up[v][jump-1]][jump-1] ;
	for (int i = 0 ; i < g[v].size() ; ++i)
	{
		int to = g[v][i] ;
		if (!used[to])
		{
			lvl[to] = lvl[v] + 1 ;
			dfs(to, v) ;
		}
	}
}

int lca(int a , int b)
{
	if (lvl[a] < lvl[b])
		swap(a,b) ;
	for (int jump = 20 ; jump >= 0 ; --jump)
		if (lvl[up[b][jump]] >= lvl[a])
			b = up[b][jump] ;
	if (a == b)
		return b ;
	for (int jump = 20 ; jump >= 0 ; --jump)
		if (up[a][jump] != up[b][jump])
			a = up[a][jump] ,
			b = up[b][jump] ;
	return up[a][0] ;
}

main()
{
	cin >> n ;
	vector<pair<int,int> >z ;
	for (int i = 0 ; i < n ; ++i)
	{
		string s ;
		cin >> s ; 
		int a , b ;
		cin >> a >> b;
		if(s=="ADD")
			g[a].push_back(b) ;
		else
		z.push_back(make_pair(a,b)) ;
	}
	lvl[1] = 1 ;
	dfs(1, 1) ;
	for (int i = 0 ; i < z.size() ; ++i)
		cout << lca(z[i].first,z[i].second) << '\n' ;
}

