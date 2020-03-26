#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1005 ;
pair<int,int> p[N][N] ;
char ch[N][N] ;
int n ;
const int xx[4] = {0,0,1,-1} ;
const int yy[4] = {1,-1,0,0} ;
const char dir[4] = {'L','R','U','D'} ; // dir reversed

bool check(int cx , int cy){
	return cx < n && cx >= 0 && cy < n && cy >= 0 
		&& (ch[cx][cy] == '.') ;
}

void dfs(int cx , int cy , int x , int y, char ch_dir){
	if(check(cx,cy) && p[cx][cy] == {x,y}){
		ch[cx][cy] = ch_dir ;
		for(int i = 0 ; i < 4 ; i++){
			dfs(cx+xx[i],cy+yy[i]) ;
		}
	}
}

void solve(int x, int y){
	if(p[x][y] != {x,y}){
		cout << "INVALID" ;
		exit(0) ;
	}
	ch[x][y] = 'X' ;
	for(int i = 0 ; i < 4 ; i++){
		dfs(x+xx[i],y+yy[i],x,y,dir[i]) ;
	}
}

void solve2(int x , int y){

int32_t main(){
	cin >> n ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> p[i][j].first >> p[i][j].second ;
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			ch[i][j] = '.' ;
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			if(ch[i][j] != '.') continue ;
			if(p[i][j].first != -1){
				int x = p[i][j].first , y = p[i][j].second ;
				if(ch[x][y] != 'X'){
					solve(x,y) ;
				}
				if(ch[i][j] == '.'){
					cout << "INVALID" ;
					return 0 ;
				}
			} else {
				solve2(x,y) ;
			}
		}
	}
	cout << "VALID\n" ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ;j++){
			cout << ch[i][j] << " " ;
		} cout << endl ;
	}

	return 0 ;
}

