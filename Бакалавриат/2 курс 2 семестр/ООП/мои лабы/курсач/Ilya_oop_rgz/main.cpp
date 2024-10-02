#include <iostream>
#include <string>
#include <time.h>
#include "Blog.h"
using namespace std;


int main() {

    Blog blog;
    blog.getInstance();
    blog.main_loop();

}
