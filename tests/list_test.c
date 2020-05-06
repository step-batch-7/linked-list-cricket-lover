#include <stdio.h>
#include "../list.h"

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
  return Success;
}

void test_add_to_end(void)
{
  List_ptr list = create_list();
  int expected[1] = {2};
  add_to_end(list, 2);
  Status result = assert_lists(expected, 1, list);
  display_test_result(result, "tests of add_to_end");
}

void run_tests(void)
{
  printf("running tests......\n\n");
  test_add_to_end();
  printf("\n......finished tests\n");
}

int main(void)
{
  run_tests();
}