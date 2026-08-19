// 600db002  FUN_600db002  size=18 bytes
// --- callers ---
//   6010112c FUN_6010112c
//   60100ffc FUN_60100ffc
//   600cb460 key_value_store__600cb460
//   600cb598 key_value_store__600cb598
//   601010c8 FUN_601010c8
//   60100ed8 FUN_60100ed8
//   60100c48 FUN_60100c48
//   60101198 FUN_60101198
// --- callees ---


int FUN_600db002(int param_1,int param_2)

{
  int iVar1;
  
  for (iVar1 = 0; (iVar1 != param_2 && (*(char *)(param_1 + iVar1) != '\0')); iVar1 = iVar1 + 1) {
  }
  return iVar1;
}


