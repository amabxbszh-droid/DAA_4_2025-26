#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    int id, deadline, profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    Job jobs[] = {
        {1, 4, 20},
        {2, 1, 10},
        {3, 1, 40},
        {4, 1, 30}
    };

    int n = 4;
    sort(jobs, jobs + n, compare);

    int maxDeadline = 4;
    int slot[maxDeadline] = {0};

    int count = 0, totalProfit = 0;

    for(int i = 0; i < n; i++) {
        for(int j = jobs[i].deadline - 1; j >= 0; j--) {
            if(slot[j] == 0) {
                slot[j] = 1;
                count++;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    cout << "Jobs done = " << count << endl;
    cout << "Total profit = " << totalProfit;

    return 0;
}