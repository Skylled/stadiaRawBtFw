// 600600c4  pwm__600600c4  size=38 bytes
// src: pwm.h
// --- callers ---
//   600d4c3a FUN_600d4c3a
//   600d4b78 FUN_600d4b78
//   600d4cae FUN_600d4cae
//   600601a4 FUN_600601a4
//   600d4a7e FUN_600d4a7e
//   60060284 FUN_60060284
// --- callees ---
//   601016a2 FUN_601016a2


/* src: pwm.h */

undefined4
pwm__600600c4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  switch(param_1) {
  case 0:
    uVar1 = 0;
    break;
  case 1:
    uVar1 = 1;
    break;
  case 2:
    uVar1 = 2;
    break;
  case 3:
    uVar1 = 3;
    break;
  default:
    FUN_601016a2(DAT_600600f4,0x74,DAT_600600f0,param_4,param_4);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  return uVar1;
}


