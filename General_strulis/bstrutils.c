#include "strutils.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>


void str_reverse(char *str)
    {
        int left = 0;
        int right = strlen(str) - 1;
        char strluutam;

        while (left < right)
        {
            strluutam = str[left];
            str[left] = str[right];
            str[right] = strluutam;

            left++;
            right--;
        }
    }


void str_trim(char *str)
    {
        int start = 0;
        int end =  0;
        while (str[start] == ' ')
        {
            start++;
        }
        
        while (str[end] != '\0')
        {
            end++;
        }
        
        end--;
        while (end > start && str[end] == ' ')
        {
            end--;
        }
        
        int i = 0;
        while (start <= end)
        {
            str[i++] = str[start++];
        }
        str[i] = '\0';


    }

int str_to_int(const char *str, int *out_num){
        int result = 0;
        int i = 0;
        int is_negative = 0;

        if (str == NULL || out_num == NULL);

        if (str[0] == '-')
        {
            is_negative = 1;
            i++;
        }
        
       while (str[i] != '\0')
       {
            char c = str[i];
            if (c < '0' || c > '9') return -1;

            int digit = c -'0';
            result = result*10 +digit;

            i++;
       }
       *out_num = is_negative ? -result : result;
       return 0;
}
