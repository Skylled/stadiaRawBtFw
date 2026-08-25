// 600f3540  FUN_600f3540  size=110 bytes
// --- callers ---
//   600c6cb0 FUN_600c6cb0
// --- callees ---
//   600f52ee FUN_600f52ee
//   600af3f4 FUN_600af3f4


undefined4 FUN_600f3540(undefined2 param_1,undefined2 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_600af3f4(param_1);
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  else {
    iVar2 = FUN_600af3f4(param_2);
    if (iVar2 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_600f52ee(iVar1 + 0x38,*(undefined2 *)(iVar2 + 0x32),*(undefined2 *)(iVar2 + 0x34),
                           *(undefined4 *)(iVar2 + 0x1c),*(undefined4 *)(iVar2 + 0x20),
                           *(undefined4 *)(iVar2 + 0x24),*(undefined4 *)(iVar2 + 0x28),
                           *(undefined4 *)(iVar2 + 0x2c));
    }
  }
  return uVar3;
}


