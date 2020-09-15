#include <bits/stdc++.h>
using namespace std ;

#define int long long

void dfs(vector<vector<int>>& g , int* d ,int start = 0 , int cnt = 0){
	d[start] = cnt ;
	for(auto i : g[start]){
		dfs(g,d,i,cnt+1) ;
	}
}

void gogogo(){
	int n , a , b ;
	cin >> n >> a >> b ;
	vector<vector<int>> g(n) ;
	int p[n] = {} ;
	p[0] = -1 ;
	for(int i = 1 ; i < n ; i++){
		int x ; cin >> x ; x-- ;
		p[i] = x ;
		g[x].push_back(i) ;
	}
	int d[n] = {} ;
	dfs(g , d) ;
	double ans = 0 ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			set<int> s ;
			int start = i ;
			while(~start){
				if((d[i]-d[start])%a == 0) s.insert(start) ;
				start = p[start] ;
			}
			start = j ;
			while(~start){
				if((d[j]-d[start])%b == 0) s.insert(start) ;
				start = p[start] ;
			}
			ans += (int)s.size() ;
		}
	}
	cout << fixed << setprecision(7) << ans/(n*n) << '\n' ;
}

int32_t main(){
	int t ;
	cin >> t ;
	for(int i = 1 ; i <= t ; i++){
		cout << "Case #" << i << ": ";
		gogogo() ;
	}	
	return 0 ;
}


