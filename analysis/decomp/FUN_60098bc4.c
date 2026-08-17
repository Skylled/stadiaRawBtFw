// 60098bc4  FUN_60098bc4  size=32 bytes
// --- callers ---
// --- callees ---
//   60098be8 FUN_60098be8


bool FUN_60098bc4(void)

{
  char cVar1;
  
  cVar1 = *DAT_60098be4;
  if (cVar1 == '\x04') {
    *DAT_60098be4 = '\x05';
    FUN_60098be8();
  }
  return cVar1 == '\x04';
}


