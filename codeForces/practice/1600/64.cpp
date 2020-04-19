#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , k ;
	cin >> n >> k ;
	map<int,int> mp ;
	for(int i = 1 ; i <= k ; i++){
		if(mp.count(n%i)){
			cout << "No" ;
			return 0 ;
		} 
		mp[n%i] = 1 ;
	}
	cout << "Yes" ;
	return 0 ;
}

