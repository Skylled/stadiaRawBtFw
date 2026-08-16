// 600c3150  FUN_600c3150  size=242 bytes
// --- callers ---
// --- callees ---
//   600c5c8c FUN_600c5c8c
//   6006dbac FUN_6006dbac
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600a21e4 FUN_600a21e4
//   600c3f04 FUN_600c3f04
//   600aa648 FUN_600aa648


void FUN_600c3150(int param_1)

{
  short sVar1;
  undefined4 uVar2;
  
  sVar1 = (ushort)*(byte *)(param_1 + 0x1a) * 0x14;
  DAT_600c3244[2] = *(undefined4 *)(param_1 + 0x10);
  FUN_600c5c8c();
  FUN_600aa648(DAT_600c3248);
  *(undefined1 *)((int)DAT_600c3244 + 0x142) = *(undefined1 *)(param_1 + 0x1a);
  if ((*(char *)((int)DAT_600c3244 + 0x142) != '\0') && (*(int *)(param_1 + 0x1c) != 0)) {
    uVar2 = FUN_6006dbac(sVar1,DAT_600c324c,0x55e);
    DAT_600c3244[0x51] = uVar2;
    if (DAT_600c3244[0x51] == 0) {
      (**(code **)(param_1 + 0x14))(4,0);
      return;
    }
    thunk_EXT_FUN_0000b572(DAT_600c3244[0x51],*(undefined4 *)(param_1 + 0x1c),sVar1);
  }
  *(undefined1 *)(DAT_600c3244 + 0x52) = *(undefined1 *)((int)DAT_600c3244 + 0x142);
  *DAT_600c3244 = *(undefined4 *)(param_1 + 0x14);
  *(undefined1 *)((int)DAT_600c3244 + 0x13e) = *(undefined1 *)(param_1 + 0x18);
  DAT_600c3244[3] = DAT_600c3244[2];
  *(undefined1 *)(DAT_600c3244 + 0x4d) = 0;
  DAT_600c3244[4] = 0;
  *(undefined1 *)((int)DAT_600c3244 + 0x21) = 0;
  uVar2 = FUN_600a21e4(param_1 + 8);
  DAT_600c3244[1] = uVar2;
  *(undefined1 *)(DAT_600c3244 + 0x50) = *(undefined1 *)(param_1 + 0x19);
  *(undefined1 *)(DAT_600c3244 + 8) = 0;
  FUN_600c3f04(param_1 + 8);
  return;
}


