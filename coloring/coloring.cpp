/*
 *Kartik Singal @ ka4tik
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<fstream>
#include<cassert>
using namespace std;
#define s(x) scanf("%d",&x)
vector< vector<int> > g;
int main(int argc,char *argv[])
{
    ifstream file(argv[1]);
    if(!file.is_open())
        cout<<"Could not open file\n";
    else
    {
        int N,M; 
        int used=0;
        file>>N>>M;
        g.resize(N);
        for(int i=0;i<N;i++) g[i].clear();

        for(int i=0;i<M;i++)
        {
            int a,b;
            file>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        vector<int> color(N,-1);

        for(int i=0;i<N;i++)
        {
            for(int j=0;;j++)
            {
                int flag=1;
                for(int k=0;k<g[i].size();k++)
                {
                    if(color[g[i][k]]==j)
                     {
                         flag=0;
                         break;
                     }
                }
                if(flag)
                {
                    used=max(used,j);
                    color[i]=j;
                    break;
                }
            }
        }
     cout<<used+1<<" 0"<<endl;
     for(int i=0;i<N;i++)
         cout<<color[i]<<" ";
     cout<<endl;
    }
                
    return 0;
}

