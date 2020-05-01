#include <bits/stdc++.h>
using namespace std ;

#define int long long

int solve(int* x , int* y , int a , int b , int n){
	int count = n ;
	int lc = (a*b)/__gcd(a,b) ;
	for(int i = 0 , j = 0 ; i < (b - 1) ; i++ , j = (j+1)%a){
		if(i + 1 <= n){
			count -= (n-(i+1))/lc + 1 ;
		}
	}
	if(n >= lc){
		count -= (n-lc)/lc + 1 ;
	}
	return count ;
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int a , b  , q ;
		cin >> a >> b >> q ;
		if(b < a) swap(a,b) ;
		int x[a] = {} , y[b] = {};
		for(int i = 0 ; i < a ; i++) x[i] = (i+1)%a ;
		for(int i = 0 ; i < b-1 ; i++) y[i] = (i+1)%a ; 
		while(q--){
			int l , r ;
			cin >> l >> r ;
			cout << solve(x,y,a,b,r) - solve(x,y,a,b,l-1) << ' ' ;
		}
		cout << '\n' ;
	}
	return 0 ;
}

