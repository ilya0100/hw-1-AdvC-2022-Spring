#include "utils.hpp"


TEST(GoodCase, CompareData) {
    char *str = "6Samsung 3 9 8Apple 3 4 8Lenovo 9 3 2Apple 4 5 3Samsung 2 4 8Apple 2 4 9";
    FILE *data = fmemopen(str, strlen(str), "r");
    List list = {0};

    ASSERT_EQ(0, group_data(&list, data));

    char *test_str = "6Samsung 3 9 8Samsung 2 4 8Apple 3 4 8Apple 4 5 3Apple 2 4 9Lenovo 9 3 2";
    FILE *test_data = fmemopen(test_str, strlen(test_str), "r");
    List test_list = {0};

    ASSERT_EQ(0, group_data(&test_list, test_data));
    EXPECT_EQ(true, listcmp(list, test_list));

    clear_list(&list);
    clear_list(&test_list);
    fclose(data);
    fclose(test_data);
}

TEST(GoodCase, BaseTest) {
    char *test_str = "5Apple 3 4.4 2HP 5 3 6Apple 4 5 9HP 3 3.8 12Asus 5 2 4";
    FILE *test_data = fmemopen(test_str, strlen(test_str), "r");
    List test_list = {0};

    ASSERT_EQ(0, group_data(&test_list, test_data));

    clear_list(&test_list);
    fclose(test_data);
}

TEST(NegCase, BadElementsCount) {
    char *test_str = "abcd 1 2 3bcde 2 3 4";
    FILE *test_data = fmemopen(test_str, strlen(test_str), "r");
    List test_list = {0};

    ASSERT_EQ(-1, group_data(&test_list, test_data));

    clear_list(&test_list);
    fclose(test_data);
}

TEST(NegCase, BadElement) {
    char *test_str = "1abcd 1 2";
    FILE *test_data = fmemopen(test_str, strlen(test_str), "r");
    List test_list = {0};
    
    ASSERT_EQ(-1, group_data(&test_list, test_data));

    clear_list(&test_list);
    fclose(test_data);
}