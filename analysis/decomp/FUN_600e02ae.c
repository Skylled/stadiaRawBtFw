// 600e02ae  FUN_600e02ae  size=34 bytes
// --- callers ---
//   600679d4 gotham__600679d4
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600e092c FUN_600e092c


undefined4 * FUN_600e02ae(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_600e092c(0x28);
  if (puVar1 != (undefined4 *)0x0) {
    thunk_EXT_FUN_0000b5ba(puVar1 + 2,0,0x20);
    *puVar1 = param_1;
    puVar1[1] = param_2;
  }
  return puVar1;
}


