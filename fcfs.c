#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int pid;
	int arrival_time;
	int burst_time;
} process;

process* sortByArrival(process* arr, int n, int total_time)
{
    process* routing;
    routing = malloc(total_time*sizeof(process));
    
    return routing;
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
//    for (int i=0;i<n;i++)
//    {
//        printf("%d - %d - %d\n",arr[i].pid, arr[i].arrival_time, arr[i].burst_time);
//    }
    int total_time=0;
    for (int i=0;i<n;i++)
    {
        total_time += arr[i].burst_time;
    }
    process *routing=malloc(total_time*sizeof(process));
    routing = sortByArrival(arr,n,total_time);
    for (int i=0;i<total_time;i++)
    {

    }
	return 0; /* DO NOT EDIT THIS LINE */
}
