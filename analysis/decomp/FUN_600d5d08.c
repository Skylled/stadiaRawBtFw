// 600d5d08  FUN_600d5d08  size=188 bytes
// --- callers ---
//   60063cf4 usb_host_audio_topology__60063cf4
// --- callees ---
//   60063b48 FUN_60063b48
//   60063c58 FUN_60063c58


void FUN_600d5d08(int *param_1)

{
  undefined4 uVar1;
  int extraout_r2;
  undefined1 uVar2;
  byte bVar3;
  
  if (*(char *)((int)param_1 + 5) == '\0') {
    return;
  }
  uVar1 = FUN_60063b48(*(undefined1 *)(*param_1 + 2),(char)param_1[1]);
  switch(uVar1) {
  case 2:
    uVar2 = *(undefined1 *)(extraout_r2 + 7);
    goto LAB_600d5d38;
  case 3:
    FUN_60063c58(param_1 + 5,extraout_r2 + 7);
  case 4:
    FUN_60063c58(param_1 + 5,*param_1 + 7);
    uVar2 = *(undefined1 *)(*param_1 + 8);
LAB_600d5d38:
    *(undefined1 *)((int)param_1 + 7) = uVar2;
    break;
  case 5:
  case 6:
    bVar3 = 0;
    while( true ) {
      if ((uint)*(byte *)(*param_1 + 4) <= (uint)bVar3) break;
      FUN_60063c58(param_1 + 5,*param_1 + bVar3 + 5);
      bVar3 = bVar3 + 1;
    }
    break;
  case 9:
  case 10:
  case 0x12:
    FUN_60063c58(param_1 + 5,extraout_r2 + 4);
    break;
  case 0xe:
  case 0xf:
    bVar3 = 0;
    while( true ) {
      if ((uint)*(byte *)(*param_1 + 6) <= (uint)bVar3) break;
      FUN_60063c58(param_1 + 5,*param_1 + bVar3 + 7);
      bVar3 = bVar3 + 1;
    }
    break;
  case 0x11:
    bVar3 = 0;
    while( true ) {
      if ((uint)*(byte *)(*param_1 + 4) <= (uint)bVar3) break;
      FUN_60063c58(param_1 + 5,*param_1 + bVar3 + 5);
      bVar3 = bVar3 + 1;
    }
  }
  return;
}


