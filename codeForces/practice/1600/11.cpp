#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ; cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
	}
	int count = 0 ;
	for(int i = 1 ; i < n - 1; i ++){
		count += (a[i] < a[i-1] && a[i] < a[i+1]) ;
		count += (a[i] > a[i-1] && a[i] > a[i+1]) ;
	}
	cout << count ;
	return 0 ;
}

