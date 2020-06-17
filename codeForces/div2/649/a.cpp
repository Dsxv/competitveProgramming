#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , b;
		cin >> n >> b;
		int a[n] ;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i] ;
		}
		int ans = -1 , sum = 0 ;
		for(int i = 0 ; i < n ; i++){
			sum += a[i] ;
			if(sum%b){
				ans = max(ans , i + 1) ;
			}
		}
		sum = 0 ;
		for(int i = n -1 ; i >= 0 ; i--){
			sum += a[i] ;
			if(sum%b){
				ans = max(ans , n  - i) ;
			}
		}
		cout << ans << '\n' ;
	}


	return 0 ;
}

