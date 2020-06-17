#include <bits/stdc++.h>
using namespace std ;

#define int long long

int xx[4] = {  1 , -1 , 0 , 0} ;
int yy[4] = { 0 , 0 , 1 , -1} ;

struct val{
	int x , y , l , r ;
	val(int x , int y , int l ,int  r){
		this->x = x ;
		this->y = y ;
		this->l = l ;
		this->r = r ;
	}
	val(){
	}
} ;

int32_t main(){
	int n , m , r , c , x , y ;
	cin >> n >> m >> r >> c >> x >> y ;
	char ch[n][m] ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin >> ch[i][j] ;
		}
	}
	r-- , c-- ;
	pair<int,int> visited[n][m] = {} ;
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < m ;j++) visited[i][j] = {-1,-1} ;
	}
	queue<val> q ;
	q.push(val(r , c , x , y)) ;
	visited[r][c] = {x,y} ;
	while(q.size()){
		auto tp = q.front() ;
		q.pop() ;
		for(int i = 0 ; i < 4 ; i++){
			int xi  = tp.x + xx[i] , yi = tp.y + yy[i] ;
			int li = tp.l - (i==3) ;
			int ri = tp.r - (i==2) ;
			if(li < 0) continue ;
			if(ri < 0) continue ;
			if(xi < n && xi >= 0 && yi < m && yi >= 0 && ch[xi][yi] != '*'){
				if(visited[xi][yi].first == -1){
					q.push(val(xi , yi , li , ri)) ;
					visited[xi][yi] = {li, ri} ;
				} else {
					pair<int,int> p = visited[xi][yi] ;
					if(p.first >= li && p.second >= ri){
						continue ;
					} else {
						visited[xi][yi] = {max(p.first , li) , max(p.second , ri)} ;
						q.push(val(xi , yi , visited[xi][yi].first , visited[xi][yi].second)) ;
					}
				}
			}
		}
	}
	int count = 0 ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			count += visited[i][j].first != -1 ;
		}
	}
	cout << count ;
	return 0 ;
}

