#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

// PROGRAM MAIN
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,BLINK_STATUS)
  TON BLINK_TIMER1;
  TOF BLINK_TIMER2;
  __DECLARE_VAR(TIME,WAIT_TIME)
  TON TON0;
  TOF TOF0;
  __DECLARE_LOCATED(BOOL,PB1)
  __DECLARE_LOCATED(BOOL,LED1)

} MAIN;

void MAIN_init__(MAIN *data__, BOOL retain);
// Code part
void MAIN_body__(MAIN *data__);
#endif //__POUS_H
