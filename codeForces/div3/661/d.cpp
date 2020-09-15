#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		string s ;
		cin >> s ;
		int l = n , r = n ;
		bool zuse = 0 , ouse = 0 ;
		int ans[n] = {} ;
		int cnt = 1 ;
		for(int i = n - 1 ; i >= 0 ; i--){
			if(s[i] - '0'){
				if(l < i){
					ans[i] = cnt++ ;
					continue ;
				} 
				if(zuse){
					ans[i] = ans[l] ;
					zuse = 0 ;
					continue ;
				}
				l-- ;
				while(l >= 0 && s[l] == '1') l-- ;
				if(l < i){
					ans[i] = cnt++ ;
					zuse = true ;
					continue ;
				} else {
					ans[i] = ans[l] ;
				}
			} else {
				if(r < i){
					ans[i] = cnt++ ;
					continue ;
				}
				if(ouse){
					ans[i] = ans[r] ;
					ouse = 0 ;
					continue ;
				}
				r-- ;
				while(r >= 0 && s[r] == '0') r-- ;
				if(r < i){
					ans[i] = cnt++ ;
					ouse = true ;
					continue ;
				} else {
					ans[i] = ans[r] ;
				}
			}
		}
		cout << *max_element(ans, ans+n) << '\n' ;
		for(int i = 0 ; i < n ; i++) cout << ans[i] << " " ;
		cout << '\n' ;
	}
	return 0 ;
}

