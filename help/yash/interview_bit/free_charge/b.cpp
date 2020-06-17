#include <bits/stdc++.h>
using namespace std ;

#define int long long

bool ok(int* a){
	for(int i = 0 ; i < 26 ; i++){
		if(a[i] > 1) return 0 ;
	}
	return 1 ;
}

int Solution::solve(string & s){
	int n = s.size() ;
	if(n < 26) return -1 ;
	int a[26] = {} ;
	for(int i = 0 ; i < 26 ; i++){
		if(s[i] == '?') continue ;
		a[s[i]-'A']++ ;
	}
	if(!ok(a)) return -1 ;
	for(int i = 26 ; i < n ; i++){
		if(s[i-26] != '?') a[s[i-26] - 'A']-- ;
		if(s[i] != '?') a[s[i] - 'A']++ ;
		if(!ok(a)) return 0 ;
	}
	return -1; 
}


int32_t main(){
	string s = string(21,'?') ;
	s += "ABCDE" ;
	cout << solve(s) ;
	return 0 ;
}

