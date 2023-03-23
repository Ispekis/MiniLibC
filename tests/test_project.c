/*
** EPITECH PROJECT, 2023
** B-ASM-400-PAR-4-1-asmminilibc-vincent.shao
** File description:
** test_project
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <dlfcn.h>
#include <stdio.h>
// extern long unsigned int strlen(const char* str);
// extern char* strchr(const char *str, int c);

/*Test(strlen, do_strlen_normal)
{
    char *str = "teststr";

    cr_assert_eq(strlen(str), 7);
}

Test(strlen, do_strlen_empty)
{
    char *str = "";

    cr_assert_eq(strlen(str), 0);
}

Test(strchr, do_strchr_normal)
{
    // const char *str = "http://www.tutorialspoint.com";

    // char *chr = strchr(str, '.');
    // printf("%d for '%d' and '%d'\n", chr == ".tutorialspoint.com", strlen(chr), strlen(".tutorialspoint.com"));
    // cr_assert_eq(chr, ".tutorialspoint.com");
}*/

Test(my_strrchr, simple_occurence_test)
{
    void *handle;
    size_t (*my_strrchr)(const char *, int c);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strrchr = dlsym(handle, "strrchr");

    char *str = "http://www.tutorialspoint.com";
    cr_assert_eq(my_strrchr(str, '.'), strrchr(str, '.'));

    dlclose(handle);
}

Test(my_strrchr, no_occurence_test)
{
    void *handle;
    size_t (*my_strrchr)(const char *, int c);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strrchr = dlsym(handle, "strrchr");

    char *str = "http://www.tutorialspoint.com";
    cr_assert_eq(my_strrchr(str, '7'), strrchr(str, '7'));

    dlclose(handle);
}

Test(my_strrchr, multiple_occurence_test)
{
    void *handle;
    size_t (*my_strrchr)(const char *, int c);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strrchr = dlsym(handle, "strrchr");

    char *str = "http://www.tutorialspoint.com";
    cr_assert_eq(my_strrchr(str, 'w'), strrchr(str, 'w'));

    dlclose(handle);
}

Test(my_strrchr, occurence_at_first_index_test)
{
    void *handle;
    size_t (*my_strrchr)(const char *, int c);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strrchr = dlsym(handle, "strrchr");

    char *str = "http://www.tutorialspoint.com";
    cr_assert_eq(my_strrchr(str, 'h'), strrchr(str, 'h'));

    dlclose(handle);
}

Test(my_strrchr, occurence_at_last_index_test)
{
    void *handle;
    size_t (*my_strrchr)(const char *, int c);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strrchr = dlsym(handle, "strrchr");

    char *str = "http://www.tutorialspoint.com";
    cr_assert_eq(my_strrchr(str, 'm'), strrchr(str, 'm'));

    dlclose(handle);
}

Test(my_strrchr, null_occurence_test)
{
    void *handle;
    size_t (*my_strrchr)(const char *, int c);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strrchr = dlsym(handle, "strrchr");

    char *str = "http://www.tutorialspoint.com";
    cr_assert_eq(my_strrchr(str, '\0'), strrchr(str, '\0'));

    dlclose(handle);
}

Test(my_strstr, strstr_normal_test)
{
    void *handle;
    char* (*my_strstr)(const char *haystack, const char *needle);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strstr = dlsym(handle, "strstr");

    char str1[] = "Hello, world!";
    char str2[] = "world";

    cr_assert_eq(my_strstr(str1, str2), strstr(str1, str2));

    dlclose(handle);
}

Test(my_strstr, strstr_not_occurence)
{
    void *handle;
    char* (*my_strstr)(const char *haystack, const char *needle);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strstr = dlsym(handle, "strstr");

    char str1[] = "Hello, world!";
    char str2[] = "8";

    cr_assert_eq(my_strstr(str1, str2), strstr(str1, str2));

    dlclose(handle);
}

Test(my_strstr, str_str_empty)
{
    void *handle;
    char* (*my_strstr)(const char *haystack, const char *needle);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strstr = dlsym(handle, "strstr");

    char str1[] = "";
    char str2[] = "";

    cr_assert_eq(my_strstr(str1, str2), strstr(str1, str2));

    dlclose(handle);
}

Test(my_strstr, strstr_first_occ)
{
    void *handle;
    char* (*my_strstr)(const char *haystack, const char *needle);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strstr = dlsym(handle, "strstr");

    char str1[] = "Hello world";
    char str2[] = "H";

    cr_assert_eq(my_strstr(str1, str2), strstr(str1, str2));

    dlclose(handle);
}

Test(my_strstr, strstr_last_occ)
{
    void *handle;
    char* (*my_strstr)(const char *haystack, const char *needle);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strstr = dlsym(handle, "strstr");

    char str1[] = "Hello world";
    char str2[] = "w";

    cr_assert_eq(my_strstr(str1, str2), strstr(str1, str2));

    dlclose(handle);
}

Test(my_strstr, strstr_inversed_occ)
{
    void *handle;
    char* (*my_strstr)(const char *haystack, const char *needle);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strstr = dlsym(handle, "strstr");

    char str1[] = "Hello world";
    char str2[] = "dl";

    cr_assert_eq(my_strstr(str1, str2), strstr(str1, str2));

    dlclose(handle);
}

Test(my_strstr, strstr_inversed_test_maj)
{
    void *handle;
    char* (*my_strstr)(const char *haystack, const char *needle);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strstr = dlsym(handle, "strstr");

    char str1[] = "One More test!";
    char str2[] = "One more";

    cr_assert_eq(my_strstr(str1, str2), strstr(str1, str2));

    dlclose(handle);
}

Test(my_strpbrk, strpbrk_normal_test)
{
    void *handle;
    char* (*my_strpbrk)(const char *haystack, const char *needle);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strpbrk = dlsym(handle, "strpbrk");

    char str1[] = "Hello world";
    char str2[] = "wr";

    cr_assert_eq(my_strpbrk(str1, str2), strpbrk(str1, str2));

    dlclose(handle);
}

Test(my_strpbrk, strpbrk_last)
{
    void *handle;
    char* (*my_strpbrk)(const char *haystack, const char *needle);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strpbrk = dlsym(handle, "strpbrk");

    char str1[] = "Hello world";
    char str2[] = "d";

    cr_assert_eq(my_strpbrk(str1, str2), strpbrk(str1, str2));

    dlclose(handle);
}

Test(my_strpbrk, strpbrk_fisrt)
{
    void *handle;
    char* (*my_strpbrk)(const char *haystack, const char *needle);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strpbrk = dlsym(handle, "strpbrk");

    char str1[] = "Hello world";
    char str2[] = "H";

    cr_assert_eq(my_strpbrk(str1, str2), strpbrk(str1, str2));

    dlclose(handle);
}

Test(my_strpbrk, strpbrk_multiple)
{
    void *handle;
    char* (*my_strpbrk)(const char *haystack, const char *needle);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strpbrk = dlsym(handle, "strpbrk");

    char str1[] = "Hello world";
    char str2[] = "ddd";

    cr_assert_eq(my_strpbrk(str1, str2), strpbrk(str1, str2));

    dlclose(handle);
}

Test(my_strpbrk, strpbrk_empty)
{
    void *handle;
    char* (*my_strpbrk)(const char *haystack, const char *needle);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strpbrk = dlsym(handle, "strpbrk");

    char str1[] = "";
    char str2[] = "";

    cr_assert_eq(my_strpbrk(str1, str2), strpbrk(str1, str2));

    dlclose(handle);
}

Test(my_strpbrk, strpbrk_priority)
{
    void *handle;
    char* (*my_strpbrk)(const char *haystack, const char *needle);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_strpbrk = dlsym(handle, "strpbrk");

    char str1[] = "Hello world";
    char str2[] = "olre";

    cr_assert_eq(my_strpbrk(str1, str2), strpbrk(str1, str2));

    dlclose(handle);
}

// Test(my_memmove, memmove_normal_total_string)
// {
//     void *handle;
//     void* (*my_memmove)(void *dest, const void *src, size_t n);
//     handle = dlopen("./libasm.so", RTLD_LAZY);
//     my_memmove = dlsym(handle, "memmove");

//     char src1[20] = "Hello, world!";
//     char dest1[20];

//     char src2[20] = "Hello, world!";
//     char dest2[20];

//     memmove(dest1, src1, strlen(src1) + 1);

//     memmove(dest2, src2, strlen(src2) + 1);

//     printf("'%s' and '%s'\n", dest1, dest2);
//     cr_assert_eq(dest1, dest2);

//     dlclose(handle);
// }

// Test(my_memmove, memmove_normal_few_char)
// {
//     void *handle;
//     void* (*my_memmove)(void *dest, const void *src, size_t n);
//     handle = dlopen("./libasm.so", RTLD_LAZY);
//     my_memmove = dlsym(handle, "memmove");

//     char src1[20] = "Hello, world!";
//     char dest1[20];

//     char src2[20] = "Hello, world!";
//     char dest2[20];

//     memmove(dest1, src1, 5);

//     memmove(dest2, src2, 5);

//     printf("'%s' and '%s'\n", dest1, dest2);
//     cr_assert_eq(dest1, dest2);

//     dlclose(handle);
// }

Test(my_index, index_normal_test)
{
    void *handle;
    char* (*my_index)(const char *s, int c);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_index = dlsym(handle, "index");

    char str1[] = "Hello world";
    char str2 = 'o';

    cr_assert_eq(my_index(str1, str2), index(str1, str2));

    dlclose(handle);
}

Test(my_rindex, rindex_normal_test)
{
    void *handle;
    char* (*my_rindex)(const char *s, int c);
    handle = dlopen("./libasm.so", RTLD_LAZY);
    my_rindex = dlsym(handle, "rindex");

    char str1[] = "Hello world";
    char str2 = 'o';

    cr_assert_eq(my_rindex(str1, str2), rindex(str1, str2));

    dlclose(handle);
}
