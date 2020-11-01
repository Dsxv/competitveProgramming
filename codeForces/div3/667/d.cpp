#include <bits/stdc++.h>
using namespace std ;

#define int long long

int ok(string &s , int n){
	int cnt = 0 ;
	for(auto i : s) cnt += i - '0' ;
	return cnt <= n ;
}

void increment(string &s){
	int carry = 1 ;
	for(int i = s.size() - 1 ; i >= 0 ; i--){
		int cur = (s[i] - '0') + carry ; cur %= 10 ;
		s[i] = (char) ( cur + '0') ;
		carry += (s[i] - '0') ;
		carry /= 10 ;
	}
	if(carry){
		s = "1" + s ;
	}
}

int val(string s , int n){
	//cout << s << endl ;
	char x = s.back() ;
	for(char i = s.back() ; i <= '9'; i++){
		s.back() = i ;
		if(ok(s , n)){
			return i - x ; 
		}
	}
	s.pop_back() ;
	int addval = ( 10 - (x-'0') ) % 10 ; 
	if(s.size()){
		for(int i = 0 ; i < addval ; i++)
			increment(s) ;
	} else {
		s = "1" ;
	}
	return val(s , n)*10 + addval ;
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		string s;
		int n ;
		cin >> s >> n ;
		cout << val(s , n) << '\n' ;
	}
	return 0 ;
}

