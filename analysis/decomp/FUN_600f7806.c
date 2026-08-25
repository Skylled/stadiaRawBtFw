// 600f7806  FUN_600f7806  size=268 bytes
// --- callers ---
//   600f77cc FUN_600f77cc
// --- callees ---
//   600b5e00 FUN_600b5e00
//   600bcc30 FUN_600bcc30
//   6006e0a4 FUN_6006e0a4
//   600bb6dc FUN_600bb6dc


undefined4
FUN_600f7806(undefined4 param_1,char param_2,undefined2 param_3,short param_4,undefined2 param_5,
            undefined4 *param_6)

{
  short sVar1;
  undefined4 uVar2;
  undefined1 auStack_20 [10];
  short local_16;
  undefined2 local_14;
  int local_10;
  int local_c;
  
  local_c = FUN_600bb6dc(param_1,1);
  if (local_c == 0) {
    uVar2 = 0;
  }
  else {
    local_10 = FUN_600bcc30(local_c,param_3);
    if (local_10 == 0) {
      uVar2 = 0;
    }
    else if (param_2 == *(char *)(local_10 + 8)) {
      if (param_6 != (undefined4 *)0x0) {
        *(undefined4 *)(local_10 + 0xa7) = *param_6;
        *(undefined2 *)(local_10 + 0xab) = *(undefined2 *)(param_6 + 1);
        if (*(char *)(local_10 + 0xab) == -1) {
          *(undefined1 *)(local_10 + 0xab) = 2;
        }
        if (*(char *)(local_10 + 0xac) == -1) {
          *(undefined1 *)(local_10 + 0xac) = 2;
        }
        if (*(char *)(local_10 + 0xa9) == -1) {
          *(undefined1 *)(local_10 + 0xa9) = 2;
        }
        if (*(char *)(local_10 + 0xaa) == -1) {
          *(undefined1 *)(local_10 + 0xaa) = 2;
        }
        sVar1 = FUN_6006e0a4(*(undefined1 *)((int)param_6 + 2));
        *(short *)(local_10 + 0x11a) = sVar1 + -0x11;
      }
      if (param_4 == 0) {
        FUN_600b5e00(local_10,0x16,0);
      }
      else {
        local_14 = param_5;
        local_16 = param_4;
        if (param_4 == 1) {
          FUN_600b5e00(local_10,0x16,auStack_20);
        }
        else {
          FUN_600b5e00(local_10,0x17,auStack_20);
        }
      }
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}


