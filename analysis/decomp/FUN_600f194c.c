// 600f194c  FUN_600f194c  size=74 bytes
// --- callers ---
//   600ac2a4 FUN_600ac2a4
//   600f4322 FUN_600f4322
//   600ac128 FUN_600ac128
//   600f6b4a FUN_600f6b4a
// --- callees ---
//   6009ff18 FUN_6009ff18


undefined4 FUN_600f194c(undefined4 param_1,undefined1 *param_2,char param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_6009ff18(param_1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    if (param_3 == '\x01') {
      *param_2 = (char)*(undefined2 *)(iVar1 + 0x2a);
    }
    else {
      *param_2 = (char)((ushort)*(undefined2 *)(iVar1 + 0x2a) >> 8);
    }
    uVar2 = 1;
  }
  return uVar2;
}


