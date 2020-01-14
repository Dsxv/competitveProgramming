#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	int a[n+1] ;
	for(int i = 2 ; i <= n ; i++) cin >> a[i] ;
	for(int i = 1 ; i < n ; i++){
	   a[1] = i ;
   	}

	return 0 ;
}

