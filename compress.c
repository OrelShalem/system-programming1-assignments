#include "compress.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data_
{
    unsigned char upper : 4;
    unsigned char lower : 4;
}data;

#define LOWER_MASK 0x0F  // הקסדצימלי לייצוג 00001111
#define UPPER_MASK 0xF0  // הקסדצימלי לייצוג 11110000


void compress_data(FILE *input_file, FILE *output_file){
  char lower, upper;
  data d;

  while((lower = fgetc(input_file))!= EOF){
    if((upper = fgetc(input_file))== EOF){

        upper = '0';

    }

    d.lower = ~(lower - '0');
    d.upper = ~(upper - '0');
    
    if(fwrite(&d, sizeof(data), 1, output_file)!= 1){
        printf("Error writing to file\n");
        exit(1);
    }

  }
}

void decompress_data(FILE *input_file, FILE *output_file){
    
   char number;

  while (fread(&number, sizeof(char), 1, input_file) == 1) {
    number = ~number;
    char lower = number & LOWER_MASK;
    char upper = (number & UPPER_MASK) >> 4;
    fprintf(output_file, "%d%d", upper, lower);
  }
}
