// 600eb95c  FUN_600eb95c  size=198 bytes
// --- callers ---
//   600eba22 FUN_600eba22
// --- callees ---
//   6013cee8 thunk_EXT_FUN_0000af90
//   600898ec FUN_600898ec


undefined4 FUN_600eb95c(undefined1 *param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  uVar1 = param_2[0x16] + 1;
  puVar3 = param_2 + 6;
  *(undefined1 *)((int)param_2 + param_2[0x16] + 0x18) = 0x80;
  if (0x38 < uVar1) {
    thunk_EXT_FUN_0000af90(uVar1 + (int)puVar3,0,0x40 - uVar1);
    FUN_600898ec(param_2,puVar3,1);
    uVar1 = 0;
  }
  thunk_EXT_FUN_0000af90(uVar1 + (int)puVar3,0,0x38 - uVar1);
  uVar2 = param_2[4];
  *(char *)(param_2 + 0x14) = (char)uVar2;
  *(char *)((int)param_2 + 0x51) = (char)((uint)uVar2 >> 8);
  *(char *)((int)param_2 + 0x52) = (char)((uint)uVar2 >> 0x10);
  *(char *)((int)param_2 + 0x53) = (char)((uint)uVar2 >> 0x18);
  uVar2 = param_2[5];
  *(char *)(param_2 + 0x15) = (char)uVar2;
  *(char *)((int)param_2 + 0x55) = (char)((uint)uVar2 >> 8);
  *(char *)((int)param_2 + 0x56) = (char)((uint)uVar2 >> 0x10);
  *(char *)((int)param_2 + 0x57) = (char)((uint)uVar2 >> 0x18);
  FUN_600898ec(param_2,puVar3,1);
  param_2[0x16] = 0;
  thunk_EXT_FUN_0000af90(puVar3,0,0x40);
  uVar2 = *param_2;
  *param_1 = (char)uVar2;
  param_1[1] = (char)((uint)uVar2 >> 8);
  param_1[2] = (char)((uint)uVar2 >> 0x10);
  param_1[3] = (char)((uint)uVar2 >> 0x18);
  uVar2 = param_2[1];
  param_1[4] = (char)uVar2;
  param_1[5] = (char)((uint)uVar2 >> 8);
  param_1[6] = (char)((uint)uVar2 >> 0x10);
  param_1[7] = (char)((uint)uVar2 >> 0x18);
  uVar2 = param_2[2];
  param_1[8] = (char)uVar2;
  param_1[9] = (char)((uint)uVar2 >> 8);
  param_1[10] = (char)((uint)uVar2 >> 0x10);
  param_1[0xb] = (char)((uint)uVar2 >> 0x18);
  uVar2 = param_2[3];
  param_1[0xc] = (char)uVar2;
  param_1[0xd] = (char)((uint)uVar2 >> 8);
  param_1[0xe] = (char)((uint)uVar2 >> 0x10);
  param_1[0xf] = (char)((uint)uVar2 >> 0x18);
  return 1;
}


