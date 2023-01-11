# primes

## `primes.c`
- double loops
- `int is_prime = 1;`
  - why 1? why not 0?
- testing
  - https://www.wolframalpha.com/input?i=+primes+less+than+100000
  - mma: `PrimePi[100000]`
  - `number = 2`
- `break`
- [x] timing
  - `clock_t start = clock(); clock_t end = clock(); (end - start) / CLOCKS_PER_SEC`
- `i * i <= number` vs. `i * i < number`
- `if (is_prime)` vs. `if (is_prime != 0)` vs. `if (is_prime == 1)`
- `stdbool.h`