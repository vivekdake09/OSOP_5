# Inter-Process Communication (IPC) using FIFO and Pipes

### Inter-Process Communication (IPC)

**Definition**:  
Inter-Process Communication (IPC) refers to mechanisms that allow processes to exchange data and signals. IPC is essential for coordinating and sharing information between processes running in the same or different programs, enabling more complex and efficient workflows in multitasking environments.

---

### Pipes

**Definition**:  
A pipe is a unidirectional communication channel that allows one process to send data to another process. Data flows in one direction (from the writing end to the reading end), making it suitable for communication between parent and child processes.

**Key Operations with Pipes**:
1. **Writing to a Pipe**:  
   The writing process sends data into the pipe, which can be read by a receiving process. If the pipe buffer is full, the writing process waits until there is space available.

2. **Reading from a Pipe**:  
   The reading process retrieves data from the pipe. If there is no data, the reading process blocks until data is available, ensuring that data flows in sync.

**Example of Pipe Usage**:
In a Unix-like system, the command `ls | grep ".txt"` uses a pipe (`|`) to send the output of the `ls` command (list directory contents) as input to the `grep` command, which filters out only `.txt` files.

---

### FIFO (First In, First Out)

**Definition**:  
FIFO, also known as a "named pipe," is a type of pipe that allows communication between unrelated processes. Unlike regular (unnamed) pipes, which only exist in the memory, a FIFO has a physical presence in the file system, making it accessible by multiple processes without a parent-child relationship.

**Properties of FIFO**:
- **Persistence**: FIFO remains in the filesystem until deleted, unlike regular pipes, which are temporary.
- **Bidirectional**: FIFO allows two-way communication but typically is used in one direction at a time.
- **Blocking Behavior**: A read operation on an empty FIFO will block until data is available, and a write operation on a full FIFO will block until space is available.

**Creating a FIFO**:
In Unix-like systems, a FIFO can be created using the command:
```bash
mkfifo my_fifo
