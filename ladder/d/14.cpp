#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	string s ;
	cin >> s ;
	int n = s.size() ;
	lsp[n] = {} ;
	int j = 0 ;
	for(int i = 1 ; i < n ; i++){
		while(s[j] != s[i] && j) {
			j = lps[j-1] ;
		}
		if(s[i] == s[j]) {
			lps[i] = j+1 ; j++ ;
		}
	}
	string k = s.substr(1,lps[n]);
	if(k == "") {
		cout << "Just a legend" ;
	} else {
		cout << k ;
	}
	return 0 ;
}

