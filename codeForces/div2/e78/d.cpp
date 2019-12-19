#include<bits/stdc++.h>
using namespace std;
 
int getparent(int* parent , int x){
    if(parent[x] == x) return x ;
    else parent[x] = getparent(parent,parent[x]) ;
    return parent[x] ;
}
 
bool merge(int x ,int y , int* parent , int* rank){
    int p1 = getparent(parent,x) , p2 = getparent(parent,y) ;
    if(p1 == p2) return true ;
    if(rank[p1] >= rank[p2]){ //p2 is smol
        parent[p2] = parent[p1] ;
        rank[p1] += rank[p2] ;
    }else{ //p1 is smol
        parent[p1] = parent[p2] ;
        rank[p2] += rank[p1] ;
    }
	return false ;
}
 
int main()
{   ios_base :: sync_with_stdio(false) ;
    cin.tie(0) ;
    int n ;
    cin >> n ;
	pair<int,int> p[n] ;
    int parent[n] , rank[n] ;
	for(int i = 0 ; i < n ; i++) parent[i] = i ;
    memset(rank,1,sizeof(rank)) ;
    for(int i = 0 ; i < n ; i++){
		cin >> p[i].first >> p[i].second ;
	} 
	sort(p,p+n) ;
	set<pair<int,int>> s ; // first element is r , second is index of pair
	s.insert({p[0].second,0}) ;
	bool found = true ;
	int count = 0 ;
	for(int i = 1 ; i < n ; i++){
		if(!found) break ;
		while(s.size() && s.begin()->first < p[i].first) {
			s.erase(s.begin()) ;
		}
		for(auto j : s){
			if(p[i].second < p[j.second].second) break ;
			count++ ;
			if(merge(i,j.second,parent,rank)) {
				found = false ;
				break ;
			}else{
				//cout << "joined! : " << i+1 << " " << j.second + 1<< endl ;
			}
		}
		s.insert({p[i].second,i}) ;
	}
	if(count == n-1 && found) cout << "YES" ;
	else cout << "NO" ;
	return 0;
}
 
