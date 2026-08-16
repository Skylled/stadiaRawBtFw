// 600c3368  FUN_600c3368  size=116 bytes
// --- callers ---
// --- callees ---
//   600efcc6 FUN_600efcc6
//   600962dc FUN_600962dc
//   6006dbac FUN_6006dbac
//   600fa31c FUN_600fa31c


void FUN_600c3368(int param_1)

{
  int iVar1;
  undefined2 *puVar2;
  
  *DAT_600c33dc = *(undefined4 *)(param_1 + 0x18);
  FUN_600efcc6(DAT_600c33e0,param_1 + 8);
  *DAT_600c33e4 = *(undefined4 *)(param_1 + 0x10);
  iVar1 = FUN_600fa31c(DAT_600c33e0,*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),
                       DAT_600c33e8);
  if (iVar1 != 0) {
    puVar2 = (undefined2 *)FUN_6006dbac(0x140,DAT_600c33ec,0x5dd);
    if (puVar2 != (undefined2 *)0x0) {
      *puVar2 = 0x206;
      puVar2[3] = 0x208;
      *(undefined2 *)(param_1 + 4) = 1;
      FUN_600962dc(puVar2);
    }
  }
  return;
}


