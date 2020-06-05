#include <bits/stdc++.h>
using namespace std ;

#define int long long

vector<vector<int>> g ;
int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , x ;
		cin >> n >> x;
		g.clear() ;
		g.resize(n) ;
		for(int i = 0 ; i < n - 1 ; i++){
			int f , s ;
			cin >> f >> s ;
			f-- , s-- ;
			g[f].push_back(s) ;
			g[s].push_back(f) ;
		}
		x-- ;
		if(n%2 == 0 ||  g[x].size() <= 1){
			cout << "Ayush\n" ;
		} else {
			cout << "Ashish\n" ;
		}
	}
	return 0 ;
}

