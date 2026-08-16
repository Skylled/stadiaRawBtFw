// 600a2e68  FUN_600a2e68  size=194 bytes
// --- callers ---
//   600a2f3c FUN_600a2f3c
// --- callees ---
//   6006dbac FUN_6006dbac
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6006ddd8 FUN_6006ddd8


void FUN_600a2e68(void)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  int local_14;
  int local_10;
  byte local_a;
  byte local_9;
  
  local_10 = DAT_600a2f2c;
  bVar4 = *(byte *)(DAT_600a2f34 + 0x1108);
  if (0x1d < bVar4) {
    bVar4 = 0x1e;
  }
  iVar3 = FUN_6006dbac(0x30,DAT_600a2f38,0x926);
  if (iVar3 != 0) {
    for (local_9 = 0; iVar2 = local_10, local_a = local_9, (int)(uint)local_9 < (int)(bVar4 - 1);
        local_9 = local_9 + 1) {
      while( true ) {
        local_a = local_a + 1;
        local_14 = iVar2 + 0x30;
        if (bVar4 <= local_a) break;
        pcVar1 = (char *)(iVar2 + 0x46);
        iVar2 = local_14;
        if (*(char *)(local_10 + 0x16) < *pcVar1) {
          thunk_EXT_FUN_0000b572(iVar3,local_14,0x30);
          thunk_EXT_FUN_0000b572(local_14,local_10,0x30);
          thunk_EXT_FUN_0000b572(local_10,iVar3,0x30);
        }
      }
      local_10 = local_10 + 0x30;
    }
    FUN_6006ddd8(iVar3,DAT_600a2f38,0x936);
  }
  return;
}


