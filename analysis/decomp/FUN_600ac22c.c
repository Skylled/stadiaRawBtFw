// 600ac22c  FUN_600ac22c  size=114 bytes
// --- callers ---
//   600f0c84 FUN_600f0c84
// --- callees ---
//   600d9250 FUN_600d9250
//   600af814 FUN_600af814
//   600f42d8 FUN_600f42d8
//   600f42fc FUN_600f42fc
//   600ac438 FUN_600ac438
//   6006ddd8 FUN_6006ddd8


void FUN_600ac22c(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  short local_a;
  
  iVar1 = FUN_600af814(param_1,2);
  if ((iVar1 != 0) && (iVar2 = FUN_600f42fc(iVar1), iVar2 == 6)) {
    FUN_600f42d8(iVar1,0);
    local_a = *(short *)(iVar1 + 8);
    while ((local_a != 0 &&
           (puVar3 = (undefined4 *)FUN_600d9250(iVar1), puVar3 != (undefined4 *)0x0))) {
      FUN_600ac438(*puVar3);
      FUN_6006ddd8(puVar3,DAT_600ac2a0,0xef);
      local_a = local_a + -1;
    }
  }
  return;
}


