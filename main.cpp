#include<bits/stdc++.h> 
//priority_queue next_permutation 
#define ll long long 
// #define int ll 
// #define double long double 
#define flot(n) cout << setprecision(n) << setiosflags(ios::fixed) << setiosflags(ios::showpoint) 
#define all(a) a.begin() , a.end() 
#define allr(a) a.rbegin() , a.rend() 
#define pb push_back 
#define mp make_pair 
#define pii pair<int,int> 
#define pll pair<ll,ll> 
#define piii pair<pii,int> 
#define plll pair<ll,pll> 
#define R return 
#define B break 
#define C continue 
#define SET(n , i) memset(n , i , sizeof(n)) 
#define SD ios::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
#define rep(i , n) for(int i = 0 ; i < n ; i++) 
#define repn(i , j , n) for(int i = j ; i < n ; i++) 
#define repr(i,n,j) for(int i=n;i>=j;i--)
#define positive(x) (x%mod+mod)%mod
#define YES(f)cout<<(f?"YES":"NO")<<endl
#define F first 
#define S second 
#define endl '\n' 
using namespace std; 
void MAX(int32_t &x,int32_t y){x=max(x,y);} 
void MAX(ll &x,ll y){x=max(x,y);} 
void MIN(int32_t &x,int32_t y){x=min(x,y);} 
void MIN(ll &x,ll y){x=min(x,y);} 
const int INF = 0x3f3f3f3f; 
const ll INFLL = 0x3f3f3f3f3f3f3f3f; 
const double EPS = 1e-7; 
const double pi = 3.14159265358979323846;
const int mod = 1e9+7; 
const int N = 1e6+7; 
ll Mul(ll x,ll y){R((x%mod)*(y%mod))%mod;}
ll Add(ll x,ll y){R((x%mod)+(y%mod)+2ll*mod)%mod;} 
int n,k;
struct node;
extern node* null;
struct node
{
    int freq;
    node *l,*r;
    node() {
        freq=0;
        l=r=this;
    }
    node(int f,node *lft=null,node *rt=null) {
        freq=f;
        l=lft;
        r=rt;
    }
};
node *null=new node;
node *roots[N];
node *insert(node *root,int val,int left =-1e9,int right=1e9) {
    if(val<left||val>right) return root;
    if(left == right) return new node(root->freq+1);
    int mid = left+(right-left)/2;
    node *r1 = insert(root->l,val,left,mid);
    node *r2 = insert(root->r,val,mid+1,right);
    return new node(r1->freq+r2->freq,r1,r2);
}
int query(node *rtst,node *rten,int k,int left=-1e9,int right=1e9) {
    if(left == right) return left;
    int lsz = rten->l->freq-rtst->l->freq;
    int md = left+(right-left)/2;
    if(k<=lsz)
        return query(rtst->l,rten->l,k,left,md);
    return query(rtst->r,rten->r,k-lsz,md+1,right);
}   
void solve() {
    scanf("%d%d",&n,&k);
    roots[0] = null;
    repn(i,1,n+1) {
        int x;
        scanf("%d",&x);
        roots[i] = insert(roots[i-1] , x);
    }
    rep(i,k) {
        int l,r,x;
        scanf("%d%d%d",&l,&r,&x);
        printf("%d\n",query(roots[l-1],roots[r],x));
    }
}
void sett(){ 
} 
int32_t main() { 
    SD; 
    int t = 1; 
    // cin >> t; 
    // scanf("%d" , &t); 
    while(t--){
        solve(); 
        sett(); 
    } 
}
