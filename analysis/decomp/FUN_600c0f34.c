// 600c0f34  FUN_600c0f34  size=230 bytes
// --- callers ---
//   600c15a8 FUN_600c15a8
// --- callees ---
//   600b1368 FUN_600b1368
//   600c15a8 FUN_600c15a8
//   600c1030 FUN_600c1030
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_600c0f34(int param_1,int param_2)

{
  int iVar1;
  
  switch(*(byte *)(param_1 + 0x1f2) & 0x7f) {
  case 9:
    thunk_EXT_FUN_0000b572(param_1 + 0x6d,param_2 + 4,*(undefined1 *)(param_2 + 1));
    *(undefined1 *)(param_1 + 0x1f2) = 10;
    iVar1 = FUN_600b1368(DAT_600c102c);
    if (iVar1 == 0) {
      FUN_600c15a8(0);
    }
    break;
  case 10:
    thunk_EXT_FUN_0000b572(param_1 + 0x75,param_2 + 4,*(undefined1 *)(param_2 + 1));
    *(undefined1 *)(param_1 + 0x1f2) = 0xb;
    iVar1 = FUN_600b1368(DAT_600c102c);
    if (iVar1 == 0) {
      FUN_600c15a8(0);
    }
    break;
  case 0xb:
    thunk_EXT_FUN_0000b572(param_1 + 0x7d,param_2 + 4,*(undefined1 *)(param_2 + 1));
    *(undefined1 *)(param_1 + 0x1f2) = 0xc;
    iVar1 = FUN_600b1368(DAT_600c102c);
    if (iVar1 == 0) {
      FUN_600c15a8(0);
    }
    break;
  case 0xc:
    thunk_EXT_FUN_0000b572(param_1 + 0x85,param_2 + 4,*(undefined1 *)(param_2 + 1));
    FUN_600c1030(param_1);
  }
  return;
}


