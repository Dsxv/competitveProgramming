#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	string s ;
	cin >> s ;
	int n = s.size() ;
	vector<int> v ;
	for(int i = 0 ; i < n ; i++){
		if(s[i] == '('){
			v.push_back(i) ;
		} else {
			if(v.size()){
				if(s[v.back()] == '('){
					v.pop_back() ;
					continue ;
				}
			}
			v.push_back(i) ;
		}
	}
	v.push_back(n) ;
	int prev = -1 ;
	int mx = 0 ;
	for(auto i : v){
		mx = max(mx , i - prev - 1) ;
		prev = i ;
	}
	if(mx == 0){
		cout << 0 << " " << 1 << '\n' ;
		return 0 ;
	}
	int cnt = 0 ;
	prev = -1 ;
	for(auto i : v){
		cnt += mx == (i - prev - 1) ;
		prev = i ;
	}
	cout << mx << " " << cnt ;
	return 0 ;
}

