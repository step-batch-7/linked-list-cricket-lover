#include <stdio.h>
#include "../list.c"

void assert_equal(Status expected, Status actual, Char_ptr message)
{
  if (expected == actual)
  {
    printf("✓ %s is successfully done\n", message);
  }
  else
  {
    printf("✗ %s is failed\n", message);
  }
}

void run_tests(void)
{
  printf("running tests......\n\n");
  List_ptr list = create_list();
  Status expected = Success;

  Status actual = add_to_end(list, 2);
  assert_equal(expected, actual, "testing add_to_end");

  actual = add_to_start(list, 2);
  assert_equal(expected, actual, "testing add_to_start");

  actual = add_unique(list, 3);
  assert_equal(expected, actual, "testing add_unique");

  expected = Failure;
  actual = add_unique(list, 2);
  assert_equal(expected, actual, "testing add_unique");

  printf("\n......finished tests\n");
}

int main(void)
{
  run_tests();
}