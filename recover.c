#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>

typedef uint8_t  BYTE;
int main(int argc, char *argv[])
{

    FILE* inptr = fopen("card.raw", "r");
    if (inptr == NULL)
    {
        fprintf(stderr, " file Not found");
        return 1;
    }

    bool foundfirst = false;
    BYTE buffer[512];
    FILE* img;
    int file_counter = 0;

    while(fread(buffer, 1, 512, inptr) != 0x00)
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {

            if(!foundfirst)
            {

                foundfirst = true;
                char filename[8];

                sprintf(filename,"%03i.jpg", file_counter++);
                img = fopen(filename, "w");

                if(img == NULL)

                return 2;

                fwrite(buffer, 1, 512, img);

            }
            else
            {
                fclose(img);
                char filename[8];

                sprintf(filename,"%03i.jpg", file_counter++);
                img = fopen(filename, "w");

                if(img == NULL)

                return 3;

                fwrite(buffer, 1, 512, img);
            }

        }
        else
        {
            if(foundfirst)
            {
                fwrite(buffer, 1, 512, img);

            }
        }


    }
    fclose(inptr);
    fclose(img);
}
