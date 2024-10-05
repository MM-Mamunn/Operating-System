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


///Compare function to sort priority queue ascendingly
///if burst time of two processes are same then place the process with lower arrival time
class Compare
{
public:
    bool operator()(object p1, object p2)
    {
        if (p2.b < p1.b)
        {
            return true;
        }
        else if (p2.b == p1.b
                 && p2.a < p1.a)
        {
            return true;
        }

        return false;
    }
};


int32_t main()
{
    cout<<"Enter the number of process: ";
    int n;
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
    priority_queue<object, vector<object>, Compare> pq;
   
   ///track which process executed in each second 
    map<int,string > ans_map;
    
    while(1)
    {
        string executed = "none";
        ///push a process if it arrived at time i
        if(m[i])
        {
            pq.push(v[ m[i] - 1]);
        }
        if(!pq.empty())
        {
            object t = pq.top();
            executed = t.n;
            pq.pop();
            t.b -= 1;
            if(t.b)
                pq.push(t);
        }
        ans_map[i] = executed;
        
        if(i >= mx and pq.empty())
            break;
        
        ++i;
    }

cout<<"Grant chart: \n";
    for(auto a : ans_map)
    {
        string temp =  to_string(a.first);
        cout<<temp;
        int space = 4 - temp.size();
        for( int j = 0 ; j < space; j++)cout<<' ';
    }
    cout<<endl;
    for(auto a : ans_map)
    {
        string temp =  a.second;
        cout<<temp;
        int space = 4 - temp.size();
        for( int j = 0 ; j < space; j++)cout<<' ';
    }

    cout<<endl;
    return 0;
}
