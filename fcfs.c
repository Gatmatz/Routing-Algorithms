#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int pid;
	int arrival_time;
	int burst_time;
} process;

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
    // FCFS - First Come First Served
    int pid_counter = 0; //Counter that keeps track of the current process in CPU
    for (int i=0;i<total_time;i++)
    {
        //If a process has ended.
        if (routing[pid_counter].burst_time == 0)
        {
            //Move to the next process.
            pid_counter++;
        }
        //Print the current process in CPU
        printf("%d\n",routing[pid_counter].pid);
        //Decrease by one burst time of current process in CPU
        routing[pid_counter].burst_time--;
    }
	return 0; /* DO NOT EDIT THIS LINE */
}
