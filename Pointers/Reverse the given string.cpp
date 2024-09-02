/*
You are given a string 'str' consisting of lower case alphabets. You have to find the reverse of the string.

For example:
 If the given string is: str = "abcde". You have to print the string "edcba".
*/
#include<cstring>
void func(char *str) {
    int n = strlen(str);
    char *start = str;
    char *end = str + n - 1;

    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}
