#include "stdio.h"

int main() {
    int quantity;
    printf("Please, provide number of processes\n");
    scanf("%d", &quantity);
    int AT[quantity], BT[quantity], CT[quantity], TAT[quantity], WT[quantity], pID[quantity];
    int q;
    int completed[quantity], iterationNumber[quantity];
    double avgTAT, avgWT;
    printf("Please, enter the quantum\n");
    scanf("%d", &q);
    for (int i = 0; i < quantity; i++) {
        completed[i] = 0;
        iterationNumber[i] = 0;
        pID[i] = i;
        printf("Please, enter the arrival time of the new process N%d\n", i);
        scanf("%d", &AT[i]);
        printf("Please, enter the burst time of the new process N%d\n", i);
        scanf("%d", &BT[i]);
    }

    for (int j = 0 ; j < quantity - 1; j++) {
        if (AT[j] > AT[j+1]) {
            int temp_at = AT[j];
            int temp_bt = BT[j];
            int temp_pid = pID[j];
            AT[j] = AT[j+1];
            BT[j] = BT[j+1];
            pID[j] = pID[j + 1];
            AT[j+1] = temp_at;
            BT[j+1] = temp_bt;
            pID[j + 1] = temp_pid;
        }
    }

    int currentTime = 0;
    int toBeProcessed = 1;
    int temp_bt[quantity];
    for (int i = 0; i < quantity; i++) {
        temp_bt[i] = BT[i];
    }
    while(toBeProcessed != 0) {
        toBeProcessed = 0;
        for (int i = 0; i < quantity; i++) {
            if (completed[i]) {
                continue;
            }
            iterationNumber[i] = iterationNumber[i] + 1;
            currentTime = (currentTime < AT[i] ? AT[i] : currentTime);
            CT[i] = (temp_bt[i] > q ? q : temp_bt[i]) + currentTime;
            TAT[i] = CT[i] - AT[i];
            WT[i] = TAT[i] - (temp_bt[i] > q ? q : temp_bt[i]);
            if (iterationNumber[i] > 1) {
                WT[i] = WT[i] - q * (iterationNumber[i] - 1);
            }
            temp_bt[i] = temp_bt[i] - (temp_bt[i] > q ? q : temp_bt[i]);
            if (temp_bt[i] == 0) {
                completed[i] = 1;
            }
            currentTime = CT[i];
        }
        for (int i = 0; i < quantity; i++) {
            if (completed[i] == 0) {
                toBeProcessed = 1;
            }
        }
    }

    double TotalTAT = 0, TotalWT = 0;
    for (int i = 0; i < quantity; ++i) {
        TotalTAT += TAT[i];
        TotalWT += WT[i];
    }
    avgTAT = TotalTAT / quantity;
    avgWT = TotalWT / quantity;

    printf("Num\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < quantity; i++) {
        printf("Num%d\t%d\t%d\t%d\t%d\t%d\n", pID[i], AT[i], BT[i], CT[i], TAT[i], WT[i]);
    }
    printf("Average TAT: %.1f\n", avgTAT);
    printf("Average WT: %.1f\n", avgWT);
    return 0;
}
