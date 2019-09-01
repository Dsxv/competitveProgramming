#include <bits/stdc++.h>
using namespace std ;

using pii = pair<int,int> ;
using pll = pair<long,long> ;
using umpii = unordered_map<int,int> ;
using mpii = map<int,int> ;

#define f first
#define s second

int32_t main(){
	int count = 0 ;
	string s, t ;
	cin >> s >> t ;
	for(int i = 0 ; i < 3 ; i++) count += s[i] == t[i] ;
	cout << count ; 
	return 0 ;
}

