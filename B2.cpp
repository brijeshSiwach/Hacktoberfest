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

const int M=1e9+7;

int main(){

    int T=1,TT=1;
    cin>>T;
    while(T--){
        cout<<"Case #"<<TT++<<": ";
        int n,q;
        cin>>n;
        vl a(n),b(n);
        for(int i=0;i<n;i++){
        	cin>>a[i]>>b[i];
        }
        cin>>q;
        vl x(q),y(q);
        for(int i=0;i<q;i++){
        	cin>>x[i]>>y[i];
        }
        ll sq_a=0,sq_b=0,s_a=0,s_b=0,sq_x=0,sq_y=0,s_x=0,s_y=0;
        for(int i=0;i<n;i++){
        	sq_a+=((ll)a[i]*a[i]%M);
            sq_a=(sq_a+M)%M;
        	sq_b+=((ll)b[i]*b[i]%M);
            sq_b=(sq_b+M)%M;
        	s_a+=(ll)a[i]%M;
            s_a=(s_a+M)%M;
        	s_b+=(ll)b[i]%M;
            s_b=(s_b+M)%M;
        }for(int i=0;i<q;i++){
        	sq_x+=((ll)x[i]*x[i]%M);
            sq_x=(sq_x+M)%M;
        	sq_y+=((ll)y[i]*y[i]%M);
            sq_y=(sq_y+M)%M;
        	s_x+=(ll)x[i]%M;
            s_x=(s_x+M)%M;
        	s_y+=(ll)y[i]%M;
            s_y=(s_y+M)%M;
        }
        ll a1=n*(sq_x+sq_y)%M;
        a1=(a1+M)%M;
        ll a2=q*(sq_a+sq_b)%M;
        a2=(a2+M)%M;
        ll a3=s_a*s_x%M;
        a3=(a3+M)%M;
        ll a4=s_b*s_y%M;
        a4=(a4+M)%M;
        cout<<((a1+a2)%M-2*(a3+a4)%M+M)%M;nl;

    }
    return 0;
}


// Case #1: 52
// Case #2: 131
// Case #3: 110090622
// Case #4: 120
// Case #5: 1712
// Case #6: 198450
// Case #7: 633155595
// Case #8: 777092013
// Case #9: 418307892