# CMakeVersionExample
Example experimenting for https://github.com/abseil/abseil-cpp/issues/259.  Specifically, outputs `CMAKE_CXX_STANDARD`, the client C++ standard level, and the lib C++ standard level for when the lib has a private usage requirement of `cxx_std_11`.

There are two binaries.  `version` uses whatever CMake does behind the scenes to determine level, either the compiler default or CMAKE_CXX_STANDARD.  `version_with_requirements` sets a compile feature of `cxx_std_11`.

To run
```bash
git clone https://github.com/JonathanDCohen/CMakeVersionExample.git
cd CMakeVersionExample
mkdir build && cd build
cmake .. <-DCMAKE_CXX_STANDARD=(98,11,14)> && cmake --build . --target version && ./version
```

Example outputs (extraneous stuff removed):

# AppleClang 10 (defaults to C++98)

```bash
$ cmake .. && cmake --build . --target version && ./version
-- CMAKE_CXX_STANDARD:
client: 199711
lib: 201103

$ cmake .. -DCMAKE_CXX_STANDARD=98 && cmake --build . --target version && ./version
-- CMAKE_CXX_STANDARD: 98
client: 199711
lib: 201103

$ cmake .. -DCMAKE_CXX_STANDARD=11 && cmake --build . --target version && ./version
-- CMAKE_CXX_STANDARD: 11
client: 201103
lib: 201103

$ cmake -DCMAKE_CXX_STANDARD=14 .. && cmake --build . --target version && ./version
-- CMAKE_CXX_STANDARD: 14
client: 201402
lib: 201402

$ cmake .. && cmake --build . --target version_with_requirements && ./version_with_requirements
-- CMAKE_CXX_STANDARD:
client: 201103
lib: 201103
```

# GCC 7.3.0 (defaults to C++14)

```bash
$ cmake .. && cmake --build . --target version && ./version
-- CMAKE_CXX_STANDARD: 14
client: 201402
lib: 201402

cmake .. -DCMAKE_CXX_STANDARD=98 && cmake --build . --target version && ./version
-- CMAKE_CXX_STANDARD: 98
client: 199711
lib: 201103

cmake .. -DCMAKE_CXX_STANDARD=11 && cmake --build . --target version && ./version
-- CMAKE_CXX_STANDARD: 11
client: 201103
lib: 201103

$ cmake .. -DCMAKE_CXX_STANDARD=14 && cmake --build . --target version && ./version
-- CMAKE_CXX_STANDARD: 14
client: 201402
lib: 201402
```

`version
