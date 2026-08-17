// 600951ec  FUN_600951ec  size=68 bytes
// --- callers ---
//   600c66e8 FUN_600c66e8
// --- callees ---
//   600efcfe FUN_600efcfe


int FUN_600951ec(undefined4 param_1)

{
  int iVar1;
  byte local_d;
  int local_c;
  
  local_c = DAT_60095230;
  local_d = 0;
  while( true ) {
    if (1 < local_d) {
      return 0;
    }
    iVar1 = FUN_600efcfe(local_c + 1,param_1);
    if (iVar1 == 0) break;
    local_d = local_d + 1;
    local_c = local_c + 0x38;
  }
  return local_c;
}


