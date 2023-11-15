#include <iostream>

#include <raylib.h>
#include <string>

int main(int argc, const char *argv[]) {
    if(argc != 2) {
        return 1;
    }

    Image input = LoadImage(argv[1]);
    if(input.data == nullptr) return 1;

    FILE *output = fopen("out.h", "w");
    fprintf(output, "unsigned char out[] = {");

    for(int y = 0; y < input.height; y++) {
        for(int x = 0; x < input.width; x++) {
            Color c = GetImageColor(input, x, y);
            fprintf(output, "%i, %i, %i, 0, ", c.b, c.g, c.r);
        }
    }


    fprintf(output, "}\n");
    fclose(output);
    UnloadImage(input);

    return 0;
}
