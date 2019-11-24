#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	map<string,int> mp = {{"SUN",0}, {"MON",1}, {"TUE",2},
				{"WED",3}, {"THU",4}, {"FRI",5}, {"SAT",6}} ;
	string s ;
	cin >> s ;
	cout << 7-mp[s] ;
	return 0 ;
}

