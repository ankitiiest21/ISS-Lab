
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
#include <time.h>
#include<ctype.h>
#define SIZE 400

int main() {

    int eSbox[16] = {14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7};
    int dSbox[16] = {14,3,4,8,1,12,10,15,7,13,9,6,11,2,0,5};

    int ePbox[8] = {0,3,4,6,2,5,1,7};
    int dPbox[8] = {0,6,4,1,2,5,3,7};

    //Plain text and cipher text are 8 bits long.

    printf("\n Enter Plain text to be encrypted(8-bit) : \n");

    int plainText[8];
    int cipherText[8];

    for(int i = 0; i < 8; i++) {

        scanf("%1d", &plainText[i]);
    }

    int key[24];

    srand(time(0));

    for(int i = 0; i < 24; i++) {

        key[i] = rand() % 2;
    }

    printf("Random Key generated --> ");

    for(int i = 0; i < 24; i++) {

        printf("%d", key[i]);

    }

    printf("\n");

    for(int r = 0; r < 4; r++) {

        int l = 4 * (r + 1); l -= 4;

        //Round key mixing

        for(int i = 0; i < 8; i++) {

            plainText[i] ^= key[i + l];
        }

        int h1 = 0; int h2 = 0;

        //converting to halves into hex to apply S-Box

        for(int i = 0; i < 4; i++) {

            h1 += (1 << (3 - i)) * plainText[i];

            h2 += (1 << (3 - i)) * plainText[i + 4];
        }

        h1 = eSbox[h1];
        h2 = eSbox[h2];

        // Converting hex back into binary and storing in plainText

        for(int i = 0; i < 4; i++) {

            plainText[i] = (h1  >> (3 - i)) & 1;

            plainText[i + 4] = (h2 >> (3 - i)) & 1;
        }

        //No p box on last turn. No diffusion needed
        if(r != 3) {

            for(int i = 0; i < 8; i++) {

                cipherText[ePbox[i]] = plainText[i];
            }

            for(int i = 0; i < 8; i++) {

                plainText[i] = cipherText[i];
            }
        }
    }

    //XOR again --> 5th round key mixing

    for(int i = 0; i < 8; i++) {

        plainText[i] ^= key[i + 16];
    }

    printf("\n Encrypted Text (bit stream) --> ");

    for(int i = 0; i < 8; i++){

        printf("%d", plainText[i]);
    }

    printf("\n");

    //Decrytpion Block.
    //Starting with fifth round key mix of encryption

    for(int i = 0; i < 8; i++) {

        plainText[i] ^= key[i + 16];
        
    }

    for(int r = 3; r >= 0; r--) {

        if(r != 3) {

            for(int i = 0; i < 8; i++) {

                cipherText[dPbox[i]] = plainText[i];
            }

            for(int i = 0; i < 8; i++) {

                plainText[i] = cipherText[i];
            }
        }

        int h1 = 0, h2 = 0;

        for(int i = 0; i < 4; i++) {

            h1 += (1 << (3 - i)) * plainText[i];

            h2 += (1 << (3 - i)) * plainText[i + 4];
        }

        h1 = dSbox[h1];
        h2 = dSbox[h2];

        for(int i = 0; i < 4; i++) {

            plainText[i] = (h1 >> (3 - i)) & 1;

            plainText[i + 4] = (h2 >> (3 - i)) & 1;
        }

        int l = 4 * (r + 1); l -= 4;

        for(int i = 0; i < 8; i++) {

            plainText[i] ^= key[i + l];
        }


    }

    printf("\nDecrypted Text --> ");

    for(int i = 0; i < 8; i++) {

        printf("%d", plainText[i]);
    }

    printf("\n");

    return 0;
}
