// 600f0048  FUN_600f0048  size=118 bytes
// --- callers ---
//   60098d8c FUN_60098d8c
// --- callees ---
//   600a1394 FUN_600a1394


undefined4 FUN_600f0048(short param_1)

{
  undefined4 uVar1;
  bool local_10 [4];
  bool *local_c;
  
  if (param_1 != 2) {
    local_10[1] = false;
  }
  else {
    local_10[1] = true;
  }
  local_10[2] = false;
  local_10[0] = param_1 == 2;
  local_c = local_10 + 3;
  uVar1 = FUN_600a1394(0xfc7e,3,local_10,0);
  return uVar1;
}


