#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	map<int,map<int,int>> check ;
	int col[n] ;
	for(int i = 0 ; i < n ; i++) {
		cin >> col[i] ;
		check[col[i]][col[i]] = 1 ;
	}
	for(int i = 0 ; i < m ; i++){
		int f, s ;
		cin >> f >> s ;
		f-- , s-- ;
		check[col[f]][col[s]] = 1 ;
		check[col[s]][col[f]] = 1 ;
	}
	pair<int,int> ans = {-1,-1} ;
	for(auto i : check){
		int x = i.second.size() ;
		if(x > ans.second) {
			ans = {i.first,x} ;
		}
		else if(x == ans.second){
				ans.first = min(ans.first,i.first) ;
		} else{
			continue ;
		}
	}
	cout << ans.first ;
	return 0 ;
}

