// 6006012c  pwm__6006012c  size=40 bytes
// src: pwm.h
// --- callers ---
//   600d4c3a FUN_600d4c3a
//   600d4b78 FUN_600d4b78
//   600d4cae FUN_600d4cae
//   600601a4 FUN_600601a4
//   600d4a7e FUN_600d4a7e
//   600d4ada FUN_600d4ada
//   600d4b28 FUN_600d4b28
//   60060284 FUN_60060284
// --- callees ---
//   601016a2 FUN_601016a2


/* src: pwm.h */

undefined4
pwm__6006012c(undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  switch(*param_1) {
  case 0:
    uVar1 = DAT_60060168;
    break;
  case 1:
    uVar1 = DAT_60060158;
    break;
  case 2:
    uVar1 = DAT_6006016c;
    break;
  case 3:
    uVar1 = DAT_6006015c;
    break;
  default:
    FUN_601016a2(DAT_60060164,0x41,DAT_60060160,*param_1,param_4);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  return uVar1;
}


