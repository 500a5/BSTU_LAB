#pragma once
#include <assert.h>
#include <fstream>

using namespace std;

//Represents an image
class Image {
public:
	Image(char* ps, int w, int h);
	~Image();

	char* pixels;
	int width;
	int height;
};

//Reads a bitmap image from file.
Image* loadBMP(const char* filename);


GLuint loadTexture(Image* image) {
    GLuint* textures = new GLuint[11];//
    glGenTextures(12, textures); //make room for 12 texture//
    glBindTexture(GL_TEXTURE_2D, *textures);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height,
        0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels); // actual pixel data
    return *textures;
}

GLuint _textureId1;
GLuint _textureId2;
GLuint _textureId3;
GLuint _textureId4;
GLuint _textureId5;
GLuint _textureId6;

Image::Image(char* ps, int w, int h) : pixels(ps), width(w), height(h) {}

Image::~Image() {
    delete[] pixels;
}

namespace {
    // Converts a four-character array to an integer, using little-endian form
    int toInt(const char* bytes) {
        return (int)(
            ((unsigned char)bytes[3] << 24) |
            ((unsigned char)bytes[2] << 16) |
            ((unsigned char)bytes[1] << 8) |
            (unsigned char)bytes[0]
            );
    }

    //Converts a two-character array to a short, using little-endian form
    short toShort(const char* bytes) {
        return (short)(((unsigned char)bytes[1] << 8) |
            (unsigned char)bytes[0]);
    }

    //Reads the next four bytes as an integer, using little-endian form
    int readInt(ifstream& input) {
        char buffer[4];
        input.read(buffer, 4);
        return toInt(buffer);
    }

    //Reads the next two bytes as a short, using little-endian form
    short readShort(ifstream& input) {
        char buffer[2];
        input.read(buffer, 2);
        return toShort(buffer);
    }

    //Just like auto_ptr, but for arrays
    template<class T>
    class auto_array {
    private:
        T* array;
        mutable bool isReleased;
    public:
        explicit auto_array(T* array_ = NULL) :
            array(array_), isReleased(false) {
        }

        auto_array(const auto_array<T>& aarray) {
            array = aarray.array;
            isReleased = aarray.isReleased;
            aarray.isReleased = true;
        }

        ~auto_array() {
            if (!isReleased && array != NULL) {
                delete[] array;
            }
        }

        T* get() const {
            return array;
        }

        T& operator*() const {
            return *array;
        }

        void operator=(const auto_array<T>& aarray) {
            if (!isReleased && array != NULL) {
                delete[] array;
            }
            array = aarray.array;
            isReleased = aarray.isReleased;
            aarray.isReleased = true;
        }

        T* operator->() const {
            return array;
        }

        T* release() {
            isReleased = true;
            return array;
        }

        void reset(T* array_ = NULL) {
            if (!isReleased && array != NULL) {
                delete[] array;
            }
            array = array_;
        }

        T* operator+(int i) {
            return array + i;
        }

        T& operator[](int i) {
            return array[i];
        }
    };
}

Image* loadBMP(const char* filename) {
    ifstream input;
    input.open(filename, ifstream::binary);
    assert(!input.fail() || !"Could not find file");
    char buffer[2];
    input.read(buffer, 2);
    assert(buffer[0] == 'B' && buffer[1] == 'M' || !"Not a bitmap file");
    input.ignore(8);
    int dataOffset = readInt(input);

    //Read the header
    int headerSize = readInt(input);
    int width;
    int height;
    switch (headerSize) {
    case 40:
        //V3
        width = readInt(input);
        height = readInt(input);
        input.ignore(2);
        assert(readShort(input) == 24 || !"Image is not 24 bits per pixel");
        assert(readShort(input) == 0 || !"Image is compressed");
        break;
    case 12:
        //OS/2 V1
        width = readShort(input);
        height = readShort(input);
        input.ignore(2);
        assert(readShort(input) == 24 || !"Image is not 24 bits per pixel");
        break;
    case 64:
        //OS/2 V2
        assert(!"Can't load OS/2 V2 bitmaps");
        break;
    case 108:
        //Windows V4
        assert(!"Can't load Windows V4 bitmaps");
        break;
    case 124:
        //Windows V5
        assert(!"Can't load Windows V5 bitmaps");
        break;
    default:
        assert(!"Unknown bitmap format");
    }

    //Read the data
    int bytesPerRow = ((width * 3 + 3) / 4) * 4 - (width * 3 % 4);
    int size = bytesPerRow * height;
    auto_array<char> pixels(new char[size]);
    input.seekg(dataOffset, ios_base::beg);
    input.read(pixels.get(), size);

    //Get the data into the right format
    auto_array<char> pixels2(new char[width * height * 3]);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int c = 0; c < 3; c++) {
                pixels2[3 * (width * y + x) + c] =
                    pixels[bytesPerRow * y + 3 * x + (2 - c)];
            }
        }
    }

    input.close();
    return new Image(pixels2.release(), width, height);
}

void initRender() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_BLEND); // turns on alpha blending
    glEnable(GL_NORMALIZE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // to see the blending

    Image* image = loadBMP("assets/floor.bmp");
    _textureId1 = loadTexture(image);
    image = loadBMP("assets/wall.bmp");
    _textureId2 = loadTexture(image);
    image = loadBMP("assets/sky2.bmp");
    _textureId3 = loadTexture(image);
    image = loadBMP("assets/glass.bmp");
    _textureId4 = loadTexture(image);
    image = loadBMP("assets/wood.bmp");
    _textureId5 = loadTexture(image);
    image = loadBMP("assets/lamp.bmp");
    _textureId6 = loadTexture(image);
    delete image;

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // clears background colour and put alpha value as 1
}
