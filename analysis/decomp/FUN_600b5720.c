// 600b5720  FUN_600b5720  size=274 bytes
// --- callers ---
//   600f7cea FUN_600f7cea
// --- callees ---
//   600b54d4 FUN_600b54d4
//   600bb6dc FUN_600bb6dc
//   6013d168 thunk_EXT_FUN_0000b554
//   60098f88 FUN_60098f88
//   600bc880 FUN_600bc880
//   600bc994 FUN_600bc994
//   6009f644 FUN_6009f644
//   600bb44c FUN_600bb44c
//   600a7268 FUN_600a7268
//   600f1746 FUN_600f1746


void FUN_600b5720(undefined2 param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4,
                 undefined2 param_5,undefined2 param_6)

{
  int iVar1;
  int local_c;
  
  local_c = FUN_600bb6dc(param_2,2);
  if (local_c == 0) {
    local_c = FUN_600bb44c(param_2,0,2);
    if (local_c == 0) {
      FUN_600a7268(param_1,2);
      return;
    }
    iVar1 = FUN_600bc880(local_c,4,DAT_600b5834);
    if (iVar1 == 0) {
      FUN_600a7268(param_1,2);
      return;
    }
  }
  *(undefined2 *)(local_c + 2) = param_1;
  *(undefined1 *)(local_c + 10) = 1;
  *(undefined1 *)(local_c + 0x32) = 2;
  *(undefined2 *)(local_c + 0x3c) = param_4;
  *(undefined2 *)(local_c + 0x3a) = *(undefined2 *)(local_c + 0x3c);
  *(undefined2 *)(local_c + 0x40) = param_6;
  *(undefined2 *)(local_c + 0x3e) = param_5;
  *(undefined1 *)(local_c + 0x38) = 8;
  iVar1 = FUN_600f1746(param_2);
  FUN_60098f88(param_2,0,iVar1 + 0x2c,param_1,*(undefined1 *)(local_c + 10),2);
  FUN_6009f644(4,1);
  if ((*(byte *)(DAT_600b5838 + 0x831) & 8) == 0) {
    *(undefined1 *)(local_c + 1) = 4;
    FUN_600bc994(local_c);
  }
  if (((*(char *)(DAT_600b5838 + 0xa68) != '\0') && (*(char *)(DAT_600b583c + 0xf42) != '\0')) &&
     (iVar1 = thunk_EXT_FUN_0000b554(param_2,DAT_600b5840,6), iVar1 == 0)) {
    FUN_600b54d4(param_2);
  }
  return;
}


