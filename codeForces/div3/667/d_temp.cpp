#include <bits/stdc++.h>
using namespace std ;

#define int long long

int val(int n){
	if(n == 0) return 0 ;
	return val(n/10) + n%10 ;
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , sum; 
		cin >> n >> sum ;
		int ans = 0 ;
		int p = 1 ;
		for(int i = 0 ; i <= 18 ; i++){
			if(val(n) <= sum){
				break ;
			}
			int x = (10 - (n % 10)) % 10 ;
			n += x ;
			ans += x*p ;
			n /= 10 ;
			p *= 10 ;
		}
		cout << ans << '\n';
	}
	return 0 ;
}

