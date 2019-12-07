#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

long add (int x, int y);

int main(void) {

    int bigInt = INT_MAX;
    int x;
    int y;
    long total;

    x = 40;
    y = 2;

    //Could have also used sizeof(int)
   // printf("The size of a int, in bytes, is %u.\n", sizeof(x));
    //printf("The variable x is located at memory address %p.\n", &x);

    total = add (x, y);

    printf("the sum of %d and %d is %ld\n", x, y, total);

    unsigned char uc = 5;   
    printf("The size of a unsigned char, in bytes, is %hhd.\n", sizeof(uc));
    printf("The variable uc is located at memory address %p.\n", &uc);
    printf("The minium value of unsigned char = 0\n");
    printf("The maximum value of unsigned char = %hhd\n\n", UCHAR_MAX);
    //printf("The substraction is : %hhu\n\n", uc-1);
    
    /*unsigned long ul       = 0;
    printf("The size of a unsigned long, in bytes, is %u.\n", sizeof(ul));
    printf("The variable ul is located at memory address %p.\n", &ul);
    printf("The minium value of unsigned long = 0\n");
    printf("The maximum value of unsigned long = %lu\n", ULONG_MAX);
    printf("The substraction is : %lu\n\n", ul-1);
    
    unsigned int ui        = 0;
    printf("The size of a unsigned int, in bytes, is %u.\n", sizeof(ui));
    printf("The variable ui is located at memory address %p.\n", &ui);
    printf("The minium value of unsigned int = 0\n");
    printf("The maximum value of unsigned int = %u\n", UINT_MAX);
    printf("The substraction is : %u\n\n", ui-1);
    
    unsigned long    long ull = 0;
    printf("The size of a unsigned long long, in bytes, is %u.\n", sizeof(ull));
    printf("The variable ull is located at memory address %p.\n", &ull);
    printf("The minium value of unsigned long long = 0\n");
    printf("The maximum value of unsigned long long = %llu\n", ULLONG_MAX);
    printf("The substraction is : %llu\n\n", ull-1);
    
    unsigned short us      = 0;
    printf("The size of a unsigned short, in bytes, is %u.\n", sizeof(us));
    printf("The variable us is located at memory address %p.\n", &us);
    printf("The minium value of unsigned short = 0\n" );
    printf("The maximum value of unsigned short = %hu\n", USHRT_MAX);
    printf("The substraction is : %hu\n\n", us-1);
    
    printf("The result of adding 1 to bigInt is: %d\n", bigInt+1);
    */

    signed char sc  = 5;
    printf("The size of a signed char, in bytes, is %hhd.\n", sizeof(sc));
    printf("The variable sc is located at memory address %p.\n", &sc);
    printf("The minium value of signed char = %hhd\n", SCHAR_MIN);
    printf("The maximum value of signed char = %hhd\n\n", SCHAR_MAX);
    
    /*signed long sl       = 6;
    printf("The size of a signed long, in bytes, is %u.\n", sizeof(sl));
    printf("The variable sl is located at memory address %p.\n", &sl);
    //printf("The minium value of signed long = %ld\n", LONG_MIN);
    //printf("The maximum value of signed long = %ld\n\n", LONG_MAX);
    
    signed int si        = 7;
    printf("The size of a signed int, in bytes, is %u.\n", sizeof(si));
    printf("The variable si is located at memory address %p.\n", &si);
    //printf("The minium value of signed int = %d\n", INT_MIN);
    //printf("The maximum value of signed int = %d\n\n", INT_MAX);
    
    signed long long sll = 8;
    printf("The size of a signed long long, in bytes, is %u.\n", sizeof(sll));
    printf("The variable sll is located at memory address %p.\n", &sll);
    //printf("The minium value of signed long long = %llu\n", LLONG_MIN);
    //printf("The maximum value of signed long long = %llu\n\n", LLONG_MAX);
    signed short ss      = 9;
    printf("The size of a signed shor, in bytes, is %u.\n", sizeof(ss));
    printf("The variable ss is located at memory address %p.\n", &ss);
    //printf("The minium value of signed short = %hd\n", SHRT_MIN);
    //printf("The maximum value of signed short = %hd\n\n", SHRT_MAX);
    */

    char c       = 5;
    printf("The size of a char, in bytes, is %hhd.\n", sizeof(c));
    printf("The variable c is located at memory address %p.\n", &c);
    printf("The minium value of char = %hhd\n", CHAR_MIN);
    printf("The maximum value of char = %hhd\n\n", CHAR_MAX);
    
    /*long l       = 11;
    printf("The size of a long, in bytes, is %u.\n", sizeof(l));
    printf("The variable l is located at memory address %p.\n", &l);
    //printf("The minium value of long = %ld\n", LONG_MIN);
    //printf("The maximum value of long = %ld\n\n", LONG_MAX);
    
    int i        = 12;
    printf("The size of a int, in bytes, is %u.\n", sizeof(i));
    printf("The variable i is located at memory address %p.\n", &i);
    //printf("The minium value of int = %d\n", INT_MIN);
    //printf("The maximum value of int = %d\n\n", INT_MAX);
    
    long long ll = 13;
    printf("The size of a long long, in bytes, is %u.\n", sizeof(ll));
    printf("The variable ll is located at memory address %p.\n", &ll);
    //printf("The minium value of long long = %lld\n", LLONG_MIN);
    //printf("The maximum value of long long = %lld\n\n", LLONG_MAX);
    short s      = 14;
    printf("The size of a short, in bytes, is %u.\n", sizeof(s));
    printf("The variable s is located at memory address %p.\n", &s);
    //printf("The minium value of short = %hd\n", SHRT_MIN);
    //printf("The maximum value of short = %hd\n\n", SHRT_MAX);
    
    float f = 3.1;
    printf("The size of a float, in bytes, is %u.\n", sizeof(f));
    printf("The variable f is located at memory address %p.\n", &f);
    //printf("The minium value of float = %e\n", FLT_MIN);
    //printf("The maximum value of float = %e\n\n", FLT_MAX);
    
    double d = 3.14;
    printf("The size of a double, in bytes, is %u.\n", sizeof(d));
    printf("The variable d is located at memory address %p.\n", &d);
    //printf("The minium value of double = %e\n", DBL_MIN);
    //printf("The maximum value of double = %e\n\n", DBL_MAX);
    
    
    // add them all together just to make use of them so the compiler
    // doesn't grumble that they are unused in the program

    double grandTotal;
    grandTotal =  uc + ul + ui + ull + us +
                  sc + sl + si + sll + ss +
                   c + l  +  i +  ll +  s +
                   f + d + bigInt;

    printf ("all these things added together make %f\n",
            grandTotal);

    // Add in your own variables, printf statements and arithmetic to
    // figure out the size of different types, where they live
    // and how big the numbers they store are
    */


    return EXIT_SUCCESS;
}

long add (int x, int y) {
    long answer;
    answer = x + y;

    return answer;
}
