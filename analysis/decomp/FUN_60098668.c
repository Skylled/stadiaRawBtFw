// 60098668  FUN_60098668  size=50 bytes
// --- callers ---
//   600ee1be FUN_600ee1be
// --- callees ---
//   60098284 FUN_60098284


char FUN_60098668(undefined1 param_1)

{
  char cVar1;
  
  cVar1 = FUN_60098284(param_1,0x1000);
  if (cVar1 != '\x03') {
    *(undefined1 *)(DAT_6009869c + 0xa68) = param_1;
  }
  return cVar1;
}


