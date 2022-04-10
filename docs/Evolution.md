# Evolution of benchmark

## CPU Benchmark

### Approach 1

A naive approach would be to have a for loop with random floating point calculations and record the time it takes to finish the computation. The code for this would look something like this

```c
for (int i = 0; i < loopcount; i++) {
    x = a*x + c;
}
```

This is clearly inefficient since it does not take advantage of either parallelism with SIMD or with multi threading. As expected the resulting GFLOPS are 1.69 GFLOPS, much lesser than what can be achieved.

### Approach 2

We can optimize the previous approach by asking telling the compiler that there are no dependencies and it can be vectorized. While this produces incorrect output, we will achieve out goal of using our CPU to its maximum potential. Adding a small change to our code we get an $8\times$ improvement.

```c
#pragma omp simd
for (int i = 0; i < loopcount; i++) {
	x = a*x + c;
}
```

We achieve a total of 13.4 GFLOPS using vector instructions. Running this code with Intel Advisor gives us the suggestion to compile with -xCORE-AVX2 option. I’m assuming this is since it defaults to using avx instructions set instead of avx2 supported by my CPU. Using the option doesn’t work, I’m guessing  its because its using instructions specific to the Intel architecture. Using `gcc` we get no improvement at all, in fact it does not vectorize either.

### Approach 3

Since we `gcc` cannot vectorize the code, I came up with something that can be vectorized.
