// 600b8ba4  FUN_600b8ba4  size=460 bytes
// --- callers ---
//   600f2158 FUN_600f2158
//   600bc424 FUN_600bc424
//   600992d4 FUN_600992d4
//   600b89b8 FUN_600b89b8
// --- callees ---
//   600bc710 FUN_600bc710
//   600bb534 FUN_600bb534
//   600d9250 FUN_600d9250
//   6006ddd8 FUN_6006ddd8
//   600bc480 FUN_600bc480
//   6009ec54 FUN_6009ec54
//   600b5e00 FUN_600b5e00
//   600bc00c FUN_600bc00c
//   600bcbe0 FUN_600bcbe0
//   60099204 FUN_60099204


undefined1 FUN_600b8ba4(undefined2 param_1,undefined1 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 local_2b;
  undefined2 local_2a;
  int local_28;
  int local_24;
  undefined1 local_1d;
  int local_1c;
  char local_16;
  undefined1 local_15;
  int local_14;
  
  local_15 = 1;
  local_16 = '\x01';
  local_1d = 1;
  local_2b = param_2;
  local_2a = param_1;
  local_24 = FUN_600bcbe0(param_1);
  if (local_24 == 0) {
    local_15 = 0;
  }
  else {
    if (*(char *)(DAT_600b8d70 + 0x1abb) != '\x0e') {
      *(undefined1 *)(DAT_600b8d70 + 0x1abb) = local_2b;
    }
    *(ushort *)(local_24 + 0x30) = (ushort)*(byte *)(DAT_600b8d70 + 0x1abb);
    *(undefined1 *)(local_24 + 1) = 5;
    if (*(char *)(local_24 + 0x32) == '\x02') {
      FUN_6009ec54(*(undefined1 *)(local_24 + 10),0);
    }
    local_14 = *(int *)(local_24 + 0x5c);
    while (local_14 != 0) {
      local_28 = *(int *)(local_14 + 0x124);
      if (local_14 != *(int *)(local_24 + 100)) {
        FUN_600b5e00(local_14,3,&local_2b);
      }
      local_14 = local_28;
    }
    if ((*(int *)(local_24 + 0x5c) != 0) || (*(int *)(local_24 + 100) != 0)) {
      local_1d = *(undefined1 *)(local_24 + 0x32);
      if (*(char *)(local_24 + 0x32) == '\x02') {
        *(undefined1 *)(DAT_600b8d74 + 0xf42) = 0;
        FUN_60099204(local_24 + 4,*(undefined1 *)(local_24 + 0x32));
        while (*(int *)(local_24 + 0x80) != 0) {
          uVar1 = FUN_600d9250(local_24 + 0x80);
          FUN_6006ddd8(uVar1,DAT_600b8d78,0x227);
        }
      }
      else {
        for (local_1c = 0; local_1c < 4; local_1c = local_1c + 1) {
          if ((*(int *)(local_24 + (local_1c + 0x24) * 4) != 0) &&
             (*(int *)(local_24 + (local_1c + 0x24) * 4) != *(int *)(local_24 + 100))) {
            (**(code **)(local_1c * 0x1c + DAT_600b8d74 + 0xed0))
                      (local_24 + 4,0,*(undefined2 *)(local_24 + 0x30),
                       *(undefined1 *)(local_24 + 0x32));
            FUN_600bc00c(*(undefined4 *)(local_24 + (local_1c + 0x24) * 4));
            *(undefined4 *)(local_24 + (local_1c + 0x24) * 4) = 0;
          }
        }
      }
      iVar2 = FUN_600bc480(local_24,local_1d);
      if (iVar2 != 0) {
        local_16 = '\0';
      }
    }
    *(undefined4 *)(local_24 + 100) = 0;
    if (local_16 != '\0') {
      FUN_600bb534(local_24);
    }
  }
  if ((local_16 != '\0') && (local_24 = FUN_600bc710(1), local_24 != 0)) {
    FUN_600bc480(local_24,1);
  }
  return local_15;
}


