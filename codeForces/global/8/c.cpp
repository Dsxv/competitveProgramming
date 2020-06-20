#include <bits/stdc++.h>
using namespace std ;

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n ;
	cin >> n ;
	int x  = 0 , y = 0 ;
	vector<pair<int,int>> v ;
	v.push_back({x,y}) ;
	int count = 0 ;
	n++ ;
	while(n--){
		v.push_back({x+1,y}) ;
		v.push_back({x+1,y+1}) ;
		v.push_back({x,y+1}) ;
		x++ , y++ ;
	}
	cout << v.size() << '\n' ;
	for(auto i : v){
		cout << i.first << " " << i.second << '\n' ;
	}
	return 0 ;
}

