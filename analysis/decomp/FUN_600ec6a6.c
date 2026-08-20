// 600ec6a6  FUN_600ec6a6  size=20 bytes
// --- callers ---
//   60090568 FUN_60090568
//   600ec8b4 FUN_600ec8b4
//   600902e4 FUN_600902e4
// --- callees ---


undefined4 FUN_600ec6a6(undefined4 *param_1)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)*param_1;
  *puVar1 = 0;
  puVar1[1] = 0;
  *param_1 = puVar1 + 2;
  return 2;
}


