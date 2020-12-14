#include <bits/stdc++.h>
using namespace std ;

#define int long long

map<int , int> ladder , snake ;
vector<int> solveSnake()

int32_t main(){
	int n , m , q ;
	cin >> n >> m >> q ;
	for(int i = 0 ; i < n ; i++){
		cin >> v[i].first >> v[i].second ;
		if(v[i].first > v[i].second){
			snake[v[i].first] = v[i].second ;
		} else {
			ladder[v[i].first] = v[i].second ;
		}
	}
	vector<int> ans = solveSnake(n , m , q , ladder , snake) ;
	return 0 ;
}

