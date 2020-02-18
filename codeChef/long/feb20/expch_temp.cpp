#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int mod = 1e9 + 7 ;

int solve(string&s , int i , int j){
	string temp = s.substr(i,j-i+1) ;
	int ccount = 0 ;
	int val = 0 ;
	for(auto x : temp){
		if(ccount == 0 && x == ')'){
			ccount++ ;
			val++ ;
			continue ;
		} 
		if(x == ')') ccount-- ;
		if(x == '(') ccount++ ;
	}
	return val;
}

int modexp(int a , int n){
	if(n == 0) return 1 ;
	if(n == 1) return a; 
	int x = modexp(a,n/2) ;
	x = (x*x) % mod ;
	if(n&1) x = (x*a) % mod ;
	return x ;
}

int32_t main(){
	int t; 
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		string s; 
		cin >> s ;
		int ans = 0 ;
		for(int i = 0 ; i < n ; i++){
			for(int j = i ; j < n ; j++){
				ans += solve(s,i,j) ;
			}
		}
		cout << (ans*modexp(n*(n+1)/2,mod-2)) % mod << endl ;
	}
	return 0 ;
}

