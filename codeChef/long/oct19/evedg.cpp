#include <bits/stdc++.h>
using namespace std ;

int32_t main(){
	int t ;
	cin >> t;
	while(t--){
		int n , m ;
		cin >> n >> m ;
		vector<int> v[n] ;
		for(int i = 0 ; i < m ; i++) {
			int f , s ;
			cin >> f >> s ;
			f-- , s-- ;
			v[f].push_back(s) ;
			v[s].push_back(f) ;
		}
		int a[n] ;
		for(int i = 0 ; i < n ; i++) a[i] = 1 ;
		int tc = 1 ;
		if(m&1){
			for(int i = 0 ; i < n ; i++){
				if(v[i].size()&1){
					a[i] = 2 ; tc = 2 ; break ;
				}
			}
			if(tc != 2){
				for(int i = 0 ; i < n ; i++){
					if(v[i].size() >= 2){
						a[i] = 2 ; 
						a[v[i][0]] = 3 ;
						tc = 3 ;
						break ;
					}
				}
			}
		}
		cout << tc << '\n' ;
		for(int i = 0 ; i < n ; i++) cout << a[i] <<" " ;
		cout << '\n' ;
    }
	return 0 ;
}

