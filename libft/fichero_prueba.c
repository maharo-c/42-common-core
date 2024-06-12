#include <stdio.h>
#include "libft.h"

void print_split_result(char **result) {
    if (!result) {
        printf("NULL\n");
        return;
    }
    int i = 0;
    while (result[i]) {
        printf("result[%d]: %s\n", i, result[i]);
        i++;
    }
    // Free the allocated memory
    ft_free(result, i);
}

int main() {
    char **result;

    printf("Test 1:\n");
    result = ft_split("hello world this is a test", ' ');
    print_split_result(result);

    printf("\nTest 2:\n");
    result = ft_split("one,two,three,four", ',');
    print_split_result(result);

    printf("\nTest 3:\n");
    result = ft_split("   leading and trailing spaces   ", ' ');
    print_split_result(result);

    printf("\nTest 4:\n");
    result = ft_split("no delimiters", ',');
    print_split_result(result);

    printf("\nTest 5:\n");
    result = ft_split(",,,multiple,,,delimiters,,,", ',');
    print_split_result(result);

    printf("\nTest 6:\n");
    result = ft_split(NULL, ',');
    print_split_result(result);

    return 0;
}