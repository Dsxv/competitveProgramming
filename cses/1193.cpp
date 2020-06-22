#include <bits/stdc++.h>
using namespace std ;

#define int long long

int xx[4] = {0,0,1,-1} ;
int yy[4] = {1,-1,0,0} ;
char mov[4] = {'R','L','D','U'} ;

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	char ch[n][m] ;
	int visited[n][m] = {} ;
	pair<int,int> start , end ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin >> ch[i][j] ;
			if(ch[i][j] == 'A') start = {i,j} ;
			if(ch[i][j] == 'B') end = {i,j} ;
		}
	}
	queue<pair<int,int>> q ;
	map<pair<int,int> , vector<int>> mp ;
	auto ok = [&](int x , int y) -> bool{
		return x >= 0 && x < n && y >= 0 && y < m ;
	} ;
	q.push(start) ;
	visited[start.first][start.second] = 1 ;
	while(q.size()) {
		auto [x,y] = q.front() ;
		if(q.front() == end){
			break ;
		}
		q.pop() ;
		for(int i = 0 ; i < 4 ; i++){
			int xi = x + xx[i] ;
			int yi = y + yy[i] ;
			if(ok(xi,yi) && !visited[xi][yi] && ch[xi][yi] != '#') {
				q.push({xi,yi}) ;
				visited[xi][yi] = 1 ;
				mp[{xi,yi}] = {x,y,i} ;
			}
		}
	}
	if(mp.count(end)){
		vector<char> v ;
		while(end != start){
			vector<int> tp = mp[end] ;
			v.push_back(mov[tp[2]]) ;
			end = {tp[0],tp[1]} ;
		}
		cout << "YES\n" ;
		cout << v.size() << endl ;
		reverse(v.begin() , v.end()) ;
		for(auto i : v) cout << i ;
	} else {
		cout << "NO" ;
	}
	return 0 ;
}

