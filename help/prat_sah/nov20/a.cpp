#include <bits/stdc++.h>
using namespace std ;

#define int long long

vector<string> braces(vector<string> &values){
	vector<string> ans ;
	map<char , char> mp ;
	mp['}'] = '{' ;
	mp[')'] = '(' ;
	mp[']'] = '[' ;
	for(auto s : values){
		stack<char> st ;
		for(auto i : s){
			if(i == '{' || i == '[' || i == '(') st.push(i) ;
			else {
				if(st.size() && mp[i] == st.top()){
					st.pop() ;
				} else {
					st.push('1') ;
					break ;
				}
			}
		}
		if(st.size()) ans.push_back("NO") ;
		else ans.push_back("YES") ;
	}
	return ans ;
}

int32_t main(){
	int n ; cin >> n ;
	vector<string> values(n) ;
	for(auto &i : values) cin >> i ;
	vector<string> ans = braces(values) ;
	for(auto i : ans) cout << i << '\n' ;
	return 0 ;
}

