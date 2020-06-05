#include <bits/stdc++.h>
using namespace std ;

#define int long long

bool prime(int n){
	int l = sqrt(n) ;
	for(int i = 2 ; i <= l ; i++){
		if(n % i == 0) return 0 ;
	}
	return 1 ;
}

int32_t main(){
	int n ;
	cin >> n ;
	int ans = n ;
	while(true){
		if(prime(n)){
			break ;
		}
		n-- ;
	}
	ans -= n ;
	if(ans == 0){
		cout << "1\n" <<  n ;
	} else if(ans < 3){
		cout << "2\n"<< ans << " " << n ;
	} else {
		assert(ans%2 == 0) ;
		for(int i = 2 ; i < ans ; i++){
			if(prime(i) && prime(ans-i)){
				cout << "3\n" << i << " " << ans-i << " " << n ;
				return 0 ;
			}
		}
		cout << -1 ;
	}
	return 0 ;
}

