// 60092de8  FUN_60092de8  size=98 bytes
// --- callers ---
//   6006c35c FUN_6006c35c
//   60095f9c FUN_60095f9c
// --- callees ---
//   6006dbac FUN_6006dbac
//   600d937c thunk_EXT_FUN_00007dac
//   600d9378 thunk_EXT_FUN_00007d64
//   6009625c FUN_6009625c
//   600962dc FUN_600962dc


undefined4 FUN_60092de8(undefined4 param_1)

{
  undefined2 *puVar1;
  undefined4 uVar2;
  
  if (*(char *)(DAT_60092e4c + 0x108) == '\0') {
    thunk_EXT_FUN_00007d64();
    FUN_6009625c(1,DAT_60092e50);
    FUN_6009625c(2,DAT_60092e54);
    thunk_EXT_FUN_00007dac();
    puVar1 = (undefined2 *)FUN_6006dbac(0xc,DAT_60092e58,0x4d);
    if (puVar1 == (undefined2 *)0x0) {
      uVar2 = 1;
    }
    else {
      *puVar1 = 0x100;
      *(undefined4 *)(puVar1 + 4) = param_1;
      FUN_600962dc(puVar1);
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


