#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>

using namespace std ;

map<pair<int,int>,int> mp ;

int tin[20001] , fup[20001] , timer ;

vector <int> g[20001] , ans ;

bool used[20001] ;

void dfs(int v,int p = -1)
{
	used[v] = 1 ;
	tin[v]=fup[v]=timer,timer++ ;
	for(int i = 0 ; i < g[v].size() ; ++i)
	{
		int u = g[v][i] ;
		if(u==p)
		continue ;
		if(used[u])
			fup[v]=min(fup[v],tin[u]) ;
		else
		{
			dfs(u,v) ;
			fup[v] = min(fup[v],fup[u]) ;
			if(tin[v]<fup[u])
			{
				pair<int,int>pr ;
				pr.first = v , pr.second = u ;
				ans.push_back(mp[pr]) ;
			}
		}
	}
}

int main()
{
	int n , m ;
	cin >> n >> m ;
	for(int i = 0 ; i < m ; ++i)
	{
		pair<int,int>pr ;
		cin >> pr.first >> pr.second ;
		mp[pr] = i+1 ;
		pair<int,int>pr1;
		pr1.first = pr.second ;
		pr1.second = pr.first ;
		mp[pr1] = i+1 ;
		g[pr.first].push_back(pr.second) ;
		g[pr.second].push_back(pr.first) ;
	}
	for(int i = 0 ; i <= n ; ++i)
	{
		if(!used[i])
		dfs(i) ;
	}
	cout << ans.size() << '\n' ;
	sort(ans.begin(),ans.end()) ;
	for(int i = 0 ; i < ans.size() ; ++i)
	{
		cout << ans[i] << ' ' ;
	}
}

