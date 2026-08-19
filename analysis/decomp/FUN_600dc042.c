// 600dc042  FUN_600dc042  size=142 bytes
// --- callers ---
// --- callees ---
//   6013d1e0 thunk_EXT_FUN_0000912c


void FUN_600dc042(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 local_14;
  undefined4 uStack_10;
  
  iVar2 = 10;
  iVar3 = param_1;
  local_14 = param_2;
  uStack_10 = param_3;
  do {
    iVar1 = thunk_EXT_FUN_0000912c
                      (*(undefined4 *)(param_1 + 0x1c0),&local_14,(int)&local_14 + 2,param_4,iVar3);
    if (iVar1 == 0) {
      return;
    }
    param_4 = (uint)(short)local_14;
    switch(param_4) {
    case 0:
      param_4 = (uint)(local_14._2_2_ == 1);
      *(bool *)(param_1 + 0x1b4) = local_14._2_2_ == 1;
      break;
    case 1:
      param_4 = (uint)(local_14._2_2_ == 1);
      *(bool *)(param_1 + 0x1b5) = local_14._2_2_ == 1;
      break;
    case 2:
      param_4 = (uint)(local_14._2_2_ == 1);
      *(bool *)(param_1 + 0x1b6) = local_14._2_2_ == 1;
      break;
    case 3:
      param_4 = (uint)(local_14._2_2_ == 1);
      *(bool *)(param_1 + 0x1b7) = local_14._2_2_ == 1;
      break;
    case 4:
      param_4 = (uint)(local_14._2_2_ == 1);
      *(bool *)(param_1 + 0x1b8) = local_14._2_2_ == 1;
      break;
    case 5:
      param_4 = (uint)(local_14._2_2_ == 1);
      *(bool *)(param_1 + 0x1b9) = local_14._2_2_ == 1;
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


