#include <bits/stdc++.h>
using namespace std ;

#define int long long

bool check(string &s , string a , string b){
	if(s.size() < a.size() || s.size() < b.size()) return 0 ;
	bool x = s.substr(0 , a.size()) == a ;
	bool y = b == s.substr(s.size() - b.size() , b.size()) ;
	return x && y ;
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		string s ;
		cin >> s ;
		if(check(s , "2020" , "") || check(s , "202" , "0") || check(s , "20" , "20") || 
				check(s , "2" , "020") || check(s , "" , "2020")){
			cout << "YES\n" ;
		} else {
			cout << "NO\n" ;
		}
	}
	return 0 ;
}

