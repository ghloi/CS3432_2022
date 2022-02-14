#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* Return true (non-zero) if c is the delimiter character
   previously chosen by the user.
   Zero terminators are not printable (therefore false) */
bool delim_character(char c, char delim)
{
    if(c==delim){
        return true;
    }
    return false;
}

/* Return true (non-zero) if c is a non-delimiter
   character.
   Zero terminators are not printable (therefore false) */
bool non_delim_character(char c, char delim)
{
    if(c == delim){
        return false;
    }
    return true;
}

/* Returns a pointer to the first character of the next
   word starting with a non-delimiter character. Return a zero pointer if
   str does not contain any words.*/
char* word_start(char* str,char delim)
{
    return str;
}

/* Returns a pointer to the first delimiter character of the zero
   terminated string*/
char* end_word(char* str,char delim)
{
    return str;
}

/* Counts the number of words or tokens*/
int count_tokens(char* str,char delim)
{
    int numSubStrings = 0;
    for(int i = 0; i < strlen(str); i++){
        int startIndex = i;
        while(non_delim_character(str[i], delim) && i < strlen(str)){
            i++;
        }
        //First SUBSTRING is from startIndex to current i
        numSubStrings++;
        
        //printf("String[%d]= %c\n", i, str[i]);
    }
    return numSubStrings;
}

/* Returns a freshly allocated new zero-terminated string
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len, char delim)
{
    return inStr;
}

/*
Returns pointer to token in pos position of str
*/
char* get_token(char* str, char delim, int pos){    
    char* token;
    int startIndex;
    int currentPos = 0;
    
    for(int i = 0; i < strlen(str); i++){
        startIndex = i;
        while(non_delim_character(str[i], delim) && i < strlen(str)){
            i++;
        }
        if(currentPos == pos){
            //This is the token we want!
            token = (char*)malloc((i-startIndex) * sizeof(char));
            int tokenIndex = 0;
            for(int j = startIndex; j < i; j++){
                token[tokenIndex] = str[j];
                tokenIndex++;
                //strcat(token, str[j]);
            }
            return token;
        }
        currentPos++;
    }
    return token;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated
   delimiter-separated tokens from zero-terminated str.
   For example, tokenize("hello world string"), with a character delimiter
   of a space " " would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string"
     tokens[3] = 0
*/
char** tokenize(char* str, char delim){
    int numTokens = count_tokens(str, delim);
    char** newstr = (char**)malloc(numTokens * sizeof(char));
    for(int i = 0; i < numTokens; i++){
        char* currentToken = get_token(str, delim, i);
        //printf("Got: %s\n", currentToken);
        newstr[i] = currentToken;
    }
    
    return newstr;
}

void print_all_tokens(char** tokens, int numTokens)
{
    for(int i = 0; i < numTokens; i++){
        printf("Tokens[%d]: %s\n", i, tokens[i]);
    }
}

int main(){
    //MAIN
    char inputChar;
    char inputString[50]; //Allocate space in case it's a long sentence
    
    //Get delimiter
    printf("Please enter the delimiter char:\n->");
    scanf("%c",&inputChar);
    
    //Clear buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
    
    //Get string to tokenize
    printf("Please enter the input string:\n->");
    scanf ("%[^\n]%*c", inputString); //Ensures we can add spaces
    
    //Assign a pointer to inputted string
    char* pString;
    pString = &inputString[0]; //Assign the pointer string
    
    //Pass pointer through tokenizer, then print out contents of tokenizer
    print_all_tokens(tokenize(pString, inputChar), count_tokens(pString, inputChar));
    printf("Original unmodified string input was: %s\n", inputString);
    
}
