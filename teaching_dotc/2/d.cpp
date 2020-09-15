#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	bool a[26] = {} ;
	int k ; 
	string s; 
	cin >> k >> s ;
	for(auto i : s) a[i-'a'] = 1;
	if(count(a,a+26,true) < k){
		cout << "NO" ;
		return 0 ;
	}
	cout << "YES" ;
	int prev = -1 ;
	for(auto i : s){
		if(a[i-'a'] && k){
			cout << '\n' ;
			a[i-'a'] = 0 ;
			k-- ;
		}
		cout << i ;
	}
	return 0 ;
}

