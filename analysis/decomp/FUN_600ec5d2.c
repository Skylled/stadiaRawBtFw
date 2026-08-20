// 600ec5d2  FUN_600ec5d2  size=46 bytes
// --- callers ---
//   6008f5e8 tasn_dec__6008f5e8
// --- callees ---
//   600ec9ca FUN_600ec9ca


void FUN_600ec5d2(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int *local_14;
  int iStack_10;
  
  local_14 = param_1;
  if (param_1[1] != 0) {
    iStack_10 = param_3;
    FUN_600ec9ca(&local_14,0,param_3,param_1[1],param_1);
  }
  *local_14 = param_2;
  if (param_2 == 1) {
    if (param_3 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = 0xff;
    }
    local_14[1] = iVar1;
  }
  else {
    local_14[1] = param_3;
  }
  return;
}


