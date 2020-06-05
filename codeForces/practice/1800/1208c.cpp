#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	int a[n][n] ;
	for(int i = 0 ; i < n / 2 ; i++){
		for(int j = 0 ; j < n / 2 ; j++){
			a[i][j] = 4*(i*(n/2) + j) ;
		}
	}
	for(int i = 0 ; i < n / 2 ; i++){
		for(int j = n / 2 ; j < n ; j++){
			a[i][j] = a[i][j-n/2] + 1 ;
		}
	}
	for(int i = n /2 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			a[i][j] = a[i-n/2][j] + 2 ;
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cout << a[i][j] << " \n"[j==n-1] ;
		}
	}
	return 0 ;
}
