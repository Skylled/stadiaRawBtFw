// 600fc260  FUN_600fc260  size=60 bytes
// --- callers ---
//   600fc17a FUN_600fc17a
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600c1a34 FUN_600c1a34


void FUN_600fc260(int param_1,int param_2)

{
  undefined1 local_10 [4];
  int local_c;
  
  thunk_EXT_FUN_0000b572(param_1 + 0x2d,param_2 + 4,0x10);
  local_10[0] = 1;
  local_c = param_2 + 4;
  FUN_600c1a34(param_1,0x10,local_10);
  return;
}


