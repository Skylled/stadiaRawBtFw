// 600bb534  FUN_600bb534  size=414 bytes
// --- callers ---
//   600b54d4 FUN_600b54d4
//   600b8ba4 FUN_600b8ba4
//   600b89b8 FUN_600b89b8
//   600bc5c4 FUN_600bc5c4
//   600b8d7c FUN_600b8d7c
//   600b50d0 FUN_600b50d0
//   600b59ec FUN_600b59ec
//   600a5964 FUN_600a5964
// --- callees ---
//   600d9250 FUN_600d9250
//   6006ddd8 FUN_6006ddd8
//   600b8f0c FUN_600b8f0c
//   600bc00c FUN_600bc00c
//   600b5c08 FUN_600b5c08
//   60099204 FUN_60099204
//   600aa3cc FUN_600aa3cc
//   600bcae8 FUN_600bcae8


void FUN_600bb534(char *param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  int local_c;
  
  if (*param_1 != '\0') {
    *param_1 = '\0';
    param_1[0x16] = '\0';
    FUN_600aa3cc(param_1 + 0x44);
    FUN_600aa3cc(param_1 + 0x68);
    if (*(int *)(param_1 + 0x8c) != 0) {
      FUN_6006ddd8(*(undefined4 *)(param_1 + 0x8c),DAT_600bb6d4,0x98);
      param_1[0x8c] = '\0';
      param_1[0x8d] = '\0';
      param_1[0x8e] = '\0';
      param_1[0x8f] = '\0';
    }
    if (*(short *)(param_1 + 0xa0) != 0) {
      if (param_1[0x32] == '\x02') {
        *(short *)(DAT_600bb6d8 + 0xf4a) =
             *(short *)(param_1 + 0xa0) + *(short *)(DAT_600bb6d8 + 0xf4a);
        if (*(ushort *)(DAT_600bb6d8 + 0xf4c) < *(ushort *)(DAT_600bb6d8 + 0xf4a)) {
          *(undefined2 *)(DAT_600bb6d8 + 0xf4a) = *(undefined2 *)(DAT_600bb6d8 + 0xf4c);
        }
      }
      else {
        *(short *)(DAT_600bb6d8 + 2) = *(short *)(param_1 + 0xa0) + *(short *)(DAT_600bb6d8 + 2);
        if (*(ushort *)(DAT_600bb6d8 + 0xe9e) < *(ushort *)(DAT_600bb6d8 + 2)) {
          *(undefined2 *)(DAT_600bb6d8 + 2) = *(undefined2 *)(DAT_600bb6d8 + 0xe9e);
        }
      }
    }
    *(undefined1 *)(DAT_600bb6d8 + 0xf42) = 0;
    FUN_600bcae8(param_1);
    local_c = *(int *)(param_1 + 0x5c);
    while (local_c != 0) {
      FUN_600bc00c(local_c);
      local_c = *(int *)(param_1 + 0x5c);
    }
    if ((param_1[1] == '\x04') || (param_1[1] == '\x05')) {
      FUN_60099204(param_1 + 4,param_1[0x32]);
    }
    while (*(int *)(param_1 + 0x80) != 0) {
      uVar1 = FUN_600d9250(param_1 + 0x80);
      FUN_6006ddd8(uVar1,DAT_600bb6d4,0xd3);
    }
    if (param_1[0x32] == '\x02') {
      if (*(short *)(DAT_600bb6d8 + 0xf40) != 0) {
        *(short *)(DAT_600bb6d8 + 0xf40) = *(short *)(DAT_600bb6d8 + 0xf40) + -1;
      }
      FUN_600b5c08();
    }
    else {
      if (*(short *)(DAT_600bb6d8 + 0xecc) != 0) {
        *(short *)(DAT_600bb6d8 + 0xecc) = *(short *)(DAT_600bb6d8 + 0xecc) + -1;
      }
      FUN_600b8f0c();
    }
    if (*(int *)(param_1 + 0x10) != 0) {
      pcVar2 = *(code **)(param_1 + 0x10);
      param_1[0x10] = '\0';
      param_1[0x11] = '\0';
      param_1[0x12] = '\0';
      param_1[0x13] = '\0';
      (*pcVar2)(1);
    }
  }
  return;
}


