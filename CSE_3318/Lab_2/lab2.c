/*
    Name: Hasnain Bharmal
    ID: 1001937588
    Got Minheap code from StackOverflow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Innit
{
  int indexfilepointer;
  char String[50];
};

typedef struct Innit minheapelement;
typedef struct MinHeap MinHeap;
struct MinHeap
{
  minheapelement *arr;
  int size;
  int capacity;
};

int parent(int i)
{
  return (i - 1) / 2;
}

int left_child(int i)
{
  return (2 * i + 1);
}

int right_child(int i)
{
  return (2 * i + 2);
}
minheapelement get_min(MinHeap *heap)
{
  return heap->arr[0];
}
MinHeap *heapify(MinHeap *heap, int index)
{
  if (heap->size <= 1)
    return heap;
  int left = left_child(index);
  int right = right_child(index);

  int smallest = index;

  if (left < heap->size && strcmp(heap->arr[left].String, heap->arr[index].String) < 0)
    smallest = left;

  if (right < heap->size && strcmp(heap->arr[right].String, heap->arr[smallest].String) < 0)
    smallest = right;

  if (smallest != index)
  {
    minheapelement temp = heap->arr[index];
    heap->arr[index] = heap->arr[smallest];
    heap->arr[smallest] = temp;
    heap = heapify(heap, smallest);
  }

  return heap;
}

MinHeap *init_minheap(int capacity)
{
  MinHeap *minheap = (MinHeap *)calloc(1, sizeof(MinHeap));
  minheap->arr = (minheapelement *)calloc(capacity, sizeof(minheapelement));
  minheap->capacity = capacity;
  minheap->size = 0;
  return minheap;
}

MinHeap *insert_minheap(MinHeap *heap, minheapelement *element) // The main minheap function
{

  if (heap->size == heap->capacity)
  {
    fprintf(stderr, "Cannot insert %s. Heap is already full!\n", element->String);
    return heap;
  }
  heap->size++;
  heap->arr[heap->size - 1] = *element;
  int curr = heap->size - 1;

  while (curr > 0 && strcmp(heap->arr[parent(curr)].String, heap->arr[curr].String) > 0)
  {
    minheapelement temp = heap->arr[parent(curr)];
    heap->arr[parent(curr)] = heap->arr[curr];
    heap->arr[curr] = temp;
    curr = parent(curr);
  }
  return heap;
}

MinHeap *delete_minimum(MinHeap *heap) // this function will delete minimum of minheap
{
  if (!heap || heap->size == 0)
    return heap;

  int size = heap->size;
  minheapelement *last_element = &heap->arr[size - 1];

  heap->arr[0] = *last_element;

  heap->size--;
  size--;

  heap = heapify(heap, 0);
  return heap;
}

void free_minheap(MinHeap *heap) // this function will free the minheap
{
  if (!heap)
    return;
  free(heap->arr);
  free(heap);
}

void print_heap(MinHeap *heap) // this function will simply print the array
{
  printf("Min Heap:\n");
  for (int i = 0; i < heap->size; i++)
  {
    printf("%s-> ", heap->arr[i].String);
  }
  printf("\n");
}

int main(void)
{
  FILE *ptr = fopen("in.dat", "r"); // opening in.dat file
  char n[5];
  fgets(n, 4, ptr);
  int filecount;
  sscanf(n, "%d", &filecount);

  FILE *files[filecount];
  char filename[40];
  MinHeap *heap = init_minheap(filecount);
  int i;
  for (i = 0; i < filecount; i++)
  {
    fgets(filename, 39, ptr);
    if (filename[strlen(filename) - 1] == '\n')
    {
      filename[strlen(filename) - 1] = '\0';
    }
    files[i] = fopen(filename, "r"); // here i am openeing the filesand putting filename from above
    minheapelement element;          //
    element.indexfilepointer = i;
    fgets(element.String, 49, files[i]);
    if (element.String[strlen(element.String) - 1] == '\n')
    {
      element.String[strlen(element.String) - 1] = '\0';
    }
    insert_minheap(heap, &element);
  }

  fclose(ptr);

  FILE *fptr = fopen("out.dat", "w");

  char string_w[50];
  char newstring[50];
  minheapelement min = get_min(heap);
  strcpy(string_w, min.String);
  int k = 1;
  delete_minimum(heap);
  if (fgets(newstring, 49, files[min.indexfilepointer])) // this is the code to set up the target string to compare other
  {                                                      // with other elements
    if (newstring[strlen(newstring) - 1] == '\n')
    {
      newstring[strlen(newstring) - 1] = '\0';
    }
    minheapelement newel;
    newel.indexfilepointer = min.indexfilepointer;
    strcpy(newel.String, newstring);
    insert_minheap(heap, &newel);
  }

  do
  {
    min = get_min(heap);
    if (strcmp(string_w, min.String) == 0)
    {
      k++;
    }
    else
    {
      fprintf(fptr, "%s %d\n", string_w, k);
      strcpy(string_w, min.String);
      k = 1;
    }
    delete_minimum(heap);
    if (fgets(newstring, 49, files[min.indexfilepointer])) // if there is a string left in the file, insert into heap
    {
      if (newstring[strlen(newstring) - 1] == '\n')
      {
        newstring[strlen(newstring) - 1] = '\0';
      }
      minheapelement newel;
      newel.indexfilepointer = min.indexfilepointer;
      strcpy(newel.String, newstring);
      insert_minheap(heap, &newel);
    }
    if (heap->size == 0)
    {
      fprintf(fptr, "%s %d\n", string_w, k); // writing for last string
    }
  } while (heap->size != 0);

  free_minheap(heap);
  for (int i = 0; i < filecount; i++)
  {
    fclose(files[i]);
  }
  fclose(fptr);
}