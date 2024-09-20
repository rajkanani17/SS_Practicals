/*
============================================================================
Name : 19c.c
Author : Raj Kanani
Roll No : MT2024074
Description : Create a FIFO file by
              c. use strace command to find out, which command (mknod or mkfifo) is better.
============================================================================
*/

/*  Output :
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_19$ strace -c mknod
    mknod: missing operand
    Try 'mknod --help' for more information.
    % time     seconds  usecs/call     calls    errors syscall
    ------ ----------- ----------- --------- --------- ----------------
      0.00    0.000000           0         7           read
      0.00    0.000000           0         4           write
      0.00    0.000000           0        10           close
      0.00    0.000000           0        19           mmap
      0.00    0.000000           0         5           mprotect
      0.00    0.000000           0         1           munmap
      0.00    0.000000           0         3           brk
      0.00    0.000000           0         2           pread64
      0.00    0.000000           0         2         2 access
      0.00    0.000000           0         1           execve
      0.00    0.000000           0         2         2 statfs
      0.00    0.000000           0         2         1 arch_prctl
      0.00    0.000000           0         1           set_tid_address
      0.00    0.000000           0        19        11 openat
      0.00    0.000000           0         8           newfstatat
      0.00    0.000000           0         1           set_robust_list
      0.00    0.000000           0         1           prlimit64
      0.00    0.000000           0         1           getrandom
      0.00    0.000000           0         1           rseq
    ------ ----------- ----------- --------- --------- ----------------
    100.00    0.000000           0        90        16 total

*/