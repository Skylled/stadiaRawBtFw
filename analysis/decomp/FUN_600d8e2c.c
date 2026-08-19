// 600d8e2c  FUN_600d8e2c  size=64 bytes
// --- callers ---
//   6006b3e8 usb_port_controller_tusb320__6006b3e8
//   600d8ed4 FUN_600d8ed4
// --- callees ---
//   6013cf40 thunk_EXT_FUN_00007d10
//   6013d3d8 thunk_EXT_FUN_0000b4c2


void FUN_600d8e2c(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 extraout_r1;
  undefined4 uVar1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r2;
  undefined4 uVar2;
  undefined4 extraout_r2_00;
  undefined4 *puVar3;
  int iVar4;
  
  thunk_EXT_FUN_0000b4c2(param_1 + 0x74);
  uVar1 = extraout_r1;
  uVar2 = extraout_r2;
  if (*(byte *)(param_1 + 0x1d) != param_2) {
    *(char *)(param_1 + 0x1d) = (char)param_2;
    puVar3 = (undefined4 *)(param_1 + 0x20);
    for (iVar4 = 0; iVar4 < *(int *)(param_1 + 0x70); iVar4 = iVar4 + 1) {
      (*(code *)*puVar3)(puVar3[1],*(undefined1 *)(param_1 + 0x1d));
      uVar1 = extraout_r1_00;
      puVar3 = puVar3 + 2;
      uVar2 = extraout_r2_00;
    }
  }
  thunk_EXT_FUN_00007d10(param_1 + 0x74,uVar1,uVar2,param_4);
  return;
}


