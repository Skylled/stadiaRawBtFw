// 600fb3fe  FUN_600fb3fe  size=60 bytes
// --- callers ---
// --- callees ---
//   600fb848 FUN_600fb848


void FUN_600fb3fe(int param_1,undefined1 *param_2)

{
  int iVar1;
  undefined1 *local_14;
  
  local_14 = param_2;
  for (iVar1 = 0; iVar1 < 0x10; iVar1 = iVar1 + 1) {
    *(undefined1 *)(param_1 + 0x1b6 + iVar1) = *local_14;
    local_14 = local_14 + 1;
  }
  FUN_600fb848(param_1,0);
  return;
}


