/*
    Name: Hasnain Bharmal
    ID: 1001937588
    command i used to comile on omega 
    1st command-->gcc -c bst.c                             
    2nd Command-->gcc -c lab4.c
    3rd Command-->gcc bst.o lab4.o -o lab4
    4th Command-->./lab4 < a.dat
*/
#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

int main()
{
    int op,key,rank;

    STinit();  // Initialize binary search tree
    verifyBSTproperties();

    scanf("%d",&op);
    while (op)
    {
        switch (op)
        {
            case 1:
                scanf("%d",&key);
                printf("1 %d\n",key);
                STinsert(key);
                break;
            case 2:
                scanf("%d",&key);
                printf("2 %d\n",key);
                STdelete(key);
                break;
            case 3:
                scanf("%d",&key);
                printf("3 %d\n",key);
                rank=STinvSelect(key);
                if (rank==(-1))
                    printf("Key %d is not in tree\n",key);
                else
                    printf("Key %d has rank %d\n",key,rank);
                break;
            case 4:
                scanf("%d",&rank);
                printf("4 %d\n",rank);
                if (rank<1 || rank>getLive())
                    printf("rank %d range error\n",rank);
                else
                    printf("rank %d has key %d\n",rank,key(STselect(rank)));
                break;
            case 5:
                printf("5\n");
                printf("Live %d Dead %d Recycled %d Height %d\n",
                    getLive(),getDead(),getRecycled(),getHeight());
                break;
            case 6:
                printf("6\n");
                removeDead();
                break;
            case 7:
                printf("7\n");
                STprintTree();
                break;
            case 8:
                printf("8\n");
                if (verifyBSTproperties())
                    printf("clean\n");
                else
                    printf("corrupt\n");
                break;
            default:
                printf("Bad operation %d\n",op);
        }
        
        scanf("%d",&op);
    }
}
