#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n; 
	int a[n] ;
	int count = 0 ;
	for(int i = 0 ; i < n ; i++) {	
		cin >> a[i] ;
		if(a[i] == 1){
			count++ ;
		}
	}
	int ans = (count?n-count:INT_MAX) ;
	for(int i = 0 ; i < n ; i++){
		int x = a[i] ;
		for(int j = i+1 ; j < n ; j++){
			x = __gcd(x,a[j]) ;
			if(x == 1){
				ans = min(j - i + n - 1,ans) ;
			}
		}
	}
	cout << (ans == INT_MAX ? -1 : ans) ;
	return 0 ;
}

