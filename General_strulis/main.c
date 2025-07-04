#include "strutils.h"
#include <stdio.h>


int main(){
    char s1[] = "Hello Peter";
    char s2[] = "   Hello Peter   ";
    const char * s3 = "3245664";
    const char *s4 = "-1728349";
    int num;


    str_reverse(s1);
    printf("chuoi moi la: %s\n", s1);

    str_trim(s2);
    printf("chuoi moi sau khi xoa la: %s\n", s2);


    if (str_to_int(s3, &num)==0)
    {
        printf("chuoi '%s' thanh %d\n", s3, num);
    }
    else printf("chuoi %s khong hop le\n", s3);

    if (str_to_int(s4, &num)==0)
    {
        printf("chuoi '%s' thanh %d\n", s4, num);
    }
    else printf("chuoi %s khong hop le\n", s4);

    
   
    


}