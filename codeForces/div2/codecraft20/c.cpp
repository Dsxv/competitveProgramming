#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int x , y ;
	int n , m , p ;
	cin >> n >>  m >> p ;
	bool found = false ;
	for(int i = 0 ; i < n ; i++){
		int t ; cin >> t ;
		if(t%p && !found){
			x = i ;
			found = true ;
		}
	}
	found = false ;
	for(int i = 0 ; i < m ; i++){
		int t ; cin >> t ;
		if(t%p && !found){
			y = i ; found = true ;
		}
	}
	cout << x + y ;
	return 0 ;
}

