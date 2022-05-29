# The truth of C++ 20 STL `format`

Until 05/29/2022, the C++ 20 STL `format` is much slower than even `snprintf`. Run `fmt_format.cpp` once and I got the following result.

```shell
0-
1446859300
0.2483896
1244047162
0.6709394
3433594290
1.539256
```

I used `CLion` with toolchain of `Visual Studio 17.0`, generator of `Visual Studio 17 2022` and build type of `release`. The `fmt.lib` is built by myself, using `8.1.1` edition. The result shows that `fmt::v8::format_to_n` will not give `'\x0'` at the last of the `char[]`, so I use `out` member of its result and set the last of the `char[]` to `'\0`' actively. I used a `mt19937` using `random_device` as its seed to generate random number as result. For `fmt::v8::format_to_n` and `snprintf` repeated it 10 million times. Both of them completed it within a second. However, for `std::format_to_n` repeadted it just a million times, it spent more than 1.5 seconds.
