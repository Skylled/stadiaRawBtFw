// 600c70ec  FUN_600c70ec  size=58 bytes
// --- callers ---
//   600ff888 FUN_600ff888
//   600f2532 FUN_600f2532
// --- callees ---


void FUN_600c70ec(undefined1 *param_1,undefined1 param_2)

{
  undefined1 local_c [4];
  
  local_c[0] = *param_1;
  if (*(int *)(DAT_600c7128 + 0x7fc) != 0) {
    (**(code **)(DAT_600c7128 + 0x7fc))(1,param_2,local_c);
  }
  return;
}


