#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	string s ;
	cin >> s ;
	int a[n] ;
	int dp[26] = {} ;
	for(int i = 0 ; i < n ; i++){
		a[i] = 1 ;
		for(int j = s[i] - 'a' + 1 ; j < 26 ; j++) {
			// all the characters that are greater than current
			// and appeared before s[i] , i.e, ones which must 
			// cross through current element
			a[i] = max(a[i] , dp[j] + 1) ;
		}
		// set the value of current char to the max value
		dp[s[i]-'a'] = max(dp[s[i]-'a'],a[i]) ;
	}
	int mx = *max_element(a,a+n) ;
	cout << mx << endl ;
	for(int i = 0 ; i < n ; i++) cout << a[i] << " " ;
	return 0 ;
}

