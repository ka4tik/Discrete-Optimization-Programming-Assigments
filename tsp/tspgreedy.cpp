/*
 *Kartik Singal @ ka4tik
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<climits>
#include<cmath>
#include<sstream>
#include<fstream>
using namespace std;
#define s(x) scanf("%lld",&x)
#define ii pair<LL,LL>
#define LL long long
LL distt(ii a ,ii b)
{
    return (((a.first-b.first)*(a.first-b.first))+((a.second-b.second)*(a.second-b.second)));
}
int main(int argc,char *argv[])
{
    ifstream file(argv[1]);
    if(!file.is_open())
        cout<<"Could not open file\n";
    else
    {

    int N;
    file>>N;
    vector<ii> v(N);
    for(int i=0;i<N;i++)
    {
        file>>v[i].first;
        file>>v[i].second;
    }
    
    vector<int> tour;
    vector<int> used(N,0);
    tour.push_back(0);
    used[0]=1;
    double tourlen=0;
    
    while(tour.size()<N)
    {
        LL m=LLONG_MAX; 
        LL mindex=-1;
        for(int i=0;i<N;i++)
        {
            if(!used[i])
            {
                if(distt(v[i],v[tour[tour.size()-1]])<m)
                {
                    mindex=i;
                    m=distt(v[i],v[tour[tour.size()-1]]);
                }
            }
        }
        used[mindex]=1;
        tourlen+=sqrt(m);
        tour.push_back(mindex);
    }
    tourlen+=sqrt(distt(v[0],v[tour[tour.size()-1]]));
    printf("%.8lf 0\n",tourlen);

    for(int i=0;i<N;i++)
    {
        cout<<tour[i]<<" ";
    }
    cout<<endl;
    }
    
    return 0;
}

