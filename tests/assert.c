#include <stdio.h>
#include "../list.h"
#include "assert.h"

void display_test_result(Status actual, Char_ptr message)
{
  if (actual == Success)
  {
    printf("✓ %s is successfully done\n", message);
  }
  else
  {
    printf("✗ %s is failed\n", message);
  }
}

Status assert_lists(Int_ptr expected, int length, List_ptr actual)
{
  if (actual->count != length)
  {
    return Failure;
  }
  int index = 0;
  Node_ptr p_walk = actual->head;
  while (p_walk != NULL && p_walk->value == expected[index])
  {
    p_walk = p_walk->next;
    index++;
  }
  return p_walk == NULL ? Success : Failure;
}