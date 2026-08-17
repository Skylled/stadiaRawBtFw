// 6006b2e8  usb_port_controller_tusb320__6006b2e8  size=96 bytes
// src: usb_port_controller_tusb320.cc
// --- callers ---
//   60074658 timer__60074658
// --- callees ---
//   6013cf40 thunk_EXT_FUN_00007d10
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   600d37ac FUN_600d37ac
//   60051120 FUN_60051120
//   600d37b8 FUN_600d37b8


/* src: usb_port_controller_tusb320.cc */

undefined1 usb_port_controller_tusb320__6006b2e8(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 auStack_ac [8];
  undefined1 auStack_a4 [144];
  undefined1 local_14;
  
  thunk_EXT_FUN_0000b4c2(param_1 + 0x74);
  iVar1 = *(int *)(param_1 + 0x70);
  if (iVar1 == 10) {
    FUN_60051120(auStack_ac,DAT_6006b348,0x97,8);
    FUN_600d37ac(auStack_a4,DAT_6006b34c);
    FUN_600d37b8(auStack_ac);
  }
  else {
    *(int *)(param_1 + 0x70) = iVar1 + 1;
    puVar2 = (undefined4 *)(param_1 + (iVar1 + 4) * 8);
    *puVar2 = param_2;
    puVar2[1] = param_3;
    local_14 = 0;
  }
  thunk_EXT_FUN_00007d10(param_1 + 0x74);
  return local_14;
}


