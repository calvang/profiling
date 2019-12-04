# Adv Hw 12 Instructions

### Using `gcov`

Use necessary flags:

`gcc -fprofile-arcs -ftest-coverage main.c -o main_with profiling`

Run:

`./main_with_profiling`

Run gcov:

`gcov -b -c main.c`

Show the report:

`cat main.c.gcov`

Branch stats should be visible on functions

### Profile Guided Optimization

Instrumentation:

`gcc -fprofile-genrate=<profile_dir> progname.c`

Optimization:

`gcc -fprofile-use=<profile_dir> progname.c`