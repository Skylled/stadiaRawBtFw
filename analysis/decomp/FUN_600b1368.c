// 600b1368  FUN_600b1368  size=110 bytes
// --- callers ---
//   600c0de4 FUN_600c0de4
//   600c0f04 FUN_600c0f04
//   600c1578 FUN_600c1578
//   600c0c84 FUN_600c0c84
//   600c0f34 FUN_600c0f34
//   600c0db4 FUN_600c0db4
//   600c0ed4 FUN_600c0ed4
//   6009bb3c FUN_6009bb3c
//   600c0e14 FUN_600c0e14
//   6009b9b0 FUN_6009b9b0
//   600c0e7c FUN_600c0e7c
//   600c1548 FUN_600c1548
//   6009b960 FUN_6009b960
//   600f0f26 FUN_600f0f26
//   6009baec FUN_6009baec
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


bool FUN_600b1368(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0x17,DAT_600b13d8,0x267);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 2) = 3;
    *(undefined2 *)(iVar1 + 4) = 4;
    *(undefined4 *)(iVar1 + 8) = param_1;
    *(undefined1 *)(iVar1 + 0xc) = 0x18;
    *(undefined1 *)(iVar1 + 0xd) = 0x20;
    *(undefined1 *)(iVar1 + 0xe) = 0;
    FUN_600a9234(0,iVar1);
  }
  return iVar1 != 0;
}


