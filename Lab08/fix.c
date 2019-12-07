// A simple C program to help understand pointers fixed code
// Written 02/07/2019
// modified by Megan Wong

#include <stdio.h>

int main(void) {

    int i = 22;
    char *s;
    char foo[] = "Hello World";

    s = foo;
    printf("s is %s\n", s);
    
    s[0] = *foo;
    printf("s[0] is %c\n", s[0]);
    
    
    //Print the value and address
    printf("Value of i: %d\n", i);
    printf("Address of i: %p\n", &i);
    printf("Value of s: %s\n", s);
    printf("Address of s: %p\n", s);
    printf("Value of *s: %c\n", *s);
    printf("Address of *s: %p\n", &s);
    printf("Value of s[3]: %c\n", s[3]);
    printf("Address of s[3]: %p\n", &s[3]);
    char *c = s + 2*sizeof(char);
    printf("Value of s+2: %s\n", c);
    printf("Address of s+2: %p\n", &c);
    printf("Value of *(s+2): %c\n", *c);
    printf("Address of *(s+2): %p\n", &c);
    
    return(0);
}
