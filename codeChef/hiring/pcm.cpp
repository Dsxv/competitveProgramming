#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		string s ;
		cin >> s ;
		set<int> st ;
		for(int i = 0 ; i < 3 ; i++) st.insert(s[i]) ;
		cout << (st.size() == 3? "YES\n":"NO\n") << '\n' ;
	}
	return 0 ;
}

