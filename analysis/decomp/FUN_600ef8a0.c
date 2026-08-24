// 600ef8a0  FUN_600ef8a0  size=40 bytes
// --- callers ---
//   600ef900 FUN_600ef900
// --- callees ---
//   60095588 FUN_60095588
//   60095534 FUN_60095534


int FUN_600ef8a0(undefined4 param_1)

{
  undefined4 local_c;
  
  local_c = FUN_60095588(param_1);
  if (local_c == 0) {
    local_c = FUN_60095534(param_1);
  }
  return local_c;
}


