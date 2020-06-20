#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	string a = "Ashishgup" ;
	string b = "FastestFinger" ;
	while(t--){
		int n ;
		cin >> n; 
		if(n%2){
			if(n == 1){
				cout << b << '\n' ;
			} else {
				cout << a << '\n' ;
			}
		} else {
			if(n == 2){
				cout << a << '\n' ;
				continue ;
			}
			int l = sqrt(n) ;
			int ans = 0 ;
			int two = 0 ;
			while(n % 2 == 0){
				n /= 2 ;
				two++ ;
			}
			for(int i = 3 ; i <= l ; i += 2){
				while(n % i == 0){
					n /= i ;
					ans += i%2 ;
				}
			}
			if(n >= 3) ans++ ;
			if(two > 1){
				cout << (ans ? a : b) << '\n' ;
			}
			if(two == 1){
				cout << (ans > 1 ? a : b) << '\n' ;
			}
		}
	}
		
	return 0 ;
}

