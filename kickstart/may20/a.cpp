#include <bits/stdc++.h>
using namespace std ;

#define int long long

void gogogo(){
	int n , k ;
	cin >> n >> k ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
	}
	int x = k , count = 0 ;
	for(int i = 0 ; i < n ; i++){
		if(a[i] == x){
			x-- ;
		} else {
			x = k - (a[i] == k);
		}
		if(x == 0){
			x = k ;
			count++ ;
		}
	}
	cout << count << '\n' ;
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


