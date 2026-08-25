// 600fa0d6  FUN_600fa0d6  size=262 bytes
// --- callers ---
//   600bc00c FUN_600bc00c
//   600f7a9c FUN_600f7a9c
//   600b5264 FUN_600b5264
//   600b4f34 FUN_600b4f34
// --- callees ---
//   600bcae8 FUN_600bcae8
//   600a7268 FUN_600a7268
//   600aa340 FUN_600aa340
//   600aa3cc FUN_600aa3cc
//   600b218c FUN_600b218c


void FUN_600fa0d6(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 local_10;
  undefined2 local_a;
  
  local_a = *(ushort *)(param_1 + 0x14);
  for (local_10 = 0; local_10 < 4; local_10 = local_10 + 1) {
    if (((local_10 != 1) && (*(int *)(param_1 + (local_10 + 0x24) * 4) != 0)) &&
       (local_a < *(ushort *)(*(int *)(param_1 + (local_10 + 0x24) * 4) + 0x120))) {
      local_a = *(ushort *)(*(int *)(param_1 + (local_10 + 0x24) * 4) + 0x120);
    }
  }
  if (*(char *)(param_1 + 0x16) == '\0') {
    if (local_a == 0) {
      cVar1 = FUN_600a7268(*(undefined2 *)(param_1 + 2),0x13);
      if (cVar1 == '\x01') {
        FUN_600bcae8(param_1);
        *(undefined1 *)(param_1 + 1) = 5;
        local_a = 0x1e;
      }
      else if (cVar1 == '\0') {
        FUN_600bcae8(param_1);
        *(undefined1 *)(param_1 + 1) = 5;
        local_a = 0xffff;
      }
      else if ((*(char *)(param_1 + 0x16) == '\0') ||
              (iVar2 = FUN_600b218c(*(undefined2 *)(param_1 + 2),0x13), iVar2 == 0)) {
        local_a = 2;
      }
      else {
        FUN_600bcae8(param_1);
        *(undefined1 *)(param_1 + 1) = 5;
        local_a = 0x1e;
      }
    }
    if (local_a == 0xffff) {
      FUN_600aa3cc(param_1 + 0x44);
    }
    else {
      FUN_600aa340(param_1 + 0x44,2,local_a);
    }
  }
  return;
}


