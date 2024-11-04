# Disk Scheduling Algorithms

Disk scheduling algorithms are used by operating systems to determine the order in which disk I/O requests are processed. Different algorithms have varying approaches to minimize seek time, improve efficiency, and reduce latency.

---
![image](https://github.com/user-attachments/assets/f74da31d-0dde-4597-9944-9c83a773ac4e)


### 1. First-Come, First-Served (FCFS)

**Definition**:  
FCFS is the simplest disk scheduling algorithm, where requests are handled in the order they arrive.

**Description**:  
- **Operation**: Requests are queued in the order they arrive, and each is processed sequentially.
- **Advantages**: Easy to implement; no starvation of requests.
- **Disadvantages**: Inefficient, as it may lead to long seek times if the requests are far apart on the disk.

**Example**:  
![image](https://github.com/user-attachments/assets/1b43f4a5-c834-47e4-baaf-aae25e9ec1c0)


---

### 2. Shortest Seek Time First (SSTF)

**Definition**:  
SSTF selects the disk request closest to the current head position, minimizing seek time for each individual request.

**Description**:  
- **Operation**: Out of all pending requests, the one closest to the head is selected next.
- **Advantages**: Reduces overall seek time compared to FCFS.
- **Disadvantages**: Can cause starvation for requests far from the head position.

**Example**:  
![image](https://github.com/user-attachments/assets/2a81c8c1-4b88-477c-875f-44985a152578)


---

### 3. SCAN (Elevator Algorithm)

**Definition**:  
SCAN, or the elevator algorithm, moves the head in one direction (up or down the cylinders) and processes requests sequentially, then reverses direction when it reaches the end.

**Description**:  
- **Operation**: The head moves in a set direction, fulfilling requests as it encounters them. Once it reaches the end, it reverses direction.
- **Advantages**: Provides fair access to all requests; good performance in systems with heavy loads.
- **Disadvantages**: Requests at the far end might experience longer wait times.

**Example**:  
![image](https://github.com/user-attachments/assets/b65ca4b5-a887-4251-8101-02546d8a14a9)


---

### 4. Circular SCAN (C-SCAN)

**Definition**:  
C-SCAN is a variation of SCAN where the head only moves in one direction, and when it reaches the end, it quickly returns to the beginning without servicing requests in the return path.

**Description**:  
- **Operation**: The head moves in one direction, processes requests, and upon reaching the end, returns to the start without serving any requests in the return.
- **Advantages**: Provides a more uniform wait time for requests across the disk.
- **Disadvantages**: Higher seek time as the head must return to the start without serving requests.

**Example**:  
![image](https://github.com/user-attachments/assets/1273c093-3c81-4c38-a145-163ced4e8b5d)


---

### 5. LOOK Algorithm

**Definition**:  
The LOOK algorithm is similar to SCAN but only moves as far as the last request in each direction before reversing, without going to the disk's physical end.

**Description**:  
- **Operation**: The head moves in one direction, serving requests, and stops when no more requests are pending in that direction.
- **Advantages**: Reduces unnecessary movement compared to SCAN.
- **Disadvantages**: May not handle edge cases as uniformly as SCAN or C-SCAN.

**Example**:  
![image](https://github.com/user-attachments/assets/ca6b37ec-2599-433e-8e64-b4fe41a2f371)


---

### 6. C-LOOK Algorithm

**Definition**:  
C-LOOK is a variation of LOOK, where the head only moves in one direction and returns to the beginning once it reaches the last request, without serving requests on the way back.

**Description**:  
- **Operation**: The head moves toward the end of the request range, then returns to the start position to continue serving requests in the same direction.
- **Advantages**: Reduces wait time variance similar to C-SCAN but with optimized movement.
- **Disadvantages**: Increased seek time due to jumping back to the start.

**Example**:  
![image](https://github.com/user-attachments/assets/79767ffa-5a09-4e08-b3b8-98a5d1eefdc0)


---


