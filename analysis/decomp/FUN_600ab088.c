// 600ab088  FUN_600ab088  size=72 bytes
// --- callers ---
//   600c6a3c FUN_600c6a3c
// --- callees ---
//   600f67b2 FUN_600f67b2
//   600af390 FUN_600af390


undefined1 FUN_600ab088(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 local_11;
  
  local_11 = 0;
  iVar1 = FUN_600af390();
  if (iVar1 != 0) {
    uVar2 = param_1[1];
    uVar3 = param_1[2];
    uVar4 = param_1[3];
    *(undefined4 *)(iVar1 + 8) = *param_1;
    *(undefined4 *)(iVar1 + 0xc) = uVar2;
    *(undefined4 *)(iVar1 + 0x10) = uVar3;
    *(undefined4 *)(iVar1 + 0x14) = uVar4;
    uVar2 = param_1[5];
    uVar3 = param_1[6];
    uVar4 = param_1[7];
    *(undefined4 *)(iVar1 + 0x18) = param_1[4];
    *(undefined4 *)(iVar1 + 0x1c) = uVar2;
    *(undefined4 *)(iVar1 + 0x20) = uVar3;
    *(undefined4 *)(iVar1 + 0x24) = uVar4;
    uVar2 = param_1[9];
    uVar3 = param_1[10];
    uVar4 = param_1[0xb];
    *(undefined4 *)(iVar1 + 0x28) = param_1[8];
    *(undefined4 *)(iVar1 + 0x2c) = uVar2;
    *(undefined4 *)(iVar1 + 0x30) = uVar3;
    *(undefined4 *)(iVar1 + 0x34) = uVar4;
    local_11 = FUN_600f67b2(DAT_600ab0d0,iVar1);
  }
  return local_11;
}


