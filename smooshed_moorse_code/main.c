/*
*  For the purpose of this challenge, Morse code represents every letter as a sequence of 1-4 characters, each of which is either . (dot) or - (dash). The code for the letter a is .-, for b is -..., etc. The codes for each letter a through z are:
*
*  .- -... -.-. -.. . ..-. --. .... .. .--- -.- .-.. -- -. --- .--. --.- .-. ... - ..- ...- .-- -..- -.-- --..
*
*  Normally, you would indicate where one letter ends and the next begins, for instance with a space between the letters' codes, but for this challenge, just smoosh all the coded letters together into a single string consisting of only dashes and dots.
*  Examples
*
*  smorse("sos") => "...---..."
*  smorse("daily") => "-...-...-..-.--"
*  smorse("programmer") => ".--..-.-----..-..-----..-."
*  smorse("bits") => "-.....-..."
*  smorse("three") => "-.....-..."
*
*  An obvious problem with this system is that decoding is ambiguous. For instance, both bits and three encode to the same string, so you can't tell which one you would decode to without more information.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char codes[] = ".- -... -.-. -.. . ..-. --. .... .. .--- -.- .-.. -- -. --- .--. --.- .-. ... - ..- ...- .-- -..- -.-- --..";

char letters[26][5];

void initLetters() {
  int i;
  char *token;

  token = strtok(codes, " ");
  strcpy(letters[0], token);

  for(i=1; i<26; i++) {
    token = strtok(NULL, " ");
    strcpy(letters[i], token);
  }
}

void smorse(const char* input, char* output) {
  int i = 0;
  char c;
  c = input[0];

  while(c != '\0') {
    strcat(output, letters[c-'a']);
    i++;
    c = input[i];
  }
}

void main(){
  char answer[100];
  initLetters();

  char problems[][20] = {"sos", "daily", "programmer", "bits", "three"};

  for(int i=0; i<5; i++) {
    answer[0] = '\0';
    smorse(problems[i], answer);
    printf("%s\n" , answer);
  }
}
