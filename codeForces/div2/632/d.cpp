#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , k ;
	cin >> n >> k ;
	int K = k ;
	string s ;
	cin >> s ;
	vector<vector<int>> v ;
	int nodes = 0 , level =  0 ;
	while(true){
		vector<int> temp ;
		for(int i = 0 ; i < s.size() - 1 ; i++){
			if(s[i] == 'R' && s[i+1] == 'L'){
				temp.push_back(i) ;
			}
		}
		if(temp.size() == 0){
			break ;
		}
		for(auto i : temp){
			swap(s[i] , s[i+1]) ;
		}
		v.push_back(temp) ;
		nodes += temp.size() ; 
		level++ ;
	}
	if(nodes < k || level > k){
		cout << -1 ;
		//cout << level << " " << nodes << endl ;
		return 0 ;
	}
	int i = 0 , j = 0 ;
	int count = 0 ;
	while((level-i) != k){
		cout << 1 << " " << v[i][j] + 1 << '\n' ;
		k-- ; j++ ; count++ ;
		if(j == (int)v[i].size()){
			j = 0 ; 
			i++ ;
		}
		if(i == (int)v.size()){
			assert(count == K) ;
			return 0 ;
		}
	}
	for(int ii = i ; ii < v.size() ; ii++){
		cout << (int)v[ii].size() - j << " " ;
		for(int x = j ; x < v[ii].size() ; x++){
			cout << v[ii][x] + 1 << " " ;
		}
		count++ ; 
		cout << '\n' ;
		j = 0 ;
	}
	assert(count == K) ;
	return 0 ;
}
