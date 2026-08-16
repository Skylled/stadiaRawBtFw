// 600b74d8  FUN_600b74d8  size=408 bytes
// --- callers ---
//   600b85e4 FUN_600b85e4
// --- callees ---
//   600f8264 FUN_600f8264
//   600b731c FUN_600b731c
//   600aa4c4 FUN_600aa4c4


void FUN_600b74d8(int param_1,int param_2,char param_3)

{
  char cVar1;
  undefined2 uVar2;
  byte *pbVar3;
  undefined1 *puVar4;
  char *pcVar5;
  ushort local_a;
  
  pbVar3 = (byte *)(param_1 + 0xb0);
  cVar1 = *(char *)(param_1 + 0xbc);
  *(undefined1 *)(param_1 + 0xbc) = 0;
  if (param_3 == '\0') {
    local_a = (ushort)DAT_600b7670 & *(ushort *)(param_2 + 6) | (ushort)*pbVar3 << 1;
    *pbVar3 = *pbVar3 + 1 & 0x3f;
  }
  else {
    pbVar3 = (byte *)((uint)*(ushort *)(param_2 + 4) + param_2 + 0xc);
    local_a = (ushort)pbVar3[1] * 0x100 + (ushort)*pbVar3 & 0xc07f;
  }
  if (*(char *)(param_1 + 0x7e) == '\x03') {
    if (cVar1 != '\0') {
      local_a = local_a | 0x80;
    }
    local_a = local_a | (ushort)*(byte *)(param_1 + 0xb2) << 8;
    *(undefined1 *)(param_1 + 0xb3) = *(undefined1 *)(param_1 + 0xb2);
    if (*(char *)(param_1 + 0xfe) != '\0') {
      FUN_600aa4c4(param_1 + 0xe8);
    }
  }
  puVar4 = (undefined1 *)((uint)*(ushort *)(param_2 + 4) + param_2 + 0xc);
  *puVar4 = (char)local_a;
  puVar4[1] = (char)(local_a >> 8);
  if (*(char *)(param_1 + 0x11f) != '\x03') {
    pcVar5 = (char *)(param_2 + 8 + (uint)*(ushort *)(param_2 + 4));
    *pcVar5 = (char)*(undefined2 *)(param_2 + 2) + -2;
    pcVar5[1] = (char)(*(ushort *)(param_2 + 2) - 2 >> 8);
    uVar2 = FUN_600f8264(param_2);
    puVar4 = (undefined1 *)
             ((uint)*(ushort *)(param_2 + 2) + (uint)*(ushort *)(param_2 + 4) + param_2 + 8);
    *puVar4 = (char)uVar2;
    puVar4[1] = (char)((ushort)uVar2 >> 8);
    *(short *)(param_2 + 2) = *(short *)(param_2 + 2) + 2;
  }
  if (*(char *)(param_1 + 0x7e) == '\x03') {
    FUN_600b731c(param_1);
  }
  return;
}


