#include <bits/stdc++.h>
using namespace std ;

#define int long long

char xr = 'R' ^ 'L' ;
int solve(string& s){
	int n = s.size() ;
	int ans = 0 ;
	for(int i = 0 ; i < n ; i++){
		if(s[(i-1+n)%n] == s[i] && s[i] == s[(i+1)%n]) s[i] ^= xr , ans++ ;
	}
	return ans; 
}


int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n; 
		cin >> n ;
		string s ;
		cin >> s ;
		string t = s , u = s ;
		u[0] ^= xr ;
		t[n-1] ^= xr ;
		cout <<min({solve(s) ,1 + solve(t) ,1 + solve(u)}) << '\n' ;
	}
	return 0 ;
}

