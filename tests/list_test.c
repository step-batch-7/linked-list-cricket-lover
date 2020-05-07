#include <stdio.h>
#include "../list.h"
#include "assert.h"

void test_add_to_end(void)
{
  printf("#add_to_end\n");
  List_ptr list = create_list();
  int expected[2] = {2};
  add_to_end(list, 2);
  Status result = assert_lists(expected, 1, list);
  display_test_result(result, "adds one element to the end of the list, when the list is empty");

  expected[1] = 3;
  add_to_end(list, 3);
  result = assert_lists(expected, 2, list);
  display_test_result(result, "adds one element to the end of the list, when the list is not empty");
}

void test_add_to_start(void)
{
  printf("#add_to_start\n");
  List_ptr list = create_list();
  int expected[2] = {2};
  add_to_start(list, 2);
  Status result = assert_lists(expected, 1, list);
  display_test_result(result, "adds one element to the start of the list, when the list is empty");

  expected[0] = 3;
  expected[1] = 2;
  add_to_start(list, 3);
  result = assert_lists(expected, 2, list);
  display_test_result(result, "adds one element to the start of the list, when the list is not empty");
}

void insert_at_zero(List_ptr list, Int_ptr expected)
{
  insert_at(list, 2, 1);
  Status result = assert_lists(expected, 0, list);
  display_test_result(result, "should not insert at any position other than zero when the list is empty");

  expected[0] = 2;
  insert_at(list, 2, 0);
  result = assert_lists(expected, 1, list);
  display_test_result(result, "inserts one element to the start of the list, when the list is empty");

  expected[0] = 3;
  expected[1] = 2;
  insert_at(list, 3, 0);
  result = assert_lists(expected, 2, list);
  display_test_result(result, "inserts one element to the start of the list, when the list is not empty");
}

void test_insert_at(void)
{
  printf("#insert_at\n");
  List_ptr list = create_list();
  int expected[4] = {};
  insert_at_zero(list, expected);
}

void run_tests(void)
{
  printf("running tests......\n\n");
  test_add_to_end();
  test_add_to_start();
  test_insert_at();
  printf("\n......finished tests\n");
}

int main(void)
{
  run_tests();
}