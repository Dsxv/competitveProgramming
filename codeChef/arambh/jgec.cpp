#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	string p = "JGEC" ;
	while(t--){
		int n ; cin >> n;
		string s ;
		cin >> s ;
		int count = 0 ;
		for(int i = 0 ; i < n - 4 + 1 ; i++){
			string temp = "" ;
			for(int j = i ; j < i+4 ; j++){
				temp += s[j] ;
			}
			count += (temp == p) ;
		}
		cout << count << '\n' ;
	}
	return 0 ;
}

