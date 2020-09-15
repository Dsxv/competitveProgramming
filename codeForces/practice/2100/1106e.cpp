#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e5 + 10 ;
pair<int,int> a[N] ;
int dp[N][202] ;
const int INF = 1e15 ;
struct reg{
	int w , d , i ;
} ;

class comp{
	public :
		bool operator() (const reg a , const reg b){
			if(a.w != b.w) return a.w > b.w ;
			if(a.d != b.d) return a.d > b.d ;
			return a.i < b.i ;
		}
} ;

int solve(int n , int m ,  int i = 0, int j = 0){
	if(j > m) return INF ;
	if(i > n) return 0 ;
	if(~dp[i][j]) return dp[i][j] ;
	if(a[i].first){
		return dp[i][j] = min(solve(n,m,a[i].second+1,j) + a[i].first ,solve(n,m,i+1,j+1)) ;
	} else {
		return dp[i][j] = solve(n,m,i+1,j) ;
	}
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n , m , k;
	cin >> n >> m >> k ;
	reg val[k] ;
	pair<int,int> start[k] , end[k] ;
	for(int i = 0 ; i < k ; i++){
		int s , t , d , w ;
		cin >> s >> t >> d >> w ;
		val[i].w = w , val[i].d = d , val[i].i = i ;
		start[i] = {s,i} ;
		end[i] = {t+1,i} ;
	}
	sort(start , start + k) ;
	sort(end , end + k) ;
	set<reg , comp> active ;
	int x = 0 , y = 0 ;
	for(int i = 1 ; i <= n ; i++){
		while(x < k && i == start[x].first){
			active.insert(val[start[x].second]) ;
			x++ ;
		}
		while(y < k && i == end[y].first){
			active.erase(val[end[y].second]) ;
			y++ ;
		}
		if(active.size()){
			reg r = *active.begin() ;
			a[i] = {r.w , r.d} ;
		}
	}
	memset(dp , -1 , sizeof(dp)) ;
	cout << solve(n,m) ;
	return 0 ;
}

