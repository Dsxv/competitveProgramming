#include <bits/stdc++.h>
using namespace std ;

void setans(vector<pair<char,int>>* v , string* s , int n , int m){
	for(int j = 0 ; j < m ; j++){
		v[j].push_back({s[0][j],1}) ;
		for(int i = 1 ; i < n ; i++){
			if(v[j].back().second == s[i][j]){
				v[j].back().second++;
			}else{
				v[j].push_back({s[i][j],1}) ;
			}
		}
	}
}

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	string s[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> s[i] ;
	}
	vector<pair<char,int>> v[m] ;
	setans(v,s,n,m) ;
	int count = 0 ;
	for(int j = 0 ;  j < m ; j++){
		if(j == 0 || j == m-1){
			for(int i = 0 ; i < verts[j].size() - 2 ; i++){
				if(verts[j][i+1].first = verts
				if(verts[j][i+1] <= verts[j][i] && verts[j][i+1] <= verts[j][i+2]){
					count++ ; verts[j][i+2] -= verts[j][i+1] , verts[j][i+1] = 0 ;
				}
			}
		}else{   
			for(int i = 0 ; i < verts[j].size() - 2 ; i++){
				if(i != 0 && i != verts[j].size() -2 ) continue ;
                  if(verts[j][i+1] <= verts[j][i] && verts[j][i+1] <= verts[j][i+2]){
                      count++ ; verts[j][i+2] -= verts[j][i+1] , verts[j][i+1] = 0 ;
                  }
             }
		}
	}
	cout << count << '\n' ;
	return 0 ;
}

