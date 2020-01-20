#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t;
	cin >> t ;
	while(t--){
		string s ;
		cin >> s ;
		if(s.size()%2){
			cout << -1 << endl ;
			continue ;
		} 
		stack<char> st ;
		for(auto i : s){
			if(i == '}' && st.size()){
				if(st.top() == '{') st.pop() ;
			} else {
				st.push(i) ;
			}
		}
		vector<char> v ;
		while(st.size()) {v.push_back(st.top()) ; st.pop() ;}
		reverse(v.begin(),v.end()) ;
		int count = 0 ;
		for(int i = 0 ; i < v.size() ; i++){
			count += (v[i] == '}') ;
		}
		for(int i = count ; i < v.size() ; i++){
			assert(v[i] == '{') ;
		}
		cout << count/2 + ((int)v.size() - count)/2 + (count%2) << '\n';
	}

	return 0 ;
}

