# A2_06_eval.c — Architecture and Flowchart

This document describes the architecture, main components, data structures, sampling approach, and flowchart for `A2_06_eval.c` (Assignment 8T A2 — Observing the OS through /proc).

## 1. Purpose

Provide a clear architecture and visual flow to explain how `A2_06_eval.c` collects static and dynamic system information from `/proc` and computes rates/percentages for the continuous mode (`./a.out c`). This document is intended for reviewers and viva preparation.

---

## 2. Components

- Main control flow
  - `main(argc, argv)` decides static or continuous mode and calls appropriate function.

- Static info collector: `print_static_info()`
  - Reads and prints:
    - `/proc/cpuinfo` — Vendor ID, Model Name, cpu MHz, cache size
    - `/proc/version` — kernel/version info
    - `/proc/meminfo` — MemTotal and MemFree
    - `/proc/uptime` — uptime (converted to H:M:S)

- Dynamic info collector: `print_dynamic_info()`
  - Looping function that prints dynamic metrics every second.
  - Uses helper `count_processes()` to count numeric entries in `/proc` (process count).
  - Reads `/proc/stat`, `/proc/meminfo`, `/proc/diskstats`, `/proc/schedstat` and prints info.

- Utilities
  - `count_processes()` — counts numeric directories in `/proc` to estimate current process count.
  - `is_pid_directory()` — helper to detect numeric directory names.

---

## 3. Data sources mapped to outputs

- Processor Information:
  - Source: `/proc/cpuinfo`
  - Extracted fields: `vendor_id`, `model name`, `cpu MHz`, `cache size`

- Kernel Information:
  - Source: `/proc/version`

- Memory Information:
  - Source: `/proc/meminfo`
  - Extracted: `MemTotal`, `MemFree` (use `MemAvailable` if available in improved version)

- System Uptime:
  - Source: `/proc/uptime` (first value)

- CPU usage percentages:
  - Source: `/proc/stat` (`cpu` line)
  - Compute percentages from deltas between two samples (recommended improvement)

- Context switches rate:
  - Source: `/proc/stat` (`ctxt`)
  - Compute per-second delta between samples

- Process creation rate:
  - Option A: `/proc/stat` exposes `processes`/`procs_created` on some kernels
  - Option B (used): count numeric directories in `/proc` and compute difference over time

- Disk I/O:
  - Source: `/proc/diskstats`
  - Parse per-device cumulative counters (sectors read/written); compute per-second rates via differencing

- Timer interrupts:
  - Source: `/proc/stat` (`intr`) or `/proc/interrupts` (timer line)
  - Compute per-second deltas

- Kernel scheduling info:
  - Source: `/proc/schedstat` and optionally `/proc/<pid>/stat` for per-task states

---

## 4. Key algorithmic points and sampling approach

- Many `/proc` values are cumulative since boot. To compute rates (per-second), follow this pattern:
  1. Read metrics at time t0 and store values.
  2. Sleep for an interval (e.g., 1 second).
  3. Read metrics at time t1.
  4. Delta = value(t1) - value(t0); rate = Delta / (t1 - t0).

- For CPU percentages, use deltas of jiffies across categories. total_delta = sum of category deltas.
  - user% = (user_delta + nice_delta) / total_delta * 100
  - system% = system_delta / total_delta * 100
  - idle% = idle_delta / total_delta * 100

- For memory, use `MemAvailable` when available to estimate available memory. Otherwise, approximate from `MemFree`, `Buffers`, `Cached`.

- For disk I/O and interrupts, use 64-bit counters to avoid overflow. Use `unsigned long long` for cumulative values.

---

## 5. High-level flowchart (Mermaid)

```mermaid
flowchart TD
  A[Start: main(argc,argv)] --> B{argc==1}
  B -- yes --> C[call print_static_info()]
  B -- no --> D{argc==2 && argv[1]=="c"}
  D -- yes --> E[call print_dynamic_info()]
  D -- no --> F[print usage]

  subgraph STATIC [print_static_info]
    C1[open /proc/cpuinfo] --> C2[extract vendor_id, model name, cpu MHz, cache]
    C2 --> C3[open /proc/version and print kernel info]
    C3 --> C4[open /proc/meminfo and print MemTotal, MemFree]
    C4 --> C5[open /proc/uptime and print uptime in H:M:S]
    C5 --> C6[return]
  end

  subgraph DYN [print_dynamic_info loop]
    E1[prev_proc_count = count_processes()] --> E2[loop start]
    E2 --> E3[open /proc/stat and read cpu line]
    E3 --> E4[compute CPU percentages (recommended: sample twice)]
    E4 --> E5[open /proc/meminfo and read MemTotal, MemFree/Available]
    E5 --> E6[open /proc/stat and read ctxt]
    E6 --> E7[curr_proc_count = count_processes(); print proc_created = curr-prev]
    E7 --> E8[open /proc/diskstats and print lines or compute deltas]
    E8 --> E9[open /proc/stat and read intr (timer interrupts)]
    E9 --> E10[open /proc/schedstat and print scheduling info]
    E10 --> E11[sleep(1)] --> E2
  end
```

---

## 6. ASCII flow (fallback)

main()
  |
  +-- if no args: print_static_info()
  |     +-- read /proc/cpuinfo -> print CPU fields
  |     +-- read /proc/version -> print kernel
  |     +-- read /proc/meminfo -> print MemTotal/MemFree
  |     +-- read /proc/uptime -> convert and print
  |
  +-- if arg == 'c': print_dynamic_info()
        +-- prev_count = count_processes()
        +-- loop:
            +-- read /proc/stat -> cpu line -> compute CPU usage (use deltas)
            +-- read /proc/meminfo -> print available memory
            +-- read /proc/stat -> ctxt -> compute delta
            +-- curr_count = count_processes() -> print creations = curr-prev
            +-- read /proc/diskstats -> show or compute per-second IO
            +-- read /proc/stat -> intr -> compute delta
            +-- read /proc/schedstat -> print scheduling info
            +-- sleep(1)
            +-- repeat

---

## 7. Viva questions (with short answers)

1. Q: Why do we need to take two samples to compute rates from `/proc`?
   - A: Because `/proc` counters are cumulative since boot; differences between two samples give the count over an interval, which yields a rate.

2. Q: Which `/proc` file gives CPU jiffies and how are they used?
   - A: `/proc/stat` contains a `cpu` line with jiffies for user, nice, system, idle, iowait, irq, softirq, steal. Deltas of these values are used to compute CPU utilization percentages.

3. Q: How do you compute per-second disk reads/writes from `/proc/diskstats`?
   - A: Read cumulative sector counts at two times, compute difference, divide by elapsed time for sectors/sec, and multiply by sector size for bytes/sec.

4. Q: Why prefer `MemAvailable` over `MemFree`?
   - A: `MemFree` excludes reclaimable caches and buffers; `MemAvailable` better estimates memory that can be used without swapping.

5. Q: How do you count processes and threads using `/proc`?
   - A: Processes can be counted by listing numeric directories in `/proc`. Threads require enumerating `/proc/<pid>/task` entries for each process.

6. Q: What are potential portability pitfalls when parsing `/proc`?
   - A: Field names, order, and availability can vary across kernel versions and distributions; parsing must be defensive.

7. Q: How would you handle counters wrapping on long-running systems?
   - A: Use 64-bit unsigned counters and compute deltas modulo 2^64 if necessary; wraparound is rare on modern 64-bit systems.

8. Q: How can you get the timer interrupt rate specifically?
   - A: Use `/proc/stat`'s `intr` counter or parse `/proc/interrupts` for the timer line and compute deltas over time.

---

## 8. Suggested improvements and next steps

- Implement proper delta-based sampling across all dynamic metrics (CPU, ctxt, intr, diskstats) to compute accurate per-second rates.
- Replace printing raw `/proc/diskstats` lines with parsed per-device reads/sec and writes/sec values.
- Add signal handling to exit continuous mode cleanly and free resources.
- Use `clock_gettime(CLOCK_MONOTONIC, ...)` to measure elapsed time accurately between samples.

---

## 9. Files created

- `A2_06_eval.c` — original source (existing)
- `A2_06_eval_ARCH.md` — this file (added)

---

If you'd like, I can now:
- Edit `A2_06_eval.c` to compute deltas correctly and add signal handling.
- Run the program in this environment and capture verification outputs (note: environment might differ from "Pure Ubuntu").

Which of these would you like next?