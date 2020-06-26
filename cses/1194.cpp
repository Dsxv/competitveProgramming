#include <bits/stdc++.h>
using namespace std ;

#define int long long

int xx[4] = {0,0,-1,1} ;
int yy[4] = {-1,1,0,0} ;
char mov[4] = {'L' , 'R' , 'U' , 'D'} ;

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	char ch[n][m] ;
	vector<int> visited[n][m] ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++) 
			cin >> ch[i][j] ;
	}
	queue<vector<int>> q ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(ch[i][j] == 'M'){
				q.push({i,j,0}) ;
				visited[i][j] = {i,j,0} ;
			}
		}
	}
	pair<int,int> target ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(ch[i][j] == 'A'){
				if(i == 0 || i == n - 1 || j == 0 || j == m - 1){
					cout << "YES\n 0" ;
					return 0 ;
				}
				q.push({i,j,1}) ;
				visited[i][j] = {i,j,0} ;
				target = {i,j} ;
			}
		}
	}
	auto ok = [&](int x , int y) -> bool{
		return x >= 0 && y >= 0 && x < n && y < m ;
	} ;
	pair<int,int> ans(-1,-1) ;
	while(q.size()){
		auto v = q.front() ;
		int x = v[0] , y = v[1] , t = v[2] ;
		if(x == 0 || y == 0 || x == n - 1 || y == m -1){
			if(ch[x][y] == '.' && t){
				ans = {x,y} ;
				break ;
			}
		}
		q.pop() ;
		for(int i = 0 ; i < 4 ; i++){
			int xi = x + xx[i] , yi = y + yy[i] ;
			if(ok(xi, yi) && visited[xi][yi].empty() && ch[xi][yi] != '#'){
				visited[xi][yi] = {x,y,i} ;
				q.push({xi,yi,t}) ;
			}
		}
	}
	if(~ans.first){
		vector<char> v ;
		while(ans != target){
			auto tp = visited[ans.first][ans.second] ;
			v.push_back(mov[tp[2]]) ;
			ans = {tp[0],tp[1]} ;
		} // moves to n - 1 honge na
		reverse(v.begin() , v.end()) ;
		cout << "YES\n" ;
		cout << v.size() << '\n' ;
		for(auto i : v) cout << i ;
	} else {
		cout << "NO" ;
	}
	return 0 ;
}

