#ifndef __ASSERT_H
#define __ASSERT_H

void display_test_result(Status actual, Char_ptr message);
Status assert_lists(Int_ptr expected, int length, List_ptr actual);

#endif