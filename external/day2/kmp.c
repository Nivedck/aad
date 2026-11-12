#include <stdio.h>
#include <string.h>



void computeLPS(char lps[] ,char pattern[],int m){
    int len=0;
    int i=0;
    lps[0]=0;

    while(i<m){
        if(pattern[i]==pattern[len]){
            len++;
            lps[i]=len;
            i++;  
        }else if(len>0){
            len=lps[len-1];
        }else{
            lps[i]=0;
            i++
        }
    }
}