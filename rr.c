#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int pid;
	int arrival_time;
	int burst_time;
} process;

//Initialization of a queue made from process.
process* queue[1000];
//A counter that stores the number of elements in the queue.
int tail=0;

/*
 * Function that adds a process in the queue.
 */
void enqueue(process* p)
{
    queue[tail] = p;
    tail++;
    return;
}

/*
 * Secondary function for swapping places in two processes.
 */
void swapProcesses(process* x, process* y)
{
    process temp = *x;
    *x = *y;
    *y = temp;
}

/*
 * Bubble Sort algorithm that sorts all elements of the queue except the first element(the process that is currently
 * executed by the CPU).
 */
void sortbyBurst(process* arr[], int n)
{
    //Bubble sort by burst time the routing array.
    for (int i=1;i<n;i++)
    {
        for (int j=1;j<n-i;j++)
        {
            if (arr[j]->burst_time > arr[j+1]->burst_time)
            {
                swapProcesses(arr[j],arr[j+1]);
            }
        }
    }
}

/*
 * Round Robin routing algorithm.
 */
void roundRobin()
{
    //Sort the queue except the first element(the process that is currently executed).
    sortbyBurst(queue,tail);
    //If current process hasn't ended (quantum expired)
    if (queue[0]->burst_time > 0)
    {
        //Keep the process
        process* temp = queue[0];
        //Move all processes to the left by one position.
        for (int i=0;i<tail-1;i++)
        {
            queue[i] = queue[i+1];
        }
        //Put the current process to the end of the queue
        queue[tail-1] = temp;
    }
    else //The current process has ended
    {
        //Move all processes to the left by one position.
        for (int i=0;i<tail-1;i++)
        {
            queue[i] = queue[i+1];
        }
        //Decrease the tail by one.
        tail--;
    }
    return;
}

/*
 * Function that returns the process that is executed or is about to by the CPU.
 */
process* pickNextProcess()
{
    return queue[0];
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

    // Round Robin Preemptive
    enqueue(&arr[0]);
    int pid_counter = queue[0]->pid; //Counter that keeps track of the current process in CPU
    int quantum_counter = 0;
    for (int i=0;i<total_time;i++)
    {
        //Check if any new processes have arrived.
        if (i>0)
        {
            //Look if the current time is arrival time for any of the processes.
            for (int j=1;j<n;j++)
            {
                //If a process has arrived
                if (i == arr[j].arrival_time)
                {
                    //Put the process in the queue.
                    enqueue(&arr[j]);
                }
            }
        }
        //If a process has finished or its quantum has expired
        if (queue[0]->burst_time == 0 || quantum_counter == quantum)
        {
            //Reset the quantum counter.
            quantum_counter=0;
            //Decide next process to be executed by CPU by Round Robin.
            roundRobin();
            //Store the process-to-be-executed to variable pid_counter.
            pid_counter = pickNextProcess()->pid;
        }
        //Print the current process in CPU.
        printf("%d\n",pid_counter);
        //Decrease by one the burst time of current process in CPU.
        queue[0]->burst_time--;
        //Increase the quantum counter by one.
        quantum_counter++;
    }
	return 0; /* DO NOT EDIT THIS LINE */
}
