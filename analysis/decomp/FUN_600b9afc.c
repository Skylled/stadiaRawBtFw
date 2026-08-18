// 600b9afc  FUN_600b9afc  size=532 bytes
// --- callers ---
//   60096a50 FUN_60096a50
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6006ddd8 FUN_6006ddd8
//   600bcbe0 FUN_600bcbe0


int FUN_600b9afc(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  int local_34;
  int local_c;
  
  if (param_1 == 0) {
    local_c = 0;
  }
  else {
    pbVar4 = (byte *)(param_1 + 8 + (uint)*(ushort *)(param_1 + 4));
    *(undefined2 *)(param_1 + 6) = 0;
    uVar1 = (ushort)pbVar4[1] * 0x100 + (ushort)*pbVar4;
    uVar2 = (ushort)pbVar4[3] * 0x100 + (ushort)pbVar4[2];
    *(undefined4 *)(DAT_600b9d10 + 0xec8) = 0;
    iVar3 = FUN_600bcbe0((ushort)(((uint)uVar1 << 0x14) >> 0x14));
    local_c = param_1;
    if (iVar3 != 0) {
      local_34 = param_1;
      if ((uVar1 >> 0xc & 3) == 2) {
        if (*(int *)(iVar3 + 0x8c) != 0) {
          FUN_6006ddd8(*(undefined4 *)(iVar3 + 0x8c),DAT_600b9d14,0x7ba);
          *(undefined4 *)(iVar3 + 0x8c) = 0;
        }
        if (param_1 != 0) {
          *(int *)(iVar3 + 0x8c) = param_1;
          *(int *)(DAT_600b9d10 + 0xec8) = iVar3;
        }
      }
      else if (*(int *)(iVar3 + 0x8c) == 0) {
        local_c = 0;
      }
      else {
        iVar5 = *(int *)(iVar3 + 0x8c);
        pbVar4 = (byte *)((uint)*(ushort *)(iVar5 + 4) + iVar5 + 10);
        uVar1 = (ushort)pbVar4[1] * 0x100 + (ushort)*pbVar4;
        if ((uint)uVar2 + (uint)uVar1 < 0x24d) {
          local_c = *(int *)(iVar3 + 0x8c);
          *(int *)(DAT_600b9d10 + 0xec8) = iVar3;
          if (4 < *(ushort *)(param_1 + 2)) {
            thunk_EXT_FUN_0000b572
                      ((uint)*(ushort *)(local_c + 2) + (uint)*(ushort *)(local_c + 4) + local_c + 8
                       ,(uint)*(ushort *)(param_1 + 4) + param_1 + 0xc,*(ushort *)(param_1 + 2) - 4)
            ;
            *(short *)(local_c + 2) = *(short *)(param_1 + 2) + *(short *)(local_c + 2) + -4;
          }
          FUN_6006ddd8(param_1,DAT_600b9d14,0x7e7);
          local_34 = 0;
          *(ushort *)((uint)*(ushort *)(iVar5 + 4) + iVar5 + 10) = uVar2 + uVar1;
        }
        else {
          FUN_6006ddd8(*(undefined4 *)(iVar3 + 0x8c),DAT_600b9d14,0x7f5);
          *(undefined4 *)(iVar3 + 0x8c) = 0;
          local_c = 0;
        }
      }
      if ((local_c == 0) && (local_34 != 0)) {
        FUN_6006ddd8(local_34,DAT_600b9d14,0x803);
      }
    }
  }
  return local_c;
}


