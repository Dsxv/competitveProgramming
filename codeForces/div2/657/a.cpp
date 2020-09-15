#include <bits/stdc++.h>
using namespace std ;

#define int long long

bool check(int id , string&s , string&k){
	int n = s.size() , m = k.size() ;
	bool found = false ;
	for(int j = id , l = 0; l < m && j < n; j++){
		if(s[j] == k[l]) l++ ;
		else if(s[j] == '?') s[j] = k[l++] ;
		else return false ;
		if(l == m) found = true ;
	}
	if(!found) return false ;
	int ans = 0;
	for(int i = 0 ; i < n ; i++){
		bool ok = false ;
		for(int j = i, l = 0 ; l < m && j < n ; j++){
			if(s[j] == k[l]) l++ ;
			else {
				break ;
			}
			if(l == m) ok = true ;
		}
		ans += ok ;
	}
	return ans == 1;
}


int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		string s , k = "abacaba" ;
		int m = k.size() ;
		cin >> s ;
		int ans = 0;
		for(int i = 0 ; i < n ; i++){
			bool ok = false ;
			for(int j = i, l = 0 ; l < m && j < n; j++){
				if(s[j] == k[l]) l++ ;
				else {
					break ;
				}
				if(l == m) ok = true ;
			}
			ans += ok ;
		}
		if(ans > 1){
			cout << "NO\n" ;
			continue ;
		} 
		if(ans == 1){
			cout << "YES\n" ;
			for(auto i : s) cout << (i=='?'?'z':i) ;
			cout << '\n' ;
			continue ;
		}
		bool ok = false ;
		for(int i = 0 ; i < n ; i++){
			string temp = s ;
			if(check(i,temp,k)){
				ok = true ;
				cout << "YES\n" ;
				for(auto j : temp) cout << (j=='?'?'z':j) ;
				cout << '\n' ;
				break ;
			}
		}
		if(!ok){
			cout << "NO\n" ;
		}
	}
	return 0 ;
}

