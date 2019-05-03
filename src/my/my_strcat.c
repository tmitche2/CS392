#include "my.h"

char* my_strcat(char* dst, char* src)
{

  if(dst == NULL)
    return dst;

  int len = my_strlen(src);
  int start = my_strlen(dst);
  int i;

  for(i=0; i < len; i++)
    dst[i + start] = src[i];

  dst[i + start] = '\0';

  return dst;

}