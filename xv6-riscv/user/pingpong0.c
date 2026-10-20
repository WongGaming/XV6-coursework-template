#include "kernel/types.h"
#include "user/user.h"

int main() {
  // Declare two pipes
  // p2c - a parent to a child communication
  int pipeP2C[2];

  // c2p - a child to a parent communication
  int pipeC2P[2];

  // Call the pipe() system call to create p2c and c2p

  pipe(pipeP2C);
  pipe(pipeC2P);
  // Declare one byte for sending to the child process
  char our_byte = 'P';

  // Fork a new process
  int pid = fork();
  if (pid > 0) {
    // 1. PLACE YOUR CODE HERE TO SEND A BYTE TO THE OTHER PROCESS
    write(pipeP2C[1], &our_byte, 1);
    // 5. PLACE YOUR CODE HERE TO RECEIVE THE MODIFIED BYTE
    read(pipeC2P[0], &our_byte, 1);
    printf("%d: received pong, %c\n",pid, our_byte);   
  }
  else if (pid == 0) {
    // 2. PLACE YOUR CODE HERE TO READ A BYTE IN THE PIPE p2c
    read(pipeP2C[0], &our_byte, 1);
    printf("%d: received ping, %c\n",pid, our_byte);
    // 3. PLACE YOUR CODE HERE TO MODIFY THE BYTE TO LETTER 'R'
    our_byte = 'R';
    // 4. PLACE YOUR CODE HERE TO SEND THE BYTE BACK OVER c2p PIPE
    write(pipeC2P[1], &our_byte, 1);
  }
  exit(0); // Exit parent process
}
