// 600a8778  FUN_600a8778  size=608 bytes
// --- callers ---
//   600a89f0 FUN_600a89f0
// --- callees ---
//   600cdd2c FUN_600cdd2c
//   60058060 FUN_60058060


void FUN_600a8778(undefined4 param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  undefined1 auStack_21c [514];
  undefined1 local_1a;
  char local_19;
  short local_18;
  char local_16;
  byte local_15;
  char local_14;
  undefined1 local_13;
  byte local_12;
  byte local_11;
  char *local_10;
  char *local_c;
  
  pcVar2 = (char *)(param_2 + 8 + (uint)*(ushort *)(param_2 + 4));
  local_13 = 4;
  local_12 = 0;
  local_14 = *pcVar2;
  local_15 = pcVar2[1];
  local_c = pcVar2 + 2;
  if ((local_14 == '\x0e') || (local_14 == '\x0f')) {
    local_16 = *local_c;
    local_18 = (ushort)(byte)pcVar2[4] * 0x100 + (ushort)(byte)pcVar2[3];
    local_19 = pcVar2[5];
    local_c = pcVar2 + 6;
    cVar1 = FUN_600cdd2c(auStack_21c,DAT_600a89d8,local_19);
    local_12 = local_12 + cVar1;
    local_10 = local_c;
    for (local_11 = 0; (int)(uint)local_11 < (int)(local_15 - 4); local_11 = local_11 + 1) {
      cVar1 = *local_10;
      local_10 = local_10 + 1;
      cVar1 = FUN_600cdd2c(auStack_21c + local_12,DAT_600a89d8,cVar1);
      local_12 = local_12 + cVar1;
    }
    if (((((local_18 == 0xc03) || (local_18 == 0x201d)) || (local_18 == 0x201e)) ||
        (local_18 == 0x201f)) && (*DAT_600a89dc != '\0')) {
      if ((*DAT_600a89e0 == '\x01') && (local_18 == 0x201f)) {
        FUN_60058060(PTR_s_HCI_LE_TX_PACKET_COUNT__s_600a89e4,auStack_21c);
        *DAT_600a89e0 = '\0';
      }
      else if ((*DAT_600a89e0 == '\x02') && (local_18 == 0x201f)) {
        FUN_60058060(PTR_s_HCI_LE_RX_PACKET_COUNT__s_600a89e8,auStack_21c);
        *DAT_600a89e0 = '\0';
      }
      else {
        FUN_60058060(PTR_DAT_600a89ec,auStack_21c);
      }
      *DAT_600a89dc = '\0';
    }
  }
  if (local_14 == -1) {
    local_10 = local_c + 1;
    if (*local_c == '\a') {
      local_1a = 7;
      local_c = local_10;
      for (local_11 = 0; (int)(uint)local_11 < (int)(local_15 - 1); local_11 = local_11 + 1) {
        cVar1 = *local_10;
        local_10 = local_10 + 1;
        cVar1 = FUN_600cdd2c(auStack_21c + local_12,DAT_600a89d8,cVar1);
        local_12 = local_12 + cVar1;
      }
      if (*DAT_600a89dc != '\0') {
        FUN_60058060(PTR_DAT_600a89ec,auStack_21c);
        *DAT_600a89dc = '\0';
      }
    }
  }
  return;
}


