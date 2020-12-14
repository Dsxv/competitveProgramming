#include <bits/stdc++.h>
using namespace std ;

#define int long long

void gogogo(){
	int n ;
	cin >> n ;
	int x[n] , y[n] ;
	for(int i = 0 ; i < n ; i++) cin >> x[i] >> y[i] ;
	sort(y , y + n) ;
	sort(x , x + n) ;
	int mid = n / 2 ;
	int sum = 0 ;
	for(int i = 0 ; i < n ; i++){
		sum += abs(y[i] - y[mid]) ;
	}
	for(int i = mid , id = x[mid] ; i >= 0 ; i--){
		sum += abs(x[i] - id) ;
		id-- ;
	}
	for(int i = mid , id = x[mid] ; i < n ; i++){
		sum += abs(x[i] - id) ;
		id++ ;
	}
	cout << sum << '\n' ;
}

int32_t main(){
	int t ;
	cin >> t ;
	for(int i = 1 ; i <= t ; i++){
		cout << "Case #" << i << ": ";
		gogogo() ;
	}	
	return 0 ;
}
