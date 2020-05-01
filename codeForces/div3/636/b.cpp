#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		n /= 2 ;
		if(n&1){
			cout << "NO\n" ;
			continue ;
		}
		int odd[n] ;
		int even[n] ;
		for(int i = 0 , k = 1  ; i < n ; i++){
			odd[i] = k ;	
			if(i&1) k += 2 ;
			else k += 4 ;
		}
		for(int i = 0 ; i < n ; i++){
			if(i&1) even[i] = odd[i] - 1 ;
			else even[i] = odd[i] + 1 ;
		}
		cout << "YES\n" ;
		for(int i = 0 ; i < n ; i++) cout << even[i] << " " ;
		for(int i = 0 ; i < n ; i++) cout << odd[i] << " " ;
		cout << '\n' ;
	}
	return 0 ;
}

