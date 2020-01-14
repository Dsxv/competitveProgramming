#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 515 ;

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n , m , a , r ;
	cin >> n >> m >> a >> r ;
	map<int,int> mp[n] , G[n] ;
	for(int i = 0 ; i < m ; i++){
		int f , s ;
		cin >> f >> s ;
		f-- , s-- ;
		mp[f][s] = 1 ;
		mp[s][f] = 1 ;
	}
	vector<vector<pair<int,int>>> v ;
	for(int i = 0 ; i < n ; i++){
		vector<int> p ;
		for(auto j : mp[i]){
			p.push_back(j.first) ;
		}
		for(int j = 0 ; j < p.size() ; j++){
			for(int k = j + 1 ; k < p.size() ; k++){
				int x = p[j] , y = p[k] ;
				if(mp[x].count(y)){
					if(G[x].count(y) && G[x].count(i)) continue ;
					if(G[y].count(x) && G[y].count(i)) continue ;
					G[i][x] = 1 ; G[x][i] = 1 ;
					G[i][y] = 1 ; G[y][i] = 1 ;
					G[x][y] = 1 ; G[y][x] = 1 ;
					v.push_back({{x,y},{x,i}}) ;
				}
			}
		}
	}
	for(int i = 0 ; i < n ; i++){
			for(auto j : mp[i]){
				if(G[i].count(j.first)) continue ;
				vector<pair<int,int>> temp = {{i,j.first}} ;
				G[i][j.first] = 1 ; G[j.first][i] = 1 ;
				v.push_back(temp) ;
			}
	}
	cout << v.size() << '\n' ;
	for(auto i : v){
		cout << 1 << " " << i.size() << " " ;
		for(auto j : i) cout << j.first + 1<< " " << j.second + 1<< " " ;
		cout << '\n' ;
	}
	return 0 ;
}

