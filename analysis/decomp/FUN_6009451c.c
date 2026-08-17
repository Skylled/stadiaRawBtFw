// 6009451c  FUN_6009451c  size=106 bytes
// --- callers ---
//   600c5c8c FUN_600c5c8c
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6006dbac FUN_6006dbac
//   600d9378 thunk_EXT_FUN_00007d64
//   6009625c FUN_6009625c
//   600d937c thunk_EXT_FUN_00007dac
//   600962b8 FUN_600962b8
//   600962dc FUN_600962dc


void FUN_6009451c(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined2 *puVar2;
  
  iVar1 = FUN_600962b8(0x1d);
  if (iVar1 == 0) {
    thunk_EXT_FUN_00007d64();
    FUN_6009625c(0x1d,DAT_60094588);
    thunk_EXT_FUN_00007dac();
  }
  puVar2 = (undefined2 *)FUN_6006dbac(0x20,DAT_6009458c,0x56);
  if (puVar2 != (undefined2 *)0x0) {
    *puVar2 = 0x1d17;
    if (param_1 != 0) {
      thunk_EXT_FUN_0000b572(puVar2 + 4,param_1,0x14);
    }
    *(undefined4 *)(puVar2 + 0xe) = param_2;
    FUN_600962dc(puVar2);
  }
  return;
}


