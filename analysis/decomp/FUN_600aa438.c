// 600aa438  FUN_600aa438  size=126 bytes
// --- callers ---
//   600b7db8 FUN_600b7db8
//   600b7800 FUN_600b7800
//   600b731c FUN_600b731c
// --- callees ---
//   6006e594 FUN_6006e594
//   6006e2d0 FUN_6006e2d0
//   6006e214 FUN_6006e214
//   6006de78 FUN_6006de78
//   6006e3b0 FUN_6006e3b0
//   6006dbac FUN_6006dbac


void FUN_600aa438(int param_1,undefined2 param_2,undefined4 param_3)

{
  int iVar1;
  undefined2 *puVar2;
  
  if (*(int *)(DAT_600aa4b8 + 0x40) == 0) {
    iVar1 = FUN_6006e594();
    if (iVar1 == 1) {
      FUN_6006e3b0(2,100,1);
    }
    else {
      puVar2 = (undefined2 *)FUN_6006dbac(8,DAT_600aa4bc,899);
      if (puVar2 != (undefined2 *)0x0) {
        *puVar2 = 0x3e00;
        FUN_6006de78(1,0,puVar2,DAT_600aa4bc,0x386);
      }
    }
  }
  FUN_6006e2d0(DAT_600aa4c0,param_1);
  *(undefined2 *)(param_1 + 0x14) = param_2;
  *(undefined4 *)(param_1 + 0xc) = param_3;
  FUN_6006e214(DAT_600aa4c0,param_1);
  return;
}


