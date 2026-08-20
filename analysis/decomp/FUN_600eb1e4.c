// 600eb1e4  FUN_600eb1e4  size=156 bytes
// --- callers ---
// --- callees ---
//   600e57ee FUN_600e57ee
//   600e2316 FUN_600e2316
//   600e643a FUN_600e643a
//   600e7588 FUN_600e7588
//   600eb1d4 FUN_600eb1d4
//   6013d168 thunk_EXT_FUN_0000b554
//   600e7a32 FUN_600e7a32


bool FUN_600eb1e4(int param_1,int param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  undefined1 auStack_b4 [32];
  undefined1 auStack_94 [32];
  undefined1 auStack_74 [32];
  undefined1 auStack_54 [68];
  
  iVar2 = FUN_600eb1d4();
  if (iVar2 == 0) {
    FUN_600e643a(auStack_b4,param_2 + 0x88);
    FUN_600e2316(auStack_b4,auStack_b4);
    FUN_600e643a(auStack_94,param_3);
    FUN_600e2316(auStack_94,auStack_94,auStack_b4);
    FUN_600e643a(auStack_74,param_2);
    FUN_600e57ee(auStack_74);
    iVar2 = thunk_EXT_FUN_0000b554(auStack_94,auStack_74,0x20);
    if (iVar2 == 0) {
      bVar1 = true;
    }
    else {
      iVar2 = FUN_600e7588(param_3,param_1 + 200,*(undefined4 *)(param_1 + 0x28));
      bVar1 = false;
      if (iVar2 != 0) {
        FUN_600e7a32(auStack_54,param_3,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc))
        ;
        FUN_600e643a(auStack_94,auStack_54);
        FUN_600e2316(auStack_94,auStack_94,auStack_b4);
        iVar2 = thunk_EXT_FUN_0000b554(auStack_94,auStack_74,0x20);
        bVar1 = iVar2 == 0;
      }
    }
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}


