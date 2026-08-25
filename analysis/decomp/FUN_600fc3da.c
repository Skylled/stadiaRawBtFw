// 600fc3da  FUN_600fc3da  size=94 bytes
// --- callers ---
//   600fc380 FUN_600fc380
// --- callees ---
//   600c1a34 FUN_600c1a34


void FUN_600fc3da(int param_1,int param_2)

{
  undefined1 local_18 [4];
  int local_14;
  ushort local_e;
  int local_c;
  
  local_e = (ushort)*(byte *)(param_2 + 5) * 0x100 + (ushort)*(byte *)(param_2 + 4);
  local_c = param_2 + 6;
  *(ushort *)(param_1 + 0x1e8) = local_e ^ *(ushort *)(param_1 + 0x1d6);
  local_18[0] = 5;
  local_14 = param_2 + 4;
  FUN_600c1a34(param_1,0x10,local_18);
  return;
}


