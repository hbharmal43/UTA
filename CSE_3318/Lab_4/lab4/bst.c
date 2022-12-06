/*
    Name: Hasnain Bharmal
    ID: 1001937588
*/
#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

linknode ascend_head, recycle_head;
linknode ascend_tail, recycle_tail;

link Root, z;
Item NULLitem = (-9999999);

int livenodes = 0;
int deadnodes = 0;
int recyclednodes = 0;

void STinit()
{
    z = (link)malloc(sizeof(struct STnode));
    z->item = NULLitem;
    z->l = NULL, z->r = NULL;
    z->N = 0;
    z->tombstone = '0';
    Root = z;
    ascend_head = NULL, recycle_head = NULL;
    ascend_tail = NULL, recycle_tail = NULL; 
}

void postorderfix(link *h)
{
    if (*h == z)
    {
        return;
    }

    postorderfix(&((*h)->l));
    postorderfix(&((*h)->r));

    if ((*h)->tombstone == '1')
    {
        (*h)->N = (*h)->l->N + (*h)->r->N;
    }
    else
    {
        (*h)->N = (*h)->l->N + (*h)->r->N + 1;
    }
}

int recursiveinsert(link *curr, link *t)
{
    if (*curr == z)
    {
        *curr = *t;
        recyclednodes = 0;
        livenodes++;
        return 0;
    }
    
    else if ((*curr)->item == (*t)->item)
    {
        if ((*curr)->tombstone == '1')
        {
            (*curr)->tombstone = '0';
            livenodes++;
            deadnodes--;
            return 0;
        }
        else
        {
            return 1;
        }
    }

    else
    {
        int duplicate = 0;
        if ((*curr)->item < (*t)->item)
        {
            duplicate = recursiveinsert(&((*curr)->r) , t);
        }
        else
        {
            duplicate = recursiveinsert(&((*curr)->l), t);
        }

        if (!duplicate)
        {
            (*curr)->N++;
            return 0;
        }
        else
        {
            return 1;
        }
    }
}

void STinsert(Item item)
{
    link t = (link) malloc(sizeof(struct STnode));
    t->item = item;
    t->l = z, t->r = z;
    t->N = 1;
    t->tombstone = '0';

    if (Root == z)
    {
        Root = t;
        livenodes++;
    }
    else
    {
        recursiveinsert(&Root, &t);
    }
    postorderfix(&Root);
}

Item selectkey(link h, int i)
{
    int r;
    if (h->tombstone == '0')
        r = h->l->N+1;
    else
        r = h->l->N;

    if (h == z)
    {
        printf("Impossible situation in select function\n");
        exit(0);
    }
    if (i == r)
    {
        if (h->tombstone == '0')
        {
            return h->item;
        }
        else if (h->l->tombstone == '1')
        {
            return selectkey(h->l, i);
        }
        else
        {
            return selectkey(h->r, i-r);
        }
    }
    if (i < r)
    {
        return selectkey(h->l, i);
    }
    return selectkey(h->r, i-r);
}   // Find node for a key

Item STselect(int k)
{
    link head = Root;
    return selectkey(head, k);
}   // Treat tree as flattened into an ordered array

int invSelect(link h, Key v)
{
    int work;
    if (h == z)
    {
        return -1;
    }

    if (v < h->item)
    {
        return invSelect(h->l, v);
    }
    if (h->item == v)
    {
        if (h->tombstone == '1')
        {
            invSelect(h->r, v);
        }
        else
            return (h->l->N)+1;
    }
    work = invSelect(h->r, v);
    if (work == (-1))
    {
        return -1;
    }

    if (h->tombstone == '0')
        return 1 + h->l->N + work;
    else
        return h->l->N + work;
}

int STinvSelect(Key v)
{
    link head = Root;
    return invSelect(head, v);
} 

int recursiveDelete(link *h, Key v)
{
    if (*h == z)
    {
        return 0;
    }
    else if ((*h)->item == v)
    {
        if ((*h)->tombstone == '0') // check if already deleted or not
        {
            (*h)->tombstone = '1';
            livenodes--;
            deadnodes++;
            return 1;
        }
        return 0;
    }
    else
    {
        int found;
        if ((*h)->item < v)
        {
            found = recursiveDelete(&((*h)->r), v);
        }
        else
        {
            found = recursiveDelete(&((*h)->l), v);
        }

        if (found == 1)
        {
            (*h)->N--;
            return 1;
        }
    }
}

void STdelete(Key v)
{
    link head = Root;
    recursiveDelete(&head, v);
    postorderfix(&Root);
}      

int check(link h, Item last)
{
    if (h == z)
    {
        return 1;
    }

    int leftcheck = check(h->l, last);
    if (!leftcheck)
        return 0;

    if (last >= h->item)
    {
        return 0;
    }
    else
    {
        if (h->tombstone == '0' && h->N == (h->l->N + h->r->N + 1))
        {
            return 1;
        }
        else if (h->tombstone == '1' && h->N == (h->l->N + h->r->N))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    
    last = h->item;
    int rightcheck = check(h->r, last);
    if (!rightcheck)
        return 0;
}

int verifyBSTproperties()
{
    return check(Root, NULLitem);
}    

void printTree(link h, int level)
{
    int i;

    if (h != z)
    {
        printTree(h->r, level+1);

        for (i = 0; i < level; i++)
        {
            printf("     ");
        }

        if (h->tombstone == '0')
        {
            printf("%d %d\n", h->item, h->N);
        }
        else
        {
            printf("(%d) %d\n", h->item, h->N);
        }

        printTree(h->l, level+1);
    }
    else
    {
        return;
    }
}

void STprintTree()
{
    link head = Root;
    int level = 0;
    printTree(head, level);
}         

int getLive()
{
    return livenodes;
}  // Number of nodes in tree with active keys.

int getDead()
{
    return deadnodes;
}  // Number of nodes in tree with tombstone set.

int getRecycled()
{
    return recyclednodes;
}  // Number of elements available from last removeDead()

int heightTree(link h)
{
    if (h == z)
    {
        return 0;
    }
    int leftheight = heightTree(h->l);
    int rightheight = heightTree(h->r);
    
    if (leftheight > rightheight)
    {
        return leftheight + 1;
    }
    else
    {
        return rightheight + 1;
    }
}

int getHeight()
{
    link head = Root;
    return heightTree(head);
}  // Longest path to sentinel

void fillLists(link *h)
{
    if (*h == z)
    {
        return;
    }

    fillLists(&((*h)->l));

    linknode t = (linknode) malloc(sizeof(struct LinkedListnode));
    t->bstnode = (link) (*h);
    t->next = NULL;

    if ((*h)->tombstone == '0')
    {
        if (ascend_head == NULL)
        {
            ascend_head = (linknode) t;
            ascend_tail = (linknode) t;
        }
        else
        {
            ascend_tail->next = (linknode) t;
            ascend_tail = ascend_tail->next;
        }
    }
    else
    {
        if (recycle_head == NULL)
        {
            recycle_head = (linknode) t;
            recycle_tail = (linknode) t;
        }
        else
        {
            recycle_tail->next = (linknode) t;
            recycle_tail = recycle_tail->next;
        }
        recyclednodes++;
    }

    fillLists(&((*h)->r));
}

link loadNewTree(int count)
{
    int leftCount, rightCount;
    link work, left;

    if (count == 0)
    {
        return z;
    }

    leftCount = count/2;
    rightCount = count-leftCount-1;

    left = (link) loadNewTree(leftCount);
    work = (link) ascend_tail->bstnode;
    ascend_tail = ascend_tail->next;
    work->l = left;
    work->r = (link) loadNewTree(rightCount);
    work->N = work->l->N + work->r->N + 1;

    return work;
}

void removeDead()
{
    ascend_head = ascend_tail = recycle_head = recycle_tail = NULL;
    deadnodes = 0;
    recyclednodes = 0;

    fillLists(&Root);
    printf("Got here too\n");

    ascend_tail = ascend_head;
    Root = loadNewTree(livenodes);

    return;
} 
