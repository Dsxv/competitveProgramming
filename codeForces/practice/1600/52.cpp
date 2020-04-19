#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n , m ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	cin >> m ;
	int b[m] ;
	for(int i = 0 ; i < m ; i++) cin >> b[i] ;
	int i = 0 , j = 0 ;
	int x = 0 , y = 0 ;
	int count = 0 ;
	while(i < n && j < m){
		if(x == y) {
			count++ ;
			x += a[i] ;
			y += b[j] ;
			i++ , j++ ;
		}
		if(x < y) x += a[i++] ;
		if(y < x) y += b[j++] ;
	}
	while(i < n) x += a[i++] ;
	while(j < m) y += b[j++] ;
	if(x != y) {
		cout << -1 ;
		return 0 ;
	}
	cout << count ;
	return 0 ;
}

