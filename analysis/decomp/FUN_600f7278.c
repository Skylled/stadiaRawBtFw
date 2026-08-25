// 600f7278  FUN_600f7278  size=62 bytes
// --- callers ---
//   600f3caa FUN_600f3caa
// --- callees ---
//   600f5a98 FUN_600f5a98
//   600af814 FUN_600af814
//   600f74a8 FUN_600f74a8


undefined4 FUN_600f7278(undefined1 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_600af814(param_2,2);
  if (iVar1 != 0) {
    FUN_600f5a98(param_1,iVar1,0,0);
  }
  uVar2 = FUN_600f74a8(param_1,0,param_2,1);
  return uVar2;
}


