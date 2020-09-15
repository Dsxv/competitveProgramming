#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e2 ;

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ; cin >> n ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		string s[n+1] ;
		s[0] = string(N+1,'a') ;
		for(int i = 1 ; i <= n ; i++){
			int j = 0 ;
			while(a[i-1]--) s[i] += s[i-1][j++] ;
			char ch = (char)(s[i-1][j] + 1) ;
			if(s[i-1][j] == 'z') ch = 'a' ; // rotate
			while(j < N) s[i] += ch , j++; 
		}
		for(int i = 0 ; i < n + 1 ; i++) cout << s[i] << '\n' ;
	}
	return 0 ;
}

