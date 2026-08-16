// 6004a4ac  FUN_6004a4ac  size=58 bytes
// --- callers ---
//   60049a4a FUN_60049a4a
// --- callees ---
//   6004a434 FUN_6004a434


void FUN_6004a4ac(int *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_1[1];
  for (iVar2 = *param_1; iVar3 != iVar2; iVar2 = iVar2 + 0x24) {
    uVar1 = param_2;
    if (param_3 == 0) {
      uVar1 = 0;
    }
    FUN_6004a434(param_1,uVar1,param_3,uVar1,param_3,iVar2);
  }
  return;
}


