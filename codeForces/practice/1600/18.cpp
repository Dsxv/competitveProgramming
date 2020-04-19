#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int k ;
	cin >> k ;
	string s ;
	cin >> s ;
	int n  = s.size() ; 
	int a[n] = {} ;
	a[0] = s[0] == '1' ;
	for(int i = 1 ; i < n ; i++){
		a[i] = a[i-1] + (s[i] == '1') ;
	}
	int sum = 0 ;
	for(int i = 0 ; i < n ; i++){
		if(k == 0 && s[i] == '1') continue ;
		int x = upper_bound(a+i,a+n,(i?a[i-1]:0) + k) - lower_bound(a+i,a+n,(i?a[i-1]:0)+k) ;
		sum += x ;
	}
	cout << sum ;
	return 0 ;
}

