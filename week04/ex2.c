#include <stdio.h>
#include <unistd.h>

int main() {

    for (int i = 0; i < 5; i++) {
        fork();
        sleep(5);
    }

    return 0;

}

/*
There are 8 processes for 3 repetitions. The growth is as follows.
a.out───a.out

a.out─┬─a.out───a.out
      └─a.out

a.out─┬─a.out─┬─a.out───a.out
      │       └─a.out
      ├─a.out───a.out
      └─a.out             
Every fork() call doubles the number of processes (due to parent and child processes).

There are 32 processes for 5 loop iterations.
a.out─┬─a.out─┬─a.out─┬─a.out─┬─a.out───a.out
      │       │       │       └─a.out
      │       │       ├─a.out───a.out
      │       │       └─a.out
      │       ├─a.out─┬─a.out───a.out
      │       │       └─a.out
      │       ├─a.out───a.out
      │       └─a.out
      ├─a.out─┬─a.out─┬─a.out───a.out
      │       │       └─a.out
      │       ├─a.out───a.out
      │       └─a.out
      ├─a.out─┬─a.out───a.out
      │       └─a.out
      ├─a.out───a.out
      └─a.out


*/