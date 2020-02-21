#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e5 + 10 ;
int score[N] ;
int done[N] ;
struct lib{
	int n , sign , count ;
	int score ;
	int id ;
	vector<int> v ;
	lib(int i , int x , int y , int z){
		id = i ;
		n = x ;
		sign = y ;
		count = z ;
		v.clear() ;
	}
} ;

struct ans{
	int id ;
	vector<int> books ;
	ans(int dd , vector<int> book){
		id = dd ;
		books = book ;
	}
} ;

bool check(lib a , lib b){
	return a.sign < b.sign ;
}

bool ok(int a , int b){
	return score[a] > score[b] ;
}

int32_t main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int b , l , d ;
	cin >> b >> l >> d ;
	for(int i = 0 ; i < b ; i++) cin >> score[i] ;
	vector<lib> val ;
	for(int i = 0 ; i < l ; i++){
		int n , m , k ;
		cin >> n >> m >> k ;
		lib temp(i,n,m,k) ;
		val.push_back(temp) ;
		for(int j = 0 ; j < n ; j++){
			int x ; cin >> x ;
			val.back().v.push_back(x) ;
		}
		sort(val[i].v.begin(),val[i].v.end(),ok) ;
	}
	sort(val.begin(),val.end(),check) ;
	int rem = d ;
	vector<ans> vv ;
	for(int i = 0 ; i < l ; i++){
		if(val[i].sign > rem) break ;
		vector<int> tp ;
		for(auto x : val[i].v){
			if(!done[x]){
				done[x] = 1;
				tp.push_back(x) ;
			}
		}
		if((int)tp.size() == 0) continue ;
		int tbooks = min((int)tp.size(),val[i].count*rem) ;
		vector<int> tt(tp.begin(),tp.begin()+tbooks) ;
		ans temp(val[i].id,tt) ;
		int menus = (val[i].n + val[i].count - 1)/val[i].count ;
		rem -= menus ;
		vv.push_back(temp); 
	}
	cout << vv.size() << endl ;
	for(int i = 0 ; i < vv.size() ; i++){
		cout << vv[i].id << " " << vv[i].books.size() << '\n' ;
		for(auto  i : vv[i].books) cout << i << " " ;
		cout << endl ;
	}
	return 0 ;
}
