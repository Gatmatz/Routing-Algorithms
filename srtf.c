#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int pid;
	int arrival_time;
	int burst_time;
} process;

//Decide the next process based on SRTF Preemptive.
int find_min(int n, process* routing, int time)
{
    int min = 100000; //Min variable that stores the minimum burst time.
    int min_id = 0; //Min_id variable that stores the id number of minimum burst time.
    for (int i=0;i<n;i++)
    {
        //If process has the minimum burst time, and it is not finished(burst_time>0), and it has arrived(arrival_time<=time)
        if (routing[i].burst_time<min && routing[i].burst_time>0 && routing[i].arrival_time<=time)
        {
            //Choose the i-th process.
            min = routing[i].burst_time;
            min_id = i;
        }
    }
    //Return the desired process based on SJF Non-Preemptive
    return min_id;
}

int main() {

	/* read in data - DO NOT EDIT (START) */
	int n;
	int quantum;
	scanf("%d", &n);
	scanf("%d", &quantum);
	process *arr;
	arr = malloc(n * sizeof(process));
	for (int i = 0; i < n ; ++i) {
		scanf("%d", &arr[i].pid);
		scanf("%d", &arr[i].arrival_time);
		scanf("%d", &arr[i].burst_time);
	}
	/* read in data - DO NOT EDIT (END) */

    //Calculate total burst time for all processes.
    int total_time=0;
    for (int i=0;i<n;i++)
    {
        total_time += arr[i].burst_time;
    }

    //Copy processes data to a new array named routing for data integrity.
    process *routing;
    routing = malloc(n*sizeof(process));
    for (int i=0;i<n;i++)
    {
        routing[i].pid = arr[i].pid;
        routing[i].arrival_time = arr[i].arrival_time;
        routing[i].burst_time = arr[i].burst_time;
    }

    // SRTF - Shortest Remaining Time First Preemptive
    int pid_counter = 0; //Counter that keeps track of the current process in CPU
    for (int i=0;i<total_time;i++)
    {
        //Decide next process to be executed by CPU.
        if (i != 0)
        {
            pid_counter = find_min(n,routing,i);
        }
        //Print the current process in CPU
        printf("%d\n",routing[pid_counter].pid);
        //Decrease by one burst time of current process in CPU
        routing[pid_counter].burst_time--;
    }
	return 0; /* DO NOT EDIT THIS LINE */
}
