#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , x ;
	cin >> n >> x ;
	string s ;
	cin >> s; 
	for(auto i : s){
		if(i == 'o') x++ ;
		else x-- ;
		x = max(0LL , x) ;
	}
	cout << x ;
	return 0 ;
}

