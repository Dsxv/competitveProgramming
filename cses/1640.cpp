#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , x ;
	cin >> n >> x ;
	map<int,int> mp ;
	for(int i = 0 ; i < n ; i++){
		int temp ;
		cin >> temp ;
		if(mp.count(x - temp)){
			cout << i + 1 << " " << mp[x-temp] ;
			return 0 ;
		}
		mp[temp] = i+1;
	}
	cout << "IMPOSSIBLE" ;
	return 0 ;
}

