// 600caa98  FUN_600caa98  size=20 bytes
// --- callers ---
// --- callees ---


undefined4 FUN_600caa98(void)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(*DAT_600caaac + 0x18);
  *(int *)(*DAT_600caaac + 0x18) = 0x20 - *(int *)(*DAT_600caaac + 0x2c);
  return uVar1;
}


