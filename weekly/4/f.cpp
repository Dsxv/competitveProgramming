#include <bits/stdc++.h>
using namespace std ;

#define int long long


bool isv(char& ch){
	if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
		return true ;
	else return false ;
}

int check(int x , string&s ){
	int n = s.size() ;
	int c = 0 , v = 0 ;
	int ans = 0 ;
	for(int i = 0 ; i < x ; i++){
		if(isv(s[i])) v++ ;
		else c++ ;
	}
	if(v <= 2*c) ans++ ;
	//if(ans && x == 6) cout << "yes" ;
	for(int i = x ; i < n ; i++){
		if(isv(s[i-x])){
				v-- ;
		} else {
				c-- ;
		}
		if(isv(s[i])) v++ ; else c++ ;
		if(v <= 2*c){
			ans++ ;
			//if(x == 6) cout << i << " " ;
		}
	}
	return ans ;
}

int32_t main(){
	string st ;
	cin >> st ;
	for(int i = 0 ; i < (int)st.size() ; i++) {
		st[i] = tolower(st[i]) ;
	}
	int n = st.size() ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++){
		if(isv(st[i])) a[i] = -1 ;
		else a[i] =2 ;
	}
	int pref[n+1] ;
	pref[0] = 0 ;
	for(int i = 0 ; i < n ; i++) pref[i+1] = a[i] + pref[i] ;
	stack<int> s; // stores index
	s.push(0) ;
	for(int i = 1 ; i <= n ; i++){
		if(pref[s.top()] > pref[i]) s.push(i) ;
	}
	int ans = 0 ;
	for(int i = n ; i > 0 ; i--){
		if(s.size() == 0) break ;
		if(i <= s.top()) s.pop() ;
		while(s.size() && (pref[i] - pref[s.top()]) >= 0){
			ans = max(ans,(i-s.top())) ;
			s.pop() ;
		}
	}
	if(ans == 0){
		cout << "No solution" ;
	} else {
		cout << ans <<" " << check(ans,st) ;
	}
	return 0 ;
}

