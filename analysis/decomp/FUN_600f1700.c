// 600f1700  FUN_600f1700  size=42 bytes
// --- callers ---
//   600c5908 FUN_600c5908
//   600c54ec FUN_600c54ec
//   600c2c04 FUN_600c2c04
// --- callees ---
//   6009ff18 FUN_6009ff18


int FUN_600f1700(undefined4 param_1)

{
  int iVar1;
  undefined4 local_c;
  
  local_c = 0;
  iVar1 = FUN_6009ff18(param_1);
  if (iVar1 != 0) {
    local_c = iVar1 + 0x2c;
  }
  return local_c;
}


