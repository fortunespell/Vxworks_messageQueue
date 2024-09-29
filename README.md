# Vxworks_messageQueue

## VxWorks Inter-Task Communication with Message Queues

This VxWorks project demonstrates inter-task communication using message queues. The project showcases how one task can send a message to another task, facilitating data exchange and synchronization.

### Project Structure

- **main.c:** Contains the main program logic, including task definitions, message queue creation, sending, and receiving messages.

### Functionality

The project defines three functions:

1. **start()**:
    - Prints messages indicating the beginning and end of the start task.
    - Spawns two tasks, `task1` and `task2`.

2. **task1()**:
    - Creates a message queue (`MsgQId`) with a specified maximum number of messages (`MAX_MSGS`) and maximum message length (`MAX_MSG_LEN`).
    - Checks if the message queue creation was successful.
    - Sends a predefined message (`MESSAGE`) to the message queue with normal priority (`MSG_PRI_NORMAL`).
    - Includes error handling for message queue creation and message sending.

3. **task2()**:
    - Defines a message buffer (`msgBuf`) to store the received message.
    - Waits to receive a message from the message queue (`MsgQId`) indefinitely (`WAIT_FOREVER`).
    - Upon successful reception, prints the received message.
    - Handles potential errors during message reception.
  
![image](https://github.com/user-attachments/assets/7f1a1715-52b2-41fd-ba9e-50c42df83575)



### How it Works

- `start()` initiates the process by spawning `task1` and `task2`.
- `task1` creates a message queue and sends a message to it.
- `task2` waits for a message on the same queue and prints it upon reception.

### Building and Running the Project

1. This code is designed to run within a VxWorks environment.
2. Ensure that you have included the required header files: `stdio.h`, `vxWorks.h`, `taskLib.h`, and `msgQLib.h`.
3. Use a VxWorks cross-compiler to compile and link the code.
4. Download and run the executable on a VxWorks target system.

### Notes

- The message queue (`MsgQId`) serves as a communication channel between tasks.
- `WAIT_FOREVER` indicates that the sending and receiving tasks should block indefinitely until the operation completes.
- Error handling is crucial in both sending and receiving messages to manage potential failures gracefully.

This project provides a basic example of using message queues for inter-task communication in VxWorks. This concept is essential for designing more complex real-time embedded systems where tasks need to exchange data and synchronize their operations.
