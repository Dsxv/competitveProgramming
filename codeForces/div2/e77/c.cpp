#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t; 
	while(t--){
		int r , b , k ;
		cin >> r >> b >> k ;
		if(r > b) swap(r,b) ;
		if(r == b){
			cout << "OBEY\n" ;
			continue ;
		}
		double x = (double)(2*b - b - 1)/r ;
		int count = b%r ? (int) x : ceil(x) ;
		
		if(count >= k){
			cout << "REBEL\n" ;
		}else{
			cout << "OBEY\n" ;
		}
	}
	return 0 ;
}

