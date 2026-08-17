// 6009519c  FUN_6009519c  size=76 bytes
// --- callers ---
//   600feba8 FUN_600feba8
//   600950bc FUN_600950bc
// --- callees ---
//   600efcfe FUN_600efcfe


char * FUN_6009519c(undefined4 param_1)

{
  int iVar1;
  byte local_d;
  char *local_c;
  
  local_c = DAT_600951e8;
  local_d = 0;
  while( true ) {
    if (1 < local_d) {
      return (char *)0x0;
    }
    if ((*local_c != '\0') && (iVar1 = FUN_600efcfe(local_c + 1,param_1), iVar1 == 0)) break;
    local_d = local_d + 1;
    local_c = local_c + 0x38;
  }
  return local_c;
}


