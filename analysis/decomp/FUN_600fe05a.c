// 600fe05a  FUN_600fe05a  size=236 bytes
// --- callers ---
//   600fea16 FUN_600fea16
//   600fe960 FUN_600fe960
// --- callees ---
//   600c6380 FUN_600c6380
//   600f7bd8 FUN_600f7bd8
//   600c6318 FUN_600c6318
//   600ee89c FUN_600ee89c
//   600947c0 FUN_600947c0


void FUN_600fe05a(undefined2 *param_1,undefined4 param_2)

{
  undefined1 uVar1;
  
  if (*(int *)(param_1 + 8) != 0) {
    if ((((*(int *)(param_1 + 10) == 0) || (*(char *)((int)param_1 + 0x19) == '\x10')) &&
        (*(char *)(*(int *)(param_1 + 8) + 8) == '\0')) ||
       (*(char *)(*(int *)(param_1 + 8) + 8) == '\x03')) {
      *(undefined1 *)((int)param_1 + 0x19) = 0;
      *(undefined1 *)(*(int *)(param_1 + 8) + 0x31) = 0;
      *(undefined1 *)(*(int *)(param_1 + 8) + 0x26) = 0;
      *(undefined1 *)(*(int *)(param_1 + 8) + 8) = 4;
      if (*(char *)(param_1 + 4) == '\x02') {
        FUN_600f7bd8(*(int *)(param_1 + 8) + 1,0,4,*(int *)(param_1 + 8) + 1,param_2);
      }
      FUN_600c6380(*(undefined4 *)(param_1 + 8));
      uVar1 = FUN_600947c0(*(undefined4 *)(param_1 + 8));
      *(undefined1 *)((int)param_1 + 0x1d) = uVar1;
      if (*(char *)((int)param_1 + 0x1d) == '\0') {
        uVar1 = FUN_600ee89c(*param_1,*(undefined4 *)(param_1 + 8),1);
        *(undefined1 *)((int)param_1 + 0x1d) = uVar1;
      }
      if (*(char *)((int)param_1 + 0x1d) == '\0') {
        *(undefined1 *)(param_1 + 0xd) = 1;
      }
      else {
        FUN_600c6318(*(undefined4 *)(param_1 + 8),*(undefined1 *)((int)param_1 + 0x1d));
      }
    }
    else {
      *(undefined1 *)((int)param_1 + 0x19) = 1;
      if (*(char *)(*(int *)(param_1 + 8) + 8) == '\0') {
        *(undefined1 *)(param_1 + 0xe) = 2;
      }
    }
  }
  return;
}


