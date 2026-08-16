// 600a62cc  FUN_600a62cc  size=680 bytes
// --- callers ---
//   600f2e2e FUN_600f2e2e
//   600f2e66 FUN_600f2e66
//   600f2e4a FUN_600f2e4a
// --- callees ---
//   6009ff18 FUN_6009ff18
//   600a8108 FUN_600a8108
//   600a7268 FUN_600a7268
//   600b4714 FUN_600b4714
//   600a4984 FUN_600a4984
//   600a4a20 FUN_600a4a20
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600b45b4 FUN_600b45b4
//   6013d168 thunk_EXT_FUN_0000b554
//   601024d8 FUN_601024d8


void FUN_600a62cc(char param_1,byte *param_2)

{
  byte *pbVar1;
  int iVar2;
  undefined1 auStack_60 [5];
  byte local_5b [4];
  undefined1 auStack_57 [11];
  int local_4c;
  char local_48;
  undefined1 local_47;
  undefined1 local_46;
  int local_1c;
  undefined1 *local_18;
  char local_11;
  
  local_11 = '\n';
  local_18 = auStack_60;
  pbVar1 = local_5b;
  for (iVar2 = 0; iVar2 < 6; iVar2 = iVar2 + 1) {
    *pbVar1 = *param_2;
    pbVar1 = pbVar1 + -1;
    param_2 = param_2 + 1;
  }
  local_1c = FUN_6009ff18(local_18);
  if (((local_1c == 0) || (*(char *)(DAT_600a6590 + 0x118c) == '\0')) ||
     (iVar2 = thunk_EXT_FUN_0000b554(DAT_600a6594,local_18,6), iVar2 != 0)) {
    *(undefined1 *)(DAT_600a6590 + 0x1abb) = 0xe;
    if (param_1 == '\x02') {
      FUN_600b45b4(local_18,0);
    }
    else if (param_1 == '\x03') {
      local_1c = FUN_6009ff18(local_18);
      if (local_1c != 0) {
        FUN_600a7268(*(undefined2 *)(local_1c + 0xc),5);
      }
    }
    else {
      FUN_600b4714(local_18);
    }
  }
  else {
    thunk_EXT_FUN_0000b572(auStack_60,local_1c + 0x10,6);
    thunk_EXT_FUN_0000b572(local_5b + 1,local_1c + 0x16,3);
    FUN_601024d8(auStack_57,local_1c + 0x2c,10);
    switch(param_1) {
    case '\x02':
      FUN_600a8108(4);
      local_4c = (uint)param_2[3] * 0x1000000 +
                 (uint)*param_2 + (uint)param_2[1] * 0x100 + (uint)param_2[2] * 0x10000;
      param_2 = param_2 + 4;
      local_48 = '\x01';
      if (((*(char *)(local_1c + 0x5a) == '\x01') && (*(char *)(DAT_600a6590 + 0x882) == '\x01')) &&
         (((*(byte *)(local_1c + 0x5b) & 1) != 0 || ((*(byte *)(DAT_600a6590 + 0x883) & 1) != 0))))
      {
        local_48 = '\0';
      }
      local_47 = *(undefined1 *)(DAT_600a6590 + 0x883);
      local_46 = *(undefined1 *)(local_1c + 0x5b);
      break;
    case '\x03':
      local_4c = (uint)param_2[3] * 0x1000000 +
                 (uint)*param_2 + (uint)param_2[1] * 0x100 + (uint)param_2[2] * 0x10000;
      param_2 = param_2 + 4;
      FUN_600a8108(9);
      break;
    case '\x04':
      FUN_600a8108(5);
      break;
    default:
      thunk_EXT_FUN_0000b572(auStack_60,local_1c + 0x10,6);
      thunk_EXT_FUN_0000b572(local_5b + 1,local_1c + 0x16,3);
      FUN_601024d8(auStack_57,local_1c + 0x2c,10);
      break;
    case '\a':
      thunk_EXT_FUN_0000b572(auStack_60,local_1c + 0x10,6);
      thunk_EXT_FUN_0000b572(local_5b + 1,local_1c + 0x16,3);
      FUN_601024d8(auStack_57,local_1c + 0x2c,10);
    }
    if (*(int *)(DAT_600a6590 + 0x1134) == 0) {
      if ((param_1 == '\x02') && (local_48 == '\x01')) {
        local_11 = '\0';
      }
    }
    else {
      local_11 = (**(code **)(DAT_600a6590 + 0x1134))
                           (param_1,auStack_60,param_1,*(code **)(DAT_600a6590 + 0x1134),param_2);
      if (local_11 != '\v') {
        return;
      }
    }
    if (param_1 == '\x02') {
      FUN_600a4984(local_11,local_18);
    }
    else if (param_1 == '\x04') {
      FUN_600a4a20(local_11,local_18,0);
    }
  }
  return;
}


