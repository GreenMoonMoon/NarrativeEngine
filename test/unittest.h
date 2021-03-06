#ifndef __UNITTEST__
#define __UNITTEST__

#define FAIL() printf("\nfailure in %s() line %d\n", __func__, __LINE__)

#define _assert(test) \
    do                \
    {                 \
        if (!(test))  \
        {             \
            FAIL();   \
            return 1; \
        }             \
    } while (0)

#define _assertEqualPointer(test, expected) \
    do                                      \
    {                                       \
        if ((&test) != (&expected))         \
        {                                   \
            FAIL();                         \
            return 1;                       \
        }                                   \
    } while (0)

#define _assertEqualValue(test, expected) \
    do                                    \
    {                                     \
        if ((test) != (expected))         \
        {                                 \
            FAIL();                       \
            return 1;                     \
        }                                 \
    } while (0)

#define _verify(test)   \
    do                  \
    {                   \
        int r = test(); \
        tests_run++;    \
        if (r)          \
            return r;   \
    } while (0)

int tests_run;
int all_tests();

#endif