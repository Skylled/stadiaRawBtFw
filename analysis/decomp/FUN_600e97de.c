// 600e97de  FUN_600e97de  size=108 bytes
// --- callers ---
//   6008d03c FUN_6008d03c
// --- callees ---
//   600e7450 FUN_600e7450
//   600e9760 FUN_600e9760
//   6013cee8 thunk_EXT_FUN_0000af90
//   600e7dc0 FUN_600e7dc0


void FUN_600e97de(int param_1,int param_2,undefined1 *param_3,uint param_4)

{
  uint uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  undefined1 auStack_64 [72];
  
  uVar1 = FUN_600e7450(param_1 + 8);
  uVar4 = uVar1 + 7 >> 3;
  if (param_4 <= uVar4) {
    uVar4 = param_4;
  }
  thunk_EXT_FUN_0000af90(param_2,0,0x44);
  puVar2 = (undefined1 *)(param_2 + -1);
  puVar3 = param_3 + uVar4;
  while (puVar3 != param_3) {
    puVar3 = puVar3 + -1;
    puVar2 = puVar2 + 1;
    *puVar2 = *puVar3;
  }
  if (uVar1 < uVar4 << 3) {
    FUN_600e9760(param_2,param_2,8 - (uVar1 & 7),*(undefined4 *)(param_1 + 0xc));
  }
  FUN_600e7dc0(param_2,0,*(undefined4 *)(param_1 + 8),auStack_64,*(undefined4 *)(param_1 + 0xc));
  return;
}


