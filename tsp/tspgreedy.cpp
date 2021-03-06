//greedy tsp 
//greedly taking a shorted node form current node and building tour
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
#define ii pair<double,double>
#define LL long long
long double distt(ii a ,ii b)
{
    return sqrt((double(a.first-b.first)*double(a.first-b.first))+(double(a.second-b.second)*double(a.second-b.second)));
}
int main(int argc,char *argv[])
{
    srand(time(NULL));
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
        vector<int> order;
        for(int i=0;i<N;i++) order.push_back(i);

        vector<int> finaltour;
        long double finaltourlen=LLONG_MAX;

        clock_t start=clock();

        while(clock()-start<CLOCKS_PER_SEC*2){//run for 2 sec

            random_shuffle(order.begin(),order.end());

            vector<int> tour;
            vector<int> used(N,0);
            tour.push_back(order[0]);
            used[order[0]]=1;
            long double tourlen=0;

            while(tour.size()<N)
            {
                long double m=LLONG_MAX; 
                LL mindex=-1;
                for(int i=0;i<N;i++)
                {
                    if(!used[order[i]])
                    {
                        if(distt(v[order[i]],v[tour[tour.size()-1]])<m)
                        {
                            mindex=order[i];
                            m=distt(v[order[i]],v[tour[tour.size()-1]]);
                        }
                    }
                }
                used[mindex]=1;
                tourlen+=(m);
                tour.push_back(mindex);
            }
            tourlen+=(distt(v[order[0]],v[tour[tour.size()-1]]));
            if(tourlen<finaltourlen)
            {
                finaltourlen=tourlen;
                finaltour=tour;
            }

            //cout<<tourlen<<" "<<finaltourlen<<endl;
        }
        printf("%.8llf 0\n",finaltourlen);

        for(int i=0;i<N;i++)
        {
            cout<<finaltour[i]<<" ";
        }
        cout<<endl;
    }
    
   

    return 0;
}

