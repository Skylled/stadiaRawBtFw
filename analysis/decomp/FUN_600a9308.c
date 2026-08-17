// 600a9308  FUN_600a9308  size=164 bytes
// --- callers ---
//   600a89f0 FUN_600a89f0
// --- callees ---
//   600a6d70 FUN_600a6d70
//   600b89b8 FUN_600b89b8


void FUN_600a9308(undefined1 *param_1)

{
  byte bVar1;
  byte bVar2;
  char *pcVar3;
  int iVar4;
  char *local_24;
  undefined1 auStack_1c [5];
  char local_17 [3];
  ushort local_14;
  undefined1 local_11;
  
  local_11 = *param_1;
  bVar1 = param_1[1];
  bVar2 = param_1[2];
  pcVar3 = local_17;
  local_24 = param_1 + 3;
  for (iVar4 = 0; iVar4 < 6; iVar4 = iVar4 + 1) {
    *pcVar3 = *local_24;
    pcVar3 = pcVar3 + -1;
    local_24 = local_24 + 1;
  }
  local_17[2] = *local_24;
  local_17[1] = local_24[1];
  local_14 = (ushort)(((uint)(ushort)((ushort)bVar2 * 0x100 + (ushort)bVar1) << 0x14) >> 0x14);
  if ((local_17[2] == '\x01') && (*DAT_600a93ac == '\0')) {
    FUN_600a6d70(auStack_1c,local_14,local_11,local_17[1]);
    FUN_600b89b8(local_11,local_14,auStack_1c);
  }
  return;
}


