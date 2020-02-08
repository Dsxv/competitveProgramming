#include <bits/stdc++.h>
using namespace std ;

#define int long long

bool check(int n){
	int l = sqrt(n) ;
	if(n < 2) return false ;
	for(int i = 2 ; i <= l ; i++){
		if(n%i == 0) return false ;
	}
	return true ;
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ; cin >> n ;
		int ans = 0 ;
		int l = sqrt(n) ;
		for(int i = 1 ; i <= l ; i++){
			if(n%i == 0){
				ans += 2 - (i*i == n) ;
			}
		}
		if(check(ans)) cout << "Yes\n" ;
		else cout << "No\n" ;
	}
	return 0 ;
}

