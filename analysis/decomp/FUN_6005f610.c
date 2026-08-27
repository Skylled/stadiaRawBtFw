// 6005f610  FUN_6005f610  size=60 bytes
// --- callers ---
//   600cbdc8 xbara__600cbdc8
// --- callees ---
//   600d478e FUN_600d478e
//   6005f534 FUN_6005f534
//   60052d64 FUN_60052d64


uint FUN_6005f610(undefined4 *param_1)

{
  uint uVar1;
  
  if (*(char *)(param_1 + 0xf) == '\0') {
    FUN_6005f534(param_1 + 1);
    FUN_60052d64(param_1 + 5,DAT_6005f64c,param_1[0xe]);
    uVar1 = FUN_600d478e(*param_1,param_1[0xd],param_1[0xe]);
    if ((uVar1 & 0xff) == 0) {
      *(undefined1 *)(param_1 + 0xf) = 1;
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


