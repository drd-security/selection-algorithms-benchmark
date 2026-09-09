# Selection Algorithms Benchmark

C implementations of four algorithms for selecting the **k-th order statistic** without fully sorting the input.

## Implementations

- `QuickSelect.c` — randomized Quickselect.
- `FRSelect.c` — Floyd-Rivest selection.
- `SelectionSelect.c` — repeated selection baseline.
- `HeapSelect.c` — heap-based selection.

All implementations conform to the same callback-based interface, allowing them to operate on arbitrary array element types while delegating comparison and swapping to the caller.

## Build note

Each source file exports the same `select(...)` symbol and is meant to be compiled **individually** against a benchmark/test harness, not linked together into one executable.

Example syntax check:

```bash
gcc -std=c99 -Wall -Wextra -Iinclude -c algorithms/QuickSelect.c
gcc -std=c99 -Wall -Wextra -Iinclude -c algorithms/FRSelect.c
```

`FRSelect.c` requires the math library when linked (`-lm`).

## Academic context

Data Structures & Algorithms project, academic year **2024-2025**, completed by a **team of two students**. The original report compared theoretical and empirical behavior, including runtime and comparison counts.

The course benchmarking harness is not redistributed; the small `Select.h` in this portfolio copy reproduces only the interface required by the submitted implementations. See [NOTICE.md](NOTICE.md).
