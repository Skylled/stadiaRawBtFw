// 600b3240  FUN_600b3240  size=352 bytes
// --- callers ---
//   600a27fc FUN_600a27fc
//   600a14e4 FUN_600a14e4
// --- callees ---
//   600a9234 FUN_600a9234
//   6006dbac FUN_6006dbac


undefined4 FUN_600b3240(char param_1,char param_2,int param_3,byte param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int local_20;
  byte local_1b;
  undefined1 *local_14;
  
  iVar1 = FUN_6006dbac(param_4 + 0xd,DAT_600b33a0,0x490);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 5;
    *(undefined1 *)(iVar1 + 9) = 0xc;
    if (param_1 == '\0') {
      *(undefined2 *)(iVar1 + 2) = 4;
      *(char *)(iVar1 + 10) = '\x01';
      *(undefined1 *)(iVar1 + 0xb) = 0;
    }
    else {
      *(ushort *)(iVar1 + 2) = param_4 + 5;
      *(char *)(iVar1 + 10) = param_4 + 2;
      *(char *)(iVar1 + 0xb) = param_1;
      local_14 = (undefined1 *)(iVar1 + 0xd);
      *(char *)(iVar1 + 0xc) = param_2;
      if (param_2 == '\x01') {
        for (iVar3 = 0; iVar3 < 3; iVar3 = iVar3 + 1) {
          *local_14 = *(undefined1 *)((2 - iVar3) + param_3);
          local_14 = local_14 + 1;
        }
        for (iVar3 = 0; iVar3 < 3; iVar3 = iVar3 + 1) {
          *local_14 = *(undefined1 *)((param_3 + 5) - iVar3);
          local_14 = local_14 + 1;
        }
        local_20 = param_3 + 6;
        local_1b = param_4 - 6;
      }
      else {
        local_20 = param_3;
        local_1b = param_4;
        if (param_2 == '\x02') {
          for (iVar3 = 0; iVar3 < 6; iVar3 = iVar3 + 1) {
            *local_14 = *(undefined1 *)((5 - iVar3) + param_3);
            local_14 = local_14 + 1;
          }
          local_20 = param_3 + 6;
          local_1b = param_4 - 6;
        }
      }
      if (local_1b != 0) {
        for (iVar3 = 0; iVar3 < (int)(uint)local_1b; iVar3 = iVar3 + 1) {
          *local_14 = *(undefined1 *)(iVar3 + local_20);
          local_14 = local_14 + 1;
        }
      }
    }
    FUN_600a9234(0,iVar1);
    uVar2 = 1;
  }
  return uVar2;
}


