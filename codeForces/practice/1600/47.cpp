#include <bits/stdc++.h>
using namespace std ;

#define int long long

int solve(string&s  , string& temp , int k){
	int n = s.size() ;
	int a[n] = {} ;
	for(int i = 0 ; i < n ; i++){
		if(s[i] != temp[i]) a[i] = 1 ;
	}
	int val = INT_MAX , csum = 0 ;
	for(int i = 0 ; i < k ; i++){
		csum += a[i] ;
	}
	val = min(csum , val) ;
	for(int i = k ; i < n ; i++){
		csum -= a[i-k] ;
		csum += a[i] ;
		val = min(csum , val) ;
	}
	return val ;
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , k ;
		cin >> n >> k ;
		string s ;
		cin >> s ;
		string x = "RGB" ;
		int ans = INT_MAX ;
		for(int id = 0 ; id < 3 ; id++){
			string temp = "" ;
			for(int i = 0 ; i < n ; i++){
				temp += x[(i+id)%3] ;
			}
			ans = min(ans,solve(s,temp,k)) ;
		}
		cout << ans << endl ;
	}
	return 0 ;
}

