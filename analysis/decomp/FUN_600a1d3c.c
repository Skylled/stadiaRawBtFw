// 600a1d3c  FUN_600a1d3c  size=342 bytes
// --- callers ---
//   600a14e4 FUN_600a14e4
//   600c290c FUN_600c290c
//   600c2810 FUN_600c2810
// --- callees ---
//   600b35cc FUN_600b35cc
//   600b3640 FUN_600b3640
//   6009dc14 FUN_6009dc14


undefined4 FUN_600a1d3c(ushort param_1,ushort param_2,ushort param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  ushort local_16;
  ushort local_14;
  byte local_9;
  
  iVar1 = DAT_600a1e94;
  local_9 = 0;
  if ((*(byte *)(DAT_600a1e98 + 0x81b) & 2) != 0) {
    iVar2 = FUN_6009dc14(param_1);
    if (iVar2 != 0) {
      return 3;
    }
    *(ushort *)(iVar1 + 0x1e) = *(ushort *)(iVar1 + 0x1e) & 0xfeff;
    *(ushort *)(iVar1 + 0x1e) = param_1 & 0x100 | *(ushort *)(iVar1 + 0x1e);
  }
  param_1 = param_1 & 0xfeff;
  if ((param_1 == 0) || (param_1 == 1)) {
    if (*(byte *)(DAT_600a1e98 + 0x881) < 2) {
      uVar3 = 0xc;
    }
    else {
      local_14 = param_2;
      if (param_2 == 0) {
        local_14 = 0x12;
      }
      local_16 = param_3;
      if (param_3 == 0) {
        local_16 = 0x800;
      }
      if (param_1 == 1) {
        if ((((local_14 < 0x11) || (0x1000 < local_14)) || (local_16 < 0x12)) ||
           ((0x1000 < local_16 || (local_16 < local_14)))) {
          return 5;
        }
        local_9 = 2;
      }
      if ((local_14 != *(ushort *)(iVar1 + 0x20)) || (local_16 != *(ushort *)(iVar1 + 0x22))) {
        *(ushort *)(iVar1 + 0x20) = local_14;
        *(ushort *)(iVar1 + 0x22) = local_16;
        iVar2 = FUN_600b3640(local_16,local_14);
        if (iVar2 == 0) {
          return 3;
        }
      }
      if ((*(ushort *)(iVar1 + 0x1c) & 3) != 0) {
        local_9 = local_9 | 1;
      }
      iVar2 = FUN_600b35cc(local_9);
      if (iVar2 == 0) {
        uVar3 = 3;
      }
      else {
        *(ushort *)(iVar1 + 0x1e) = *(ushort *)(iVar1 + 0x1e) & 0xfffe;
        *(ushort *)(iVar1 + 0x1e) = param_1 | *(ushort *)(iVar1 + 0x1e);
        uVar3 = 0;
      }
    }
  }
  else {
    uVar3 = 5;
  }
  return uVar3;
}


