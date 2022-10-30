#include<stdio.h>
#include<string.h>
void replace(char s[], char x[], char y[]) { //TODO: your function definition
    char temp[1000];
    int idx=0;
    for(int i=0;i<strlen(s);i++){
        if(s[i]==x[0]){
            int flag=1;
            for(int j=0;j<strlen(x);j++){
                if(i+j>=strlen(s)||s[i+j]!=x[j]){flag=0;break;}
            }
            if(flag){
                for(int j=0;j<strlen(y);j++)temp[idx++]=y[j];
                i+=strlen(x)-1;
            }
            else{
                temp[idx++]=s[i];
            }
        }
        else temp[idx++]=s[i];
    }
    temp[idx]='\0';
    strcpy(s,temp);
}

#include <stdio.h>

#define N 80

int main() {
    char s[3 * N + 1], x[N + 1], y[N + 1];
    scanf("%s%s%s", s, x, y);
    replace(s, x, y);
    printf("%s\n", s);
    return 0;
}