// 600c0434  FUN_600c0434  size=132 bytes
// --- callers ---
//   6009af60 FUN_6009af60
// --- callees ---
//   600efcfe FUN_600efcfe
//   600c1a34 FUN_600c1a34
//   6009ff18 FUN_6009ff18


undefined4 FUN_600c0434(undefined4 param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  bVar1 = false;
  iVar2 = FUN_600efcfe(param_1,DAT_600c04b8);
  if (iVar2 == 0) {
    bVar1 = true;
  }
  else {
    iVar2 = FUN_6009ff18(param_1);
    if (((iVar2 != 0) && (iVar3 = FUN_600efcfe(iVar2 + 100,DAT_600c04b8), iVar3 == 0)) &&
       (iVar2 = FUN_600efcfe(iVar2 + 100,DAT_600c04bc), iVar2 != 0)) {
      bVar1 = true;
    }
  }
  if ((*(char *)(DAT_600c04c0 + 0x23) == '\x0e') && (bVar1)) {
    FUN_600c1a34(DAT_600c04c0,0x18,0);
    uVar4 = 1;
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}


