#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int sterrlen(char *coco);
char * sterrcpy(char *dest, char *source);
char * sternkats(char *dest, char *source, int n);
int sterrcmp(char *s1, char *s2);
char * sterrchr(char *s, char c);

int sterrlen(char *dest){
  int i = 0;
  while(dest[i]){
    i++;
  }
  return i;
}

char * sterrcpy(char *dest, char *source){
  char *a = "error";
  dest = source;
  return dest;
}

char * sternkats(char *dest, char *source, int n) {
  int i;
  int a = sterrlen(dest);
  for(i = 0; i < n; i++){
    dest[a+i] = source[i];
    //printf("dest[sterrlen(dest) + i] = %c\n%d\n", dest[a + i], i);

  }
  return dest;
}

int sterrcmp(char *s1, char *s2){
  int i;
  while(*s1 == *s2){
    if(*s1 == 0){
      return 0;
    }
    s1++;
    s2++;
  }
  if(*s1 > *s2){
    return 17;
  }
  else{
    return -17;
  }
}

char * sterrchr(char *s, char c){
  while(*s != c){
    if(*s == 0){
      return NULL;
    }
    s++;
  }
  return s;
}


int main(){
  /*
  char d[10] = "hello";
  char d1[10] = "hello";
  char s = 'o';
  printf("sterrchr: %p\n", sterrchr(d, s));
  printf("strchr: %p\n", strchr(d, s));
  */
  char d0[50] = "alex_lu_and_herman_lin";
  char d1[50] = "alex_lu_and_herman_lin";
  char d2[50] = "_like_green_and_red";
  char d3[50] = "_like_green_and_red";
  char c1 = 'n';
  char c2 = '_';
  printf("--------------Our fxns are the one with teacher names!--------------\n");
  printf("d1, a string, is %s\n", d1);
  printf("d2, a string, is %s\n", d2);
  printf("c1, a char, is %c\n", c1);
  printf("c2, a char, is %c\n", c2);
  printf("-------------------Testing sterrlen vs strlen-----------------------\n");
  printf("length of d1 according to sterrlen: %d\n", sterrlen(d1));
  printf("length of d1 according to strlen: %lu\n", strlen(d1));
  printf("length of d2 according to sterrlen: %d\n", sterrlen(d2));
  printf("length of d2 according to strlen: %lu\n", strlen(d2));
  printf("-------------------Testing sterrcpy vs strcpy-----------------------\n");
  printf("copying d1 to d2 with sterrcpy, sterrcpy(d2, d1): %s\n", sterrcpy(d2, d1));
  strcpy(d2, d3);
  printf("copying d1 to d2 with strcpy, strcpy(d2, d1): %s\n", strcpy(d2, d1));
  strcpy(d2, d3);
  printf("-------------------Testing sternkats vs strncat---------------------\n");
  printf("catting first 11 chars of d2 onto d1 with sternkats, sternkats(d1, d2, 11): %s\n", sternkats(d1, d2, 11));
  strcpy(d1, d0);
  printf("catting first 11 chars of d2 onto d1 with strncat, strncat(d1, d2, 11): %s\n", strncat(d1, d2, 11));
  strcpy(d1, d0);
  printf("-------------------Testing sterrcmp vs strcmp-----------------------\n");
  printf("comparing d1 and d2, sterrcmp(d1, d2): %d\n", sterrcmp(d1, d2));
  printf("comparing d1 and d2, strcmp(d1, d2): %d\n", strcmp(d1, d2));
  printf("comparing d2 and d1, sterrcmp(d2, d1): %d\n", sterrcmp(d2, d1));
  printf("comparing d2 and d1, strcmp(d2, d1): %d\n", strcmp(d2, d1));
  printf("-------------------Testing sterrchr vs strchr-----------------------\n");
  printf("sterrchr on d1 and c1, sterrchr(d1, c1): %p\n", sterrchr(d1, c1));
  printf("strchr on d1 and c1, strchr(d1, c1): %p\n", strchr(d1, c1));
  printf("sterrchr on d2 and c2, sterrchr(d2, c2): %p\n", sterrchr(d2, c2));
  printf("strchr on d2 and c2, strchr(d2, c2): %p\n", strchr(d2, c2));
  return 0;
}
