#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n; 
	int a[n] = {} ;
	for(int i = 0 ; i < n ; i++){
		int x ;
		cin >> x ;
		a[x-1] = i ;
	}
	int m ;
	cin >> m ;
	int f = 0 , s = 0 ;
	for(int i = 0 ; i < m ; i++){
		int x ; cin >> x ;
		x-- ;
		f += a[x] + 1 ;
		s += n - 1 - a[x] + 1 ;
	}
	cout << f << " " << s ;
	return 0 ;
}

