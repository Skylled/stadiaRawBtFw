// 600fbf8a  FUN_600fbf8a  size=192 bytes
// --- callers ---
//   600fc110 FUN_600fc110
// --- callees ---
//   600f05da FUN_600f05da
//   600fbf06 FUN_600fbf06
//   600f061a FUN_600f061a
//   600fbe82 FUN_600fbe82


void FUN_600fbf8a(int param_1,undefined1 *param_2)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 auStack_14 [7];
  undefined1 local_d;
  undefined1 *local_c;
  
  local_d = 0;
  local_c = param_2;
  iVar1 = FUN_600f061a(param_1 + 0x1d,auStack_14,&local_d);
  if (iVar1 != 0) {
    FUN_600f05da(param_1 + 0x1d,param_1 + 500,param_1 + 499);
    if (*(char *)(param_1 + 0x26) == '\0') {
      puVar2 = local_c + 1;
      *local_c = *(undefined1 *)(param_1 + 499);
      local_c = local_c + 2;
      *puVar2 = local_d;
      FUN_600fbe82(param_1,&local_c,1);
      FUN_600fbf06(param_1,&local_c,2);
    }
    else {
      puVar2 = local_c + 1;
      *local_c = local_d;
      local_c = local_c + 2;
      *puVar2 = *(undefined1 *)(param_1 + 499);
      FUN_600fbf06(param_1,&local_c,1);
      FUN_600fbe82(param_1,&local_c,2);
    }
  }
  return;
}


