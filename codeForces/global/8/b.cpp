#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int k ; cin >> k ;
	string s = "codeforces" ;
	int a[10] ;
	for(int i = 0 ; i < 10 ; i++){
		a[i] = 1 ;
	}
	int cur = 1 , i = 0 ;
	while(cur < k){
		cur /= a[i] ;
		cur *= (a[i] + 1) ;
		a[i]++ ;
		i = (i+1) % 10 ;
	}
	for(int i = 0 ; i < 10 ; i++){
		cout << string(a[i],s[i]) ;
	}
	return 0 ;
}

