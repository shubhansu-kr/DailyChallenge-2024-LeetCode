#include <iostream>
#include <vector>

int getMinimumOperations(const std::vector<int>& executionTime, int x, int y) {

    int operations = 0;
    int majorJobTime = 0;
    int restJobsTime = 0;

    for (int i = 0; i < executionTime.size(); ++i) {
        if (i == 0) {
            majorJobTime += x;
        } else {
            restJobsTime += y;
        }
    }

    int totalJobsTime = majorJobTime + restJobsTime;

    for (int time : executionTime) {
        if (time <= majorJobTime) {
            operations++;
        } else {
            int remainingTime = time - majorJobTime;
            operations += (remainingTime + restJobsTime - 1) / restJobsTime + 1;
        }
    }

    return operations;
}

int main() {
    // Example usage:
    std::vector<int> executionTime = {3, 4, 1, 7, 6};
    int x = ; // Time executed on the major job
    int y = 2; // Time executed on the rest of the jobs

    int result = getMinimumOperations(executionTime, x, y);

    std::cout << "Minimum number of operations: " << result << std::endl;

    return 0;
}
