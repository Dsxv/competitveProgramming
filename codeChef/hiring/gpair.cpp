#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 2e6 + 10 ;
bool sieve[N] ;

int32_t main(){
	for(int i = 2 ; i < N ; i++) sieve[i] = 1 ;
	for(int i = 2 ; i < N ; i++){
		if(sieve[i])
		for(int j = i*i ; j < N ; j += i){
			sieve[j] = 0 ;
		}
	}
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		int count = 0 ;
		for(int i = 0 ; i < n ; i++){
			for(int j = i+1 ; j < n ; j++){
				count += sieve[a[i]+a[j]] ;
			}
		}
		cout << count << '\n' ;
	}
	return 0 ;
}

