#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	string s ;
	cin >> s ;
	vector<int> v ;
	for(int i = 0 ; i < s.size() ; i++){
		if(s[i] == '(') v.push_back(i) ;
		else {
			if(v.size() && s[v.back()] == '('){
				v.pop_back() ;
			} else {
				v.push_back(i) ;
			}
		}
	}
	v.push_back((int)s.size()) ;
	int l = -1;
	int ans = 0 ;
	for(int i = 0 ; i < v.size() ; i++){
		ans = max(ans , v[i] - l - 1) ;
		l = v[i] ;
	}
	cout << ans ;
	return 0 ;
}

