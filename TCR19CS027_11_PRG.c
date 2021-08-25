#include <stdio.h>
#include <stdlib.h>

struct arr
{
  int k;
  int data;
};
struct arr *array;
int capacity = 10;
int size = 0;

int hashFunction(int k)
{
  return (k % capacity);
}
int checkPrime(int n)
{
  int i;
  if (n == 1 || n == 0)
  {
    return 0;
  }
  for (i = 2; i < n / 2; i++)
  {
    if (n % i == 0)
    {
      return 0;
    }
  }
  return 1;
}
int getPrime(int n)
{
  if (n % 2 == 0)
  {
    n++;
  }
  while (!checkPrime(n))
  {
    n += 2;
  }
  return n;
}
void init_array()
{
  capacity = getPrime(capacity);
  array = (struct arr *)malloc(capacity * sizeof(struct arr));
  for (int i = 0; i < capacity; i++)
  {
    array[i].k = 0;
    array[i].data = 0;
  }
}

void insert(int k, int data)
{
  int index = hashFunction(k);
  if (array[index].data == 0)
  {
    array[index].k = k;
    array[index].data = data;
    size++;
    printf("\n Key (%d) has been inserted \n", k);
  }
  else if (array[index].k == k)
  {
    array[index].data = data;
  }
  else
  {
    printf("\n Collision occured  \n");
  }
}

void remove_element(int k)
{
  int index = hashFunction(k);
  if (array[index].data == 0)
  {
    printf("\n This k does not exist \n");
  }
  else
  {
    array[index].k = 0;
    array[index].data = 0;
    size--;
    printf("\n K (%d) has been removed \n", k);
  }
}
void display()
{
  int i;
  for (i = 0; i < capacity; i++)
  {
    if (array[i].data == 0)
    {
      printf("\n array[%d]: / ", i);
    }
    else
    {
      printf("\n k: %d array[%d]: %d \t", array[i].k, i, array[i].data);
    }
  }
}

int size_of_hashtable()
{
  return size;
}

int main()
{
  int choice, k, data, n;
  int c = 0;
  init_array();

  do
  {
    printf("1.Insert item in the Hash Table"
         "\n2.Remove item from the Hash Table"
         "\n3.Check the size of Hash Table"
         "\n4.Display a Hash Table"
         "\n\n Please enter your choice: ");

    scanf("%d", &choice);
    switch (choice)
    {
    case 1:

      printf("Enter k -:\t");
      scanf("%d", &k);
      printf("Enter data -:\t");
      scanf("%d", &data);
      insert(k, data);

      break;

    case 2:

      printf("Enter the key to delete-:");
      scanf("%d", &k);
      remove_element(k);

      break;

    case 3:

      n = size_of_hashtable();
      printf("Size of Hash Table is-:%d\n", n);

      break;

    case 4:

      display();

      break;

    default:

      printf("Invalid Input\n");
    }

    printf("\nDo you want to continue (press 1 for yes): ");
    scanf("%d", &c);

  } while (c == 1);
}