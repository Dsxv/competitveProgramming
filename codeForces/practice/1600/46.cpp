#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	int a[n][m] ;
	vector<set<int>> v(n) ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin >> a[i][j] ;
		}
		for(int j = 0 ; j < m ; j++){
			v[i].insert(a[i][j]) ;
		}
	}
	vector<int> ans(n,0) ;
	int xr = 0 ;
	for(int i = 0 ; i < n ; i++) xr ^= a[i][0];
	if(xr){
		cout << "TAK\n" ;
		for(auto i : ans) cout << i + 1 << " " ;
		return 0 ;
	} else {
		bool found = false ;
		for(int i = 0 ; i < n ; i++){
			if(v[i].size() > 1){
				for(int j = 1 ; j < m ; j++){
					found = true ;
					if(a[i][j] != a[i][0]) ans[i] = j ;
				}
				break ;
			}
		}
		if(found) {
			cout << "TAK\n" ;
			for(auto i : ans) cout << i + 1 << " " ;
		} else {
			cout << "NIE" ;
		}
	}
	return 0 ;
}

