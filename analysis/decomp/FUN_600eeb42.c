// 600eeb42  FUN_600eeb42  size=150 bytes
// --- callers ---
//   60094ba4 FUN_60094ba4
//   600ee9c6 FUN_600ee9c6
// --- callees ---
//   600ee9c6 FUN_600ee9c6
//   600ee9f6 FUN_600ee9f6
//   600ee678 FUN_600ee678


void FUN_600eeb42(undefined2 param_1,int param_2)

{
  int iVar1;
  
  *(char *)(param_2 + 0x30) = *(char *)(param_2 + 0x30) + -1;
  if (*(char *)(param_2 + 0x30) == '\0') {
    *(char *)(param_2 + 0x2c) = *(char *)(param_2 + 0x2c) + '\x01';
    FUN_600ee9f6(param_1,param_2);
  }
  else {
    *(char *)(param_2 + 0x2d) = *(char *)(param_2 + 0x2d) + '\x01';
    iVar1 = (uint)*(byte *)(param_2 + 0x2d) * 0x1c + *(int *)(param_2 + 0x28);
    FUN_600ee678(param_2,*(undefined2 *)(iVar1 + 0x14),iVar1,*(undefined1 *)(iVar1 + 0x1a),1);
    FUN_600ee9c6(param_1,param_2);
  }
  return;
}


