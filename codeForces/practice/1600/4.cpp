#include <bits/stdc++.h>
using namespace std ;

#define int long long

int xx[4] = {1,-1,0,0} ;
int yy[4] = {0,0,1,-1} ;

int32_t main(){
	int n , m ;
	int x ;
	cin >> n >> m >> x ;
	char ch[n][m] ;
	pair<int,int> start ;
	int count = 0 ;
	for(int i = 0 ; i < n ; i++){
		string s ;	cin >> s ;
		for(int j = 0 ; j < m ; j++){
			ch[i][j] = s[j] ;
			if(ch[i][j] == '.'){
				start = {i,j} ;
				ch[i][j] = 'X' ;
				count++ ;
			}
		}
	}
	count -= x ;
	queue<pair<int,int>> q ;
	q.push(start) ;
	int visited[n][m] = {};
	visited[start.first][start.second] = 1 ;
	while(q.size() && count) {
		int x = q.front().first ;
		int y = q.front().second ;
		count-- ;
		ch[x][y] = '.' ;
		if(!count){
			break ;
		}
		q.pop() ;
		for(int i = 0 ; i < 4 ; i++){
			int xi = xx[i] + x ;
			int yi = yy[i] + y ;
			if(xi >= 0 && xi < n && yi >= 0 && yi < m){
				if(ch[xi][yi] != '#' && !visited[xi][yi]){
					visited[xi][yi] = 1 ;
					q.push({xi,yi}) ;
				}
			}
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++) cout << ch[i][j] ;
		cout << endl ;
	}
	return 0 ;
}

