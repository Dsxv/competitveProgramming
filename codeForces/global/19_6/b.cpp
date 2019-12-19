#include <bits/stdc++.h>
using namespace std ;
 
#define int long long
 
int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n , m ;
	cin >> n >> m ;
	if(n == 1 && m == 1) {
		cout << 0 ;
		return 0 ;
	}
	bool check = false ;
	if(n < m) { check = true ; swap(n,m) ; }
	int a[n][m] ;
	int x = 2 ;
	a[0][0] = 2 ;
	for(int i = 1 ; i < m ; i++) {
		a[i][0] = x + 1 ;
		a[0][i] = x + 2 ;
		x += 2 ;
	}
	for(int i = m ; i < n ; i++) a[i][0] = ++x ;
	for(int i = 1 ; i < n ; i++){
		for(int j = 1 ; j < m ; j++){
			a[i][j] = a[i][0]*a[0][j] ;
		}
	}
	if(!check){
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++) cout << a[i][j] << " " ;
			cout << '\n';
		} 
	} else {
		for(int j = 0 ; j < m ; j++){
			for(int i = 0 ; i < n ; i++) cout << a[i][j] << " " ;
			cout << '\n' ;
		}
	}
	return 0 ;
}
