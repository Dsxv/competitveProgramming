#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	int a[n][m] ;
	int mn = 101 ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin >> a[i][j] ;
			mn = min(mn , a[i][j]) ;
		}
	}
	int ans = 0 ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			ans += a[i][j] - mn ;
		}
	}
	cout << ans ;
	return 0 ;
}

