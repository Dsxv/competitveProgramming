#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int l = sqrt(n) ;
		int sum = 0 ;
		for(int i = 1; i <= l ; i++){
			if(n%i) continue ;
			if(i*i == n){
				sum += i; 
			} else {
				sum += i ;
				sum += (n/i) ;
			}
		}
		sum -= n ;
		cout << ((sum==n)?"YES\n":"NO\n") ;
	}
	return 0 ;
}

