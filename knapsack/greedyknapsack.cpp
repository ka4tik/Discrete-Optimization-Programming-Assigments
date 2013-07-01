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
#define MAXN 1011
#define MAXW 500011
int main(int argc,char *argv[])
{
    ifstream file(argv[1]);
    if(!file.is_open())
        cout<<"Could not open file\n";
    else
    {
        int n,capicity;
        file>>n>>capicity;
        vector<int> values(n),wt(n);
        vector<pair<double,int> > t;
        for(int i=0;i<n;i++)
        {
          file>>values[i]>>wt[i];
          t.push_back(pair<double,int>(double(values[i])/double(wt[i]),i));
        }
        vector<int> ans(n,0);
        sort(t.begin(),t.end());
        reverse(t.begin(),t.end());
        int i=0; 
        while(capicity>0&&i<n)
        {
            if(capicity>=wt[t[i].second])
            {
                ans[t[i].second]=1;
                capicity-=wt[t[i].second];

            }
            i++;
        }
        int value=0;
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i])
                value+=values[i];
        }
        cout<<value<<" "<<0<<endl;
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
        cout<<endl;

    }


    return 0;
}

