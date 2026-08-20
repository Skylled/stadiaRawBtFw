// 600ec364  FUN_600ec364  size=36 bytes
// --- callers ---
//   6008df70 FUN_6008df70
//   600ec388 thunk_FUN_600ec364
// --- callees ---


undefined4 FUN_600ec364(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if ((param_1 != (undefined4 *)0x0) && (param_3 != (undefined4 *)0x0)) {
    param_3[0x3c] = 10;
    puVar1 = param_1;
    do {
      puVar2 = puVar1 + 1;
      *param_3 = *puVar1;
      puVar1 = puVar2;
      param_3 = param_3 + 1;
    } while (puVar2 != param_1 + 4);
    return 0;
  }
  return 0xffffffff;
}


