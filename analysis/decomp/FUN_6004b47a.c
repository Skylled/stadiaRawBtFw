// 6004b47a  FUN_6004b47a  size=34 bytes
// --- callers ---
//   6004b422 FUN_6004b422
//   6004b43a FUN_6004b43a
// --- callees ---
//   6004b46e FUN_6004b46e


void FUN_6004b47a(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = *(int *)(param_1 + -8) + 8;
    FUN_6004b46e(param_1 + -8,iVar1,param_3,param_4,param_4);
    func_0x6004c2bc(param_1 + -8,iVar1,0);
  }
  return;
}


