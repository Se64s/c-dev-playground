#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <criterion/criterion.h>

bool solution(const char *string, const char *ending);

static void test_solution(const char *string, const char *ending, bool expected)
{
    bool actual = solution(string, ending);
    cr_assert_eq(actual, expected,
        "solution(\"%s\", \"%s\") should return %s, actual: %s",
        string, ending, (expected)? "true": "false", (actual)? "true": "false");
}

Test(solution, should_pass_some_example_tests)
{
    test_solution("samurai", "ai", true);
    test_solution("sumo", "omo", false);
    test_solution("ninja", "ja", true);
    test_solution("sensei", "i", true);
    test_solution("samurai", "ra", false);
    test_solution("abc", "abcd", false);
    test_solution("abc", "abc", true);
    test_solution("abcabc", "bc", true);
    test_solution("ails", "fails", false);
    test_solution("fails", "ails", true);
    test_solution("this", "fails", false);
    test_solution("abc", "", true);
    test_solution(":-)", ":-(", false);
    test_solution("!@#$%^&*() :-)", ":-)", true);
}

static char *create_random_string(size_t length, const char *alphabet)
{
    if (!alphabet)
        alphabet = "abcdefghijklmnopqrstuvwxyz";
    size_t alphabet_length = strlen(alphabet);
    char *result = (char *) malloc((length + 1) * sizeof(char));
    if (!result)
        return NULL;
    for (size_t i = 0; i < length; ++i)
        result[i] = alphabet[rand() % alphabet_length];
    result[length] = '\0';
    return result;
}

Test(solution, should_pass_some_random_tests)
{
    srand(time(NULL));
    for (int i = 0; i < 100; ++i)
    {
        int string_length = rand() % 10;
        char *string = create_random_string(string_length, "ab");
        int ending_length = rand() % 10;
        char *ending = create_random_string(ending_length, "ab");
        if (!string || !ending)
            cr_assert_fail("INTERNAL ERROR: could not allocate memory");
        bool expected = string_length >= ending_length && strcmp(string + string_length - ending_length, ending) == 0;;
        test_solution(string, ending, expected);
        free(ending);
        free(string);
    }
}
