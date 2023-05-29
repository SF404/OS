#include <stdio.h>

int main()
{
    int i, n, total = 0, counter = 0, y, qt, wt = 0, tat = 0, at[10], bt[10], temp[10];
    float avg_wt, avg_tat;
    printf(" Total number of process in the system: ");
    scanf("%d", &n);
    y = n;
    // Enter Time Quantum
    printf("Enter the Time Quantum for the process: \t");
    scanf("%d", &qt);

    // Enter Details
    for (i = 0; i < n; i++)
    {
        printf("\n Enter the Arrival and Burst time of the Process[%d]\n", i + 1);
        printf(" Arrival time is: \t");
        scanf("%d", &at[i]);
        printf("\n Burst time is: \t"); 
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
    }

    printf("\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time ");
    for (total = 0, i = 0; y != 0;)
    {
        if (temp[i] <= qt && temp[i] > 0)
        {
            total = total + temp[i];
            temp[i] = 0;
            counter = 1;
        }
        else if (temp[i] > 0)
        {
            temp[i] = temp[i] - qt;
            total = total + qt;
        }
        if (temp[i] == 0 && counter == 1)
        {
            y--; // decrement the process no.
            printf("\nProcess No[%d] \t\t %d\t\t\t %d\t\t %d", i + 1, bt[i], total - at[i], total - at[i] - bt[i]);
            wt = wt + total - at[i] - bt[i];
            tat = tat + total - at[i];
            counter = 0;
        }
        if (i == n - 1)
        {
            i = 0;
        }
        else if (at[i + 1] <= total)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }
    // represents the average waiting time and Turn Around time
    avg_wt = wt * 1.0 / n;
    avg_tat = tat * 1.0 / n;
    printf("\n Average Turn Around Time: \t%f", avg_wt);
    printf("\n Average Waiting Time: \t%f\n", avg_tat);
}