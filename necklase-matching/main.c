//https://www.reddit.com/r/dailyprogrammer/comments/ffxabb/20200309_challenge_383_easy_necklace_matching
#include <stdio.h>
#include <string.h>

int same_necklace(const char *first, const char *second) {
  int firstLen = strlen(first);
  int secondLen = strlen(second);
  if(firstLen != secondLen) return 0;
  for(int i=0; i<firstLen; i++) {
    if(first[i] == second[0]) {
      int match = 1;
      for(int j=0; j<secondLen; j++) {
        if(first[(i+j)%firstLen] != second[j]) {
          match = 0;
          break;
        }
      }
      if(match) return 1;
    }
  }
  return 0;
}

int main() {
  {
    const char* a = "nicole";
    const char* b = "icolen";
    printf("%s, %s, %d\n", a, b, same_necklace(a, b));
  }

  {
    const char* a = "nicole";
    const char* b = "coneli";
    printf("%s, %s, %d\n", a, b, same_necklace(a, b));
  }

  {
    const char* a = "xxyyy";
    const char* b = "xxxyy";
    printf("%s, %s, %d\n", a, b, same_necklace(a, b));
  }
}
