// 600955dc  FUN_600955dc  size=106 bytes
// --- callers ---
//   600696d0 adapter__600696d0
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6006dbac FUN_6006dbac
//   600d9378 thunk_EXT_FUN_00007d64
//   6009625c FUN_6009625c
//   600d937c thunk_EXT_FUN_00007dac
//   600962b8 FUN_600962b8
//   600962dc FUN_600962dc


void FUN_600955dc(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined2 *puVar2;
  
  iVar1 = FUN_600962b8(0x1e);
  if (iVar1 == 0) {
    thunk_EXT_FUN_00007d64();
    FUN_6009625c(0x1e,DAT_60095648);
    thunk_EXT_FUN_00007dac();
  }
  puVar2 = (undefined2 *)FUN_6006dbac(0x20,DAT_6009564c,0x57);
  if (puVar2 != (undefined2 *)0x0) {
    *puVar2 = 0x1e00;
    if (param_1 != 0) {
      thunk_EXT_FUN_0000b572(puVar2 + 4,param_1,0x14);
    }
    *(undefined4 *)(puVar2 + 0xe) = param_2;
    FUN_600962dc(puVar2);
  }
  return;
}


