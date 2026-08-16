// 600bcae8  FUN_600bcae8  size=242 bytes
// --- callers ---
//   600fa0d6 FUN_600fa0d6
//   600b8d7c FUN_600b8d7c
//   600bb534 FUN_600bb534
// --- callees ---
//   600bc00c FUN_600bc00c


void FUN_600bcae8(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 local_14;
  
  bVar1 = *(byte *)(param_1 + 0x24);
  if (*(char *)(param_1 + 0x32) == '\x02') {
    *(undefined1 *)(param_1 + 0x24) = 0;
  }
  for (local_14 = 0; local_14 < 4; local_14 = local_14 + 1) {
    if (*(int *)(param_1 + (local_14 + 0x24) * 4) == 0) {
      if ((((int)(uint)bVar1 >> (local_14 + 4U & 0xff) & 1U) != 0) &&
         (*(int *)(local_14 * 0x1c + DAT_600bcbdc + 0xed0) != 0)) {
        (**(code **)(local_14 * 0x1c + DAT_600bcbdc + 0xed0))
                  (param_1 + 4,0,*(undefined2 *)(param_1 + 0x30),*(undefined1 *)(param_1 + 0x32));
      }
    }
    else if (*(int *)(param_1 + (local_14 + 0x24) * 4) != *(int *)(param_1 + 100)) {
      uVar2 = *(undefined4 *)(param_1 + (local_14 + 0x24) * 4);
      *(undefined4 *)(param_1 + (local_14 + 0x24) * 4) = 0;
      FUN_600bc00c(uVar2);
      (**(code **)(local_14 * 0x1c + DAT_600bcbdc + 0xed0))
                (param_1 + 4,0,*(undefined2 *)(param_1 + 0x30),*(undefined1 *)(param_1 + 0x32));
    }
  }
  return;
}


