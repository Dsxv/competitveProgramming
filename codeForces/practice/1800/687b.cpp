#include <bits/stdc++.h>
using namespace std ;

#define int long long

int lcm(int x , int y){
	return x*y / __gcd(x,y) ;
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n , k ;
	cin >> n >> k ;
	int a[n] ;
	for(int i = 0 ; i  < n ; i++){
		int x ; cin >> x ;
		a[i] = __gcd(x , k) ;
	}
	int val = a[0] ;
	for(int i = 1 ; i < n ; i++){
		val = lcm(a[i] , val) ;
		if(val > k){
			cout << "No" ;
			return 0 ;
		}
	}
	cout << (val == k ? "Yes" : "No") ;
	return 0 ;
}

