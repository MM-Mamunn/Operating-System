///SRTF --> Shortest remaining time first

#include<bits/stdc++.h>

using namespace std;

///class to hold process with arrival time(a), burst time (b),Name(n)
class object
{
public:
    int a, b;
    string n;
};





int32_t main()
{
    cout<<"Enter the number of process: ";
    int n,k;
    cin>>n;
    vector<object>v(n);
    map<int,int>m;
    int i = 0, mx = 0;
    for(auto &a : v)
    {
        cout<<"Enter the arrival time , burst time and process name of process no : "<<i+ 1<<":";
        cin>>a.a>>a.b>>a.n;
        mx = max(mx, a.a);
        ///maintaining arrival time index
        m[a.a] = i + 1;
        ++i;
    }
    i = 0;
    cout<<"Enter Quantum : ";
    cin>>k;
    map<int,string>ans;
    queue<object> q;
    while(1)
    {
        string name = "none";
                    int cnt = 0;
            if(q.empty() and m[i])
                q.push(v[m[i]- 1]);
        if(!q.empty())
        {

            object temp = q.front();
                       ans[i] = temp.n;

            q.pop();
            for( int j = 1 ; j <= k; j++)
            {
                if(temp.b > 0)
                {
                    --temp.b;
                    ++i;
                    if(m[i])
                        q.push(v[m[i]- 1]);

                }

            }

            if(temp.b > 0)
                q.push(temp);

        }
        else
            ++i;

        if(i >= mx and q.empty())
            break;
    }
    for(auto a : ans)
    {
        cout<<a.first;
        string tmp = to_string(a.first);
        int space = 4 - tmp.size();
        for( int j = 0 ; j < space ; j ++ )cout<<' ';
    }
    cout<<endl;
    for(auto a : ans)
    {
        cout<<a.second;
        int space = 4 - a.second.size();
          for( int j = 0 ; j < space ; j ++ )cout<<' ';
    }
    cout<<endl;
    return 0;
}


//TC
//4
//0 5 p1
//1 4 p2
//2 2 p3
//4 1 p4
//2