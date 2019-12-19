#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--) {
		int n , m ;
		cin >> n >> m ;
		string s[n] ;
		for(int i = 0 ; i < n ; i++) cin >> s[i] ; 
		int col[m] = {} , row[n] = {} ;
		int count = 0 ;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0; j < m ; j++){
				count += s[i][j] == 'A' ;
				row[i] += s[i][j] == 'A' ;
			}
		}
		for(int j = 0 ; j < m ; j++){
			for(int i = 0 ; i < n ; i++){
				col[j] += s[i][j] == 'A' ;
			}
		}
		if(count == 0) {
			cout << "MORTAL\n" ; continue ;
		}
		bool ok = count == n*m;
		if(ok) {
			cout << 0 << '\n'; continue ;
		}
		if(row[0] == m || row[n-1] == m || col[0] == n || col[m-1] == n) {
			cout << 1 << '\n' ; continue ;
		}
		for(int i = 0 ; i < n ; i++) if(row[i] == m) ok = true ;
		for(int i = 0 ; i < m ; i++) if(col[i] == n) ok = true ;
		if(ok || s[0][0] == 'A' || s[0][n-1] == 'A' || s[0][m-1] == 'A' 
				|| s[n-1][m-1] == 'A') {
			cout << 2 << '\n' ; continue ;
		}	
		for(int i = 0 ;  i < n ; i++) {
			if(s[i][0] == 'A' || s[i][m-1] == 'A') ok = true ;
		}
		for(int i = 0 ; i < m ; i++) {
			if(s[0][i] == 'A' || s[n-1][i] == 'A') ok = true ;
		}
		if(ok) cout << 3 << '\n' ;
		else cout << 4 << '\n' ;
	}
	return 0 ;
}

