#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t; 
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int a[n+1] ;
		for(int i = 1 ; i <= n ; i++){
			cin >> a[i] ;
		}
		int count = 0 ;
		for(int i = 1 ; i <= n ; i++){
			for(int j = i + 1 ; j <= n ; j++) {
				count += (a[j] < a[i]) ;
			}
		}
		cout << (count%2 == 0?"YES\n" : "NO\n") ;
	}
	return 0 ;
}

