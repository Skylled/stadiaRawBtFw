// 6009c2c0  FUN_6009c2c0  size=384 bytes
// --- callers ---
//   600f139a FUN_600f139a
//   6009ca80 FUN_6009ca80
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6013d168 thunk_EXT_FUN_0000b554
//   6013cf90 thunk_EXT_FUN_0000b5ba


undefined1 FUN_6009c2c0(char param_1,undefined4 param_2,byte *param_3)

{
  int iVar1;
  int iVar2;
  undefined1 local_1b;
  byte local_1a;
  byte local_19;
  int local_18;
  int local_14;
  int local_10;
  byte local_9;
  
  iVar1 = DAT_6009c440;
  local_9 = *param_3;
  local_10 = DAT_6009c440 + 0xf8;
  local_1b = 0;
  if ((param_1 != '\0') &&
     ((*(char *)(DAT_6009c440 + 0xf7) == '\n' || (*(char *)(DAT_6009c440 + 0xf4) == '\0')))) {
    return 0;
  }
  local_19 = 0;
  while( true ) {
    if (9 < local_19) goto LAB_6009c428;
    if ((*(char *)(local_10 + 8) != '\0') &&
       (iVar2 = thunk_EXT_FUN_0000b554(local_10,param_2,6), iVar2 == 0)) break;
    if ((*(char *)(local_10 + 8) == '\0') && (param_1 != '\0')) {
      thunk_EXT_FUN_0000b572(local_10,param_2,6);
      *(undefined1 *)(local_10 + 8) = 1;
      *(char *)(iVar1 + 0xf7) = *(char *)(iVar1 + 0xf7) + '\x01';
      *(byte *)(local_10 + 6) = local_9 | *(byte *)(local_10 + 6);
      local_1b = 1;
      goto LAB_6009c428;
    }
    local_19 = local_19 + 1;
    local_10 = local_10 + 9;
  }
  if (param_1 == '\0') {
    *(byte *)(local_10 + 6) = ~local_9 & *(byte *)(local_10 + 6);
  }
  else {
    *(byte *)(local_10 + 6) = local_9 | *(byte *)(local_10 + 6);
  }
  local_9 = *(byte *)(local_10 + 6);
  if (*(char *)(local_10 + 6) == '\0') {
    thunk_EXT_FUN_0000b5ba(local_10,0,9);
    *(char *)(iVar1 + 0xf7) = *(char *)(iVar1 + 0xf7) + -1;
    local_18 = local_10;
    local_1a = local_19;
    while( true ) {
      local_14 = local_10 + 9;
      local_1a = local_1a + 1;
      if ((9 < local_1a) || (*(char *)(local_10 + 0x11) == '\0')) break;
      thunk_EXT_FUN_0000b572(local_18,local_14,9);
      local_18 = local_18 + 9;
      local_10 = local_14;
    }
    if (local_1a < 0xb) {
      thunk_EXT_FUN_0000b5ba(local_18,0,9);
    }
  }
  local_1b = 1;
LAB_6009c428:
  if (local_19 == 10) {
    return local_1b;
  }
  *param_3 = local_9;
  return local_1b;
}


