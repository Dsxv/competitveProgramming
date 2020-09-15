#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e7 + 10 ;
int a[N] ;
int32_t main(){
	for(int i = 1 ; i < N ; i++){
		for(int j = i ; j < N ; j += i){
			a[j]++ ;
		}
	}
	int n ; cin >> n ;
	int ans = 0 ;
	for(int i = 1 ; i <= n ; i++){
		ans += i*a[i] ;
	}
	cout << ans ;
	return 0 ;
}

