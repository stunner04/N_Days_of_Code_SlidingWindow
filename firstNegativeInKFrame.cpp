#include <bits/stdc++.h>
using namespace std;

// dequeue
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{
    vector<long long> res;
    deque<long long> negativeBox;

    int i = 0, j = 0;

    while (j < N)
    {
        if (A[j] < 0)
        {
            negativeBox.push_back(A[j]);
        }

        if (j - i + 1 < K)
        {
            j++;
        }

        else if (j - i + 1 == K)
        {
            if (negativeBox.size() == 0)
            {
                res.push_back(0);
            }
            else
            {
                res.push_back(negativeBox.front());
                if (A[i] == negativeBox.front())
                {
                    negativeBox.pop_front();
                }
                i++;
                j++;
            }
        }
    }
    return res;
}

// queue

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{

    vector<long long> v;
    queue<int> q;
    int j = 0;
    for (int i = 0; i < N; i++)
    {
        if (A[i] < 0)
        {
            q.push(A[i]);
        }
        if (i - j + 1 == K)
        {
            if (q.empty())
            {
                v.push_back(0);
            }
            else
            {
                v.push_back(q.front());
                if (A[j] == q.front())
                {
                    q.pop();
                }
            }
            j++;
        }
    }
    return v;
}

int main()
{
    return 0;
}

https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1