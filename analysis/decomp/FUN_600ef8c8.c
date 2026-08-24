// 600ef8c8  FUN_600ef8c8  size=56 bytes
// --- callers ---
//   600ef974 FUN_600ef974
// --- callees ---
//   60095588 FUN_60095588
//   6013cf90 thunk_EXT_FUN_0000b5ba


bool FUN_600ef8c8(undefined4 param_1)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)FUN_60095588(param_1);
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 0;
    thunk_EXT_FUN_0000b5ba(puVar1 + 1,0,6);
  }
  return puVar1 != (undefined1 *)0x0;
}


