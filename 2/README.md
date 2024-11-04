# Process Control Concepts

### Process States

| **Concept**                  | **Description**                                                                                                 |
|------------------------------|-----------------------------------------------------------------------------------------------------------------|
| **Zombie Process**           | A process that has completed execution but still has an entry in the process table, awaiting parent acknowledgment. This occurs when a parent process doesn't call `wait()` to read the exit status. |
| **Orphan Process**           | A child process whose parent has terminated, causing it to be adopted by the `init` process (PID 1) to ensure it is properly managed. |

---

### System Calls

| **System Call**  | **Description**                                                                                                                 |
|------------------|---------------------------------------------------------------------------------------------------------------------------------|
| **fork**         | Creates a new process by duplicating the calling process. The new process, or "child," receives a unique process ID (PID).     |
| **execv**        | Replaces the current process image with a new one, executing a new program in the process’s memory space.                      |
| **wait**         | Makes a parent process wait for a child process to complete, ensuring proper cleanup of child resources.                        |
| **exit**         | Terminates a process, returning a status code to the parent if applicable, marking it as completed.                            |
| **kill**         | Sends a signal to a process, which can terminate or interrupt it, depending on the signal type used (e.g., `SIGKILL`).        |
| **getpid**       | Returns the PID (process ID) of the calling process, useful for tracking and managing processes.                               |
| **getppid**      | Returns the PID of the parent of the calling process, enabling child processes to interact with or monitor their parent.       |

---

### Additional Process Management Concepts

| **Concept**                  | **Description**                                                                                                         |
|------------------------------|-------------------------------------------------------------------------------------------------------------------------|
| **Process Table**            | A system-maintained table containing details of all active processes, including state, PID, and resources in use.     |
| **Context Switching**        | The process of saving and loading the state of processes, allowing the CPU to switch from one process to another efficiently. |
| **Daemon Process**           | A background process, often started at boot, which runs independently of any user session, typically without a controlling terminal. |

---

This README provides a quick overview of important process control concepts and system calls. For deeper exploration, consider referring to system programming resources or operating system documentation.
