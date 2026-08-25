// 600f578e  FUN_600f578e  size=104 bytes
// --- callers ---
//   600f52ee FUN_600f52ee
//   600f539c FUN_600f539c
//   600f57f6 FUN_600f57f6
// --- callees ---
//   600ad494 FUN_600ad494
//   6013cf90 thunk_EXT_FUN_0000b5ba


undefined4 FUN_600f578e(int param_1,undefined4 *param_2,ushort param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*(uint *)(param_1 + 0x14) < (uint)param_3) && (iVar1 = FUN_600ad494(param_1), iVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 4);
    *(uint *)(param_1 + 4) = *(int *)(param_1 + 4) + (uint)param_3;
    *(uint *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) - (uint)param_3;
    thunk_EXT_FUN_0000b5ba(uVar2,0,param_3);
    *param_2 = uVar2;
    uVar2 = 1;
  }
  return uVar2;
}


