#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	int a[n][2] ;
	for(int i = 0 ; i < n ; i++){
		int x , y ; 
		cin >> x >> y ;
		x-- , y-- ;
		a[i][0] = x , a[i][1] = y ;
	}

	int x = 0 , y = 0 ;
	while(x < n){
		if(y == m){
			cout << -1 << '\n' ;
			x++ ;
			continue ;
		}
		if(y >= a[x][0] && y <= a[x][1]) y++ ;
		else {
			x++ ;
			cout << x + y << '\n' ;
		}
	}
	return 0 ;
}

