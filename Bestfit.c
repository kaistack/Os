#include <iostream>
#include <limits.h>
using namespace std;

int main() {
    int blockNumber = 5;
    int processesNumber = 3;
    int blockSize[] = {400, 500, 300, 200, 100};
    int processSize[] = {88, 192, 277, 365, 489};
    int allocationFirstFit[5], allocationBestFit[5], allocationWorstFit[5];
    int flagsFirstFit[5], flagsBestFit[5], flagsWorstFit[5];

    // Initialize flags and allocation arrays
    for (int i = 0; i < 5; i++) {
        flagsFirstFit[i] = flagsBestFit[i] = flagsWorstFit[i] = 0;
        allocationFirstFit[i] = allocationBestFit[i] = allocationWorstFit[i] = -1;
    }
// Best Fit Allocation
    for (int i = 0; i < processesNumber; i++) {
        int bestFit = INT_MAX;
        int bestFitIndex = -1;
        for (int j = 0; j < blockNumber; j++) {
            if (flagsBestFit[j] == 0 && blockSize[j] >= processSize[i] && blockSize[j] - processSize[i] < bestFit) {
                bestFit = blockSize[j] - processSize[i];
                bestFitIndex = j;
            }
        }
        if (bestFitIndex != -1) {
            allocationBestFit[bestFitIndex] = i;
            flagsBestFit[bestFitIndex] = 1;
        }
    }
// Display the allocation result

    cout << "\nBest Fit Memory Allocation:" << endl;
    for (int i = 0; i < blockNumber; i++) {
        if (flagsBestFit[i] == 1) {
            cout << "Process " << processSize[allocationBestFit[i]] << " is allocated to Block " << i + 1 << endl;
        }
    }
return 0;
}
