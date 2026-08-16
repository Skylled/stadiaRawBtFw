// 6009f6c0  FUN_6009f6c0  size=502 bytes
// --- callers ---
//   600f0568 FUN_600f0568
// --- callees ---
//   6009ee8c FUN_6009ee8c
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   6009ee18 FUN_6009ee18
//   6009f93c FUN_6009f93c
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600a1394 FUN_600a1394
//   6009f08c FUN_6009f08c
//   6009f644 FUN_6009f644
//   6013d168 thunk_EXT_FUN_0000b554
//   600b19c0 FUN_600b19c0


char FUN_6009f6c0(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 local_68;
  undefined2 local_64;
  undefined1 auStack_60 [16];
  undefined1 local_50;
  undefined1 local_4f [39];
  undefined4 local_28;
  int local_24;
  char local_1d;
  int local_1c;
  char local_15;
  undefined1 *local_14;
  
  thunk_EXT_FUN_0000b5ba(&local_50,0,0x28);
  local_15 = '\0';
  local_1c = DAT_6009f8b8;
  local_68 = 0;
  local_64 = 0;
  local_1d = *(char *)(DAT_6009f8b8 + 0x1b0);
  if (*(char *)(DAT_6009f8bc + 0xa6b) == '\0') {
    local_15 = '\0';
  }
  else {
    thunk_EXT_FUN_0000b5ba(auStack_60,0,0x10);
    if (((param_1 != 0) && ((*(ushort *)(param_1 + 0x2a) & 0x80) != 0)) &&
       (((*(byte *)(param_1 + 0x7b) & 2) != 0 || ((*(byte *)(param_1 + 0x7b) & 0x20) != 0)))) {
      if (((*(byte *)(param_1 + 0x72) & 2) == 0) &&
         (iVar2 = FUN_6009ee8c(param_1 + 0x10,2), iVar2 == 0)) {
        if (*(char *)(local_1c + 0x19c) != '\0') {
          if ((local_1d == '\0') || (iVar2 = FUN_6009f644(local_1d,0), iVar2 != 0)) {
            FUN_6009f08c(param_1 + 0x10,1);
            if ((*(byte *)(DAT_6009f8bc + 0x831) & 0x40) == 0) {
              local_14 = local_4f;
              local_50 = 2;
              for (iVar2 = 0; iVar2 < 0x10; iVar2 = iVar2 + 1) {
                puVar1 = local_14 + 1;
                *local_14 = *(undefined1 *)(param_1 + iVar2 + 0x7c);
                local_14 = puVar1;
              }
              puVar1 = local_14 + 1;
              *local_14 = *(undefined1 *)(param_1 + 0x6b);
              local_14 = puVar1;
              for (iVar2 = 0; iVar2 < 6; iVar2 = iVar2 + 1) {
                puVar1 = local_14 + 1;
                *local_14 = *(undefined1 *)((param_1 - iVar2) + 0x71);
                local_14 = puVar1;
              }
              iVar2 = FUN_600a1394(0xfce9,0x18,&local_50,DAT_6009f8c4);
              if (iVar2 == 1) {
                local_15 = '\x01';
              }
            }
            else {
              local_24 = param_1 + 0x7c;
              local_28 = DAT_6009f8c0;
              iVar2 = thunk_EXT_FUN_0000b554(param_1 + 0x6c,&local_68,6);
              if (iVar2 == 0) {
                thunk_EXT_FUN_0000b572(param_1 + 0x6c,param_1 + 0x10,6);
                *(undefined1 *)(param_1 + 0x6b) = *(undefined1 *)(param_1 + 0x6a);
              }
              local_15 = FUN_600b19c0(*(undefined1 *)(param_1 + 0x6b),param_1 + 0x6c,local_24,
                                      local_28);
            }
            if (local_15 != '\0') {
              FUN_6009ee18(param_1 + 0x10,2);
            }
            if (local_1d != '\0') {
              FUN_6009f93c(local_1d);
            }
          }
          else {
            local_15 = '\0';
          }
        }
      }
      else {
        local_15 = '\x01';
      }
    }
  }
  return local_15;
}


