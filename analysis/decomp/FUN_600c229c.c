// 600c229c  FUN_600c229c  size=98 bytes
// --- callers ---
//   600c0698 FUN_600c0698
// --- callees ---
//   600c1a34 FUN_600c1a34


void FUN_600c229c(undefined1 *param_1,undefined4 param_2)

{
  undefined1 local_14 [4];
  undefined1 *local_10;
  undefined1 *local_c;
  
  *param_1 = (char)param_2;
  param_1[1] = (char)((uint)param_2 >> 8);
  param_1[2] = (char)((uint)param_2 >> 0x10);
  local_c = param_1 + 4;
  param_1[3] = (char)((uint)param_2 >> 0x18);
  local_14[0] = 0;
  local_10 = param_1;
  FUN_600c1a34(DAT_600c2300,0x10,local_14);
  return;
}


