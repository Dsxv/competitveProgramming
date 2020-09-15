#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t; 
	cin >> t ;
	while(t--){
		string s ;
		cin >> s ;
		int z = count(s.begin() , s.end() , '0') ;
		int sum = 0;
		int even = 0;
		for(auto i : s){
			sum += i-'0' ;
			even += (i-'0')%2 == 0 ;
		}
		if(even > 1 && sum%3 == 0 && z >= 1){
			cout << "red\n" ;
		} else {
			cout << "cyan\n" ;
		}
	}
	return 0 ;
}

