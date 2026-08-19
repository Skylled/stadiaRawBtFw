// 600daf3a  FUN_600daf3a  size=100 bytes
// --- callers ---
//   60076ba0 FUN_60076ba0
// --- callees ---
//   600daeea FUN_600daeea
//   60101d4e FUN_60101d4e
//   6013d378 thunk_EXT_FUN_0000b532


int * FUN_600daf3a(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  int *local_28;
  int iStack_24;
  
  local_28 = param_1;
  iStack_24 = param_2;
  FUN_600daeea(&local_28);
  iVar1 = iStack_24;
  uVar3 = 0;
  piVar2 = local_28;
  if (iStack_24 != 0) {
    if ((local_28 == (int *)0x0) && (param_2 + 4 != iStack_24)) {
      if (*param_3 < *(int *)(iStack_24 + 0x10)) {
        uVar4 = 1;
      }
      else {
        uVar4 = 0;
      }
    }
    else {
      uVar4 = 1;
    }
    piVar2 = (int *)thunk_EXT_FUN_0000b532(0x14);
    piVar2[4] = *param_3;
    FUN_60101d4e(uVar4,piVar2,iVar1,param_2 + 4);
    uVar3 = 1;
    *(int *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + 1;
  }
  *param_1 = (int)piVar2;
  *(undefined1 *)(param_1 + 1) = uVar3;
  return param_1;
}


