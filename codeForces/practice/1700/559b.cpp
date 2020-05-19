#include <bits/stdc++.h>
using namespace std ;

#define int long long

string solve(string s){
	if(s.size()%2) return s; 
	string a = s.substr(s.size()/2) ;
	string b = s.substr(0,s.size()/2) ;
	a = solve(a);
	b = solve(b) ;
	if(a > b) swap(a,b) ;
	return a + b ;
}
//hmm
int32_t main(){
	string s , t ;
	cin >> s >> t ;
	swap(s,t) ;
	if(solve(s) == solve(t)){
		cout << "YES" ;
	} else {
		cout << "NO" ;
	}
	return 0 ;
}

