// 600bb904  FUN_600bb904  size=2 bytes
// --- callers ---
//   600ba1c4 FUN_600ba1c4
// --- callees ---


void FUN_600bb904(int param_1,byte *param_2,ushort param_3,ushort param_4)

{
  ushort uVar1;
  short sVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbStack_30;
  int iStack_10;
  ushort uStack_a;
  
  if ((param_4 < 0xffe6) && (iVar4 = FUN_6006dbac(param_4 + 0x1a,DAT_600bbb28,800), iVar4 != 0)) {
    *(undefined2 *)(iVar4 + 4) = 0;
    *(char *)(iVar4 + 8) = (char)*(undefined2 *)(*(int *)(param_1 + 300) + 2);
    *(byte *)(iVar4 + 9) = (byte)((ushort)*(undefined2 *)(*(int *)(param_1 + 300) + 2) >> 8) | 0x20;
    *(char *)(iVar4 + 0xc) = (char)param_4 + '\n';
    *(char *)(iVar4 + 0xd) = (char)(param_4 + 10 >> 8);
    *(undefined1 *)(iVar4 + 0xe) = 1;
    *(undefined1 *)(iVar4 + 0xf) = 0;
    *(undefined1 *)(iVar4 + 0x10) = 5;
    *(undefined1 *)(iVar4 + 0x11) = *(undefined1 *)(param_1 + 8);
    *(char *)(iVar4 + 0x12) = (char)param_4 + '\x06';
    *(char *)(iVar4 + 0x13) = (char)(param_4 + 6 >> 8);
    *(char *)(iVar4 + 0x14) = (char)*(undefined2 *)(param_1 + 2);
    *(char *)(iVar4 + 0x15) = (char)((ushort)*(undefined2 *)(param_1 + 2) >> 8);
    *(undefined1 *)(iVar4 + 0x16) = 0;
    *(undefined1 *)(iVar4 + 0x17) = 0;
    *(undefined1 *)(iVar4 + 0x18) = 3;
    iStack_10 = iVar4 + 0x1a;
    *(undefined1 *)(iVar4 + 0x19) = 0;
    pbVar5 = param_2 + param_3;
    pbVar3 = param_2;
    uStack_a = param_4;
LAB_600bbace:
    pbStack_30 = pbVar3;
    if (pbStack_30 < pbVar5) {
      uVar1 = (ushort)pbStack_30[1];
      if ((*pbStack_30 & 0x7f) - 1 < 3) {
        pbVar3 = pbStack_30 + uVar1 + 2;
      }
      else {
        pbVar3 = pbVar5;
        if ((ushort)(uVar1 + 2) <= param_3) {
          if (-1 < (char)*pbStack_30) {
            if (uStack_a < (ushort)(uVar1 + 2)) goto LAB_600bbace;
            thunk_EXT_FUN_0000b572(iStack_10,pbStack_30,uVar1 + 2);
            iStack_10 = uVar1 + 2 + iStack_10;
            uStack_a = (uStack_a - uVar1) - 2;
          }
          pbVar3 = pbStack_30 + uVar1 + 2;
        }
      }
      goto LAB_600bbace;
    }
    sVar2 = (short)iStack_10 - (short)(short *)(iVar4 + 10);
    *(short *)(iVar4 + 10) = sVar2 + -2;
    *(short *)(iVar4 + 2) = sVar2 + 2;
    FUN_600b9408(*(undefined4 *)(param_1 + 300),0,iVar4);
  }
  return;
}


