#include <bits/stdc++.h>
using namespace std ;

#define int long long

bool is_prime(int n ){
	if(n == 1) return 1 ;
	int l = sqrt(n) ;
	for(int i = 2 ; i <= l ; i++){
		if(n%i == 0) return false ;
	} return true ;
}

int32_t main(){
	int n ;
	cin >> n ;
	if(is_prime(n)){
		cout << 1 ;
		return 0 ;
	}
	if(n%2 == 0){
		cout << 2 ;
		return 0 ;
	}
	if(is_prime(n-2)) cout << 2 ;
	else cout << 3 ;
	return 0 ;
}

