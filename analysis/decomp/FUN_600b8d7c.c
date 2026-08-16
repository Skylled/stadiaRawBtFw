// 600b8d7c  FUN_600b8d7c  size=392 bytes
// --- callers ---
//   600bb2ac FUN_600bb2ac
// --- callees ---
//   600b9408 FUN_600b9408
//   600bb534 FUN_600bb534
//   600a7268 FUN_600a7268
//   600aa340 FUN_600aa340
//   600b218c FUN_600b218c
//   600b5e00 FUN_600b5e00
//   600b54d4 FUN_600b54d4
//   600bcae8 FUN_600bcae8


void FUN_600b8d7c(int param_1)

{
  int iVar1;
  code *pcVar2;
  undefined1 local_f;
  undefined2 local_e;
  undefined4 local_c;
  
  if ((((*(char *)(param_1 + 1) == '\x02') || (*(char *)(param_1 + 1) == '\x03')) ||
      (*(char *)(param_1 + 1) == '\x01')) || (*(char *)(param_1 + 1) == '\x05')) {
    *(undefined4 *)(param_1 + 100) = 0;
    local_c = *(int *)(param_1 + 0x5c);
    while (local_c != 0) {
      iVar1 = *(int *)(local_c + 0x124);
      FUN_600b5e00(local_c,3,0);
      local_c = iVar1;
    }
    if (((*(char *)(param_1 + 1) == '\x03') && (*(char *)(DAT_600b8f04 + 0xf42) == '\x01')) ||
       (*(char *)(param_1 + 1) == '\x05')) {
      FUN_600b54d4(DAT_600b8f08);
    }
    FUN_600bb534(param_1);
  }
  if (*(char *)(param_1 + 1) == '\x04') {
    if (*(int *)(param_1 + 0x10) != 0) {
      pcVar2 = *(code **)(param_1 + 0x10);
      *(undefined4 *)(param_1 + 0x10) = 0;
      (*pcVar2)(2);
      local_c = *(int *)(param_1 + 0x5c);
      while (local_c != 0) {
        iVar1 = *(int *)(local_c + 0x124);
        FUN_600b5e00(local_c,3,0);
        local_c = iVar1;
      }
    }
    if (*(int *)(param_1 + 0x5c) == 0) {
      if (*(char *)(param_1 + 0x34) == '\0') {
        local_f = FUN_600a7268(*(undefined2 *)(param_1 + 2),0x13);
      }
      else {
        local_f = FUN_600a7268(*(undefined2 *)(param_1 + 2),0x3b);
      }
      if (local_f == '\x01') {
        *(undefined1 *)(param_1 + 1) = 5;
        local_e = 0x1e;
      }
      else if (local_f == '\0') {
        FUN_600bcae8(param_1);
        *(undefined1 *)(param_1 + 1) = 5;
        local_e = -1;
      }
      else if (local_f == '\x02') {
        local_e = -1;
      }
      else if ((*(char *)(param_1 + 0x16) == '\0') ||
              (iVar1 = FUN_600b218c(*(undefined2 *)(param_1 + 2),0x13), iVar1 == 0)) {
        local_e = 2;
      }
      else {
        FUN_600bcae8(param_1);
        *(undefined1 *)(param_1 + 1) = 5;
        local_e = 0x1e;
      }
      if (local_e != -1) {
        FUN_600aa340(param_1 + 0x44,2,local_e);
      }
    }
    else {
      FUN_600b9408(param_1,0,0);
    }
  }
  return;
}


