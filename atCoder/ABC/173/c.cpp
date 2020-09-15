#include <bits/stdc++.h>
using namespace std ;

#define int long long
int h , w , k ;
int32_t main(){
	cin >> h >> w >> k ;
	vector<vector<char>> ch(h,vector<char>(w)) ;
	for(int i = 0 ; i < h ; i++){
		for(int j = 0 ; j < w ; j++){
			cin >> ch[i][j] ;
		}
	}
	int cnt = 0 ;
	for(int i = 0 ; i < (1LL<<h) ; i++){
		for(int j = 0 ; j < (1LL<<w) ; j++){
			auto tp = ch ;
			for(int k = 0 ; k < h ; k++){
				if((1LL<<k)&i){
					for(int x = 0 ; x < w ; x++){
						tp[k][x] = '.' ;
					}
				}
			}
			for(int k = 0 ; k < w ; k++){
				if((1LL<<k)&j){
					for(int x = 0 ; x < h ; x++){
						tp[x][k] = '.' ;
					}
				}
			}
			int val = 0 ;
			for(auto x : tp){
				val += count(x.begin() , x.end() , '#') ;
			}
			cnt += (val == k) ;
		}
	}
	cout << cnt ;
	return 0 ;
}
