// Concatenations of 2 structures
// By Megan Wong (z5241209)
// Modified on 2019-07-03

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100


char * concat(char * s1, char * s2);

int main(int argc, char * argv[]){
    
    char s1[] = "Fun";
    char s2[MAX];
    
    //Assume fgets gets some valid input
    fgets(s2,MAX,stdin);
    int len = strlen(s2);
    
    //Remove newline if it exists
    if(len > 0 && s2[len-1] == '\n'){
        s2[len-1] = '\0';
    }
        
    char * s3 = concat(s1,s2);
    char * s4 = concat(s2,s1);
    char * s5 = concat("",s2);
    char * s6 = concat(s2,"");
    char * s7 = concat(s3,s3);
        
    printf("s1: %s\n",s1);
    printf("s2: %s\n",s2);
    printf("s3: %s\n",s3);
    printf("s4: %s\n",s4);
    printf("s5: %s\n",s5);
    printf("s6: %s\n",s6);
    printf("s7: %s\n",s7);
     
    free(s3);
    free(s4);
    free(s5);
    free(s6);
    free(s7);
    return EXIT_SUCCESS;
}

char * concat(char * s1, char * s2){
   //TODO
   //Use malloc to change the strings later, reserve memory for both strings
    char *linked = (char *)malloc((strlen(s1)+1+strlen(s2)+1)*sizeof(char));
    if(linked == NULL){
        fprintf(stderr,"Error: memory could not be allocated.\n");
        exit(EXIT_FAILURE);
    } 
    int k = 0;
    strcpy(linked,s1);
    for(int i=strlen(s1);i<strlen(s2)+strlen(s1)+1;i++){
    linked[i]=s2[k];
    k++;
    }
 
 
    return linked;
}
