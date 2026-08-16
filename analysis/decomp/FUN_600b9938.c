// 600b9938  FUN_600b9938  size=448 bytes
// --- callers ---
//   600f2ae0 FUN_600f2ae0
// --- callees ---
//   600bcbe0 FUN_600bcbe0
//   600b9408 FUN_600b9408


void FUN_600b9938(byte *param_1)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  byte *pbVar5;
  byte *local_1c;
  byte local_9;
  
  bVar1 = *param_1;
  local_1c = param_1 + 1;
  for (local_9 = 0; local_9 < bVar1; local_9 = local_9 + 1) {
    bVar2 = *local_1c;
    pbVar5 = local_1c + 1;
    uVar3 = (ushort)local_1c[3] * 0x100 + (ushort)local_1c[2];
    local_1c = local_1c + 4;
    iVar4 = FUN_600bcbe0((ushort)*pbVar5 * 0x100 + (ushort)bVar2);
    if ((iVar4 != 0) && (*(int *)(iVar4 + 0x2c) != 0)) {
      (**(code **)(iVar4 + 0x2c))(iVar4 + 4);
    }
    if ((iVar4 == 0) || (*(char *)(iVar4 + 0x32) != '\x02')) {
      if (iVar4 != 0) {
        *(ushort *)(DAT_600b9af8 + 2) = uVar3 + *(short *)(DAT_600b9af8 + 2);
      }
    }
    else {
      *(ushort *)(DAT_600b9af8 + 0xf4a) = uVar3 + *(short *)(DAT_600b9af8 + 0xf4a);
    }
    if (iVar4 != 0) {
      if (*(short *)(iVar4 + 0x1a) == 0) {
        if (*(char *)(iVar4 + 0x32) == '\x02') {
          if (uVar3 < *(ushort *)(DAT_600b9af8 + 0xf52)) {
            *(ushort *)(DAT_600b9af8 + 0xf52) = *(short *)(DAT_600b9af8 + 0xf52) - uVar3;
          }
          else {
            *(undefined2 *)(DAT_600b9af8 + 0xf52) = 0;
          }
        }
        else if (uVar3 < *(ushort *)(DAT_600b9af8 + 6)) {
          *(ushort *)(DAT_600b9af8 + 6) = *(short *)(DAT_600b9af8 + 6) - uVar3;
        }
        else {
          *(undefined2 *)(DAT_600b9af8 + 6) = 0;
        }
      }
      if (uVar3 < *(ushort *)(iVar4 + 0xa0)) {
        *(ushort *)(iVar4 + 0xa0) = *(short *)(iVar4 + 0xa0) - uVar3;
      }
      else {
        *(undefined2 *)(iVar4 + 0xa0) = 0;
      }
      FUN_600b9408(iVar4,0,0);
      if (*(char *)(iVar4 + 0x32) == '\x02') {
        if (((*(char *)(iVar4 + 0x28) == '\x01') && (*(char *)(DAT_600b9af8 + 0xf54) != '\0')) &&
           (*(ushort *)(DAT_600b9af8 + 0xf52) < *(ushort *)(DAT_600b9af8 + 0xf50))) {
          FUN_600b9408(0,0,0);
        }
      }
      else if (((*(char *)(iVar4 + 0x28) == '\x01') && (*(char *)(DAT_600b9af8 + 8) != '\0')) &&
              (*(ushort *)(DAT_600b9af8 + 6) < *(ushort *)(DAT_600b9af8 + 4))) {
        FUN_600b9408(0,0,0);
      }
    }
  }
  return;
}


