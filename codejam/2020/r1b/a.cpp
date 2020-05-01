#include <bits/stdc++.h>
using namespace std ;

#define int long long

inline int pw(int x){
	return 1LL<<x ;
}

char getans(char ch , int i){
	if(ch == 'x'){
		if(i > 0) {
			return 'E' ;
		} else {
			return 'W' ;
		}
	} else {
		if(i > 0) {
			return 'N' ;
		} else {
			return 'S' ;
		}
	}
}

int gv(int i){
	return log2(abs(i)) ;
}

void gogogo(){
	int x , y ;
	cin >> x >> y ;
	int xx = 1 ;
	if(x) xx = abs(x)/x ;
	int yy = 1 ;
	if(y) yy = abs(y)/y ;
	x = abs(x) , y = abs(y) ;
	bitset<32> b(x+y) ;
	if(b[0] == 0){
		cout << "IMPOSSIBLE\n" ;
		return ;
	}
	int l = log2(x+y) ;
	set<int> s ;
	s.insert(1) ;
	for(int i = 1 ; i <= l ; i++){
		if(b[i] == 0){
			if(b[i-1] == 0){
				cout << "IMPOSSIBLE\n" ;
				return ;
			} else {
				s.erase(pw(i-1)) ;
				s.insert(-pw(i-1)) ;
				s.insert(pw(i)) ;
			}
		} else {
			s.insert(pw(i)) ;
		}
	}
	vector<int> v(s.begin(),s.end()) ;
	vector<int> ans ;
	bool found = false ;
	for(int i = 0 ; i < pw(v.size()) ; i++){
		vector<int> tmp ;
		for(int j = 0 ; j < v.size() ; j++) {
			if(i&(1LL<<j)) {
				tmp.push_back(v[j]) ;
			}
		}
		if(accumulate(tmp.begin(),tmp.end(),0LL) == x){
			ans = tmp ;
			found = true ;
			break ;
		}
	}
	if(!found) {
		cout << "IMPOSSIBLE\n" ;
		return ;
	}
	string sol(32,'x') ;
	for(auto i : ans) {
		if(sol[gv(i)] != 'x'){
			cout << "IMPOSSIBLE\n" ;
			return ;
		}
		sol[gv(i)] = getans('x',i*xx) ;
		s.erase(i) ;
	}
	for(auto i : s){
		if(sol[gv(i)] != 'x') {
			cout << "IMPOSSIBLE\n" ;
			return ;
		}
		sol[gv(i)] = getans('y',i*yy) ;
	}
	for(auto i : sol){
		if(i != 'x') cout << i ;
	}
	cout << '\n' ;
}

int32_t main(){
	int t ;
	cin >> t ;
	for(int i = 1 ; i <= t ; i++){
		cout << "Case #" << i << ": ";
		gogogo() ;
	}	
	return 0 ;
}


