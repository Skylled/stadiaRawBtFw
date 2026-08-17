// 600cad94  timers__600cad94  size=114 bytes
// src: timers.c
// --- callers ---
// --- callees ---
//   6013d140 thunk_EXT_FUN_0000b344
//   601016a2 FUN_601016a2
//   6013d2a0 thunk_EXT_FUN_00007a2c
//   6013d210 thunk_EXT_FUN_0000b316


/* src: timers.c */

void timers__600cad94(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar2 = DAT_600cae14;
  uVar4 = DAT_600cae0c;
  puVar1 = DAT_600cae08;
  while( true ) {
    piVar5 = (int *)*puVar1;
    if (*piVar5 == 0) break;
    uVar7 = ((uint *)piVar5[3])[3];
    uVar8 = *(uint *)piVar5[3];
    thunk_EXT_FUN_0000b344(uVar7 + 4);
    (**(code **)(uVar7 + 0x24))(uVar7);
    if (*(int *)(uVar7 + 0x1c) == 1) {
      uVar6 = *(int *)(uVar7 + 0x18) + uVar8;
      if (uVar8 < uVar6) {
        *(uint *)(uVar7 + 4) = uVar6;
        *(uint *)(uVar7 + 0x10) = uVar7;
        thunk_EXT_FUN_0000b316(*puVar1,uVar7 + 4);
      }
      else {
        iVar3 = thunk_EXT_FUN_00007a2c(uVar7,0,uVar8,0,0,param_2,param_3);
        if (iVar3 == 0) {
          FUN_601016a2(uVar2,0x36e,uVar4);
        }
      }
    }
  }
  uVar4 = *DAT_600cae10;
  *DAT_600cae10 = piVar5;
  *puVar1 = uVar4;
  return;
}


