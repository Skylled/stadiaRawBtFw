// 600c52cc  FUN_600c52cc  size=292 bytes
// --- callers ---
// --- callees ---
//   600935dc FUN_600935dc
//   600c53f8 FUN_600c53f8
//   600944c0 FUN_600944c0


void FUN_600c52cc(char param_1,char param_2,char param_3,undefined4 param_4)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  byte local_9;
  
  iVar3 = FUN_600944c0(param_4);
  if ((param_1 == '\0') && (iVar3 != 0)) {
    *(undefined1 *)(iVar3 + 8) = 1;
    for (local_9 = 1; local_9 <= *(byte *)(*DAT_600c53f0 + 1); local_9 = local_9 + 1) {
      if (((param_3 == *(char *)((uint)local_9 * 3 + *DAT_600c53f0 + 1)) ||
          (*(char *)((uint)local_9 * 3 + *DAT_600c53f0 + 1) == -1)) &&
         (param_2 == *(char *)((uint)local_9 * 3 + *DAT_600c53f0))) {
        bVar1 = *(byte *)((uint)local_9 * 3 + *DAT_600c53f0 + 2);
        if (*(byte *)(iVar3 + 9) < bVar1) {
          *(byte *)(iVar3 + 9) = bVar1;
        }
        break;
      }
    }
  }
  if ((param_2 == '\x11') || (param_2 == '\x12')) {
    if (param_1 == '\a') {
      if (iVar3 != 0) {
        *(byte *)(iVar3 + 0xb) = *(byte *)(iVar3 + 0xb) | 0x20;
      }
      if (param_2 == '\x11') {
        uVar2 = FUN_600935dc();
        *(undefined1 *)(DAT_600c53f4 + 0x244) = uVar2;
      }
    }
    else if (param_1 == '\x06') {
      if (iVar3 != 0) {
        *(byte *)(iVar3 + 0xb) = *(byte *)(iVar3 + 0xb) & 0xdf;
      }
      if (param_2 == '\x11') {
        uVar2 = FUN_600935dc();
        *(undefined1 *)(DAT_600c53f4 + 0x244) = uVar2;
      }
    }
  }
  FUN_600c53f8();
  return;
}


