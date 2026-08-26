// 6010039a  FUN_6010039a  size=64 bytes
// --- callers ---
//   601003da FUN_601003da
// --- callees ---


int FUN_6010039a(int param_1,int param_2)

{
  int iVar1;
  int local_c;
  
  do {
    iVar1 = param_2;
    local_c = iVar1 + -1;
    if (local_c < 0) {
      return iVar1;
    }
    param_2 = local_c;
  } while (*(int *)(local_c * 4 + param_1) == 0);
  return iVar1;
}


