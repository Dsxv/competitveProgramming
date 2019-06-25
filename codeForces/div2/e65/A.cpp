#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ; cin >> n ;
		string s ; cin >> s ;
		bool found = false ;
		for(int i = 0 ; i < s.size() ; i++){
			if(s.size() - i < 11) break ;
			if(s[i] == '8') { cout << "YES"; found = true ;break; }
		}
	if(!found)	cout << "NO" ;
	cout << '\n' ;
	}
 	return 0;
}

