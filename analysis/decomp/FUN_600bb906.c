// 600bb906  FUN_600bb906  size=544 bytes
// --- callers ---
//   6013aad0 FUN_6013aad0
// --- callees ---
//   6006dbac FUN_6006dbac
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600b9408 FUN_600b9408


void FUN_600bb906(int param_1,byte *param_2,ushort param_3,ushort param_4)

{
  ushort uVar1;
  short sVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  byte *local_28;
  int local_8;
  ushort local_2;
  
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
    local_8 = iVar4 + 0x1a;
    *(undefined1 *)(iVar4 + 0x19) = 0;
    pbVar5 = param_2 + param_3;
    pbVar3 = param_2;
    local_2 = param_4;
LAB_600bbace:
    local_28 = pbVar3;
    if (local_28 < pbVar5) {
      uVar1 = (ushort)local_28[1];
      if ((*local_28 & 0x7f) - 1 < 3) {
        pbVar3 = local_28 + uVar1 + 2;
      }
      else {
        pbVar3 = pbVar5;
        if ((ushort)(uVar1 + 2) <= param_3) {
          if (-1 < (char)*local_28) {
            if (local_2 < (ushort)(uVar1 + 2)) goto LAB_600bbace;
            thunk_EXT_FUN_0000b572(local_8,local_28,uVar1 + 2);
            local_8 = uVar1 + 2 + local_8;
            local_2 = (local_2 - uVar1) - 2;
          }
          pbVar3 = local_28 + uVar1 + 2;
        }
      }
      goto LAB_600bbace;
    }
    sVar2 = (short)local_8 - (short)(short *)(iVar4 + 10);
    *(short *)(iVar4 + 10) = sVar2 + -2;
    *(short *)(iVar4 + 2) = sVar2 + 2;
    FUN_600b9408(*(undefined4 *)(param_1 + 300),0,iVar4);
  }
  return;
}


