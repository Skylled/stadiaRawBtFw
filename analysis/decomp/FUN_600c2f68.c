// 600c2f68  FUN_600c2f68  size=280 bytes
// --- callers ---
//   600c4cdc FUN_600c4cdc
// --- callees ---
//   6006d97c FUN_6006d97c
//   600c4d18 FUN_600c4d18
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6006dbac FUN_6006dbac
//   600c41c0 FUN_600c41c0
//   600a2300 FUN_600a2300
//   600aa648 FUN_600aa648
//   6009cd94 FUN_6009cd94
//   600a1fc8 FUN_600a1fc8


void FUN_600c2f68(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_11;
  short local_10;
  short local_e;
  char local_c [2];
  short local_a;
  
  local_a = (ushort)*(byte *)(param_1 + 0x1d) * 0x14;
  if (((*(char *)(DAT_600c3080 + 10) == '\0') || (*(char *)(param_1 + 0x1c) != '\0')) ||
     (iVar1 = FUN_600c4d18(0x200), iVar1 == 0)) {
    FUN_600a2300(0);
    *DAT_600c3088 = *(undefined4 *)(param_1 + 0x18);
    DAT_600c3088[2] = *(undefined4 *)(param_1 + 0x14);
    FUN_6006d97c(&local_10,&local_e,&local_11);
    if ((local_10 != 0) && (local_e != 0)) {
      FUN_6009cd94(local_10,local_e,local_11);
    }
    FUN_600aa648(DAT_600c308c);
    *(undefined1 *)((int)DAT_600c3088 + 0x142) = *(undefined1 *)(param_1 + 0x1d);
    if ((*(char *)((int)DAT_600c3088 + 0x142) != '\0') && (*(int *)(param_1 + 0x20) != 0)) {
      uVar2 = FUN_6006dbac(local_a,PTR_s_bta_dm_search_start_600c3090,0x4f0);
      DAT_600c3088[0x51] = uVar2;
      if (DAT_600c3088[0x51] == 0) {
        local_c[0] = '\x01';
        local_c[1] = 0;
        FUN_600c41c0(local_c);
        return;
      }
      thunk_EXT_FUN_0000b572(DAT_600c3088[0x51],*(undefined4 *)(param_1 + 0x20),local_a);
    }
    local_c[0] = FUN_600a1fc8(param_1 + 8,PTR_LAB_600c40b0_1_600c3098,PTR_FUN_600c41c0_1_600c3094);
    if (local_c[0] != '\x01') {
      local_c[1] = 0;
      FUN_600c41c0(local_c);
    }
  }
  else {
    thunk_EXT_FUN_0000b572(DAT_600c3084,param_1,0x24);
  }
  return;
}


