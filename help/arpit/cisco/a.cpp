#include <bits/stdc++.h>
using namespace std ;

#define int long long

vector<int> solve(int x , int y , int z){
	z /= 10 ;
	pair<int , int> ans ;
	ans.first = INT_MAX ;
	for(int i = 0 ; i <= 4 ; i++){
		for(int j = 24 - i ; j >= 0 ; j--){
			if(z == (i * x  + y * j)){
				if(ans.first > (i + j)){
					ans.first = (i + j) ;
					ans.second = i ;
				}
			}
		}
	}
	return {ans.second , ans.first - ans.second} ;
}


int32_t main(){
	int x , y , z ;
	cin >> x >> y >> z ;
	vector<int> v = solve(x,y,z) ;
	cout << v[0] << "\n" << v[1] << endl ;
	return 0 ;
}

