#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int pid;
	int arrival_time;
	int burst_time;
} process;

void swap(process* x, process* y)
{
    process temp = *x;
    *x = *y;
    *y = temp;
}

process* sortByArrival(process* arr, int n)
{
    //Copy arr contents to another array named routing.
    process* routing;
    routing = malloc(n*sizeof(process));
    for (int i=0;i<n;i++)
    {
        routing[i].pid = arr[i].pid;
        routing[i].arrival_time = arr[i].arrival_time;
        routing[i].burst_time = arr[i].burst_time;
    }
    //Bubble sort by arrival time the routing array.
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n-i;j++)
        {
            if (routing[j].arrival_time > routing[j+1].arrival_time)
            {
                swap(&routing[j],&routing[j+1]);
            }
        }
    }
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
    process *routing=malloc(n*sizeof(process));
    routing = sortByArrival(arr,n);
    for (int i=0;i<n;i++)
    {
        printf("%d - %d - %d\n",routing[i].pid, routing[i].arrival_time, routing[i].burst_time);
    }
	return 0; /* DO NOT EDIT THIS LINE */
}
