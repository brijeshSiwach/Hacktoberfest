#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
typedef vector<pl> vpl;
 
#define all(x) x.begin(), x.end()
#define nl cout<<"\n"
#define ar  array

#ifdef LOCAL
#include "../Library/debug.h"
#else 
#define dbg(...) "OM BHOLE"
#endif


vector<ll> prefix_function(vector<ll> &s) {
    int n = (int)s.size();
    vector<ll> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

vector<ll> KMP(vector<ll> &pattern,vector<ll> &text){
    int n = text.size();
    int m = pattern.size();
    // vector<int>Lps(m);
    vector<ll> Lps=prefix_function(pattern);
    // lps_func(pattern,Lps); // This function constructs the Lps array.
    // dbg(Lps);
    // dbg(text);
    // dbg(test);
    vl ans;
    int i=0,j=0;
    while(i<n){
        if(pattern[j]==text[i]){i++;j++;} // If there is a match continue.
    	// dbg(j);
        if (j == m) { 
            // cout<<i - m <<' ';    // if j==m it is confirmed that we have found the pattern and we output the index
            
            if(i-m!=m) {ans.push_back(i-m);}                    // and update j as Lps of last matched character. ;
            j = Lps[j - 1]; 
        } 
        else if (i < n && pattern[j] != text[i]) {  // If there is a mismatch
            if (j == 0)          // if j becomes 0 then simply increment the index i
                i++;
            else
                j = Lps[j - 1];  //Update j as Lps of last matched character
        }
    }
    // dbg(ans);
    return ans;
}

int main(){

    int T=1,TT=1;
    cin>>T;
    while(T--){
        cout<<"Case #"<<TT++<<": ";
        int n,k;
        cin>>n>>k;
        vl a(2*n),b(n);
        for(int i=0;i<n;i++){
        	cin>>a[i];
        }
        for(int j=0;j<n;j++){
        	cin>>b[j];
        }
        for(int i=n;i<2*n;i++){
        	a[i]=a[i-n];
        }
        // dbg(a);
        vector<ll> res=KMP(b,a);
        int sz=res.size();
        // dbg(res);
        int ok=0;
        if(sz>0){
        	ok=1;
        	if(k==0){
        		if(res[0]!=0)ok=0;
        	}
        	if(k==1){
        		if(res[0]==0&&sz==1) ok=0;
        	}
       
    		if(n==2){
    			if(a[0]==b[0]&&a[1]==b[1]&&a[0]!=b[1]){
    				if(k%2) ok=0;
    			}
    			else if(a[0]!=b[0]&&a[1]!=b[1]){
    				if(k%2==0) ok=0;
    			}
    		}
        	
        }
        cout<<(ok?"YES\n":"NO\n");
    }
    return 0;
}

// Case #1: YES
// Case #2: NO
// Case #3: NO
// Case #4: YES
// Case #5: YES
// Case #6: NO
// Case #7: YES
// Case #8: NO
// Case #9: YES
// Case #10: NO
// Case #11: YES
// Case #12: NO
// Case #13: YES
// Case #14: NO
// Case #15: YES
// Case #16: YES
// Case #17: YES
// Case #18: NO
// Case #19: YES
// Case #20: YES
// Case #21: YES
// Case #22: NO
// Case #23: NO
// Case #24: YES
// Case #25: NO