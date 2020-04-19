#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n , m ; 
	cin >> n >> m ;
	vector<pair<int,int>> mst , rem ;
	int mn = INT_MAX ;
	for(int i = 0 ; i < m ; i++){
		int w , b ;
		cin >> w >> b ;
		if(b == 1){
			mst.push_back({w,i}) ;
		} else {
			mn = min(mn , w) ;
			rem.push_back({w,i}) ;
		}
	}
	vector<pair<int,int>> edges(m) ;
	sort(mst.begin(),mst.end()) ;
	sort(rem.begin() , rem.end()) ;
	map<int,int> mp ;
	for(int i = 0 ; i < n - 1 ; i++){
		edges[mst[i].second] = {0,i+1} ;
		mp[i+1] = mst[i].first ;
	}
	int count = 0 ;
	for(int x = 2 ; x < n ; x++){
		if(count == m-n+1) break ;
		for(int i = 1 ; i < x ; i++){
			if(count == m-n+1) break ;
			if(rem[count].first < mp[x]) break ;
			edges[rem[count++].second] = {i,x} ;
		}
	}
	if(count != (m-n+1)) {
		cout << - 1 ;
		return 0 ;
	}
	for(auto i : edges) cout << i.first + 1 << " " << i.second + 1 << '\n' ;
	return 0 ;
}

