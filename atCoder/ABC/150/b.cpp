#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	string s ;
	cin >> n >> s ;
	int count = 0 ;
	for(int i = 0 ; i <= n - 3 ; i++){
		string k = "" ;
		for(int j = i ; j < i+3 ; j++){
			k += s[j] ;
		}
		if(k == "ABC") count++ ;
	}
	cout <<  count ;
	return 0 ;
}

