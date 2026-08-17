// 6007f454  receiver__6007f454  size=162 bytes
// src: receiver.cc
// --- callers ---
//   600deaea FUN_600deaea
// --- callees ---
//   600decf8 FUN_600decf8
//   601017b4 FUN_601017b4
//   600d37ac FUN_600d37ac
//   600cbb14 FUN_600cbb14
//   601016f0 FUN_601016f0
//   6013cf40 thunk_EXT_FUN_00007d10
//   6013d0e8 thunk_EXT_FUN_00006a74
//   6013d3d8 thunk_EXT_FUN_0000b4c2


/* src: receiver.cc */

byte receiver__6007f454(void)

{
  int *piVar1;
  byte bVar2;
  undefined4 uVar3;
  byte local_a8 [4];
  undefined *local_a4;
  undefined4 local_a0;
  undefined1 *local_9c;
  undefined4 local_98;
  undefined4 uStack_94;
  undefined1 local_90;
  undefined1 local_8f;
  undefined1 local_8e [130];
  byte local_c;
  
  piVar1 = DAT_6007f4f8;
  thunk_EXT_FUN_0000b4c2(DAT_6007f4fc);
  if (*piVar1 != 0) {
    thunk_EXT_FUN_00006a74(*(undefined4 *)(*piVar1 + 0xb0),PTR_DAT_6007f500,0xffffffff,0);
    bVar2 = FUN_601017b4(*piVar1,500);
    if (bVar2 != 0) {
      local_a4 = PTR_s_receiver_cc_6007f504;
      local_a0 = 0x45;
      local_9c = local_8e;
      local_98 = 0x80;
      uStack_94 = 0;
      local_90 = 0;
      local_8f = 0;
      local_8e[0] = 0;
      local_a8[0] = bVar2;
      local_c = bVar2;
      uVar3 = FUN_600cbb14(local_a8);
      FUN_600d37ac(&local_9c,uVar3);
      FUN_600d37ac(&local_9c,PTR_LAB_6011c45c_1_6007f508);
      FUN_600d37ac(&local_9c,PTR_s_Timed_out_joining_SpiReceiverTas_6007f50c);
      bVar2 = local_c;
      FUN_601016f0(0x28,local_a4,local_a0,&local_9c);
      goto LAB_6007f4de;
    }
    FUN_600decf8(piVar1);
  }
  bVar2 = 0;
LAB_6007f4de:
  thunk_EXT_FUN_00007d10(DAT_6007f4fc);
  return bVar2;
}


