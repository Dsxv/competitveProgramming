#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t; 
	while(t--){
		int n ;
		cin >> n ;
		int two = 0 , three = 0 ;
		while(n%2 == 0) n /= 2  , two++;
		while(n%3 == 0) n /= 3 , three++;
		if(n > 1 || (two > three)){
			cout << -1 << '\n';
			continue ;
		}
		cout << (three + three-two) << '\n' ;
	}
	return 0 ;
}

