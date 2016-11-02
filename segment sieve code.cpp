/******************************************************************
*                                      *                                                                                            *
* zihadnayem8@gmail.com             *     *
*                                      *                                                                                            *
* Dept: CSTE in NSTU,bd
*                                      *                                                                                            *
*                                   *     *                                                                                         *
*                                      *                                                                                             *
*******************************************************************/
// segment sieve code.
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

#define pb push_back
#define ll long long
#define SIZE 100005
ll arr[SIZE+1];   ///globally declare


vector < ll > prime;  ///stores generate prime
bool Sieve[SIZE+1];

void simpleSieve(ll n)
{
    Sieve[0]=Sieve[1]=1;  /// 0 and 1 not prime
    prime.pb(2);   /// only 2 is prime of even numbers
    for( ll i=4; i<=n; i+=2)
         {
             Sieve[i]=1;
         }


         //ll sqrtn=sqrt(n);

         for(ll i=3; i*i<=n; i+=2)
         {
             if( Sieve[i]==0 )
             {
                 for( ll j=i*i; j<=n; j=j+i+i)
                 {
                     Sieve[j]=1;
                 }
             }
         }

         for( ll i=3; i<=n; i+=2)
            if(Sieve[i]==0)
         {
             //cout<<i<<" ";
             prime.pb(i);
         }
         //cout<<endl;


}
///segment[a,b] sieve

ll segmentSieve( ll a, ll b )
{
    if( a==1 ) a++;

    ll sqrtn=sqrt(b);
    simpleSieve(sqrtn);  ///genrate prime 1 to root of b

    memset(arr, 0, sizeof arr);   /// arr[size+1]={0};

    ll len=prime.size();  /// the total prime number

    for( ll  i =0; i<len && prime[i]<=sqrtn; i++)
    {
        ll p=prime[i];
        ll j=p*p;


        ///if j is smaller thanf a ,then shift it inside of of segment[a,b]
        if( j < a ) j = ( ( a + p - 1) / p) * p;

        for( ; j <= b; j+=p)
        {
            ///checking for arr[index] value assign
             //cout<<"arr["<<j-a<<"]==1\n";
            arr[ j-a ] = 1 ;/// mark them as not prime
        }
    }

    ll ans=0;
    for( ll i= a;i<= b; i++)
    {
        ///if it is not marked ,then it is a prime.
         if( arr[i-a] == 0)
         {
             //cout<<i<<" ";  //*
             ++ans;
         }

    }
    //cout<<endl  //*;

       return ans;    ///return the no of primes number between range[a,b]
}



int main()
{
   int test,i;
   ll a,b;
   scanf("%d",&test);
   for( i = 1; i <= test; i++)
   {
       scanf("%lld%lld",&a,&b);
       printf("Case %d: %lld\n",i,segmentSieve(a,b));

   }


    return 0;
}
