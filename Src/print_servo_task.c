#include "print_servo_task.h"
#include "usart.h"



void printWelcome(){
  USART_Printf("Welcome to the Project 4 Demo!\n\r");
  USART_Printf("List of Commands:\n\r");
  USART_Printf("\t(B | b) - Begin or Restart the Recipe\n\r");
  USART_Printf("\t(P | p) - Pause Recipe Execution\n\r");
  USART_Printf("\t(C | c) - Continue Recipe Execution\n\r");
  USART_Printf("\t(R | r) - Move 1 Position to the Right\n\r");
  USART_Printf("\t(L | l) - Move 1 Position to the Left\n\r");
  USART_Printf("\t(N | n) - No-op\n\r");
}

void printPrompt(){
  USART_Printf(">>");
}
