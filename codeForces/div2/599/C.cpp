#include <bits/stdc++.h>
using namespace std ;

#define int long long
map<int,int> all_prime ;

bool dothis(int n){
	int s = sqrt(n) ;
	for(int i = 2 ; i <= s ; i++){
		while(n%i == 0){
			all_prime[i] = 1 ;
			n /= i ;
		}
	}
	if(n >= 2) all_prime[n] = 1 ;
	return true ;
}

int32_t main(){
	int n ;
	cin >> n ;
	if(n <=  2){
		cout << n ;
		return 0 ;
	}else{
		dothis(n) ;
		int gcd = 0 ;
		for(auto i : all_prime){
		gcd = __gcd(gcd ,i.first) ;
		}
		cout << gcd ;
	}
	return 0 ;
}

