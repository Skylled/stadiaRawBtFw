// 600f4ed6  FUN_600f4ed6  size=44 bytes
// --- callers ---
//   600ae0dc FUN_600ae0dc
//   600ab424 FUN_600ab424
//   600afbd0 FUN_600afbd0
// --- callees ---


undefined4 FUN_600f4ed6(int *param_1)

{
  undefined4 uVar1;
  
  if ((param_1 == (int *)0x0) || (*param_1 == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(*param_1 + 4);
  }
  return uVar1;
}


