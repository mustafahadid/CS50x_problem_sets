// Implements a dictionary's functionality
#include <stdio.h>
#include <stdbool.h>
#include "dictionary.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 6000;

// Hash table
node *table[N];
int loadwords = 0;
// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO

    int length = strlen(word);
    char *newword = malloc((length + 1) * sizeof(char));
    newword[length] ='\0';

    for(int i= 0; i < length; i++)
    {
        newword[i] = tolower(word[i]);
    }
    int x = hash(newword);
    node *index = table[x];

    while(index != NULL)
    {
        if(strcmp(index->word, newword)== 0)
            return true;

        index = index->next;
    }
    free(newword);
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int hashvalue = 0;
    for(int i =0; i < strlen(word); i++)
    {
        hashvalue = (hashvalue << 2)^word[i];
    }
    // TODO
    return hashvalue % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    char dictionaryword[LENGTH + 1];
    // loading dicationary into memory
    FILE *file = fopen(dictionary, "r");

    if(file == NULL)
    {
        printf("could not open dictionary");
        return false;
    }

    while(fscanf(file, "%s\n", dictionaryword) != EOF)
    {
        int index2 = hash(dictionaryword);
        node *newnode = malloc(sizeof(node));

        if(newnode == NULL)
        {
            return false;
        }
        if(table[index2] == NULL)
        {
            table[index2] = newnode;
            newnode->next = NULL;
        }
        else
        {
            newnode->next = table[index2];
            table[index2] = newnode;
        }
        strcpy(newnode->word, dictionaryword);
        loadwords++;
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return loadwords;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    for(int i = 0; i < N; i++)
    {
        node* cursor = table[i];
        while(cursor != NULL)
        {
            node* temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
        free(cursor);
    }
    return true;
}
