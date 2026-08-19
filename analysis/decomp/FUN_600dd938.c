// 600dd938  FUN_600dd938  size=86 bytes
// --- callers ---
// --- callees ---
//   6013d368 thunk_EXT_FUN_00009304
//   6013d278 thunk_EXT_FUN_00005ab4


void FUN_600dd938(undefined4 param_1,int param_2,int param_3,undefined4 param_4,int param_5,
                 undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = param_2;
  if (param_3 == 0) {
    iVar1 = 0;
  }
  uVar2 = param_4;
  if (param_5 == 0) {
    uVar2 = 0;
  }
  thunk_EXT_FUN_00005ab4(param_1,iVar1,param_3,uVar2,param_5,2,param_6);
  thunk_EXT_FUN_00009304(param_2,param_2 + param_3 * 4,param_4);
  return;
}


