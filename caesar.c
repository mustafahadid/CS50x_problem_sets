#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar Key\n");
    return 1;
    }
    else
    {

    int key = atoi(argv[1]); // convert string to integer


            if(key < 0)
            {
                printf("Usage: ./caesar key\n");
            return 1;
            }
            else
            {

                string text = get_string("plaintext: "); // get the plaintext
                printf("ciphertext: ");
                for (int j = 0; j<strlen(text); j++)
                {
                   if (isupper(text[j]))
                        printf("%c", (text[j] - 'A' + key) % 26 + 'A');   // encrypting formula for upper case letter

                    else if (islower(text[j]))
                    printf("%c", (text[j] - 'a' + key)% 26 + 'a');  // encryping formula for lower case letter

                    else
                    printf("%c", text[j]);

                }
                printf("\n");


            }
    }
}


