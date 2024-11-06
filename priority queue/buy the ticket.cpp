/*
Problem statement
You want to buy a ticket for a well-known concert which is happening in your city. But the number of tickets available is limited. Hence the sponsors of the concert decided to sell tickets to customers based on some priority.

A queue is maintained for buying the tickets and every person is attached with a priority (an integer, 1 being the lowest priority).

The tickets are sold in the following manner -

1. The first person (pi) in the queue requests for the ticket.
2. If there is another person present in the queue who has higher priority than pi, then ask pi to move at end of the queue without giving him the ticket.
3. Otherwise, give him the ticket (and don't make him stand in queue again).
Giving a ticket to a person takes exactly 1 second and it takes no time for removing and adding a person to the queue. And you can assume that no new person joins the queue.

Given a list of priorities of N persons standing in the queue and the index of your priority (indexing starts from 0). Find and return the time it will take until you get the ticket.
*/

#include <queue>
int buyTicket(int *arr, int n, int k) {
    // Write your code here
    queue<int> p; //a queue of indices
    for(int i=0;i<n ;i++)
         p.push(i);
   
    
    priority_queue <int > pq;
    //build a heap
    for(int i=0 ; i<n ;i++)
    {
        pq.push(arr[i]);
    }
    
    int time=0;

while( p.front()!=k || pq.top()!= arr[p.front()] )  //unless ticket counter meets me and i am the priority .
{   //if less priority send at end of queue 
    if(pq.top()>arr[p.front()])
    { int x=p.front();
        p.pop();
       p.push(x);
    }
    
    else if(pq.top()==arr[p.front()])
    { pq.pop();
      p.pop();
       time++;			//incres time
    }
}
    return time+1;  //now i will be getting the ticket
}
