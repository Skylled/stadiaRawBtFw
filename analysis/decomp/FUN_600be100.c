// 600be100  FUN_600be100  size=76 bytes
// --- callers ---
// --- callees ---
//   600fa5c6 FUN_600fa5c6
//   600bf2d8 FUN_600bf2d8
//   6006ddd8 FUN_6006ddd8


void FUN_600be100(undefined2 param_1,undefined4 param_2)

{
  char *pcVar1;
  
  pcVar1 = (char *)FUN_600bf2d8(param_1);
  if (((pcVar1 != (char *)0x0) && (*pcVar1 == '\x03')) && ((pcVar1[1] & 1U) == 0)) {
    FUN_600fa5c6(pcVar1,param_2);
  }
  FUN_6006ddd8(param_2,DAT_600be14c,0x1fc);
  return;
}


