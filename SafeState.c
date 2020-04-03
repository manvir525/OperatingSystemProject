
/*There are 5 processes and 3 resource types, resource A with 10 instances, B with 5 instances and C with 7 instances.
 Consider following and write a c code to find whether the system is in safe state or not?

Available	Processes    Allocation	      Max
A	B	C	              A	 B  C	    A	B	C
3	3	2	P0	          0	 1  0	    7	5	3
        	P1	          2	 0	0	    3	2	2
	        P2	          3	 0	2	    9	0	2
	        P3	          2	 1	1	    2	2	2
	        P4	          0	 0	2	    4	3	3
*/


#include<stdio.h>
int main()
{
// There are Four Processes: P0,P1,P2,P3,P4
int processes, resources, p, q, r;
processes = 5;
resources = 3;

int allocation_matrix [5] [3] = {{0,1,0}, {2,0,0}, {3,0,2}, {2,1,1}, {0,0,2}}; // Allocation Matrix for: P0,P1,P2,P3,P4
int max_matrix [5] [3] = {{7,5,3}, {3,2,2}, {9,0,2}, {2,2,2}, {4,3,3}}; // Max Matrix for: P0,P1,P2,P3,P4
int available_resources [3] = {3,3,2}; // Available Resources

int x[processes], y[processes], z = 0;
for(r = 0; r < processes; r++)
{
  x[r] = 0;
}
int need[processes][resources];
for(p = 0; p < processes; p++)
{
  for(q = 0; q < resources; q++)
     need[p][q] = max_matrix[p][q] - allocation_matrix[p][q];
}
int i = 0;
for(r = 0; r < 5; r++)
{
  for(p = 0; p < processes; p++)
   {
     if(x[p] == 0)
      {
        int flag = 0;
        for( q = 0; q < resources; q++)
         {
           if(need[p][q] > available_resources[q])
            {
              flag = 1;
               break;
             }
          }
        if(flag == 0)
         {
           y[z++] = p;
           for(i = 0; i < resources; i++)
              available_resources[i] += allocation_matrix[p][i];
           x[p] = 1;
        }
      }
   }
}
printf("\n The System is in SAFE STATE!! \n   SAFE Sequence is: \n");
for(p = 0; p < processes - 1; p++)
   printf("     P%d -->", y[p]);
printf("P%d", y[processes - 1]);
return(0);
}
