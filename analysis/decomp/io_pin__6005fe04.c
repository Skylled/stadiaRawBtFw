// 6005fe04  io_pin__6005fe04  size=318 bytes
// src: io_pin.cc
// --- callers ---
//   600d4d62 FUN_600d4d62
//   6006b3e8 usb_port_controller_tusb320__6006b3e8
//   600d49d8 FUN_600d49d8
//   60068970 FUN_60068970
//   600cbdc8 xbara__600cbdc8
//   600d9b7c FUN_600d9b7c
//   600d4a7e FUN_600d4a7e
//   6006efd4 FUN_6006efd4
//   6006a390 FUN_6006a390
//   60071a30 board__60071a30
//   6005fcc0 FUN_6005fcc0
//   600d49ce FUN_600d49ce
// --- callees ---
//   60101b76 FUN_60101b76
//   600532f0 FUN_600532f0
//   60101740 FUN_60101740


/* src: io_pin.cc */

void io_pin__6005fe04(int *param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  byte *pbVar8;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined1 *local_a8;
  undefined4 local_a4;
  int iStack_a0;
  undefined1 local_9c;
  undefined1 local_9b;
  undefined1 local_9a [134];
  
  if (*param_1 == 0) {
    local_b0 = DAT_6005ff44;
    local_9c = 0;
    local_ac = 0x22;
    local_a8 = local_9a;
    local_9b = 0;
    local_9a[0] = 0;
    local_a4 = 0x80;
    iStack_a0 = *param_1;
    FUN_60101b76(&local_a8,DAT_6005ff48);
    FUN_60101740(&local_b0);
  }
  piVar6 = (int *)param_1[2];
  iVar4 = param_1[3];
  *(uint *)*param_1 = param_1[1] & 0xfU | (uint)*(byte *)((int)param_1 + 0x27) << 4;
  if (piVar6 != (int *)0x0) {
    *piVar6 = iVar4;
  }
  iVar4 = 3;
  iVar5 = 0;
  bVar1 = *(byte *)((int)param_1 + 0x1e);
  if ((char)param_1[7] == '\x03') {
    uVar7 = 0x800;
  }
  else {
    uVar7 = 0;
  }
  do {
    iVar3 = iVar5 + iVar4 >> 1;
    bVar2 = *(byte *)(DAT_6005ff4c + iVar3 * 2);
    if (bVar1 == bVar2) {
      iVar3 = iVar3 * 2;
      goto LAB_6005feaa;
    }
    if (bVar1 < bVar2) {
      iVar4 = iVar3 + -1;
    }
    else {
      iVar5 = iVar3 + 1;
    }
  } while (iVar5 < iVar4);
  if ((bVar1 < *(byte *)(DAT_6005ff4c + iVar5 * 2)) && (iVar5 != 0)) {
    iVar5 = iVar5 + -1;
  }
  iVar3 = iVar5 << 1;
LAB_6005feaa:
  pbVar8 = (byte *)(DAT_6005ff4c + iVar3);
  if (*(byte *)(DAT_6005ff4c + iVar3) != bVar1) {
    pbVar8 = DAT_6005ff50;
  }
  bVar1 = *(byte *)((int)param_1 + 0x1d);
  uVar7 = (*(byte *)((int)param_1 + 0x2a) & 1) << 0xc | (*(byte *)(param_1 + 10) & 7) << 3 |
          *(byte *)((int)param_1 + 0x29) & 1 | (*(byte *)((int)param_1 + 0x2b) & 1) << 0x10 | uVar7
          | (uint)(byte)(pbVar8[1] << 6);
  if (bVar1 != 0) {
    iVar4 = 4;
    iVar5 = 0;
    do {
      iVar3 = iVar5 + iVar4 >> 1;
      bVar2 = *(byte *)(DAT_6005ff54 + iVar3 * 2);
      if (bVar1 == bVar2) {
        iVar3 = iVar3 * 2;
        goto LAB_6005fed8;
      }
      if (bVar1 < bVar2) {
        iVar4 = iVar3 + -1;
      }
      else {
        iVar5 = iVar3 + 1;
      }
    } while (iVar5 < iVar4);
    if ((bVar1 < *(byte *)(DAT_6005ff54 + iVar5 * 2)) && (iVar5 != 0)) {
      iVar5 = iVar5 + -1;
    }
    iVar3 = iVar5 << 1;
LAB_6005fed8:
    pbVar8 = (byte *)(DAT_6005ff54 + iVar3);
    if (*(byte *)(DAT_6005ff54 + iVar3) != bVar1) {
      pbVar8 = DAT_6005ff58;
    }
    uVar7 = uVar7 | 0x2000 | (uint)(ushort)((ushort)pbVar8[1] << 0xe);
  }
  if ((uint *)param_1[4] != (uint *)0x0) {
    *(uint *)param_1[4] = uVar7;
  }
  if (param_1[8] != 0) {
    FUN_600532f0(param_1[8],param_1[6],param_1 + 9);
  }
  return;
}


