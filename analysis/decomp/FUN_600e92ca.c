// 600e92ca  FUN_600e92ca  size=38 bytes
// --- callers ---
//   600e9b62 FUN_600e9b62
//   600e9af4 FUN_600e9af4
// --- callees ---
//   6013cee8 thunk_EXT_FUN_0000af90
//   600e721a FUN_600e721a
//   600e092c FUN_600e092c


int FUN_600e92ca(void)

{
  int iVar1;
  
  iVar1 = FUN_600e092c(0x30);
  if (iVar1 != 0) {
    thunk_EXT_FUN_0000af90(iVar1,0,0x30);
    FUN_600e721a(iVar1);
    FUN_600e721a(iVar1 + 0x14);
  }
  return iVar1;
}


