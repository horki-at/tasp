#include "path.ih"

void path_shuffle_display(int method)
{
  char const *shuffle_str;
  
  switch (method)
  {
  case 0:
    shuffle_str = "SWAP";
    break;
  case 1:
    shuffle_str = "INVERT";
    break;
  case 2:
    shuffle_str = "SHIFT";
    break;
  default:
    shuffle_str = "INVALID";
    break;
  }

  printf("%s", shuffle_str);
}
