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
			if(v.size() && s[v.back()] == '('){
				v.pop_back() ;
			} else {
				v.push_back(i) ;
			}
		}
	}
	v.push_back(n) ;
	int mx = 0 ;
	int prev = -1 ;
	for(auto i : v){
		mx = max(i - prev - 1, mx) ;
		prev = i ;
	}
	prev = -1 ;
	if(mx == 0){
		cout << "0 1" ;
		return 0 ;
	}
	prev = -1 ;
	int cnt = 0 ;
	for(auto i : v){
		cnt += mx == (i-prev-1) ;
		prev = i ;
	}
	cout << mx << " " << cnt ;
	return 0 ;
}

