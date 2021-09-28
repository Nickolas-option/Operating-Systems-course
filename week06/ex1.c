#include <stdio.h>

int main() {
    int BT[100], AT[100], TAT[100], CT[100], WT[100] = {0};
    int quantity;
    int sumTAT = 0;
    int sumWT = 0;

    printf("Input number of processes:\n");
    scanf("%d", &quantity);
    printf("Input ATs and BTs:\n");
    int i = 0;
    for (i = 0; i < quantity; i++) {
        printf("Input the AT of process N%d: ", i + 1);
        scanf("%d", &AT[i]);
        printf("Input the BT of process N%d: ", i + 1);
        scanf("%d", &BT[i]);
    }
    int currentTime = AT[0];
    for (i = 0; i < quantity; ++i) {
        currentTime += BT[i];
        CT[i] = currentTime;
    }
    for (i = 0; i < quantity; ++i) {
        TAT[i] = CT[i] - AT[i];
        sumTAT += TAT[i];
    }
    for (i = 0; i < quantity; ++i) {
        WT[i] = TAT[i] - BT[i];
        sumWT += WT[i];
    }

    printf("Num\t AT\t BT\t CT\t TAT\t WT\n");
    for (i = 0; i < quantity; i++) {
        printf("P%d\t %d\t %d\t %d\t %d\t %d\t\n", i + 1, AT[i], BT[i], CT[i], TAT[i], WT[i]);
    }
    printf("Average WT is %f\n", sumWT / (quantity * 1.0));
    printf("Average TAT i: %f\n", sumTAT / (quantity * 1.0));
}
