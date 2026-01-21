#include "POUS.h"
#include "Config0.h"

void MAIN_init__(MAIN *data__, BOOL retain) {
  __INIT_VAR(data__->BLINK_STATUS,__BOOL_LITERAL(FALSE),retain)
  TON_init__(&data__->BLINK_TIMER1,retain);
  TOF_init__(&data__->BLINK_TIMER2,retain);
  __INIT_VAR(data__->WAIT_TIME,__time_to_timespec(1, 0, 2, 0, 0, 0),retain)
  TON_init__(&data__->TON0,retain);
  TOF_init__(&data__->TOF0,retain);
  __INIT_LOCATED(BOOL,__IX0_0,data__->PB1,retain)
  __INIT_LOCATED_VALUE(data__->PB1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0,data__->LED1,retain)
  __INIT_LOCATED_VALUE(data__->LED1,__BOOL_LITERAL(FALSE))
}

// Code part
void MAIN_body__(MAIN *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->BLINK_TIMER1.,IN,,!(__GET_VAR(data__->BLINK_STATUS,)));
  __SET_VAR(data__->BLINK_TIMER1.,PT,,__GET_VAR(data__->WAIT_TIME,));
  TON_body__(&data__->BLINK_TIMER1);
  __SET_VAR(data__->BLINK_TIMER2.,IN,,__GET_VAR(data__->BLINK_TIMER1.Q,));
  __SET_VAR(data__->BLINK_TIMER2.,PT,,__GET_VAR(data__->WAIT_TIME,));
  TOF_body__(&data__->BLINK_TIMER2);
  __SET_VAR(data__->,BLINK_STATUS,,__GET_VAR(data__->BLINK_TIMER2.Q,));
  __SET_LOCATED(data__->,LED1,,(__GET_VAR(data__->BLINK_STATUS,) || __GET_LOCATED(data__->PB1,)));

  goto __end;

__end:
  return;
} // MAIN_body__() 





