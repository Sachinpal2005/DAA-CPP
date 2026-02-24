#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int start, finish, profit;
};

bool compare(Job a, Job b) {
    return a.finish < b.finish;
}

int main() {
    int n;

    cout << "Enter number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);

    cout << "Enter start, finish, profit:\n";
    for(int i = 0; i < n; i++)
        cin >> jobs[i].start >> jobs[i].finish >> jobs[i].profit;

    sort(jobs.begin(), jobs.end(), compare);

    vector<int> dp(n);
    dp[0] = jobs[0].profit;

    for(int i = 1; i < n; i++) {
        dp[i] = jobs[i].profit;

        for(int j = 0; j < i; j++) {
            if(jobs[j].finish <= jobs[i].start)
                dp[i] = max(dp[i], dp[j] + jobs[i].profit);
        }
    }

    int result = dp[0];
    for(int i = 1; i < n; i++)
        result = max(result, dp[i]);

    cout << "Maximum profit: " << result;

    return 0;
}