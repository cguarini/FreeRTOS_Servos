#ifndef __user_input_task_h
#define __user_input_task_h
#include "stm32l476xx.h"
#include "cmsis_os.h"

void user_input_task(void *parameters);
void user_input_task_init();
#endif /* __user_input_task_h */