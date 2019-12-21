#include <bits/stdc++.h>
using namespace std ;

#define int long long

string solve(string&t , int n , int k, int x){
	string ans = "" ;
	for(int i = 0 ; i < n/k + 1 ; i++) ans += t ;
	return ans.substr(0,x) ;
}

int32_t main(){
	int n , k ;
	cin >> n >> k ;
	string s ; cin >> s ;
	string ans ;
	string t = s.substr(0,k) ;
	ans = solve(t,n,k,n) ;
	if(ans >= s) cout <<n <<endl << ans ;
	else {
		int carry = 1 ;
		for(int i = t.size() - 1 ; i >= 0 ; i--){
			carry += (t[i] - '0') ;
			t[i] = carry%10 + '0';
			carry /= 10 ;
		}
		if(carry) t = "1" + t ;
		ans = solve(t,n,k,n) ;
		if(ans >= s) {
			cout << n << endl << ans ;
		}
		else {
			ans = solve(t,n,k,n+1) ;
			cout << n+1 << endl << ans ;
		}
	}
	return 0 ;
}

