#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	string s ; cin >> s ;
	stack<char> st ;
	for(auto i : s){
		if(st.empty()) st.push(i) ;
		else {
			if(st.top() == i) st.pop() ;
			else st.push(i) ;
		}
	}
	if(st.size()) cout << "No";
	else cout << "Yes" ;
	return 0 ;
}

