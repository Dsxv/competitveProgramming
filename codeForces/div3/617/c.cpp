#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(int* a, int n, int x){
	map<int,int> mp ;
	int s = 0 ;
	int ans = n + 1 ;
	mp[0] = -1 ;
	pair<int,int> tp ;
	for(int i = 0 ; i < n ; i++){
		s += a[i] ;
		//cout << s << " " ;
		if(mp.count(s)) {
			if((i - mp[s]) < ans) {
				tp.first = mp[s]+1 ,
				tp.second = i ;
				ans = i - mp[s] ;
			}
		}
		mp[s] = i ;
	}
	if(ans == (n+1)) {
		cout << -1 << '\n' ;
		return ;
	}
	else {
		cout << tp.first + 1 << " " << tp.second + 1 << endl ;
	}
}

  int32_t main(){
	int t; 
	cin >> t ;
	while(t--){
		int n ;
		cin >> n; 
		int a[n] ;
		map<char,int> mp = {
			{'U',INT_MAX} , {'D' , -INT_MAX} , {'L' , 1} , {'R' , -1}
		} ;
		string s; 
		cin >> s ;
		for(int i = 0 ; i < n ; i++){
			a[i] = mp[s[i]] ;
		}
		solve(a,n,0) ;
	}

	return 0 ;
}

