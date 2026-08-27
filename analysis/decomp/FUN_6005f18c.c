// 6005f18c  FUN_6005f18c  size=46 bytes
// --- callers ---
//   6006044c reset__6006044c
// --- callees ---


void FUN_6005f18c(uint param_1,uint param_2,uint param_3)

{
  uint local_c;
  uint uStack_8;
  
  local_c = (param_2 & 0xf) << 0x14 | param_3 & 0xf | 0xeb000000 | (param_1 & 0xf) << 0x10;
  uStack_8 = param_3;
  (**(code **)(*DAT_6005f1bc + 8))(&local_c);
  return;
}


