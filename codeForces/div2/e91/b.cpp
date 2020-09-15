#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		string s;
		cin >> s ;
		int a = count(s.begin() , s.end() , 'R') ;
		int b = count(s.begin() , s.end() , 'P') ;
		int c = count(s.begin() , s.end() , 'S') ;
		vector<pair<int,char>> v = {{a,'P'} , {b,'S'} , {c,'R'}} ;
		sort(v.begin() , v.end()) ;
		cout << string(s.size() , v.rbegin()->second) << '\n' ;
	}
	return 0 ;
}

