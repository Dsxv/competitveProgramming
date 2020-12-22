#include <bits/stdc++.h>
using namespace std ;

#define int long long

int solve(int i , string &s , int n , int k , bool odd){
	int ans = 0 ;
	int l = i - odd , r = i + 1 ;
	while(l > -k && r < n + k && (r - l + 1) <= n){
		int cl = (l + n) % n , cr = r % n ;
		if(s[cl] == s[cr]){
			ans = max(ans , r - l + 1) ;
		} else {
			break ;
		}
		l-- , r++ ;
	}
	return ans ;
}


int32_t main(){
	int n , k ;
	cin >> n >> k ;
	string s ;
	cin >> s ;
	k = min(n , k) ;
	int ans = 0 ;
	for(int i = 0 ; i < n ; i++){
		ans = max(ans , solve(i , s , n , k , 0)) ;
		ans = max(ans , solve(i , s , n , k , 1)) ;
	}
	cout << ans ;
	return 0 ;
}

