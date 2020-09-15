#include <bits/stdc++.h>
using namespace std ;

int ans ;

string val(string s, string t) 
{ 

    string ans = "" ;
    int cval = 0; 
    int size1 = s.size() ;
	int size2 = t.size(); 
    int dval = size1 - size2; 
  
    for (int i= size2 - 1; i >= 0; i--) { 
        int substraction = (s[i+dval]-'0') ;
		substraction -= t[i] - '0' ;
		substraction -= cval ;
        if (substraction < 0){ 
            substraction += 10; 
            cval = 1; 
        } else {
            cval = 0; 
		}
        ans += (char)(substraction + '0') ;
    } 
  
    for (int i= size1 - size2 -1; i >= 0; i--) { 
        if (s[i]=='0' && cval) { 
            ans += '9' ; 
        } else { 
        	int substraction = ((s[i]-'0') - cval); 
        	if (i>0 || substraction>0) { 
            	ans += (char)(substraction+'0');
			}
        	cval = 0;
		}
    } 
    reverse(ans.begin(), ans.end()); 
    return ans; 
} 

void inc(string &a){
	int l = a.size() ;
	int carry = 1 ;
	for(int i = l - 1 ; i >= 0 ; i--){
		int val = a[i] - '0' ;
		int newval  = (val + carry) % 10 ;
		carry = (val + carry) / 10 ;
		a[i] = (char)(newval + '0') ;
	}
	if(carry){
		a = "1" + a ;
	}
}

bool ok(string s){
	int l = (int)s.size() ;
	for(int i = 0 ; i < l ; i++){
		if(s[i] != s[l-i-1]) return false ;
	}
	return true ;
}

bool valid(string &s){
	int h = (s[0]-'0')*10 + (s[1] - '0') ;
	int m = (s[2] -'0')*10 + (s[3] - '0') ;
	int sec = (s[4] - '0')*10 + (s[5] - '0') ;
	return h >= 0 && h <= 23 && m >= 0 && m <= 59 && sec >= 0 && sec <= 59 ;
}

void solve(string& a , int i = 0 , string cur  = ""){
	if(i == 6){
		if(valid(cur)){
			ans += ok(a + cur) ;
		}
		return ;
	}
	for(char j = '0' ; j <= '9' ; j++){
		solve(a , i + 1 , cur + j) ;
	}
}

int32_t main(){
	string a , b ;
	cin >> a >> b ;
	int x = stoi(val(b,a)) ;
	cout << 236*(x+1) ;
	return 0 ;
}

