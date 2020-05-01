#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	if(n&1){
		cout << ":(" ;
		return 0 ;
	}
	string s ;
	cin >> s ;
	int a = s.size() / 2 ;
	int b = a ;
	for(auto i : s){
		if(i == '(') a-- ;
		if(i == ')') b-- ;
	}
	for(auto &i : s){
		if(i == '?' && a) {
			i = '(' ;
			a-- ;
		}
		if(i == '?' && b){
			i = ')' ;
			b-- ;
		}
	}
	int cnt = 0 ;
	for(int i = 0 ; i < s.size() ; i++){
		if(s[i] == '(') cnt++ ;
		else cnt-- ;
		if(i == (int)s.size() - 1){
			if(cnt == 0) {
				cout << s ;
				return 0 ;
			}
		}
		if(cnt <= 0){
			cout << ":(" ;
			return 0 ;
		}
	}
	cout << ":(" ;
	return 0 ;
}

