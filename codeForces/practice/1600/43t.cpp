#include <bits/stdc++.h>
using namespace std ;

#define int long long

char s[105][105] ;

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin >> s[i][j] ;
		}
	}
	vector<int> good ;
	for(int j = 0; j < m ; j++){
		bool ok = true ;
		for(int i = 1 ; i < n ; i++){
			if(s[i][j] < s[i-1][j]){
				if(good.size()){
					bool phew = false ;
					for(auto x : good){
						if(s[i][x] > s[i-1][x]) phew = true ;
					}
					if(!phew) ok = false ;
				} else {
					ok = false ;
				}
			}
		}
		if(ok){
			good.push_back(j) ;
		} 
	}
	cout << m - (int)good.size() ;
	return 0 ;
}

