#include <bits/stdc++.h>
using namespace std ;

#define int long long
map<int , string> mp ;
void init(){
	mp[0] = "zero" ;
	mp[1] = "one" ; mp[2] = "two" ; mp[3] = "three" ; mp[4] = "four" ;
	mp[5] = "five" ; mp[6] = "six" ; mp[7] = "seven" ; mp[8] = "eight" ;
	mp[9] = "nine" ; mp[10] = "ten" ; mp[11] = "eleven" ; mp[12] = "twelve" ;
	mp[13] = "thirteen" ; mp[14] = "fourteen" ; mp[15] = "fifteen" ;
	mp[16] = "sixteen" ; mp[17] = "seventeen" ; mp[18] = "eighteen" ;
	mp[19] = "nineteen" ; mp[20] = "twenty" ; mp[30] = "thirty" ; mp[40] = "forty" ;
	mp[50] = "fifty" ; mp[60] = "sixty" ; mp[70] = "seventy" ; mp[80] = "eighty" ;
	mp[90] = "ninety" ; mp[100] = "hundred" ;
}


string convertWord(int x){
	if(x > 100){
		return "greater 100" ;
	}
	if(x <= 20) return mp[x] ;
	else if(x%10 == 0) return mp[x] ;
	else return mp[(x/10)*10] + mp[x%10] ;
}

int countVowel(string s){
	int ans = 0 ;
	for(auto i : s){
		ans += i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u' ;
	}
	return ans ;
}

int32_t main(){
	init() ;
	int n ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
	}
	int d = 0 ;
	for(int i = 0 ; i < n ; i++){
		string s = convertWord(a[i]) ;
		d += countVowel(s) ;
	}
	int ans = 0 ;
	map<int,int> mp ;
	for(int i = 0 ; i < n ; i++){
		ans += mp[d - a[i]] ;
		mp[a[i]]++ ;
	}
	cout << convertWord(ans) ;
	return 0 ;
}

