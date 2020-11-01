#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 3e5 + 10 ;
pair<int,int> row[N] , col[N] ;
map<pair<int,int> , int> mp ;
int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n , m , k ;
	cin >> n >> m >> k ;
	for(int i = 0 ; i < N ; i++){
		row[i].second = col[i].second = i ;
	}
	for(int i = 0 ; i < k ; i++){
		int x , y ;
		cin >> x >> y ;
		row[x].first++ , col[y].first++ ;
		mp[{x,y}]++ ;
	}
	sort(row , row + N , greater<pair<int,int>>()) ;
	sort(col , col + N , greater<pair<int,int>>()) ;
	vector<int> f , s ;
	int val = row[0].first + col[0].first ;
	for(int i = 0 ; i < N ; i++){
		if(row[0].first == row[i].first){
			f.push_back(row[i].second) ;
		} else {
			break ;
		}
	}
	for(int i = 0 ; i < N ; i++){
		if(col[0].first == col[i].first){
			s.push_back(col[i].second) ;
		}
	}
	for(auto i : f){
		for(auto j : s){
			if(mp.count({i,j})){
				mp.erase({i,j}) ;
			} else {
				cout << val ;
				return 0 ;
			}
		}
	}
	cout << val - 1 ;
	return 0 ;
}

