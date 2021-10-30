# loop: for
add_executable(stars stars.c)       # double loops
add_executable(prime prime.c)       # break; double loops
add_executable(selection-sort selection-sort.c) # while for reading inputs; double loops

# loop: while and do-while
add_executable(palindrome palindrome.c)   # while; comma expression in for; break
add_executable(binary-search binary-search.c) # while; break
add_executable(digits digits.c) # while; do-while