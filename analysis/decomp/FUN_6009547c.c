// 6009547c  FUN_6009547c  size=176 bytes
// --- callers ---
//   600ef900 FUN_600ef900
// --- callees ---
//   600efcfe FUN_600efcfe


char FUN_6009547c(byte param_1,undefined4 param_2,char param_3)

{
  int iVar1;
  char local_e;
  byte local_d;
  char *local_c;
  
  local_c = DAT_6009552c;
  local_e = '\0';
  local_d = 0;
  while ((local_d < 2 && (local_e == '\0'))) {
    if ((*local_c != '\0') &&
       ((iVar1 = FUN_600efcfe(local_c + 1,param_2), iVar1 == 0 ||
        (iVar1 = FUN_600efcfe(local_c + 1,DAT_60095530), iVar1 == 0)))) {
      if ((((int)(uint)*(ushort *)(local_c + 8) >> (param_1 - 1 & 0xff) & 1U) != 0) &&
         (param_3 == '\0')) {
        local_e = '\x01';
      }
      if ((((int)(uint)*(ushort *)(local_c + 10) >> (param_1 - 1 & 0xff) & 1U) != 0) &&
         (param_3 == '\x01')) {
        local_e = '\x01';
      }
    }
    local_d = local_d + 1;
    local_c = local_c + 0xc;
  }
  return local_e;
}


