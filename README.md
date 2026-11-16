*This project has been created as part of the 42 curriculum by jaoyama and keklein.*

# push_swap

## Description

**Goal.** Sort a list of distinct integers on a stack `a`, using a second stack `b` and only these 11 operations, and print the shortest sequence of operations we can find:

`sa sb ss pa pb ra rb rr rra rrb rrr`

**Overview.** This version of the project asks for more than one sorting method. The `push_swap` binary embeds four strategies, measures how disordered the input is, and can report its own statistics:

| Flag | Strategy | Technique | Cost in Push_swap operations |
|------|----------|-----------|------------------------------|
| `--simple` | Simple | Selection sort | O(n²) |
| `--medium` | Medium | Chunk sort (window of about 1.4·√n ranks) | O(n√n) |
| `--complex` | Complex | LSD radix sort on ranks (binary) | O(n log n) |
| `--adaptive` (default) | Adaptive | Chooses one of the above from the measured disorder | O(n²) / O(n√n) / O(n log n) per regime |

An optional `--bench` flag prints the disorder, the strategy used, and the operation counts to `stderr`, without touching the operations printed on `stdout`.

**Data structure.** Each stack is a doubly linked list that keeps `head`, `tail` and `size`. This makes every one of the 11 operations O(1) in time and O(1) in extra space (no shifting of elements), which is what lets us count cost in operations and not in memory moves.

## Instructions

### Build

Requirements: `cc` (gcc or clang) and `make`.

```bash
make          # builds ./push_swap  (flags: -Wall -Wextra -Werror)
make clean    # removes object files
make fclean   # removes object files and the binary
make re       # fclean + all
```

The Makefile does not relink when nothing changed. No global variables are used.

### Run

```
./push_swap [--simple | --medium | --complex | --adaptive] [--bench] <int> <int> ...
```

- The first number is the **top** of stack `a`.
- Flags must come **before** the numbers. If several strategy flags are given, the last one wins. With no strategy flag, `--adaptive` is used.
- Each operation is printed on `stdout`, followed by `\n`, and nothing else.
- With no arguments, the program prints nothing.

```bash
$ ./push_swap 2 1 3 6 5 8
$ ./push_swap --simple 5 4 3 2 1
$ ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_linux $ARG
OK
$ ARG="4 67 3 87 23"; ./push_swap --bench --adaptive $ARG 2> bench.txt | ./checker_linux $ARG
OK
```

### Benchmark mode (`--bench`)

Printed to `stderr` after sorting, and only when the flag is present. Example with a random list of 500 numbers (default strategy):

```
[bench] disorder: 52.26%
[bench] strategy: Adaptive / O(n log n)
[bench] total_ops: 6784
[bench] sa: 0 sb: 0 ss: 0 pa: 2284 pb: 2284
[bench] ra: 2216 rb: 0 rr: 0 rra: 0 rrb: 0 rrr: 0
```

The disorder is shown as a percentage with two decimals. The strategy line shows the strategy name and the complexity class of the algorithm that was actually executed.

### Errors

The program prints `Error` followed by `\n` on `stderr` (and nothing on `stdout`) when:

- an argument is not a valid integer (letters, an empty string, a lone `+` or `-`, a trailing sign such as `5-`, ...). A leading `+` is accepted: `+5` is read as 5,
- an integer is outside the range of `int`,
- there are duplicate values,
- an unknown flag is given (e.g. `--foo`).

```bash
$ ./push_swap --adaptive 0 one 2 3
Error
$ ./push_swap --simple 3 2 3
Error
```

### Norm

All files are checked with `norminette` (`norminette *.c *.h`).

## Algorithms

All algorithms generate a sequence of Push_swap operations. When we state a complexity class, it counts **operations generated**, not CPU time of a classical array-based algorithm (this is the model required by the subject).

### Shared building blocks

**Rank normalization (`assign_index`).** Before the simple, medium and complex strategies run, each value is replaced by its rank `0 … n-1` (stored in the node's `index` field). We copy the values to an array, sort it with a merge sort, then find each node's rank by binary search. This costs O(n log n) CPU time and O(n) extra memory (two `int` arrays, freed right after) and **zero** Push_swap operations. Working on ranks gives the algorithms a clean, gap-free range and makes bit-based and window-based strategies possible even with negative or very large values.

**Disorder metric (`compute_disorder`).** Measured once, **before any move**:

```
disorder = (number of pairs i < j with a[i] > a[j]) / (n * (n - 1) / 2)
```

It is 0 for a sorted list, 1 for a reversed one, and 0 when `n < 2`. Computing it takes O(n²) CPU time but no Push_swap operations, so it does not count against the operation complexity of the strategies. A uniformly random permutation has an expected disorder of 0.5, because every pair is inverted with probability ½.

### Simple: selection sort — O(n²)

For `target = 0, 1, …, n-1`: find the node with rank `target` in `a`, bring it to the top with `ra` (if it is in the first half) or `rra` (otherwise), then `pb`. At the end, `pa` everything back; since the smallest was pushed first, stack `a` ends up ascending.

- **Operations:** with `s` elements left in `a`, bringing the target to the top costs at most `s/2` rotations, plus 1 `pb`. Summing over `s = n … 1` gives at most `n(n+1)/4 + n` operations, plus `n` `pa`. Therefore **O(n²)**.
- **Space:** O(1) beyond the stacks and the O(n) ranking.
- **Why it is here:** it is the simplest correct baseline, easy to verify, and cheap in constant factors for small inputs.

### Medium: chunk sort — O(n√n)

Let `k = ⌊1.4 · ⌊√n⌋⌋` (integer square root computed with a loop, no `math.h`).

1. **Push phase.** Let `i` be the number of elements pushed so far. Look at the top of `a`:
   - rank `≤ i` → `pb` (a small element, it stays on top of `b`);
   - rank `≤ i + k` → `pb` then `rb` (inside the window, it goes to the bottom of `b`);
   - otherwise → `ra` (rotate it out of the way).
2. **Return phase.** Repeatedly find the maximum of `b`, bring it to the top with `rb` or `rrb` (whichever is shorter), then `pa`. `a` ends up ascending.

**Complexity (sketch).** In the push phase, every element whose rank is within the window and still in `a` gets pushed during one traversal of `a`. At least `k+1` unpushed elements have a rank below `i + k + 1`, so each traversal (at most `|a| ≤ n` rotations) pushes at least `k+1` elements. That makes at most about `n/k` traversals, i.e. O(n·n/k) = O(n√n) operations when `k = Θ(√n)`. In the return phase the largest remaining element is always one of the last elements pushed, so it sits within O(k) positions of the top or the bottom of `b`; retrieving all `n` elements costs O(n·k) = O(n√n). Space is O(1) beyond the stacks and the ranking.

**Why `k` depends on `n`.** With a fixed window size, the number of traversals grows linearly with `n` and the cost becomes O(n²/k) — quadratic. We measured this: with a fixed window of 15, ops/n grew from 12 (n=500) to 35 (n=2000); with `k ≈ 1.4·√n`, the ratio `ops / (n√n)` stays flat (≈ 0.4 – 0.6) from n=100 to n=2000. The factor 1.4 was tuned empirically (n=100 and n=500).

### Complex: LSD radix sort — O(n log n)

Binary LSD radix sort on the ranks. For `bit = 0, 1, …, ⌈log₂ n⌉ - 1`: go through the `n` elements of `a` once; if the current bit of the rank is 0 → `pb`, otherwise → `ra`; then `pa` everything from `b` back to `a`.

- **Operations:** each pass costs exactly `n` (pb/ra) plus `|b| ≤ n` (pa), so at most `2n` operations. With `⌈log₂ n⌉` passes the total is at most `2n⌈log₂ n⌉` = **O(n log n)**.
- **Space:** O(1) beyond the stacks and the O(n) ranking.
- **Input independence:** since the ranks of any input are always a permutation of `0 … n-1`, the operation count depends only on `n` (always 1084 for n=100, 6784 for n=500).
- **Why radix:** the cost does not depend on the initial order, and for the sizes of the project it is the most predictable O(n log n) option with two stacks.

### Adaptive — thresholds, techniques, bounds

The adaptive strategy measures the disorder before any move and picks the method:

| Regime | Condition | Method | Operations (upper bound) |
|--------|-----------|--------|--------------------------|
| Low | disorder < 0.2 | Selection sort | O(n²) |
| Medium | 0.2 ≤ disorder < 0.5 | Chunk sort | O(n√n) |
| High | disorder ≥ 0.5 | LSD radix sort | O(n log n) |

The thresholds `0.2` and `0.5` are those required by the subject. Why they make sense:

- **0.5 is the disorder of a random permutation** (standard deviation ≈ 0.03 at n=100 and ≈ 0.015 at n=500). Everything at or above it is "random or worse", where the only safe choice is the algorithm whose cost does not depend on the input order: radix, O(n log n).
- **Below 0.2, fewer than a fifth of the pairs are inverted**: the list is mostly sorted, and the cheap O(n²) method (low overhead, simple) is acceptable.
- **Between 0.2 and 0.5** the input is partly ordered, and chunk sort gives a middle ground with O(n√n) operations.

**Space.** In every regime: the two stacks (O(n) nodes) and, for the ranking, two temporary `int` arrays of size n (O(n)), freed immediately. The merge sort adds O(log n) of recursion depth.

**Note on the benchmark.** Since random lists have disorder ≈ 0.5, they land roughly half of the time in the medium regime (chunk) and half in the high regime (radix). Both therefore have to meet the benchmark targets.

### Limitations and possible improvements

- Selection sort (low regime) does not exploit how sorted the input already is; an insertion-like method would be cheaper.
- `rr`, `rrr` and `ss` are implemented and counted correctly, but the strategies do not yet combine independent rotations of `a` and `b` into them. Doing so would reduce the operation count.
- The adaptive thresholds are fixed; they could be tuned experimentally.
- Just above the small-input cutoff the high-disorder regime can cost more than selection sort (for n = 6 the worst case is 29 operations with radix against 21 with selection sort). A higher cutoff, or choosing by estimated cost, would improve it.

## Performance

Average over random permutations (5 runs per cell); all results were verified as sorted.

| Strategy | n = 100 | n = 500 |
|----------|---------|---------|
| `--simple` | ~1,450 | ~32,000 |
| `--medium` | ~570 | ~5,050 |
| `--complex` | 1,084 | 6,784 |
| default (adaptive) | ~570 or 1,084 | ~5,050 or 6,784 |

Subject targets: for 100 numbers < 2000 (pass), < 1500 (good), < 700 (excellent); for 500 numbers < 12000 (pass), < 8000 (good), < 5500 (excellent).

- 100 numbers: medium (~570) is in the *excellent* range and radix (1,084) in the *good* range.
- 500 numbers: medium (~5,050) is in the *excellent* range and radix (6,784) in the *good* range.
- The adaptive strategy picks one or the other depending on the list, so a random list lands in one of these two tiers.
- `--simple` is a baseline and is not intended to meet the 500-number target.

`--medium` scales as expected: `ops / (n√n)` is 0.59 (n=100), 0.45 (n=500), 0.42 (n=1000) and 0.40 (n=2000).

Reproduce:

```bash
ARG=$(shuf -i 0-9999 -n 500 | tr '\n' ' ')
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker_linux $ARG
./push_swap --bench $ARG > /dev/null
```

## Testing

- **Correctness:** every strategy checked with the provided `checker_linux` on random lists of 5, 100, 500 numbers (and 1000+ for scaling), including negative values.
- **Small inputs:** all permutations of 2 to 5 elements, for the adaptive strategy and for each forced flag.
- **Errors:** letters, empty string `""`, duplicates, values outside `int` (e.g. `2147483648`, `-2147483649`), unknown flags, no arguments, flags only.
- **Edge cases:** one element, already sorted list, reversed list.
- **Memory:** run under `valgrind --leak-check=full` (or AddressSanitizer) with valid and invalid inputs: no leaks, no invalid accesses.
- **Operations:** `rr`, `rrr` and `ss` print and count as a single operation.

## Project structure

| File | Content |
|------|---------|
| `push_swap.c` | `main`, flag parsing, strategy selection |
| `push_swap.h` | types and prototypes |
| `dll.c` | doubly linked list used for both stacks |
| `parse.c`, `validation.c`, `helper_functions.c` | argument parsing and validation, small helpers |
| `swap_ops.c`, `push_ops.c`, `rotate_ops.c`, `reverse_ops.c` | the 11 operations (print and count each one) |
| `disorder.c` | disorder metric |
| `assign_index.c` | rank normalization (merge sort + binary search) |
| `sort_medium.c` | chunk sort (medium strategy) |
| `radix_sort.c` | LSD radix sort (complex strategy) |
| `disorder.c` | disorder metric and osrterd check |
| `benchmark.c` | `--bench` counters and report |

## Contributions

Based on the repository history; adjust it if you want to be more precise.

- **jaoyama:** doubly linked list (`dll.c`); rank normalization with merge sort (`assign_index.c`); radix sort (`radix_sort.c`); adaptive strategy and disorder-based regime selection (`herlper_functions.c`); project structure of `push_swap.c` / `push_swap.h`; README.
- **keklein:** the 11 operations (`swap_ops.c`, `push_ops.c`, `rotate_ops.c`, `reverse_ops.c`); argument parsing and validation (`parse.c`, `validation.c`, `helper_functions.c`); selection sort; chunk sort (`sort_medium.c`); disorder metric; benchmark mode (`benchmark.c`); Makefile.
- **Both:** `push_swap.c` / `push_swap.h`, testing, norm cleanup, algorithm review. Both of us reviewed and can explain every algorithm in this repository.

## Resources

**References**

- Donald Knuth, *The Art of Computer Programming, Vol. 3: Sorting and Searching*.
- GeeksforGeeks: Deque data structure; Implementation of a deque using a doubly linked list; Selection sort; Radix sort (LSD and MSD); Merge sort; Quick sort; Introduction to Max-Heap.
- Wikipedia: Big O notation; Inversion (discrete mathematics); Kendall tau distance (the disorder metric counts inversions).
- 42 peers: discussions and peer reviews about operation counting, chunk sizes and norm issues.
- `man` pages: `read`, `write`, `malloc`, `free`, `exit`; `norminette` documentation.

**How AI was used**

We used an AI assistant (Claude, by Anthropic) as support, never as a replacement for understanding:

- **Planning:** splitting the work between the two of us and ordering the tasks by day.
- **Code review:** finding Norm problems, functions that were never called, `gcc`-specific compilation errors (`-Wmisleading-indentation`), and the malformed output of `rr` / `rrr` / `ss`.
- **`--bench` output:** checking the expected format against the subject and suggesting how to structure the counters and the printing without `printf` or global variables.
- **Chunk size:** measuring how the operation count scales and suggesting a window proportional to √n instead of a fixed size.
- **Testing:** helper scripts (a Python checker of operation sequences and benchmark runs) to test all permutations of small inputs and measure averages.
- **Documentation:** a first draft of this README.

Every suggestion was read, tested and discussed between both of us before being kept; we ran the checker, the norm and the memory tools on the final code.
