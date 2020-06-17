#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	string s ;
	cin >> s ;
	vector<char> v ;
	for(auto i : s){
		if(i == '('){
			v.push_back(i) ;
		} else {
			if(v.size()){
				if(v.back() == '('){
					v.pop_back() ;
				}
			}
		}
	}
	if(v.size()){
		cout << s.size() ;
	} else {
		cout << (int)s.size() - 1 ;
	}
	return 0 ;
}

