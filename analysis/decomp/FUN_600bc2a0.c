// 600bc2a0  FUN_600bc2a0  size=378 bytes
// --- callers ---
//   600b6900 FUN_600b6900
//   600f8664 FUN_600f8664
//   600b6d30 FUN_600b6d30
// --- callees ---
//   600b38fc FUN_600b38fc
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600bc2a0(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (*(char *)(param_2 + 6) != '\0') {
    *(undefined1 *)(param_1 + 0x12) = 1;
    uVar1 = *(undefined4 *)(param_2 + 0xc);
    uVar2 = *(undefined4 *)(param_2 + 0x10);
    uVar3 = *(undefined4 *)(param_2 + 0x14);
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_2 + 8);
    *(undefined4 *)(param_1 + 0x18) = uVar1;
    *(undefined4 *)(param_1 + 0x1c) = uVar2;
    *(undefined4 *)(param_1 + 0x20) = uVar3;
    uVar1 = *(undefined4 *)(param_2 + 0x1c);
    *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_2 + 0x18);
    *(undefined4 *)(param_1 + 0x28) = uVar1;
  }
  if (*(char *)(param_2 + 0x24) == '\0') {
    *(undefined1 *)(param_2 + 0x26) = 0;
  }
  else {
    if (*(char *)(param_2 + 0x26) == '\0') {
      thunk_EXT_FUN_0000b5ba(param_2 + 0x26,0,10);
    }
    else {
      *(undefined2 *)(param_2 + 0x2a) = 0;
      *(undefined2 *)(param_2 + 0x2c) = *(undefined2 *)(param_2 + 0x2a);
      if (*(char *)(param_2 + 0x26) == '\x04') {
        *(undefined1 *)(param_2 + 0x27) = 0;
        *(undefined1 *)(param_2 + 0x28) = *(undefined1 *)(param_2 + 0x27);
      }
    }
    *(char *)(param_1 + 0xb5) =
         (char)(uint)((ulonglong)DAT_600bc41c * (ulonglong)*(byte *)(param_2 + 0x27) >> 0x21);
    if ((*(uint *)(*(int *)(param_1 + 300) + 0x20) & 0x20) == 0) {
      *(undefined1 *)(param_2 + 0x30) = 0;
    }
    else if ((*(char *)(param_2 + 0x30) != '\0') && (*(char *)(param_2 + 0x31) == '\0')) {
      *(byte *)(param_1 + 0x11f) = *(byte *)(param_1 + 0x11f) | 1;
    }
  }
  *(undefined1 *)(param_1 + 0x32) = *(undefined1 *)(param_2 + 0x26);
  *(undefined1 *)(param_1 + 0x30) = *(undefined1 *)(param_2 + 0x24);
  if (*(char *)(param_2 + 0x20) != '\0') {
    if ((*(short *)(param_2 + 0x22) == 0) || (*(short *)(param_2 + 0x22) == -1)) {
      *(undefined1 *)(param_2 + 0x20) = 0;
    }
    else {
      *(undefined2 *)(param_1 + 0x2e) = *(undefined2 *)(param_2 + 0x22);
      iVar4 = *(int *)(param_1 + 300);
      if ((*(ushort *)(param_2 + 0x22) < *(ushort *)(iVar4 + 0x18)) &&
         (*(undefined2 *)(iVar4 + 0x18) = *(undefined2 *)(param_2 + 0x22),
         *(ushort *)(param_2 + 0x22) < 0x500)) {
        FUN_600b38fc(*(undefined2 *)(iVar4 + 2),
                     (short)(int)((longlong)DAT_600bc420 *
                                  (longlong)(int)((uint)*(ushort *)(param_2 + 0x22) * 8 + 3) >> 0x21
                                 ));
      }
    }
  }
  return;
}


