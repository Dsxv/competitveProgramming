#include <bits/stdc++.h>
using namespace std ;

#define int long long

bool is_prime(int n){
	int l = sqrt(n) ;
	for(int i = 2 ; i <= l ; i++){
		if(n % i == 0) return false ;
	}
	return true ;
}

int32_t main(){
	int n ;
	cin >> n ;
	int count = 0 , ind = 1 ;
	for(int i = n ; i >= 1; i--){
		if(is_prime(i)) count++ ;
		if(count == 3){
			ind = i ;
			break ;
		}
	}
	int mx = 0 ;
	for(int i = ind ; i <= n ; i++){
		for(int j = ind ; j <= n ; j++){
			for(int  k = ind ; k <= n ; k++){
				int x = (i*j)/__gcd(i,j) ;
				mx = max(mx , x*k/__gcd(x,k)) ;
			}
		}
	}
	cout << mx ;
	return 0 ;
}

