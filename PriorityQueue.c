#include <stdio.h>
#include <limits.h>
#include<stdlib.h>
struct item {
    int value, priority;
};

struct item pr[100000];
int size = -1;

// Function to insert element in priority queue
void enqueue(int value, int priority) {
    pr[++size] = (struct item){value, priority};
}

// Function to get index of element with highest priority
int peek() {
    int highestPriority = INT_MIN, ind = -1;
    for (int i = 0; i <= size; i++) {
        if (pr[i].priority > highestPriority || 
           (pr[i].priority == highestPriority && pr[i].value > pr[ind].value)) {
            highestPriority = pr[i].priority;
            ind = i;
        }
    }
    return ind;
}

// Function to remove the element with highest priority
void dequeue() {
    int ind = peek();
    for (int i = ind; i < size; i++) {
        pr[i] = pr[i + 1];
    }
    size--;
}
void show() {
    for (int i =0; i <=size; i++) {
        printf("\n %d\t %d",pr[i].value, pr[i].priority);
    }
}
int main() {
    int ch,pri,val;
    while(1)
    {
        printf("\n 1. Enqueue");
        printf("\n 2. Dequeue");
        printf("\n 3. Display");
        printf("\n 4. Peek");
        printf("\n 0. Exit");
        printf("\n Enter choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\n Enter value and priority");
                    scanf("%d%d",&val,&pri);
                    enqueue(val, pri);
                    break;
            case 2:dequeue();
                    break;
            case 3: show();
                    break;
            case 4: printf("%d\n", pr[peek()].value);
                    break;
            case 0: exit(0);
                    break;
            default: printf("\n Wrong choice");
        }
    }
    return 0;
}