
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
    ///Assume there is only 3 resources (A,B,C) and 5 processes.
    int A, B, C, totall_A = 0, totall_B = 0, totall_C = 0;
    cout<<"Input totall resources for A : ";
    cin>>A;
    cout<<"Input totall resources for B : ";
    cin>>B;
    cout<<"Input totall resources for C : ";
    cin>>C;
    vector<int> allocation[10], Max[10],Current[10];
    cout<<"Allocation input : \n";
    for( int i = 1; i <= 5; i++)
    {
        int a, b, c;
        cout<<"Enter allocation A B C for process no "<<i<<": ";
        cin>>a>>b>>c;
        allocation[i].pb(a);
        allocation[i].pb(b);
        allocation[i].pb(c);
        totall_A += a;
        totall_B += b;
        totall_C += c;
    }

    cout<<"Max input : \n";
    for( int i = 1; i <= 5; i++)
    {
        int a, b, c;
        cout<<"Enter Max A B C for process no "<<i<<": ";
        cin>>a>>b>>c;
        Max[i].pb(a);
        Max[i].pb(b);
        Max[i].pb(c);
    }
    for( int i = 1; i <= 5; i++)
    {
        int a, b, c;
        a =Max[i][0] - allocation[i][0];
        b =Max[i][1] - allocation[i][1];
        c =Max[i][2] - allocation[i][2];
        Current[i].pb(a);
        Current[i].pb(b);
        Current[i].pb(c);
    }
    vector <int> available(10,0);
    map<int, bool>m;
    available[1] = A - totall_A;
    available[2] = B - totall_B;
    available[3] = C - totall_C;
    int  rA, rB, rC, curA, curB, curC;
    int choice;
    cout<<"Enter the process no : ";
    cin>>choice;
    cout<<"request A B C input : ";
    cin>>rA>>rB>>rC;
    curA = Max[choice][0] - allocation[choice][0];
    curB = Max[choice][1] - allocation[choice][1];
    curC = Max[choice][2] - allocation[choice][2];
    for(int i = 1; i <= 3; i ++)
        cout<<available[i]<<' ';
    cout<<endl;
    if(rA <= curA and rB <= curB and rC <= curC)
    {
        if(rA <= available[1] and rB <= available[2] and rC <= available[3])

        {
            int cnt = 0;
            available[1] -= rA;
            available[2] -= rB;
            available[3]-= rC;
            allocation[choice][0] +=rA;
            allocation[choice][1] +=rB;
            allocation[choice][2] +=rC;
            Current[choice][0] -= rA;
            Current[choice][1]-= rB;
            Current[choice][2] -= rC;
            vector<int> ans;
            while( 1)
            {
                int f = 0;
                for( int i = 1 ; i <= 5; i++)
                {
                    if(m[i])
                        continue;
                    if(Current[i][0] <= available[1] and Current[i][1] <= available[2] and
                            Current[i][2] <= available[3]  )
                    {
                        m[i] = 1 ;
                        available[1]+= allocation[i][0];
                        available[2]+= allocation[i][1];
                        available[3]+= allocation[i][2];
                        f = 1;
                        ++cnt;
                        ans.pb(i);
                    }

                }
                if(!f )
                    break;

            }
            if(cnt == 5)
            {
                cout<<"accepted!! ";

            }
            else
            {
                cout<<"Not safe\n";
                available[1] += rA;
                available[2] += rB;
                available[3]+= rC;
                allocation[choice][0] -=rA;
                allocation[choice][1] -=rB;
                allocation[choice][2] -=rC;
                Current[choice][0] += rA;
                Current[choice][1] += rB;
                Current[choice][2] += rC;
            }
        }
        else
        {

            cout<<"Not safe\n";
        }

    }
    else
    {

        cout<<"Not safe\n";
    }
}
//
////Test Case:
////total resources
//10 5 7
//
/////Allocations
//0 1 0
//2 0 0
//3 0 2
//2 1 1
//0 0 2
//
////Max
//7 5 3
//3 2 2
//9 0 2
//2 2 2
//4 3 3
//
////Suppose process no 2 request for R(1 0 2)
//2
//1 0 2
//
////Output:
////accepted!!

