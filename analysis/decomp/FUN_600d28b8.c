// 600d28b8  FUN_600d28b8  size=206 bytes
// --- callers ---
//   60056fa4 FUN_60056fa4
// --- callees ---
//   600d33b2 FUN_600d33b2
//   60056a9c FUN_60056a9c


undefined4 FUN_600d28b8(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  int local_28;
  uint local_24;
  
  local_28 = 0;
  local_24 = 0;
  FUN_600d33b2(*(undefined4 *)(param_2 + 4),0xc,&local_28);
  local_28 = (uint)(local_28 * 7) / 0x48 + local_28;
  FUN_600d33b2(*(undefined4 *)(param_2 + 4),4,&local_24);
  iVar1 = FUN_60056a9c(local_24 & 0xff,*(undefined1 *)(param_2 + 0x14),
                       *(undefined1 *)(param_2 + 0x13),*(undefined2 *)(param_2 + 0xc));
  uVar3 = 0;
  do {
    if (*(ushort *)(param_2 + 0x1c) <= uVar3) {
      return 0xf;
    }
    uVar4 = (uint)(uVar3 >> 3);
    while( true ) {
      if (0x3ff < uVar4) {
        *(short *)(param_2 + 0x20) = (short)(iVar1 + local_28);
        *(ushort *)(param_2 + 0x1e) = uVar3 >> 3;
        *(byte *)(param_2 + 0x26) = (byte)uVar3 & 7;
        *(undefined1 *)(param_2 + 0x27) = 0;
        *(undefined1 *)(param_2 + 0x28) = 0;
        return 0;
      }
      uVar5 = 0;
      for (piVar2 = *(int **)(param_1 + 0x38); piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
        if ((((*(byte *)(piVar2 + 5) & 0xfd) == 1) && (*(ushort *)((int)piVar2 + 0x1e) <= uVar4)) &&
           ((*(ushort *)((int)piVar2 + 0xe) - 1 & uVar4 - *(ushort *)((int)piVar2 + 0x1e)) == 0)) {
          uVar5 = uVar5 + *(ushort *)(piVar2 + 8) & 0xffff;
        }
      }
      if (900 < uVar5 + iVar1 + local_28) break;
      uVar4 = uVar4 + *(ushort *)(param_2 + 0xe) & 0xffff;
    }
    uVar3 = uVar3 + 1;
  } while( true );
}


