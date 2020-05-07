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
  display_test_result(result, "should add one element to the end of the list, when the list is empty");

  expected[1] = 3;
  add_to_end(list, 3);
  result = assert_lists(expected, 2, list);
  display_test_result(result, "should add one element to the end of the list, when the list is not empty");
}

void test_add_to_start(void)
{
  printf("#add_to_start\n");
  List_ptr list = create_list();
  int expected[2] = {2};
  add_to_start(list, 2);
  Status result = assert_lists(expected, 1, list);
  display_test_result(result, "should add one element to the start of the list, when the list is empty");

  expected[0] = 3;
  expected[1] = 2;
  add_to_start(list, 3);
  result = assert_lists(expected, 2, list);
  display_test_result(result, "should add one element to the start of the list, when the list is not empty");
}

void insert_at_start(List_ptr list, Int_ptr expected)
{
  insert_at(list, 2, 1);
  Status result = assert_lists(expected, 0, list);
  display_test_result(result, "should not insert at any position other than start when the list is empty");

  expected[0] = 2;
  insert_at(list, 2, 0);
  result = assert_lists(expected, 1, list);
  display_test_result(result, "should insert one element to the start of the list, when the list is empty");

  expected[0] = 3;
  expected[1] = 2;
  insert_at(list, 3, 0);
  result = assert_lists(expected, 2, list);
  display_test_result(result, "should insert one element to the start of the list, when the list is not empty");
}

void insert_at_middle(List_ptr list, Int_ptr expected)
{
  expected[1] = 4;
  expected[2] = 2;
  insert_at(list, 4, 1);
  Status result = assert_lists(expected, 3, list);
  display_test_result(result, "should insert at given position if the position is valid");

  insert_at(list, 5, 6);
  result = assert_lists(expected, 3, list);
  display_test_result(result, "should not insert when the position is more than than maximum position");

  insert_at(list, 5, -1);
  result = assert_lists(expected, 3, list);
  display_test_result(result, "should not insert when the position less than zero");
}

void insert_at_end(List_ptr list, Int_ptr expected)
{
  expected[3] = 5;
  insert_at(list, 5, 3);
  Status result = assert_lists(expected, 4, list);
  display_test_result(result, "should insert at last position when the position is equal to the length of the list");
}

void test_insert_at(void)
{
  printf("#insert_at\n");
  List_ptr list = create_list();
  int expected[4] = {};
  insert_at_start(list, expected);
  insert_at_middle(list, expected);
  insert_at_end(list, expected);
}

void test_add_unique(void)
{
  printf("#add_unique\n");
  List_ptr list = create_list();
  int expected[4] = {2};
  add_unique(list, 2);
  Status result = assert_lists(expected, 1, list);
  display_test_result(result, "should add any given number when the list is empty");

  expected[1] = 3;
  add_unique(list, 3);
  result = assert_lists(expected, 2, list);
  display_test_result(result, "should add when the given number is not present in the list");

  expected[1] = 3;
  add_unique(list, 2);
  result = assert_lists(expected, 2, list);
  display_test_result(result, "should not add when the given number is present in the list");
}

void test_remove_from_start(void)
{
  printf("#remove_from_start\n");
  List_ptr list = create_list();
  int expected[4] = {};
  remove_from_start(list);
  Status result = assert_lists(expected, 0, list);
  display_test_result(result, "should not remove anything when the list is empty");

  add_to_start(list, 2);
  remove_from_start(list);
  result = assert_lists(expected, 0, list);
  display_test_result(result, "should remove first item when the list has only one item");

  insert_at(list, 2, 0);
  insert_at(list, 3, 1);
  remove_from_start(list);
  expected[0] = 3;
  result = assert_lists(expected, 1, list);
  display_test_result(result, "should remove first item from the list");
}

void run_tests(void)
{
  printf("running tests......\n\n");
  test_add_to_end();
  test_add_to_start();
  test_insert_at();
  test_add_unique();
  test_remove_from_start();
  printf("\n......finished tests\n");
}

int main(void)
{
  run_tests();
}