// 600dfe6e  FUN_600dfe6e  size=48 bytes
// --- callers ---
//   60083678 FUN_60083678
//   600836a0 FUN_600836a0
// --- callees ---
//   60101a80 FUN_60101a80
//   600cc450 FUN_600cc450
//   6010138c FUN_6010138c
//   60101a54 FUN_60101a54


uint FUN_600dfe6e(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = FUN_60101a80(*(undefined4 *)(param_1 + 0x14));
  FUN_600cc450(uVar1,param_2,param_3);
  uVar2 = FUN_6010138c(param_1,*(undefined4 *)(param_1 + 0x14));
  if ((uVar2 & 0xff) == 0) {
    FUN_60101a54(*(undefined4 *)(param_1 + 0x14));
  }
  return uVar2;
}


