#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , k ; 
		cin >> n >> k ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i] ;
		}
		sort(a,a+n,greater<int>()) ;
		int b[k] ;
		for(int i = 0 ; i < k ; i++){
			cin >> b[i] ;
		}
		int ans = 0 ;
		sort(b,b+k) ;
		set<int> s[k] ;
		int j = 0 ;
		for(int i = 0 , mx = 0 ; mx < k ; i = max((i+1)%k , mx)){
				if(a[j] < 0) break ;
				b[i]-- ;
				s[i].insert(a[j++]) ;
				if(!b[i]) mx++ ;
		}
		int l = n - 1 ;
		for(int i = k - 1 ; i >= 0 ; i--){
			while(b[i]-- && l >= j) s[i].insert(a[l--]) ;
			ans += *s[i].begin() + *s[i].rbegin() ;
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}

