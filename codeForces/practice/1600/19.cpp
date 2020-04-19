#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	string x , y ;
	cin >> x >> y ;
	int n = x.size() ;
	int s[n]  ;
	for(int i = 0 ; i < n ; i++){
		s[i] = x[i] - 'a' ;
	}
	int carry = 1 ;
	for(int i = n - 1 ; i >= 0 ; i--){
		s[i] = (s[i] + carry);
		carry = s[i]/26 ;
		s[i] %= 26 ;
	}
	if(carry){
		cout << "No such string" ;
	}
	for(int i = 0 ; i < n ; i++){
		x[i] = 'a' + s[i] ;
	}
	if(x < y){
		cout << x ;
	} else {
		cout << "No such string" ;
	}
	return 0 ;
}

