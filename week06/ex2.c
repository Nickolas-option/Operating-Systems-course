#include "stdio.h"

int main() {
    int quantity;
    printf("Please, provide number of processes\n");
    scanf("%d", &quantity);
    int AT[quantity], BT[quantity], CT[quantity], TAT[quantity], WT[quantity], pid[quantity];
    double avgTAT, avgWT;
    for (int i = 0; i < quantity; i++) {
        pid[i] = i;
        printf("Enter the arrival time of process N%d\n", i);
        scanf("%d", &AT[i]);
        printf("Enter the burst time of process N%d\n", i);
        scanf("%d", &BT[i]);
    }

    // Sort processes by arrival time and then by burst time
    for (int i = 0; i < quantity - 1; ++i) {
        for (int j = 0; j < quantity - i - 1; ++j) {
            if (AT[j] > AT[j + 1]) {
                int temp_at = AT[j];
                int temp_bt = BT[j];
                int temp_pid = pid[j];
                AT[j] = AT[j + 1];
                BT[j] = BT[j + 1];
                pid[j] = pid[j + 1];
                AT[j + 1] = temp_at;
                BT[j + 1] = temp_bt;
                pid[j + 1] = temp_pid;
            } else if (AT[j] == BT[j + 1]) {
                if (BT[j] > BT[j + 1]) {
                    int temp_at = AT[j];
                    int temp_bt = BT[j];
                    int temp_pid = pid[j];
                    AT[j] = AT[j + 1];
                    BT[j] = BT[j + 1];
                    pid[j] = pid[j + 1];
                    AT[j + 1] = temp_at;
                    BT[j + 1] = temp_bt;
                    pid[j + 1] = temp_pid;
                }
            }
        }
    }
    int currentTime = 0;
    for (int i = 0; i < quantity; i++) {
        currentTime = ((currentTime) < (AT[i]) ? (AT[i]) : (currentTime));
        CT[i] = BT[i] + currentTime;
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];
        currentTime = CT[i];
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
        printf("Num%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], AT[i], BT[i], CT[i], TAT[i], WT[i]);
    }
    printf("Average TAT is %.1\n", avgTAT);
    printf("Average WT is %.1\n", avgWT);
    return 0;
}
