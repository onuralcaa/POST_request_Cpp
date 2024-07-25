# HTTP POST with CPR in C++

This repository contains a simple example of how to make an HTTP POST request using the [CPR](https://github.com/libcpr/cpr) library in C++.

## Requirements

- C++11 or later
- CMake 3.1 or later
- CPR library
- A C++ compiler (e.g., GCC, Clang)

## Installation

First, you need to clone this repository and navigate to the project directory:

```bash
git clone https://github.com/yourusername/http-post-cpp.git
cd http-post-cpp
Installing CPR
To use the CPR library, you can either build it from source or use a package manager. Below are the steps to build from source:

bash
Kodu kopyala
git clone https://github.com/libcpr/cpr.git
cd cpr
mkdir build
cd build
cmake ..
cmake --build .
sudo cmake --install .
Building the Project
Once CPR is installed, you can build the project using CMake:

bash
Kodu kopyala
mkdir build
cd build
cmake ..
cmake --build .
Usage
Run the compiled executable to make an HTTP POST request:

bash
Kodu kopyala
./http_post_example
Example Code
Here's the C++ code used in this project:

cpp
Kodu kopyala
#include <cpr/cpr.h>
#include <iostream>

int main() {
    cpr::Response r = cpr::Post(
        cpr::Url{"https://jsonplaceholder.typicode.com/posts"},
        cpr::Payload{{"title", "foo"}, {"body", "bar"}, {"userId", "1"}}
    );

    std::cout << "Status Code: " << r.status_code << std::endl;
    std::cout << "Response Body: " << r.text << std::endl;

    return 0;
}
Contributing
If you want to contribute to this project, feel free to submit a pull request or open an issue.
