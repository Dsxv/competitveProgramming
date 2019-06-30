#include <bits/stdc++.h>
using namespace std ;

using pii = pair<int,int> ;
using pll = pair<long,long> ;
using umpii = unordered_map<int,int> ;
using mpii = map<int,int> ;

#define f first
#define s second

int32_t main(){
	string s ;
	cin >> s ;
	set<char> se; 
	for(auto i : s) se.insert(i) ;
	if(se.size() == 2){
		int x = 0 ; 
		for(auto i : s) x^= i ;
		if(x == 0) cout << "Yes" ;
		else cout<< "No" ;
	}else{
		cout << "No" ;
	}
	return 0 ;
}

