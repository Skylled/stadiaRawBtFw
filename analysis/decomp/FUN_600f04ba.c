// 600f04ba  FUN_600f04ba  size=42 bytes
// --- callers ---
//   600c4da8 FUN_600c4da8
// --- callees ---
//   60098ec8 FUN_60098ec8


int FUN_600f04ba(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_60098ec8(param_1,1);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = iVar1 + 0x10e;
  }
  return iVar1;
}


