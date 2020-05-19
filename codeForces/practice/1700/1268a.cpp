#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , k ;
	cin >> n >> k ;
	string s ;
	cin >> s ;
	int a[k] ;
	for(int i = 0 ; i < k ; i++){
		a[i] = s[i] - '0' ;
	}
	{
		string t = s.substr(0,k) ;
		for(int i = 0 ; i < n - k ; i++){
			t += s[i%k] ;
		}
		bool found = true ;
		for(int i = 0 ; i < n ; i++) {
			if(t[i] > s[i]) break ;
			if(t[i] < s[i]) {
				found = false ;
				break ;
			}
		}
		if(found) {
			cout << n << endl ;
			cout << t ;
			return 0 ;
		}
	}
	int carry = 1 ;
	for(int i = k - 1; i >= 0 ; i--){
		a[i] += carry ;
		carry = a[i]/10 ;
		a[i] %= 10 ;
	}
	string t = "" ;
	for(int i = 0 ; i < k ; i++) t += (char)(a[i] + '0') ;
	int l = carry + n ;
	if(carry){
		t = "1" + string(k-1,'0') ;
	}
	s = t ;
	for(int i = 0 ; i < n - k ; i++){
		s += t[i%k] ;
	}
	cout << l << endl << s;
	return 0 ;
}

