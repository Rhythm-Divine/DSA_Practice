#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

bool compare(Job a, Job b)
{
    if (a.profit > b.profit)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Function to find the maximum profit and the number of jobs done.
vector<int> JobScheduling(Job arr[], int n)
{
    vector<int> ans;
    int jobs = 0;
    int profit = 0;
    int maxm = INT_MIN;
    sort(arr, arr + n, compare);

    for (int i = 0; i < n; i++)
    {

        maxm = max(maxm, arr[i].dead);
    }
    vector<int> temp(maxm, -1);

    for (int i = 0; i < n; i++)
    {
        for (int j = maxm - 1; j >= 0; j--)
        {
            if (temp[j] == -1 && jobs<arr[i].dead)
            {
                temp[j] = arr[i].id;
                jobs++;
                profit += arr[i].profit;
                break;
            }
        }
    }
    ans.push_back(jobs);
    ans.push_back(profit);
    return ans;
}

int main()
{
    Job job1;
    job1.id = 1;
    job1.dead = 4;
    job1.profit = 20;

    Job job2;
    job2.id = 2;
    job2.dead = 1;
    job2.profit = 10;

    Job job3;
    job3.id = 3;
    job3.dead = 1;
    job3.profit = 40;

    Job job4;
    job4.id = 4;
    job4.dead = 1;
    job4.profit = 30;

    // Job job5;
    // job5.id = 5;
    // job5.dead = 1;
    // job5.profit = 15;

    Job arr[4] = {job1, job2, job3, job4};
    vector<int> ans = JobScheduling(arr, 4);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}
/*17
1 56 288, 2 27 435, 3 67 401, 4 64 368, 5 94 248, 6 54 361, 7 43 108
8 96 167, 9 73 251, 10 96 170, 11 14 156, 12 78 184, 13 61 370, 14 77 424, 15 68 397, 16 40 375, 17 36 218*/