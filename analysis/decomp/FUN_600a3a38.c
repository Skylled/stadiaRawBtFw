// 600a3a38  FUN_600a3a38  size=518 bytes
// --- callers ---
//   600a3d8c FUN_600a3d8c
//   600a3424 FUN_600a3424
//   600a3c54 FUN_600a3c54
// --- callees ---
//   600b2b54 FUN_600b2b54
//   600b2c18 FUN_600b2c18
//   600b2da4 FUN_600b2da4
//   600a3904 FUN_600a3904
//   600b2e68 FUN_600b2e68
//   600b2d20 FUN_600b2d20


undefined4 FUN_600a3a38(undefined1 param_1,int param_2,undefined4 param_3)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  ushort local_24;
  ushort local_22;
  undefined2 local_20;
  undefined2 local_1e;
  char local_1c;
  char local_19;
  int local_18;
  undefined1 local_11;
  
  local_18 = param_2 * 0x24 + DAT_600a3c50 + 0x64c;
  local_11 = 0;
  local_19 = FUN_600a3904(param_1,local_18,param_3,&local_24);
  if (local_19 == *(char *)(local_18 + 0x20)) {
    if ((local_19 == '\0') ||
       ((*(ushort *)(local_18 + 0x1e) <= local_24 && (local_22 <= *(ushort *)(local_18 + 0x1e))))) {
      *(undefined1 *)(local_18 + 0x22) = 0;
      return 0xd;
    }
    local_11 = 1;
  }
  *(undefined1 *)(local_18 + 0x22) = local_11;
  if ((local_19 != '\0') && (*(char *)(local_18 + 0x20) != '\0')) {
    *(undefined1 *)(local_18 + 0x22) = 1;
  }
  local_1c = local_19;
  if (*(char *)(local_18 + 0x22) == '\x01') {
    local_1c = '\0';
  }
  *(undefined1 *)(DAT_600a3c50 + 0x6ec) = 4;
  *(undefined1 *)(DAT_600a3c50 + 0x6ed) = param_1;
  uVar1 = (undefined1)param_2;
  switch(local_1c) {
  case '\0':
    if (*(char *)(local_18 + 0x20) == '\x02') {
      iVar2 = FUN_600b2d20(*(undefined2 *)(param_2 * 0x14c + DAT_600a3c50 + 0x110));
      if (iVar2 != 0) {
        *(undefined1 *)(DAT_600a3c50 + 0x6ec) = uVar1;
      }
    }
    else if ((*(char *)(local_18 + 0x20) == '\x03') &&
            (iVar2 = FUN_600b2e68(*(undefined2 *)(param_2 * 0x14c + DAT_600a3c50 + 0x110)),
            iVar2 != 0)) {
      *(undefined1 *)(DAT_600a3c50 + 0x6ec) = uVar1;
    }
    break;
  case '\x01':
    iVar2 = FUN_600b2b54(*(undefined2 *)(param_2 * 0x14c + DAT_600a3c50 + 0x110),local_24,local_22);
    if (iVar2 != 0) {
      *(undefined1 *)(DAT_600a3c50 + 0x6ec) = uVar1;
    }
    break;
  case '\x02':
    iVar2 = FUN_600b2c18(*(undefined2 *)(param_2 * 0x14c + DAT_600a3c50 + 0x110),local_24,local_22,
                         local_20,local_1e);
    if (iVar2 != 0) {
      *(undefined1 *)(DAT_600a3c50 + 0x6ec) = uVar1;
    }
    break;
  case '\x03':
    iVar2 = FUN_600b2da4(*(undefined2 *)(param_2 * 0x14c + DAT_600a3c50 + 0x110),local_24,local_22);
    if (iVar2 != 0) {
      *(undefined1 *)(DAT_600a3c50 + 0x6ec) = uVar1;
    }
  }
  if (*(char *)(DAT_600a3c50 + 0x6ec) == '\x04') {
    uVar3 = 3;
  }
  else {
    *(undefined1 *)(local_18 + 0x21) = *(undefined1 *)(local_18 + 0x20);
    *(undefined1 *)(local_18 + 0x20) = 5;
    uVar3 = 1;
  }
  return uVar3;
}


