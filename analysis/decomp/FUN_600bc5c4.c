// 600bc5c4  FUN_600bc5c4  size=322 bytes
// --- callers ---
//   600b9358 FUN_600b9358
//   600bc480 FUN_600bc480
// --- callees ---
//   60099d18 FUN_60099d18
//   600b20a0 FUN_600b20a0
//   6009ff18 FUN_6009ff18
//   600bb534 FUN_600bb534
//   600aa340 FUN_600aa340
//   600bc574 FUN_600bc574
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600a21e4 FUN_600a21e4
//   600a1354 FUN_600a1354
//   60099f4c FUN_60099f4c


bool FUN_600bc5c4(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_30 [8];
  undefined2 *local_28;
  byte *local_24;
  char local_1d;
  int local_1c;
  ushort local_18;
  undefined2 local_16;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  
  local_11 = 1;
  local_18 = FUN_60099d18();
  local_1c = FUN_6009ff18(param_1 + 4);
  local_1d = FUN_600bc574();
  local_24 = (byte *)FUN_600a1354();
  if ((((*(char *)(DAT_600bc708 + 0xe9d) == '\0') && (local_18 < 3)) ||
      ((*(char *)(param_1 + 0x16) != '\0' && (local_1d == '\0')))) && ((*local_24 & 0x20) != 0)) {
    local_11 = 1;
  }
  else {
    local_11 = 0;
  }
  *(undefined1 *)(param_1 + 1) = 3;
  local_28 = (undefined2 *)FUN_600a21e4(param_1 + 4);
  if (local_28 == (undefined2 *)0x0) {
    local_12 = 1;
    local_13 = 0;
    if (local_1c == 0) {
      local_16 = 0;
    }
    else {
      local_16 = *(undefined2 *)(local_1c + 0xe);
    }
  }
  else {
    local_12 = *(undefined1 *)((int)local_28 + 0xb);
    local_13 = *(undefined1 *)((int)local_28 + 0xd);
    local_16 = *local_28;
  }
  if ((local_1c != 0) && (*(int *)(DAT_600bc70c + 0xd4) != 0)) {
    thunk_EXT_FUN_0000b572(auStack_30,param_1 + 4,6);
    iVar1 = (**(code **)(DAT_600bc70c + 0xd4))(9,auStack_30);
    if (iVar1 == 1) {
      return true;
    }
  }
  uVar2 = FUN_60099f4c(0xffff);
  iVar1 = FUN_600b20a0(param_1 + 4,uVar2,local_12,local_13,local_16,local_11);
  if (iVar1 != 0) {
    FUN_600aa340(param_1 + 0x44,2,0x3c);
  }
  else {
    FUN_600bb534(param_1);
  }
  return iVar1 != 0;
}


