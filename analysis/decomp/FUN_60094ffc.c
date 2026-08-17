// 60094ffc  FUN_60094ffc  size=106 bytes
// --- callers ---
//   600fee40 FUN_600fee40
//   600ef390 FUN_600ef390
//   600c69dc FUN_600c69dc
//   600fd8c4 FUN_600fd8c4
//   600ef900 FUN_600ef900
//   600ef974 FUN_600ef974
// --- callees ---
//   600efcfe FUN_600efcfe


int FUN_60094ffc(char param_1,undefined4 param_2,char param_3)

{
  int iVar1;
  byte local_d;
  int local_c;
  
  local_c = DAT_60095068;
  local_d = 0;
  while( true ) {
    if (5 < local_d) {
      return 0;
    }
    if ((((*(char *)(local_c + 0x1b) != '\0') && (param_1 == *(char *)(*(int *)(local_c + 0xc) + 5))
         ) && (param_3 == *(char *)(local_c + 8))) &&
       (iVar1 = FUN_600efcfe(local_c + 2,param_2), iVar1 == 0)) break;
    local_d = local_d + 1;
    local_c = local_c + 0x20;
  }
  return local_c;
}


