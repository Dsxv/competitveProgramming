#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	string s[n+1] ;
	s[0] = "";
	for(int i = 1 ; i <= n ; i++){
		string st ;
		cin >> st ;
		s[i] = st.substr(1) ;
	}
	int cur = 1;
	int ans[n+1] ;
	set<int> sett ;
	for(int i = 0 ; i <= n ; i++){
		ans[i] = s[i].size() ;
		sett.insert(i) ;
	}
	for(int j = 0 ; ; j++){
		if(sett.size() == 0) break ; 
		vector<int> toe ;
		set<int> ok ;
		for(auto i : sett){
			if(ans[i] <= (j+1)) toe.push_back(i) ;
		}
		for(auto i : toe) sett.erase(i) ;
	}
	for(int i = 1 ; i <= n ; i++){
		cout << "#" ;
		for(int j = 0 ; j < ans[i] ; j++) cout << s[i][j] ;
		cout << endl ;
	}
	return 0 ;
}

