// 600ecb72  FUN_600ecb72  size=34 bytes
// --- callers ---
//   600ecbca FUN_600ecbca
//   600ecbd8 FUN_600ecbd8
// --- callees ---


int FUN_600ecb72(int *param_1,char *param_2)

{
  int iVar1;
  
  if ((((*param_2 == '\x01') || (*param_2 == '\x06')) &&
      (iVar1 = *(int *)(param_2 + 0x10), iVar1 != 0)) && ((*(uint *)(iVar1 + 4) & 1) != 0)) {
    return *(int *)(iVar1 + 8) + *param_1;
  }
  return 0;
}


