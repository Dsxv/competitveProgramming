#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , m ;
		cin >> n >> m ;
		string s = "BW" ;
		char ans[n][m] ;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				ans[i][j] = s[(i+j)%2] ;
			}
		}
		if((n*m)%2 == 0){
			ans[0][1] = 'B' ;
		}
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				cout << ans[i][j] ;
			} cout << endl ;
		}
	}
	return 0 ;
}

