#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n; 
	cin >> n ;
	map<string,int> mp ;
	while(n--){
		string s; 
		cin >> s ;
		mp[s]++ ;
	}
	cout << "AC x " << mp["AC"] << endl ;
	cout << "WA x " << mp["WA"] << endl ;
	cout << "TLE x " << mp["TLE"] << endl ;
	cout << "RE x " << mp["RE"] << endl ;
	return 0 ;
}

