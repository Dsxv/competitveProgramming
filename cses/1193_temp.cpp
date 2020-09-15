#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define DB(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin() , (x).end()
#define rall(x) (x).begin() , (x).end()

using namespace std;
const int maxN = 1e3;
char mat[maxN][maxN];
bool vis[maxN][maxN];
pair<int ,int > source;
int  n, m ;

int dx[4] = {-1 , 0 , 1 , 0};
int dy[4] = {0, 1, 0 , -1 };
pair<int ,int > dest;

bool isok(int xx , int yy){
	if( xx >=0 && yy >=0 && xx <n && yy < m && mat[xx][yy] == '.' && !vis[xx][yy]){
		return true;
	}
	return false;
}
bool ok(int xx , int yy){
	if( xx >=0 && yy >=0 && xx <n && yy < m){
		return true;
	}
	return false;
}



vector<char> pos;
int ct =0;
void bfs(){
	queue<pair<int, int>> q;
	q.push(source);
	int ans =0;
	while(!q.empty()){
		pair<int , int>  dd = q.front();
		q.pop();

		vis[dd.fi][dd.se] = true;
		for(int i =0; i<4; ++i){
			if(ok(dd.fi + dx[i] , dd.se + dy[i]) && mat[dd.fi+ dx[i]][dd.se+dy[i]] == 'B'){
				ans= 1;
				break;
			}
			if(isok(dd.fi + dx[i] , dd.se + dy[i])){
				q.push({dd.fi + dx[i] , dd.se + dy[i]});
				ct++;
			}
		}
		if(ans){
			cout << "YES" << "\n";
			cout << ct << "\n";		
			break;
		}
	}

}


int32_t main(){
	IOS;
	cin >>n >>m;
	for(int i =0; i<n; ++i){
		for(int j =0; j<m; ++j){
			cin >> mat[i][j];
		}
	}
	memset(vis , false , sizeof(vis));
	for(int i =0; i<n; ++i){
		for(int j =0; j<m; ++j){
			if( mat[i][j] == 'A'){
				source = {i , j};
			}
			if(mat[i][j] == 'B'){
				dest = {i , j};
			}
		}
	}
	bfs();


	return 0;
}

