#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n;
		int a = 0 , b = 0 ;
		int l = n / 2 ;
		for(int i = l - 1 ; i < n - 1 ; i++){
			b += 1LL<<i ;
		}
		for(int i = 0 ; i < l - 1 ; i++){
			a += 1LL<<i ;
		}
		cout << 2*((a + (1LL<<(n-1))) - b) << '\n' ;
	}
	return 0 ;
}

