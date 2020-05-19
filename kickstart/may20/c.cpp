#include <bits/stdc++.h>
using namespace std ;
const int N = 1e7 + 10 ;
const int N2 = 1e5 + 10 ;
void gogogo(){
	int n ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
	}
	int l = N ;
	if(n <= 1000) l = N2 ; 
	int s = 0 ;
	map<int,int> mp ;
	mp[0]++ ;
	int ans = 0 ;
	for(int i = 0 ; i < n ; i++){
		s += a[i] ;
		for(int j = 0 ; j*j < l ; j++){
			if(mp.count(s-j*j))
				ans += mp[s-j*j] ;
		}
		mp[s]++ ;
	}
	cout << ans << '\n' ;
}

int32_t main(){
	int t ;
	cin >> t ;
	for(int i = 1 ; i <= t ; i++){
		cout << "Case #" << i << ": ";
		gogogo() ;
	}	
	return 0 ;
}
