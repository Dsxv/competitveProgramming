#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , k; 
		cin >> n >> k ;
		int l = sqrt(n) ;
		int ans = n ;
		for(int i = 2 ; i <= l ; i++){
			if(n%i == 0){
				ans += i ;
				break ;
			}
		}
		if(ans == n) ans += n ;
		ans += 2*(k-1) ;
		cout << ans << '\n';
	}
	return 0 ;
}

