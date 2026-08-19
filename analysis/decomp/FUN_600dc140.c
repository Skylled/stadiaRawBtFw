// 600dc140  FUN_600dc140  size=94 bytes
// --- callers ---
// --- callees ---
//   6013d220 thunk_EXT_FUN_00008f98
//   6013d198 thunk_EXT_FUN_00008fe4
//   6007c698 FUN_6007c698
//   6013d350 thunk_EXT_FUN_00002fac


void FUN_600dc140(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *local_20;
  int iStack_1c;
  
  local_20 = param_1;
  iStack_1c = param_2;
  if (*param_1 == 1) {
    thunk_EXT_FUN_00008f98();
  }
  else {
    iVar1 = param_1[0xa0];
    thunk_EXT_FUN_00008fe4(&local_20,param_1 + 0x9d);
    FUN_6007c698(iVar1,param_2,local_20,iStack_1c);
    if (*(char *)((int)param_1 + 0x1b9) == '\0') {
      local_20 = (int *)param_1[0x9d];
      iStack_1c = param_1[0x9e] - (int)local_20 >> 2;
      if (iStack_1c == 0) {
        local_20 = (int *)0x0;
      }
      thunk_EXT_FUN_00002fac(local_20,iStack_1c,param_3);
    }
  }
  return;
}


