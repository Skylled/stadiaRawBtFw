// 600ef390  FUN_600ef390  size=60 bytes
// --- callers ---
//   600fdab8 FUN_600fdab8
//   600fd83a FUN_600fd83a
// --- callees ---
//   60094ffc FUN_60094ffc
//   600950bc FUN_600950bc


int FUN_600ef390(undefined1 param_1,undefined4 param_2,undefined1 param_3)

{
  undefined4 local_c;
  
  local_c = FUN_60094ffc(param_1,param_2,param_3);
  if (local_c == 0) {
    local_c = FUN_600950bc(param_1,param_2,param_3);
  }
  return local_c;
}


