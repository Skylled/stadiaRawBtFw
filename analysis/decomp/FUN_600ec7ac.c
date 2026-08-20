// 600ec7ac  FUN_600ec7ac  size=30 bytes
// --- callers ---
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554


int FUN_600ec7ac(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_2[1];
  iVar3 = param_1[1];
  iVar1 = iVar2;
  if (iVar3 <= iVar2) {
    iVar1 = iVar3;
  }
  if ((iVar1 == 0) ||
     (iVar1 = thunk_EXT_FUN_0000b554(*param_1,*param_2,iVar1,param_4,param_4), iVar1 == 0)) {
    iVar1 = iVar3 - iVar2;
  }
  return iVar1;
}


