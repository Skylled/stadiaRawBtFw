// 60095588  FUN_60095588  size=80 bytes
// --- callers ---
//   600ef8c8 FUN_600ef8c8
//   600ef8a0 FUN_600ef8a0
// --- callees ---
//   600efcfe FUN_600efcfe


char * FUN_60095588(undefined4 param_1)

{
  int iVar1;
  char *local_10;
  byte local_9;
  
  local_10 = DAT_600955d8;
  local_9 = 0;
  while( true ) {
    if (9 < local_9) {
      return (char *)0x0;
    }
    if ((*local_10 != '\0') && (iVar1 = FUN_600efcfe(param_1,local_10 + 1), iVar1 == 0)) break;
    local_9 = local_9 + 1;
    local_10 = local_10 + 7;
  }
  return local_10;
}


