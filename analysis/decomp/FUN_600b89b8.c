// 600b89b8  FUN_600b89b8  size=486 bytes
// --- callers ---
//   600a9308 FUN_600a9308
//   600a96d8 FUN_600a96d8
// --- callees ---
//   600aa340 FUN_600aa340
//   600f0406 FUN_600f0406
//   600b8ba4 FUN_600b8ba4
//   600b5e00 FUN_600b5e00
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6009ff18 FUN_6009ff18
//   60098f88 FUN_60098f88
//   600f9a70 FUN_600f9a70
//   600f9ae6 FUN_600f9ae6
//   600aa3cc FUN_600aa3cc
//   600bc480 FUN_600bc480
//   600f9d16 FUN_600f9d16
//   600bb534 FUN_600bb534
//   600bb15c FUN_600bb15c
//   600bc760 FUN_600bc760
//   600bb6dc FUN_600bb6dc


undefined4 FUN_600b89b8(byte param_1,undefined2 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_30 [6];
  byte local_2a;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  local_18 = 0;
  local_2a = param_1;
  thunk_EXT_FUN_0000b572(auStack_30,param_3,6);
  local_1c = FUN_600bb6dc(auStack_30,1);
  if (local_1c == 0) {
    uVar2 = 0;
  }
  else if (*(char *)(local_1c + 1) == '\x03') {
    *(undefined2 *)(local_1c + 2) = param_2;
    if (local_2a == 0) {
      *(undefined1 *)(local_1c + 1) = 4;
      FUN_600f9ae6(local_1c,2);
      local_18 = FUN_6009ff18(param_3);
      if (local_18 == 0) {
        FUN_60098f88(auStack_30,0,0,param_2,*(undefined1 *)(local_1c + 10),1);
      }
      else {
        FUN_60098f88(auStack_30,local_18 + 0x16,local_18 + 0x2c,param_2,
                     *(undefined1 *)(local_1c + 10),1);
      }
      FUN_600f0406(auStack_30,*(undefined2 *)(DAT_600b8ba0 + 0x642));
      if ((*(char *)(local_1c + 0x16) != '\0') && (iVar1 = FUN_600f9d16(param_2), iVar1 != 0)) {
        return 1;
      }
      FUN_600bb15c(0);
      FUN_600aa3cc(local_1c + 0x44);
      for (local_14 = *(int *)(local_1c + 0x5c); local_14 != 0;
          local_14 = *(int *)(local_14 + 0x124)) {
        FUN_600b5e00(local_14,0,auStack_30);
      }
      if (*(int *)(local_1c + 0x10) == 0) {
        if (*(int *)(local_1c + 0x5c) == 0) {
          FUN_600aa340(local_1c + 0x44,2,0x3c);
        }
      }
      else {
        FUN_600f9a70(local_1c,0,0);
        FUN_600aa340(local_1c + 0x44,2,0x1e);
      }
    }
    else if ((local_2a == 9) && (iVar1 = FUN_600bc760(), iVar1 != 0)) {
      *(undefined1 *)(local_1c + 1) = 1;
      *(undefined2 *)(local_1c + 2) = 0xffff;
    }
    else {
      *(undefined1 *)(local_1c + 1) = 5;
      local_14 = *(int *)(local_1c + 0x5c);
      while (local_14 != 0) {
        local_20 = *(int *)(local_14 + 0x124);
        FUN_600b5e00(local_14,1,auStack_30);
        local_14 = local_20;
      }
      *(ushort *)(local_1c + 0x30) = (ushort)param_1;
      if (*(int *)(local_1c + 0x5c) == 0) {
        FUN_600bb534(local_1c);
      }
      else if (local_2a == 0xb) {
        *(undefined1 *)(local_1c + 1) = 3;
      }
      else {
        FUN_600bc480(local_1c,1);
      }
    }
    uVar2 = 1;
  }
  else {
    if (param_1 != 0) {
      FUN_600b8ba4(*(undefined2 *)(local_1c + 2),param_1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


