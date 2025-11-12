# ASSIGNMENT_8T_A2 — Program Flow, /proc Mapping, Verification & Viva Questions

## Overview

This document explains the flow of the C program (`A2_06_eval.c`) that inspects kernel data via the `/proc` virtual filesystem and meets the assignment requirements. It contains:

- What the program prints when run without arguments (static info)
- What it prints in continuous mode (`./a.out c`) and how the dynamic calculations are made
- Which `/proc` files are used and how to parse them
- Verification commands (shell tools) and sample outputs to attach
- Edge cases, testing checklist, build/run instructions
- Important viva questions with short model answers

---

## 1. High-level program flow

1. Program start: `main(argc, argv)`
   - If run without arguments (`argc == 1`): call `print_static_info()`
   - If run with single argument `"c"`: call `print_dynamic_info()` which loops indefinitely, printing dynamic stats every 1 second
   - Else: print usage

2. `print_static_info()`:
   - Read `/proc/cpuinfo` and extract:
     - Vendor ID (`vendor_id`)
     - Model Name (`model name`)
     - CPU Clock Speed (`cpu MHz`)
     - Cache Size (`cache size`)
   - Read `/proc/version` (or use `uname -a`) to extract kernel name/release
   - Read `/proc/meminfo` and extract `MemTotal` and `MemFree` (or `MemAvailable` if present)
   - Read `/proc/uptime` and convert seconds to Hours:Minutes:Seconds
   - Print all values in a human-readable format

3. `print_dynamic_info()` (loop every 1 second):
   - Sample `/proc/stat`, `/proc/meminfo`, `/proc/diskstats`, `/proc/interrupts` (or `intr` from `/proc/stat`), and `/proc/schedstat` (and per-pid `/proc/<pid>/stat` as needed)
   - Use two consecutive samples separated by ~1s and compute deltas for rate/percentage calculations (see Section 3)
   - Print the dynamic values and repeat until interrupted (SIGINT)

---

## 2. Which `/proc` files are used and why

- `/proc/cpuinfo` — CPU vendor, model name, MHz, cache size
- `/proc/version` or `uname -a` — kernel version/release and build info
- `/proc/meminfo` — MemTotal, MemFree, MemAvailable (preferred)
- `/proc/uptime` — uptime in seconds (first number)
- `/proc/stat` — `cpu` line with cumulative jiffies; `ctxt` (context switches); `intr` (interrupts); possibly `processes`/`procs_created`
- `/proc/diskstats` — per-device I/O cumulative counters (reads, sectors, writes,...)
- `/proc/interrupts` — interrupts per source (use to find timer interrupts)
- `/proc/schedstat` — kernel scheduling stats (per-cpu/thread counters)
- `/proc/[pid]/stat` and `/proc/[pid]/status` — to inspect process/thread state, find currently running tasks

Notes:
- Most `/proc` counters are cumulative since boot; to compute rates you must sample at two times and take differences.
- Prefer `MemAvailable` over `MemFree` when present because it better reflects usable memory.

---

## 3. Key calculations (how numbers are derived)

A. CPU usage (per-second percentages):

- Read CPU fields at t0 and t1 (user, nice, system, idle, iowait, irq, softirq, steal).
- total_delta = total_t1 - total_t0
- user_delta = (user_t1 + nice_t1) - (user_t0 + nice_t0)
- system_delta = system_t1 - system_t0
- idle_delta = idle_t1 - idle_t0
- user% = user_delta / total_delta * 100
- system% = system_delta / total_delta * 100
- idle% = idle_delta / total_delta * 100

B. Memory available:

- total_mem from `MemTotal` (kB)
- avail_mem from `MemAvailable` (kB) if present; else approximate with `MemFree + Buffers + Cached`
- available% = avail_mem / total_mem * 100

C. Context switch rate:

- Read `ctxt` from `/proc/stat` at t0 and t1
- rate = (ctxt_t1 - ctxt_t0) / interval_seconds

D. Process creation rate:

- Use kernel `processes` or `procs_created` counter if present in `/proc/stat`; else count numeric `/proc` entries
- rate = (created_t1 - created_t0) / interval_seconds

E. Disk read/write per second:

- For each device in `/proc/diskstats`, get sectors read and sectors written at t0 and t1
- sectors/sec = (sectors_t1 - sectors_t0) / interval
- bytes/sec = sectors/sec * sector_size (typically 512 bytes)

F. Timer interrupts:

- Use `intr` from `/proc/stat` or parse `/proc/interrupts` for the timer line. Compute per-second delta.

G. Currently executing scheduling entities:

- Scan `/proc/<pid>/stat` for state field (usually `R` for running). Collect pid/comm for tasks in running state.
- Number of scheduling entities: count numeric directories in `/proc` (processes) and sum `/proc/<pid>/task` entries for threads.

---

## 4. Verification commands (run on Pure Ubuntu and attach outputs)

Run these commands in a separate terminal to verify the program's output. Save outputs (e.g., `> verify_cpu.txt`) and paste them into the source file header as the assignment requires.

- CPU snapshot/comparison:
  - sar -u 1 1
  - top -b -n 1
  - vmstat 1 2

- Memory:
  - free -k
  - vmstat -s

- Context switches:
  - sar -w 1 1
  - vmstat 1 2 (check `cs` column)

- Process creation rate:
  - cat /proc/stat | grep processes    # if present
  - watch "ls /proc | egrep '^[0-9]+$' | wc -l"

- Disk I/O:
  - iostat -dx 1 2
  - sar -d 1 1
  - cat /proc/diskstats

- Timer interrupts:
  - cat /proc/interrupts | grep timer
  - cat /proc/stat | grep intr

- Scheduling entities:
  - ps -eLo pid,tid,stat,comm | grep ' R '
  - ps -eLf | grep R

Example capture commands:

```bash
sar -u 1 5 > verify_cpu.txt
vmstat 1 5 > verify_vmstat.txt
iostat -dx 1 5 > verify_iostat.txt
free -k > verify_free.txt
cat /proc/stat > verify_proc_stat.txt
cat /proc/diskstats > verify_diskstats.txt
cat /proc/interrupts > verify_interrupts.txt
```

Attach these `verify_*.txt` files (or paste their contents) into the top comment block of `A2_06_eval.c`.

---

## 5. Sample output excerpts (what your program prints)

Static run (no args):

```
Processor Information:
Vendor ID: GenuineIntel
Model Name: 12th Gen Intel(R) Core(TM) i5-12400
CPU Clock Speed: 2500.000
Cache Size: 18432 KB

Kernel Information:
Linux version 5.15.0-139-generic ...

Memory Information:
Total Memory: MemTotal: 7809728 kB
Free Memory: MemFree: 2624908 kB

System Uptime:
System Uptime: 2 hours, 6 minutes, 39 seconds
```

Continuous run (`./a.out c`) (every second):

```
CPU Usage: User Mode: 1.89%, System Mode: 0.40%, Idle Mode: 97.33%
Memory Usage: 33.38% available
Context Switches Rate: 12 per second
Number of Processes Created: 0
Disk I/O: <device lines or computed reads/sec writes/sec>
Timer Interrupts Rate: 125 per second
Kernel Scheduling: <schedstat lines and running tasks>
```

---

## 6. Implementation notes & recommended edits

- Use *deltas* (sample at t0 and t1) for CPU, `ctxt`, `intr`, diskstats to compute rates.
- Use `MemAvailable` when present. Fall back to `MemFree + Buffers + Cached` if not.
- Parse `/proc/diskstats` by whitespace; kernel versions may vary fields—parse defensively.
- Use 64-bit integers (`unsigned long long`) for cumulative counters to avoid overflow.
- For currently executing tasks, check `/proc/<pid>/stat`'s state field for `R`.
- Add a SIGINT (Ctrl-C) handler to exit the continuous loop cleanly.
- Base per-second rates on actual elapsed time using `clock_gettime(CLOCK_MONOTONIC, ...)` for accuracy.

---

## 7. Edge cases & testing checklist

- Kernel differences: fields or names may differ across kernels—parse defensively and provide fallbacks.
- Permissions: reading most `/proc` files does not require elevated privileges, but check `fopen` return values and `perror` on failure.
- Multi-disk and loop devices: handle many devices and ignore non-disk device lines if needed.
- Thread counting: to include threads, iterate `/proc/<pid>/task` directories.
- Stress testing: run `stress-ng`, `dd if=/dev/zero of=/tmp/test bs=1M count=1024 conv=fsync`, or compile a test loop to generate CPU/disk load to ensure values change.

---

## 8. How to improve the provided code (concrete edits)

- Convert instantaneous reads into sampled deltas for accurate per-second values.
- Parse and display reads/sec and writes/sec per block device rather than printing raw `/proc/diskstats` lines.
- Add a human-friendly display (aligned columns) and optional verbose flags.
- Add a `--once` flag that prints one sample of dynamic info (like `top -b -n 1`) for easier verification.

---

## 9. Build & Run

Build:

```bash
gcc A2_06_eval.c -o os_eval
```

Run static:

```bash
./os_eval
```

Run continuous:

```bash
./os_eval c
# Press Ctrl-C to stop
```

---

## 10. Important viva questions (with short model answers)

1. **What is `/proc` and why is it useful?**
   - `/proc` is a virtual filesystem exposing kernel and process information. It is useful for monitoring and debugging without needing kernel APIs.

2. **How do you compute CPU usage using `/proc/stat`?**
   - Read cumulative jiffies at two timestamps and compute deltas; divide category delta by total delta to get percentages.

3. **Why use deltas for `/proc` counters?**
   - `/proc` exposes cumulative counters; differences over an interval give rates per time unit.

4. **Which `/proc/meminfo` field best estimates available memory?**
   - `MemAvailable` is preferred. If missing, approximate with `MemFree + Buffers + Cached`.

5. **How do you calculate disk I/O rate from `/proc/diskstats`?**
   - Take sectors read/written at two times, difference divided by elapsed time yields sectors/sec; multiply by sector size for bytes/sec.

6. **How do you count processes and threads in `/proc`?**
   - Processes: numeric directories in `/proc`. Threads: entries in `/proc/<pid>/task` for each process.

7. **How do you ensure sampling accuracy over long runs?**
   - Use high-resolution monotonic clock (clock_gettime) for elapsed time and compute rates using the actual elapsed interval.

8. **What is `ctxt` in `/proc/stat`?**
   - `ctxt` is the cumulative count of context switches performed by the kernel since boot.

9. **How to find timer interrupt rate?**
   - Use `intr` in `/proc/stat` or parse `/proc/interrupts` for timer-related lines and compute deltas.

10. **What portability issues can occur when reading `/proc`?**
    - Field availability, names, and formats can change across kernel versions and distributions—parse defensively.

---

## 11. Deliverables checklist

- `A2_06_eval.c` — Source code with verification outputs in the header comment block.
- `ASSIGNMENT_8T_A2_FLOW.md` — This flow document (added).
- `README.md` — Build & run instructions + sample outputs (recommended).
- `verify_*.txt` — Optional files containing captured verification outputs (sar, iostat, vmstat, free, etc.).

---

If you want, I can:

- Update `A2_06_eval.c` to compute deltas correctly, add signal handling, and improve parsing (I can implement these edits now).
- Run verification commands in this environment and capture outputs (note: results may differ from a "Pure Ubuntu" system).

Which would you like next?