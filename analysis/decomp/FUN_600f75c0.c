// 600f75c0  FUN_600f75c0  size=202 bytes
// --- callers ---
//   600bdd9c FUN_600bdd9c
//   600ad610 FUN_600ad610
// --- callees ---
//   600bc1a8 FUN_600bc1a8
//   600bc158 FUN_600bc158


ushort FUN_600f75c0(ushort param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  ushort local_16;
  int local_14;
  
  if ((((param_2[4] == 0) || (param_2[3] == 0)) || (param_2[8] == 0)) || (param_2[5] == 0)) {
    local_16 = 0;
  }
  else if ((param_1 & 0x101) == 1) {
    local_16 = param_1;
    if ((0x1000 < param_1) && (*param_2 == 0)) {
      local_16 = 0x1002;
      while ((-1 < (short)local_16 && (iVar1 = FUN_600bc1a8(local_16), iVar1 != 0))) {
        local_16 = local_16 + 2;
      }
    }
    local_14 = FUN_600bc1a8(local_16);
    if ((local_14 == 0) && (local_14 = FUN_600bc158(local_16), local_14 == 0)) {
      local_16 = 0;
    }
    else {
      iVar1 = param_2[1];
      iVar2 = param_2[2];
      iVar3 = param_2[3];
      *(int *)(local_14 + 8) = *param_2;
      *(int *)(local_14 + 0xc) = iVar1;
      *(int *)(local_14 + 0x10) = iVar2;
      *(int *)(local_14 + 0x14) = iVar3;
      iVar1 = param_2[5];
      iVar2 = param_2[6];
      iVar3 = param_2[7];
      *(int *)(local_14 + 0x18) = param_2[4];
      *(int *)(local_14 + 0x1c) = iVar1;
      *(int *)(local_14 + 0x20) = iVar2;
      *(int *)(local_14 + 0x24) = iVar3;
      iVar1 = param_2[9];
      iVar2 = param_2[10];
      *(int *)(local_14 + 0x28) = param_2[8];
      *(int *)(local_14 + 0x2c) = iVar1;
      *(int *)(local_14 + 0x30) = iVar2;
      *(ushort *)(local_14 + 4) = param_1;
    }
  }
  else {
    local_16 = 0;
  }
  return local_16;
}


