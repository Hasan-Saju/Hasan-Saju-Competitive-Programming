#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define pb          push_back
#define mp          make_pair
#define ff          first
#define ss          second
#define vi          vector<int>
#define si          set<int>
#define FOR(i,n)    for(int i=0;i<n;i++)
#define fast        ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SP(x)       fixed<<setprecision(x)
#define fWrite      freopen("out.txt", "w", stdout);//to write the output in a txt file
#define fRead       freopen("in.txt", "r", stdin);
#define asi         cout<<"Check"<<endl
#define bye         return 0
#define ok          cout<<"OK"<<endl
//lower_bound == Shoman othoba prothom boro element ta return korbe//iterator return kore
//upper bound mane first boro element return korbe
//string s(n,'a');

ll Digits(ll a)
{
    return(floor(log10(a))+1);
}
ll BMod(ll B,ll P,ll M)
{
    ll R=1;
    B=B%M;
    while(P)
    {
        if(P&1)
            R=(R*B)%M;
        P >>= 1;
        B=(B*B)%M;
    }
    return R;
}
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);

}
ll lcm(ll a,ll b)
{
    return a*b/gcd(a,b);

}


int main()
{
    fast
    int total,atleast;
    cin>>total>>atleast;

    vector<int >now,next;

    FOR(i,total)
    {
        int x;
        cin>>x;
        now.pb(x);
    }
    FOR(i,total)
    {
        int x;
        cin>>x;
        next.pb(x);
    }

    int exp=0;
    multimap<int,pair<int,int> >m;
    pair<int,int>temp;

    int x=0;
    FOR(i,total)
    {

        if(next[i]>=now[i])
        {
            exp+=now[i];
           // cout<<now[i]<<endl;
            now[i]=next[i]=0;
            x++;
        }
        else
        {
            temp.ff=now[i];
            temp.ss=next[i];
            int kkey=now[i]-next[i];
            m.insert({kkey, temp });
        }


    }

   // cout<<m.size()<<"size\n";

    if(atleast>x)
    {
        int aroBad=atleast-x;
        label:
        for(auto it:m)
        {
            int key=it.ff;
            temp=it.ss;

            exp+=temp.ff;
          //  cout<<temp.ff<<"arobad"<<endl;
            m.erase(m.begin());
            aroBad--;
            if(aroBad==0)
                break;
            goto label;
        }

    }

   // cout<<m.size()<<"size\n";
    for(auto it:m)
    {
      //  cout<<"hi\n";
        temp=it.ss;
        exp+=temp.ss;
        //cout<<temp.ss<<"final"<<endl;
    }
    cout<<exp;

}

