#include <bits/stdc++.h>
using namespace std ;

vector <int> NG2L(vector <int> v )
{
    stack <int> s;
    vector <int> op ;
    for(int i = 0 ; i < v.size() ; i++)
    {
        if( s.size() == 0)
        {
            op.push_back(-1);
        }
        if(s.size() > 0 and s.top() > v[i])
            op.push_back(s.top());
        else if(s.size() > 0 and s.top() <= v[i])
        {
            while(s.size() > 0 and s.top() <= v[i])
            {
                s.pop();
            }
            if(s.size()== 0)
                op.push_back(-1);
            else if (s.top() > v[i])
                op.push_back(s.top());
        }

        s.push(v[i]);
    }

    return op ;
}


int main()
{
    int size ;
    cin >> size ;
    vector <int> v (size)  ;

    for(int i = 0  ; i < size ; i ++)
    {
        cin >> v[i] ;
    }

    vector <int> res (size) ;
    res = NG2L(v);

    for(auto i = res.begin() ; i != res.end() ; i++)
    {
        cout << *i << " " ;
    }
    cout << endl;
    return 0;

}