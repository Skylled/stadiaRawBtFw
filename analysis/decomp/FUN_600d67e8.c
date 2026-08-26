// 600d67e8  FUN_600d67e8  size=126 bytes
// --- callers ---
//   600d6866 FUN_600d6866
// --- callees ---
//   60064438 usb_host_audio_topology__60064438
//   600d5fc2 FUN_600d5fc2
//   600d5e14 FUN_600d5e14
//   6013cf40 thunk_EXT_FUN_00007d10
//   600d6658 FUN_600d6658
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   6013d378 thunk_EXT_FUN_0000b532
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600d5e4a FUN_600d5e4a


/* WARNING: Type propagation algorithm not settling */

int * FUN_600d67e8(int *param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int local_34;
  int local_30 [5];
  
  thunk_EXT_FUN_0000b4c2(param_2);
  FUN_600d5e4a(&local_34);
  local_30[3] = 0;
  local_30[1] = 0;
  local_30[2] = 0;
  uVar1 = thunk_EXT_FUN_0000b532(0x18);
  iVar2 = thunk_EXT_FUN_0000b5ba(uVar1,0,0x18);
  iVar3 = *(int *)(param_2 + 0x54);
  *(undefined1 *)(iVar2 + 4) = 0;
  *param_1 = iVar2;
  *(int *)(iVar2 + 0xc) = iVar2 + 4;
  *(int *)(iVar2 + 0x10) = iVar2 + 4;
  local_30[0] = *(int *)(iVar3 + 0xc);
  while (local_30[0] != iVar3 + 4) {
    *(undefined1 *)(local_30[0] + 0x1a) = 0;
    FUN_600d5e14(local_30);
  }
  usb_host_audio_topology__60064438(param_2,param_3,*param_1,local_30 + 1);
  FUN_600d5fc2(local_30 + 1);
  if (local_34 != 0) {
    FUN_600d6658();
  }
  thunk_EXT_FUN_00007d10(param_2);
  return param_1;
}


