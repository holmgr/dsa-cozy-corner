# C++ Implementations

Make sure that you have CMake installed.
We use the Google Test C++ testing framework which you can read more about on their
[github page](https://github.com/google/googletest)

## Setup test environment
We use the Google Test testing framework which is automatically downloaded by running:

```
cmake -H. -Bbuild
```

## Compiling and running tests
Compiling is done by running:

```
cmake --build build -- -j3
```

After which you can run the tests for one executable as such:

```
./bin/example
```
