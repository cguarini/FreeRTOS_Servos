#include "main.h"
#include "cmsis_os.h"
#include "led_task.h"
#include "rng.h"
#include "usart.h"
#include "user_input_task.h"
#include "stdio.h"
#include "clock.h"
#include "UART.h"
#include "print_servo_task.h"
#include "servo.h"

#include "string.h"

TaskHandle_t user_handle = NULL;
char str[100];


void user_input_task(void *parameters)
{
	int strIndex = 0;
	while(1){
 //Check for User Input While Looping
		if(hasCharacter(USART2)){
			char c = getChar();
			putChar(c);
			
			str[strIndex] = c;
			strIndex++;
			
			//Check for newline character
			if(c == 0x0D){
        putChar('\n');
        //null terminate string
				str[strIndex] = 0x00;
        
        //Parse and handle the command string
        handleCommand(str);
        
        //reset the string
        strIndex = 0;
        
        //Re-print the prompt
        printPrompt();
			}
		}
    else{
      vTaskDelay(20);
    }
	
		}

}



void user_input_task_init()
	
{
  xTaskCreate( user_input_task, "Input Task", 256, (void *) 0, 2, &user_handle); // go ahead and create the task 
	
}
