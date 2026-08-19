// 600db8b8  FUN_600db8b8  size=32 bytes
// --- callers ---
//   600db97e FUN_600db97e
//   600db902 FUN_600db902
// --- callees ---
//   600ca560 FUN_600ca560


int FUN_600db8b8(void)

{
  uint uVar1;
  
  uVar1 = FUN_600ca560();
  return ((uVar1 % 1000) * 1000 + 500) / 1000 + (uVar1 / 1000) * 1000;
}


