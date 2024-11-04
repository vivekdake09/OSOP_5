# CPU Scheduling Algorithms

### Overview

| **Algorithm**              | **Description**                                                                                                  |
|----------------------------|------------------------------------------------------------------------------------------------------------------|
| **Round Robin (RR)**       | A time-sharing scheduling algorithm that assigns a fixed time slice (quantum) to each process in a circular queue. It’s fair but may lead to high turnaround times. |
| **Shortest Job First (SJF)** | Schedules processes with the shortest burst time first, minimizing overall waiting time but potentially causing starvation of longer processes.        |
| **First-Come, First-Served (FCFS)** | Processes are scheduled in the order they arrive, easy to implement but can cause the "convoy effect" where long processes delay others.   |
| **Priority Scheduling**    | Schedules processes based on priority levels, where higher priority tasks are executed first. Lower-priority tasks may face starvation. |

---

### Examples

#### 1. Round Robin (RR) Example

**Scenario**: Assume three processes with the following burst times and a time quantum of 4.

| **Process** | **Burst Time** |
|-------------|-----------------|
| P1          | 10             |
| P2          | 4              |
| P3          | 6              |

**Execution Order**:
- **Round 1**: P1 (4), P2 (4, completes), P3 (4)
- **Round 2**: P1 (4, completes), P3 (2, completes)

**Result**:
- P1 completes after 8 units, P2 completes after 4 units, and P3 completes after 6 units.

#### 2. Shortest Job First (SJF) Example

**Scenario**: Assume three processes with the following burst times, where SJF scheduling selects the process with the shortest burst time.

| **Process** | **Burst Time** |
|-------------|-----------------|
| P1          | 6              |
| P2          | 2              |
| P3          | 8              |

**Execution Order**:
- P2 (2 units) → P1 (6 units) → P3 (8 units)

**Result**:
- P2 completes first, minimizing waiting time, followed by P1 and then P3.

---

This document summarizes CPU scheduling algorithms with examples for Round Robin and Shortest Job First to illustrate how processes are managed in different scheduling scenarios.
