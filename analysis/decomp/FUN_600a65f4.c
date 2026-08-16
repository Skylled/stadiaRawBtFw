// 600a65f4  FUN_600a65f4  size=286 bytes
// --- callers ---
//   600f2ef4 FUN_600f2ef4
// --- callees ---
//   600a8108 FUN_600a8108
//   600aa340 FUN_600aa340
//   600aa3cc FUN_600aa3cc
//   6013d168 thunk_EXT_FUN_0000b554
//   600f1ce4 FUN_600f1ce4
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6009ff18 FUN_6009ff18


void FUN_600a65f4(char *param_1)

{
  char *pcVar1;
  int iVar2;
  char *local_34;
  undefined1 auStack_30 [5];
  char local_2b [15];
  undefined1 local_1c;
  int local_18;
  char local_12;
  char local_11;
  
  local_11 = '\0';
  local_12 = *param_1;
  pcVar1 = local_2b;
  for (iVar2 = 0; local_34 = param_1 + 1, iVar2 < 6; iVar2 = iVar2 + 1) {
    *pcVar1 = *local_34;
    pcVar1 = pcVar1 + -1;
    param_1 = local_34;
  }
  local_18 = FUN_6009ff18(auStack_30);
  if (local_18 != 0) {
    local_1c = 10;
    if (local_12 == '\0') {
      local_1c = 0;
      *(ushort *)(local_18 + 0x2a) = *(ushort *)(local_18 + 0x2a) | 2;
    }
    else if (local_12 == '\x18') {
      FUN_600a8108(10);
      FUN_600aa340(DAT_600a6714,0xd,2);
    }
    else {
      iVar2 = thunk_EXT_FUN_0000b554(DAT_600a6718,auStack_30,6);
      if (iVar2 == 0) {
        FUN_600aa3cc(DAT_600a6714);
        if (*(char *)(local_18 + 0x50) != '\x01') {
          local_11 = '\x01';
        }
      }
      else {
        local_11 = '\x01';
      }
    }
    thunk_EXT_FUN_0000b572(auStack_30,local_18 + 0x10,6);
    thunk_EXT_FUN_0000b572(local_2b + 1,local_18 + 0x16,3);
    if (*(int *)(DAT_600a671c + 0x1134) != 0) {
      (**(code **)(DAT_600a671c + 0x1134))(8,auStack_30);
    }
    if (local_11 != '\0') {
      FUN_600f1ce4(local_18,5,*(undefined2 *)(local_18 + 0xc));
    }
  }
  return;
}


