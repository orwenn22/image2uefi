#include <iostream>

#include <raylib.h>
#include <string>

int main(int argc, const char *argv[]) {
    if(argc != 2) {
        return 1;
    }

    Image input = LoadImage(argv[1]);
    if(input.data == nullptr) return 1;

    FILE *output = fopen("background_image.h", "w");
    fprintf(output, "unsigned char bg_buf[] = {");

    for(int y = 0; y < input.height; y++) {
        for(int x = 0; x < input.width; x++) {
            Color c = GetImageColor(input, x, y);
            fprintf(output, "%i, %i, %i, 0, ", c.b, c.g, c.r);
        }
    }

    fprintf(output, "};\n");
    fprintf(output, "int bg_w = %i;\n", input.width);
    fprintf(output, "int bg_h = %i;\n", input.height);
    fclose(output);
    UnloadImage(input);

    return 0;
}
