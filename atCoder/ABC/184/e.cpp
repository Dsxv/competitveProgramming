#include <bits/stdc++.h>
using namespace std ;

#define int long long
int h , w ;

int dx[4] = {0 , 0 , -1 , 1} ;
int dy[4] = {-1 , 1 , 0 , 0} ;

int linear(int x , int y){
	return y + x * w ;
}

int32_t main(){
	cin >> h >> w ;
	char ch[h][w] ;
	vector<pair<int,int>> v[26] ;
	int sx , sy , gx , gy ;
	for(int i = 0 ; i < h ; i++){
		for(int j = 0 ; j < w ; j++){
			cin >> ch[i][j] ;
			if(ch[i][j] >= 'a' && ch[i][j] <= 'z'){
				v[ch[i][j] - 'a'].push_back({i , j}) ;
			}
			if(ch[i][j] == 'S'){
				sx = i , sy = j ;
			}
			if(ch[i][j] == 'G'){
				gx = i , gy = j ;
			}
		}
	}
	bool aval[26] = {} ;
	bool visited[h][w] = {} ;
	deque<pair<int , int>> q ;
	q.push_back({linear(sx , sy) , 0}) ;
	visited[sx][sy] = 1 ;
	while(q.size()){
		int cur = q.front().first , dis = q.front().second ;
		int x = cur / w , y = cur % w ;
		q.pop_front() ;
		if(x == gx && y == gy){
			cout << dis ;
			return 0 ;
		}
		char c = ch[x][y] ;
		if(c >= 'a' && c <= 'z' && !aval[c - 'a']){
			for(auto i : v[c-'a']){
				if(!visited[i.first][i.second]){
					q.push_back({linear(i.first , i.second) , dis + 1}) ;
					visited[i.first][i.second] = 1 ;
				}
			}
			aval[c - 'a'] = 1 ;
		}

		for(int i = 0 ; i < 4 ; i++){
			int cx = x + dx[i] , cy = y + dy[i] ;
			if(cx >= 0 && cx < h && cy >= 0 && cy < w && !visited[cx][cy] && ch[cx][cy] != '#'){
				q.push_back({linear(cx , cy) , dis + 1}) ;
				visited[cx][cy] = 1 ;
			}
		}
	}
	cout << -1 ;
	return 0 ;
}

