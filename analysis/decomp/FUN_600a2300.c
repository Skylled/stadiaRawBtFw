// 600a2300  FUN_600a2300  size=52 bytes
// --- callers ---
//   600c2f68 FUN_600c2f68
// --- callees ---
//   600a2578 FUN_600a2578


undefined4 FUN_600a2300(undefined4 param_1)

{
  undefined4 uVar1;
  
  if ((*(char *)(DAT_600a2334 + 0x61e) == '\0') && (*(char *)(DAT_600a2334 + 0x61a) == '\0')) {
    FUN_600a2578(param_1);
    uVar1 = 0;
  }
  else {
    uVar1 = 2;
  }
  return uVar1;
}


